#include <Poco/Util/TimerTaskAdapter.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>

#include "olink/clientregistry.h"
#include "olink/iobjectsink.h"
#include "olinkconnection.h"

#include <iostream>
#include <memory>

using namespace ApiGear::PocoImpl;

namespace{
    const std::string jsonContentType = "application/json";
    const std::string defaultGatewayUrl = "ws://localhost:8000/ws";
    const std::string closeFramePayload = "bye";
    const std::string pingFramePayload = "ping";
    long retryInterval = 500; //Milliseconds
    long smallDelay = 10; //Milliseconds
    long tryReconnectDelay = 500; //Milliseconds
}

OlinkConnection::OlinkConnection(ApiGear::ObjectLink::ClientRegistry& registry)
    : m_node(registry),
    m_isConnecting(false),
    m_disconnectRequested(false)
{
    auto writeFunction = [this](const auto& msg) {
        if(m_disconnectRequested){
            trySendImmediately(msg, Poco::Net::WebSocket::FRAME_TEXT);
        } else {
            std::unique_lock<std::timed_mutex> lock(m_queueMutex, std::defer_lock);
            if (lock.try_lock_for(std::chrono::milliseconds(100)))
            {
                m_queue.push(msg);
                lock.unlock();
            }
            scheduleProcessMessages();
        }
    };
    m_node.onWrite(writeFunction);
}

std::shared_ptr<OlinkConnection> OlinkConnection::create(ApiGear::ObjectLink::ClientRegistry& registry)
{
    return  std::shared_ptr<OlinkConnection>(new OlinkConnection(registry));
}

OlinkConnection::~OlinkConnection()
{
    m_disconnectRequested = true;
    auto ids = m_node.registry().getObjectIds(m_node);
    for(auto& id : ids)
    {
        disconnectAndUnlink(id);
    }
    trySendImmediately(closeFramePayload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
    cleanupConnectionResources();
    if (m_receivingDone.valid()){
        m_receivingDone.wait();
    }
}

void OlinkConnection::receiveInLoop()
{
    onConnected();
    auto serverClosedConnection = false;
    do{
        try {
            auto canSocketRead = m_socket ? m_socket->poll(Poco::Timespan(10000), Poco::Net::WebSocket::SELECT_READ) : false;
            if (canSocketRead && !m_disconnectRequested) {
                // TODO change buffer size
                char buffer[1024];
                std::memset(buffer, 0, sizeof buffer);
                int flags;

                std::unique_lock<std::timed_mutex> lock(m_socketMutex, std::defer_lock);
                if (m_socket && lock.try_lock_for(std::chrono::milliseconds(100))) {

                    auto frameSize = m_socket->receiveFrame(buffer, sizeof(buffer), flags);
                    auto frameOpCode = flags & Poco::Net::WebSocket::FRAME_OP_BITMASK;

                    if (frameOpCode == Poco::Net::WebSocket::FRAME_OP_PING){
                        m_socket->sendFrame(buffer, frameSize, Poco::Net::WebSocket::FRAME_OP_PONG);
                    } else if (frameOpCode == Poco::Net::WebSocket::FRAME_OP_PONG) {
                        // handle pong
                    } 
                    lock.unlock();
                    if (frameSize == 0 || frameOpCode == Poco::Net::WebSocket::FRAME_OP_CLOSE)
                    {
                        std::cout << "close connection" << std::endl;
                        serverClosedConnection = true;
                    } else {
                        handleTextMessage(buffer);
                    }
                }
            }
        }
        catch(Poco::Exception& e) {
            serverClosedConnection = true;
            std::cout << "connection closed with exception:"  << e.what() << std::endl;
        }
    } while (!serverClosedConnection && !m_disconnectRequested);
    if (serverClosedConnection)
    {
        cleanupConnectionResources();
    }
}

void OlinkConnection::connectAndLinkObject(ApiGear::ObjectLink::IObjectSink& object)
{
    m_node.registry().addSink(object);
    m_node.registry().setNode(m_node, object.olinkObjectName());
    if (m_socket){
        m_node.linkRemote(object.olinkObjectName());
    }
}

void OlinkConnection::disconnectAndUnlink(const std::string& objectId)  
{
    m_node.unlinkRemote(objectId);
    m_node.registry().removeSink(objectId);
}

void OlinkConnection::connectToHost(Poco::URI url)
{
    m_disconnectRequested = false;
    if(url.empty()) {
        m_serverUrl = Poco::URI(defaultGatewayUrl);
        std::clog << "No host url provided" << std::endl;
    } else {
        m_serverUrl = url;
    }
    
    if(!m_socket && !m_isConnecting) {
        std::clog << "Connecting to host " << url.toString() << std::endl;
        try {
            m_isConnecting = true;
            Poco::Net::HTTPClientSession session(m_serverUrl.getHost(), m_serverUrl.getPort());
            Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/ws", Poco::Net::HTTPMessage::HTTP_1_1);
            request.setKeepAlive(true);
            request.setContentType(jsonContentType);
            Poco::Net::HTTPResponse response;

            m_socket = std::make_unique<Poco::Net::WebSocket>(session, request, response);
            m_receivingDone = std::async(std::launch::async, [this](){receiveInLoop(); });
        } catch (std::exception &e) {
            m_socket.reset();
            std::cerr << "Exception " << e.what() << std::endl;
        }
        m_isConnecting = false;
    }

    // schedule retry if connection fails
    m_processMessagesTask = new Poco::Util::TimerTaskAdapter<OlinkConnection>(*this, &OlinkConnection::processMessages);
    m_retryTimer.schedule(m_processMessagesTask, smallDelay, retryInterval);
}

void OlinkConnection::disconnect() {
    std::clog << " request to disconnect socket" << std::endl;
    m_disconnectRequested = true;
    m_node.unlinkRemoteForAllSinks();
    trySendImmediately(closeFramePayload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
    cleanupConnectionResources();
    m_receivingDone.wait();
}

ApiGear::ObjectLink::ClientNode &OlinkConnection::node()
{
    return m_node;
}

void OlinkConnection::onConnected()
{
    std::clog << " socket connected" << std::endl;
    m_node.linkRemoteForAllSinks();
    scheduleProcessMessages();
}

void OlinkConnection::onDisconnected()
{
    disconnect();    
    std::clog << "received connection close message" << std::endl;
}

void OlinkConnection::handleTextMessage(const std::string &message)
{
    m_node.handleMessage(message);
}

void OlinkConnection::scheduleProcessMessages()
{
    if(m_processMessagesTask){
        m_processMessagesTask->cancel();
    }
    m_processMessagesTask = new Poco::Util::TimerTaskAdapter<OlinkConnection>(*this, &OlinkConnection::processMessages);
    m_retryTimer.schedule(m_processMessagesTask, smallDelay, retryInterval);
}

void OlinkConnection::processMessages(Poco::Util::TimerTask& /*task*/)
{
    trySendImmediately(pingFramePayload, Poco::Net::WebSocket::FRAME_OP_PING);
    // DOROTA TO DO - rewrite so only one lock is locked at the time
    std::unique_lock<std::timed_mutex> lock(m_queueMutex, std::defer_lock);
    if (!lock.try_lock_for(std::chrono::milliseconds(100)))
    {
        while(!m_queue.empty()) {
            auto message = m_queue.front();
            std::clog << "write message to socket " << message << std::endl;
            // if we are using JSON we need to use txt message otherwise binary messages
            // locks the socket mutex. Better to be outside locking queue mutex.
            auto messageSent = trySendImmediately(message, Poco::Net::WebSocket::FRAME_TEXT);
            if (messageSent){
                m_queue.pop();
            } else {
                break;
            }
        }
        }
    lock.unlock();

    if (!m_socket && !m_disconnectRequested) {
        if (m_processMessagesTask){
            m_processMessagesTask->cancel();
        }
        connectToHost(m_serverUrl);
        m_processMessagesTask = new Poco::Util::TimerTaskAdapter<OlinkConnection>(*this, &OlinkConnection::processMessages);
        m_retryTimer.schedule(m_processMessagesTask, tryReconnectDelay, retryInterval);
        return;
    }
    if (m_disconnectRequested)
    {
        trySendImmediately(closeFramePayload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
        cleanupConnectionResources();
    }
}

bool OlinkConnection::trySendImmediately(std::string message, int frameOpCode)
{
    bool succeed = false;
    try {
        std::unique_lock<std::timed_mutex> lock(m_socketMutex, std::defer_lock);
        if (m_socket && lock.try_lock_for(std::chrono::milliseconds(100))) {

            m_socket->sendFrame(message.c_str(), static_cast<int>(message.size()), frameOpCode);
            lock.unlock();
            succeed = true;
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception " << e.what() << std::endl;
    }
    return succeed;
}

void OlinkConnection::cleanupConnectionResources()
{
    // Give time other threads if they are finishing some actions with socket
    std::unique_lock<std::timed_mutex> lock(m_socketMutex, std::defer_lock);
    if (m_socket && lock.try_lock_for(std::chrono::milliseconds(100))){}
    m_socket.reset();
    std::clog << " socket disconnected" << std::endl;
}

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
    long timerInterval = 5000; //Milliseconds
}

OlinkConnection::OlinkConnection(ApiGear::ObjectLink::ClientRegistry& registry)
    : m_node(registry)
{
    ApiGear::ObjectLink::WriteMessageFunc func = [this](std::string msg) {
        m_queueMutex.lock(100);
        m_queue.push(msg);
        m_queueMutex.unlock();
        scheduleProcessMessages();
    };
    m_node.onWrite(func);

    // socket connection retry
    m_processMessagesTask = new Poco::Util::TimerTaskAdapter<OlinkConnection>(*this, &OlinkConnection::processMessages);
    long firstDelay = 10;
    m_retryTimer.schedule(m_processMessagesTask, firstDelay, timerInterval);
}

void OlinkConnection::run()
{
    onConnected();
    bool connectionClosed = false;
    do{
        try {
            auto canSocketRead = m_socket->poll(Poco::Timespan(10000), Poco::Net::WebSocket::SELECT_READ);
            if (canSocketRead) {
                // TODO change buffer size
                char buffer[1024];
                std::memset(buffer, 0, sizeof buffer);

                int flags;
                auto frameSize = m_socket->receiveFrame(buffer, sizeof(buffer), flags);
                auto frameOpCode = flags & Poco::Net::WebSocket::FRAME_OP_BITMASK;

                if (m_socket && frameOpCode == Poco::Net::WebSocket::FRAME_OP_PING){
                    m_socket->sendFrame(buffer, frameSize, Poco::Net::WebSocket::FRAME_OP_PONG);
                } else if (m_socket && frameOpCode == Poco::Net::WebSocket::FRAME_OP_PONG) {
                    // handle pong
                } else if (frameSize == 0 || frameOpCode == Poco::Net::WebSocket::FRAME_OP_CLOSE)
                {
                    std::cout << "close connection" << std::endl;
                    connectionClosed = true;
                } else {
                    handleTextMessage(buffer);
                }
            }
        }
        catch(Poco::Exception& e) {
            connectionClosed = true;
            std::cout << "connection closed with exception:"  << e.what() << std::endl;
        }
    } while (!connectionClosed && !m_disconnectRequested);
    onDisconnected();
}

void OlinkConnection::connectAndLinkObject(ApiGear::ObjectLink::IObjectSink& object)
{
    m_node.registry().addObject(object);
    m_node.registry().setNode(m_node, object.olinkObjectName());
    if (m_socket){
        m_node.linkRemote(object.olinkObjectName());
    }
}

void OlinkConnection::disconnectAndUnlink(const std::string& objectId)  
{
    m_node.unlinkRemote(objectId);
    m_node.registry().removeObject(objectId);
}

void OlinkConnection::connectToHost(Poco::URI url)
{
    static bool connecting = false;
    if(url.empty()) {
        m_serverUrl = Poco::URI(defaultGatewayUrl);
        std::clog << "No host url provided" << std::endl;
    } else {
        m_serverUrl = url;
    }
    std::clog << "Connecting to host " << url.toString() << std::endl;
    

    if(!m_socket && !connecting) {
        try {
            connecting = true;
            Poco::Net::HTTPClientSession session(m_serverUrl.getHost(), m_serverUrl.getPort());
            Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/ws", Poco::Net::HTTPMessage::HTTP_1_1);
            request.setKeepAlive(true);
            request.setContentType(jsonContentType);
            Poco::Net::HTTPResponse response;

            m_socket = std::make_unique<Poco::Net::WebSocket>(session, request, response);
            Poco::ThreadPool::defaultPool().start(*this);
        } catch (std::exception &e) {
            m_socket.reset();
            std::cerr << "Exception " << e.what() << std::endl;
        }
        connecting = false;
    }
}

void OlinkConnection::disconnect() {

    m_node.unlinkRemoteForAllSinks();
    try {
        if(m_socket) {
            m_socket->sendFrame(closeFramePayload.c_str(), static_cast<int>(closeFramePayload.size()), Poco::Net::WebSocket::FRAME_OP_CLOSE);
        }
    } catch (std::exception &e) {
        std::cerr << "Exception " << e.what() << std::endl;
        return;
    }
    m_disconnectRequested = true;
    m_processMessagesTask->cancel();
    Poco::ThreadPool::defaultPool().joinAll();
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
    m_node.unlinkRemoteForAllSinks();
    m_socket.reset();
    std::clog << " socket disconnected" << std::endl;
}

void OlinkConnection::handleTextMessage(const std::string &message)
{
    m_node.handleMessage(message);
}

void OlinkConnection::scheduleProcessMessages()
{
    m_processMessagesTask->cancel();
    m_processMessagesTask = new Poco::Util::TimerTaskAdapter<OlinkConnection>(*this, &OlinkConnection::processMessages);
    long firstDelay = 10;
    m_retryTimer.schedule(m_processMessagesTask, firstDelay, timerInterval);
}

void OlinkConnection::processMessages(Poco::Util::TimerTask& /*task*/)
{
    if (m_socket) {
        m_processMessagesTask->cancel();
        connectToHost(m_serverUrl);
        m_processMessagesTask = new Poco::Util::TimerTaskAdapter<OlinkConnection>(*this, &OlinkConnection::processMessages);
        long firstDelay = 5000;
        m_retryTimer.schedule(m_processMessagesTask, firstDelay, timerInterval);
        return;
    }
    m_socket->sendFrame(pingFramePayload.c_str(), static_cast<int>(pingFramePayload.size()), Poco::Net::WebSocket::FRAME_OP_PING);
    m_queueMutex.lock(100);
    while(!m_queue.empty()) {
        // if we are using JSON we need to use txt message
        // otherwise binary messages
        const std::string msg = m_queue.front();
        std::clog << "write message to socket " << msg << std::endl;
        try {
            if(m_socket) {
                m_socket->sendFrame(msg.c_str(), static_cast<int>(msg.size()));
                m_queue.pop();
            } else {
                return;
            }
        } catch (std::exception &e) {
            std::cerr << "Exception " << e.what() << std::endl;
            return;
        }
    }
    m_queueMutex.unlock();
}

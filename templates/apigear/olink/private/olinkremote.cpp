#include "Poco/Buffer.h"
#include "Poco/Exception.h"
#include "Poco/Net/WebSocket.h"
#include "private/olinkremote.h"
#include "private/requesthandlerfactory.h"
#include "private/iconnectionstorage.h"
#include "olink/remotenode.h"
#include <iostream>
#include <chrono>
#include <future>
#include <mutex>

namespace 
{
    const std::string closeFramePayload = "bye";
}

namespace ApiGear {
namespace PocoImpl {

OLinkRemote::OLinkRemote(std::unique_ptr<Poco::Net::WebSocket> socket, IConnectionStorage& connectionStorage, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_socket(std::move(socket)),
     m_connectionStorage(connectionStorage),
     m_stopConnection(false),
     m_node(ApiGear::ObjectLink::RemoteNode::createRemoteNode(registry))
{
    m_node->onLog(m_log.logFunc());
    m_node->onWrite([this](std::string msg) {
        writeMessage(msg, Poco::Net::WebSocket::FRAME_TEXT);
    });
    m_receivingDone = std::async(std::launch::async, [this](){receiveInLoop(); });
}

OLinkRemote::~OLinkRemote(){
    if(m_socket)
    {
        close();
    }
}

void OLinkRemote::close(){
    m_stopConnection = true;
    m_receivingDone.wait();
    writeMessage(closeFramePayload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
    closeSocket();
}

void OLinkRemote::writeMessage(const std::string msg, int frameOpcode)
{
    std::unique_lock<std::timed_mutex> lock(m_socektMutex, std::defer_lock);
    if (!lock.try_lock_for(std::chrono::milliseconds(100)))
    {
        std::cout << "socket busy, dropping message  " << msg << std::endl;
        return;
    }

    std::cout << "writing " << msg << std::endl;
    if (m_socket ){
        try {
            m_socket->sendFrame(msg.c_str(), static_cast<int>(msg.size()), frameOpcode);
        }
        catch (Poco::Exception& e) {
            lock.unlock();
            std::cerr << "Exception " << e.what() << std::endl;
        }
    }
    lock.unlock();
}

void OLinkRemote::handleMessage(const std::string& msg)
{
    std::cout << msg;
    if (m_node)
    {
        m_node->handleMessage(msg);
    }
}

void OLinkRemote::receiveInLoop(){
    // TODO change buffer size
    bool clientClosedConnection = false;
    do
    {
        try {
            bool canSocketRead = m_socket && m_socket->poll(Poco::Timespan(10000), Poco::Net::WebSocket::SELECT_READ);
            if (canSocketRead && !m_stopConnection){
                char buffer[1024];
                int flags;
                std::memset(buffer, 0, sizeof buffer);
                std::unique_lock<std::timed_mutex> lock(m_socektMutex, std::defer_lock);
                if (lock.try_lock_for(std::chrono::milliseconds(100))) {
                
                    auto receivedSize = m_socket->receiveFrame(buffer, sizeof(buffer), flags);
                    lock.unlock();
                
                    auto frameOpcode = flags & Poco::Net::WebSocket::FRAME_OP_BITMASK;
                    if (frameOpcode == Poco::Net::WebSocket::FRAME_OP_PING) {
                         m_socket->sendFrame(buffer, receivedSize, Poco::Net::WebSocket::FRAME_OP_PONG);
                    } else if (frameOpcode == Poco::Net::WebSocket::FRAME_OP_PONG){
                         // handle pong
                    } else if (receivedSize == 0 || frameOpcode == Poco::Net::WebSocket::FRAME_OP_CLOSE){
                        std::cout << "close connection" << std::endl;
                        clientClosedConnection = true;
                    } else {
                        handleMessage(buffer);
                    }
                }
            }
        } catch (Poco::Exception& /*e*/) {
            clientClosedConnection = true;
        }
    } while (!clientClosedConnection && !m_stopConnection);
    if (!m_stopConnection)
    {   
        closeSocket();
        m_connectionStorage.notifyConnectionClosed();
    }
}


bool OLinkRemote::isClosed() const
{
    return m_socket == nullptr;
}

void OLinkRemote::closeSocket()
{
    std::unique_lock<std::timed_mutex> lock(m_socektMutex, std::defer_lock);
    if (!lock.try_lock_for(std::chrono::milliseconds(100))) {
        std::cout << "closing socket, some messages may be dropped" << std::endl;
    }
    m_socket.reset();
    m_node.reset();
    lock.unlock();
}

}}  //namespace ApiGear::PocoImpl

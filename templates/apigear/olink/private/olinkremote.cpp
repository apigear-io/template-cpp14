#include <iostream>
#include "Poco/Buffer.h"
#include "Poco/Exception.h"
#include "Poco/Net/WebSocket.h"
#include "private/olinkremote.h"
#include "private/requesthandlerfactory.h"
#include "private/iconnectionstorage.h"
#include "olink/remotenode.h"

namespace 
{
    const std::string closeFramePayload = "bye";
    const long tryLockTimeoutMilliseconds = 100;
}

namespace ApiGear {
namespace PocoImpl {

OLinkRemote::OLinkRemote(std::unique_ptr<Poco::Net::WebSocket> socket, IConnectionStorage& connectionStorage, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_socket(std::move(socket)),
     m_connectionStorage(connectionStorage),
     m_stopRequested(false),
     m_node(registry)
{
    m_node.onLog(m_log.logFunc());
    m_node.onWrite([this](std::string msg) {
        writeMessage(msg, Poco::Net::WebSocket::FRAME_TEXT);
    });
    m_thread.start(*this);
}

OLinkRemote::~OLinkRemote(){
    if (m_thread.isRunning())
    {
        m_thread.join();
    }
    if(m_socket)
    {
        close();
    }
}

void OLinkRemote::close(){
    m_stopRequested = true;
    m_thread.join();
    writeMessage(closeFramePayload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
    m_socket.reset();
}

void OLinkRemote::writeMessage(const std::string msg, int frameOpcode)
{
    if (!m_socektMutex.tryLock(tryLockTimeoutMilliseconds))
    {
        std::cout << "couldn't get socket, dropping message  " << msg << std::endl;
    }

    std::cout << "writing " << msg << std::endl;
    if (m_socket ){
        try {
            m_socket->sendFrame(msg.c_str(), static_cast<int>(msg.size()), frameOpcode);
        }
        catch (Poco::Exception& e) {
            std::cerr << "Exception " << e.what() << std::endl;
        }
    }
    m_socektMutex.unlock();
}

void OLinkRemote::handleMessage(const std::string& msg)
{
    std::cout << msg;

    m_node.handleMessage(msg);
}

void OLinkRemote::run(){
    // TODO change buffer size
    bool clientClosedConnection = false;
    do
    {
        try {
            if(m_socektMutex.tryLock(tryLockTimeoutMilliseconds)) {
                bool canSocketRead = m_socket && m_socket->poll(Poco::Timespan(10000), Poco::Net::WebSocket::SELECT_READ);
                if (canSocketRead && !m_stopRequested){
                    char buffer[1024];
                    int flags;
                    std::memset(buffer, 0, sizeof buffer);
                    auto receivedSize = m_socket->receiveFrame(buffer, sizeof(buffer), flags);
                    auto frameOpcode = flags & Poco::Net::WebSocket::FRAME_OP_BITMASK;
                    if (frameOpcode == Poco::Net::WebSocket::FRAME_OP_PING) {
                        m_socket->sendFrame(buffer, receivedSize, Poco::Net::WebSocket::FRAME_OP_PONG);
                    }
                    else if (frameOpcode == Poco::Net::WebSocket::FRAME_OP_PONG){
                        // handle pong
                    }
                    else if (receivedSize == 0 || frameOpcode == Poco::Net::WebSocket::FRAME_OP_CLOSE)
                    {
                        std::cout << "close connection" << std::endl;
                        clientClosedConnection = true;
                    }
                    else {
                        handleMessage(buffer);
                    }
                }
                m_socektMutex.unlock();
            }
        } catch (Poco::Exception& /*e*/) {
            clientClosedConnection = true;
        }
    } while (!clientClosedConnection && !m_stopRequested);
    std::cout << "connection closed" << std::endl;
    if (!m_stopRequested)
    {   
        m_socket.reset();
        m_connectionStorage.notifyConnectionClosed();
    }
}

bool OLinkRemote::isMarkedForDeletion() const
{
    return m_socket == nullptr;
}

}}  //namespace ApiGear::PocoImpl

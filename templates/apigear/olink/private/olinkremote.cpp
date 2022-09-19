#include <iostream>
#include "Poco/Buffer.h"
#include "Poco/Exception.h"
#include "Poco/Net/WebSocket.h"
#include "private/olinkremote.h"
#include "private/requesthandlerfactory.h"
#include "olink/remotenode.h"

namespace ApiGear {
namespace PocoImpl {

OLinkRemote::OLinkRemote(RequestHandlerFactory* factory, Poco::Net::WebSocket* socket)
    : m_socket(socket)
    , m_stopRequested(false)
    , m_factory(factory)
    , m_node(*factory->getRegistry())
{
    m_node.onLog(m_log.logFunc());
    ApiGear::ObjectLink::WriteMessageFunc writeFunc = [this](std::string msg) {
        writeMessage(msg);
    };
    m_node.onWrite(writeFunc);
    m_thread.start(*this);
}

OLinkRemote::~OLinkRemote(){

}

void OLinkRemote::close(){
    m_stopRequested = true;
    m_factory = nullptr;
    m_thread.join();
    try {
        if (m_socket != nullptr) {
            m_socket->sendFrame("bye", 3, Poco::Net::WebSocket::FRAME_OP_CLOSE);
        }
    }
    catch (Poco::Exception& e) {
        std::cerr << "Exception " << e.what() << std::endl;
        return;
    }
}

void OLinkRemote::writeMessage(const std::string msg)
{
    std::cout << msg;
    if (m_socket == nullptr) {
        return;
    }

    try {
        m_socket->sendFrame(msg.c_str(), msg.size());
    }
    catch (Poco::Exception& e) {
        std::cerr << "Exception " << e.what() << std::endl;
        return;
    }
}

void OLinkRemote::handleMessage(const std::string& msg)
{
    std::cout << msg;

    m_node.handleMessage(msg);
}

void OLinkRemote::run(){
    // TODO change buffer size
    char buffer[1024];
    int flags;
    int n;
    bool connectionClosed = false;
    do
    {
        try {
            if (m_socket->poll(Poco::Timespan(10000), 1) && !m_stopRequested) {
                std::memset(buffer, 0, sizeof buffer);
                n = m_socket->receiveFrame(buffer, sizeof(buffer), flags);
                if ((flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_PING) {
                    m_socket->sendFrame(buffer, n, Poco::Net::WebSocket::FRAME_OP_PONG);
                }
                else if (m_socket != nullptr && ((flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_PONG))
                {
                    // handle pong
                }
                else if (n == 0 || (flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_CLOSE)
                {
                    std::cout << "close connection" << std::endl;
                    connectionClosed = true;
                }
                else {
                    handleMessage(buffer);
                }
            }
        }
        catch (Poco::Exception& e) {
            connectionClosed = true;
        }
    } while (!connectionClosed && !m_stopRequested);
    std::cout << "connection closed" << std::endl;
    if (m_factory != nullptr) {
        m_factory->removeRemoteConnection(this);
    }
}

}}
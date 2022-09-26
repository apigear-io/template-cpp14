#pragma once

#include "olink/remotenode.h"
#include "olink/consolelogger.h"

#include <Poco/Net/WebSocket.h>
#include <atomic>
#include <memory>
#include <mutex>
#include <future>

namespace ApiGear {

namespace ObjectLink {
class RemoteRegistry;
} // namespace ObjectLink

namespace PocoImpl {

class IConnectionStorage;

class OLinkRemote
{
public:
    explicit OLinkRemote(std::unique_ptr<Poco::Net::WebSocket> socket,
                        IConnectionStorage& connectionStorage,
                        ApiGear::ObjectLink::RemoteRegistry& registry);

    ~OLinkRemote();
    void writeMessage(const std::string msg, int frameOpcode);
    void handleMessage(const std::string& msg);

    void close();
    bool isClosed() const;

private:
    void closeSocket();
    void receiveInLoop();
    std::unique_ptr<Poco::Net::WebSocket> m_socket;
    IConnectionStorage& m_connectionStorage;

    std::atomic<bool> m_stopConnection;

    std::unique_ptr<ApiGear::ObjectLink::RemoteNode> m_node;

    ApiGear::ObjectLink::ConsoleLogger m_log;
    std::future<void> m_receivingDone;

    /** A mutex for the using socket */
    std::timed_mutex m_socektMutex;
};
}}   //namespace ApiGear::PocoImpl

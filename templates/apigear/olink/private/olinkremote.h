#pragma once

#include "olink/remotenode.h"
#include "olink/consolelogger.h"

#include <Poco/Mutex.h>
#include <Poco/Thread.h>
#include <Poco/Net/WebSocket.h>
#include <atomic>
#include <memory>

namespace ApiGear {

namespace ObjectLink {
class RemoteRegistry;
} // namespace ObjectLink

namespace PocoImpl {

class IConnectionStorage;

class OLinkRemote : public Poco::Runnable
{
public:
    explicit OLinkRemote(std::unique_ptr<Poco::Net::WebSocket> socket,
                        IConnectionStorage& connectionStorage,
                        ApiGear::ObjectLink::RemoteRegistry& registry);

    ~OLinkRemote();
    void writeMessage(const std::string msg, int frameOpcode);
    void handleMessage(const std::string& msg);

    void run() override;
    void close();
    bool isMarkedForDeletion() const;

private:
    std::unique_ptr<Poco::Net::WebSocket> m_socket;
    IConnectionStorage& m_connectionStorage;

    Poco::Thread m_thread;
    std::atomic<bool> m_stopRequested;

    ApiGear::ObjectLink::RemoteNode m_node;

    ApiGear::ObjectLink::ConsoleLogger m_log;

    /** A mutex for the using socket */
    Poco::Mutex m_socektMutex;
};
}}   //namespace ApiGear::PocoImpl

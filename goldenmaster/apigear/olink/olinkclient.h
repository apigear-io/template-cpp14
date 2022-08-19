#pragma once

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
  #define APIGEAR_OLINK_EXPORT __attribute__ ((dllexport))
#else
  #define APIGEAR_OLINK_EXPORT __declspec(dllexport)
#endif
#else
  #if __GNUC__ >= 4
    #define APIGEAR_OLINK_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define APIGEAR_OLINK_EXPORT
  #endif
#endif

#include <Poco/URI.h>
#include <Poco/Net/WebSocket.h>
#include <Poco/Util/Timer.h>
#include <Poco/Util/TimerTask.h>
#include <Poco/Mutex.h>
#include <atomic>
#include <queue>
#include <set>
#include "olink/clientnode.h"
#include "olink/consolelogger.h"

namespace ApiGear {
namespace PocoImpl {
class APIGEAR_OLINK_EXPORT OLinkClient: public Poco::Runnable
{
public:
    OLinkClient(ApiGear::ObjectLink::ClientRegistry& registry);
    virtual ~OLinkClient();

    void connectToHost(Poco::URI url=Poco::URI());
    void disconnect();
    ApiGear::ObjectLink::ClientNode &node();

    void linkObjectSource(std::string name);
    void run() override;
    void processMessages(Poco::Util::TimerTask& task);

private:
    void onConnected();
    void onDisconnected();
    void handleTextMessage(const std::string& message);
    void process();

    Poco::Mutex m_queueMutex;
    Poco::URI m_serverUrl;
    Poco::Net::WebSocket *m_socket;
    Poco::Util::Timer m_retryTimer;
    Poco::Util::TimerTask::Ptr m_task;
    std::queue<std::string> m_queue;
    std::atomic<bool> m_disconnectRequested;

    ApiGear::ObjectLink::ClientNode m_node;
    ApiGear::ObjectLink::ConsoleLogger m_logger;
    std::set<std::string> m_linkedObjects;
};
} // namespace PocoImpl
} // namespace ApiGear

#pragma once

#include "olink/remotenode.h"
#include "olink/consolelogger.h"

#include <Poco/Thread.h>
#include <atomic>

namespace Poco {
namespace Net {
class WebSocket;
}} //namespace Poco::Net


namespace ApiGear {
namespace PocoImpl {

class RequestHandlerFactory;

class OLinkRemote : public Poco::Runnable
{
public:
    explicit OLinkRemote(RequestHandlerFactory* factory, Poco::Net::WebSocket* socket);
    ~OLinkRemote();
    void writeMessage(const std::string msg);
    void handleMessage(const std::string& msg);

    void run() override;
    void close();

private:
    Poco::Net::WebSocket* m_socket;
    ApiGear::ObjectLink::RemoteNode m_node;
    ApiGear::ObjectLink::ConsoleLogger m_log;
    std::atomic<bool> m_stopRequested;
    Poco::Thread m_thread;
    RequestHandlerFactory* m_factory;
};
}}

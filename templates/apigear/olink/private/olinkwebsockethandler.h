#pragma once

#include "Poco/Net/HTTPRequestHandler.h"

namespace Poco {
namespace Net {
class HTTPServerRequest;
class HTTPServerResponse;
}
}


namespace ApiGear {
namespace PocoImpl {
class RequestHandlerFactory;

class OLinkWebsocketHandler : public Poco::Net::HTTPRequestHandler
{
public:
    explicit OLinkWebsocketHandler(RequestHandlerFactory* factory);
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
    void close();
private:
    RequestHandlerFactory* m_factory;
};

}}

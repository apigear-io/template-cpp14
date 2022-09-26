#pragma once

#include "Poco/Net/HTTPRequestHandler.h"

namespace Poco {
namespace Net {
class HTTPServerRequest;
class HTTPServerResponse;
}} // namespace Poco::Net


namespace ApiGear {
namespace PocoImpl {

class IConnectionStorage;

class OLinkWebsocketHandler : public Poco::Net::HTTPRequestHandler
{
public:
    explicit OLinkWebsocketHandler(IConnectionStorage& connectionStorage);
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
private:
    IConnectionStorage& m_connectionStorage;
};

}}   //namespace ApiGear::PocoImpl

#pragma once

#include "private/apigear_olink.hpp"
#include "Poco/Net/HTTPRequestHandlerFactory.h"

// HTTPServerRequest forward declaration
namespace Poco {
namespace Net {
class HTTPServerRequest;
}} //namespace Poco::Net

namespace ApiGear {
namespace PocoImpl {

// IConnectionStorage forward declaration
class IConnectionStorage;

class RequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    RequestHandlerFactory(IConnectionStorage& connectionStorage);
    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request) override;
private:
    IConnectionStorage& m_connectionStorage;
};

}} //namespace ApiGear::PocoImpl

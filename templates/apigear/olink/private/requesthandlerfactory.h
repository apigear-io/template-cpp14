#pragma once

#include "private/apigear_olink.hpp"

#include "olink/remoteregistry.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"

#include <set>

namespace Poco {
namespace Net {
class HTTPServerRequest;
}} //namespace Poco::Net

namespace ApiGear {
namespace ObjectLink {
class RemoteRegistry;
}} //Namespace ApiGear::ObjectLink

namespace ApiGear {
namespace PocoImpl {

class OLinkRemote;

class RequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    RequestHandlerFactory(ApiGear::ObjectLink::RemoteRegistry& registry);

    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);

    void addRemoteConnection(OLinkRemote* connection);

    void  removeRemoteConnection(OLinkRemote* connection);

    void close();
    ApiGear::ObjectLink::RemoteRegistry* getRegistry();
private:
    std::set<OLinkRemote*> m_remoteConnections;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};

}}

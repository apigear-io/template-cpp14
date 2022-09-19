#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPRequestHandler.h"

#include "olink/remoteregistry.h"
#include "private/olinkremote.h"
#include "private/olinkwebsockethandler.h"
#include "private/requesthandlerfactory.h"

#include <iostream>

namespace ApiGear {
namespace PocoImpl {

RequestHandlerFactory::RequestHandlerFactory(ApiGear::ObjectLink::RemoteRegistry& registry) : m_registry(&registry) {};

Poco::Net::HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request)
{
    std::cout << "Request from "
        << request.clientAddress().toString()
        << ": "
        << request.getMethod()
        << " "
        << request.getURI()
        << " "
        << request.getVersion() << std::endl;

    for (Poco::Net::HTTPServerRequest::ConstIterator it = request.begin(); it != request.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    /// TODO DOROTA handle somehow if we cannot upgrade
    if (request.find("Upgrade") != request.end() && Poco::icompare(request["Upgrade"], "websocket") == 0) {
        std::cout << "wss.newConnection()\n";
        OLinkWebsocketHandler* handler = new OLinkWebsocketHandler(this);
        return handler;
    }
}

void RequestHandlerFactory::addRemoteConnection(OLinkRemote* connection) {
    m_remoteConnections.insert(connection);
}

void  RequestHandlerFactory::removeRemoteConnection(OLinkRemote* connection) {
    m_remoteConnections.erase(connection);
    delete connection;
}

void RequestHandlerFactory::close()
{
    for (auto remoteConnection : m_remoteConnections){
        remoteConnection->close();
        delete remoteConnection;
    }
    m_remoteConnections.clear();
}

ApiGear::ObjectLink::RemoteRegistry* RequestHandlerFactory::getRegistry(){
    return m_registry;
}

}}
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPRequestHandler.h"

#include "private/olinkwebsockethandler.h"
#include "private/requesthandlerfactory.h"
#include "private/iconnectionstorage.h"

#include <iostream>

namespace ApiGear {
namespace PocoImpl {

RequestHandlerFactory::RequestHandlerFactory(IConnectionStorage& connectionStorage)
: m_connectionStorage(connectionStorage)
{};

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
        OLinkWebsocketHandler* handler = new OLinkWebsocketHandler(m_connectionStorage);
        return handler;
    }
}


}} //namespace ApiGear::PocoImpl

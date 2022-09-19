#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/WebSocket.h"

#include "private/olinkremote.h"
#include "private/olinkwebsockethandler.h"
#include "private/requesthandlerfactory.h"

namespace ApiGear {
namespace PocoImpl {

OLinkWebsocketHandler::OLinkWebsocketHandler(RequestHandlerFactory* factory)
    :m_factory(factory)
{}

void OLinkWebsocketHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
    m_factory->addRemoteConnection(new OLinkRemote(m_factory, new Poco::Net::WebSocket(request, response)));
}
}}
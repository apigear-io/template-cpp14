#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/WebSocket.h"

#include "private/olinkwebsockethandler.h"
#include "private/iconnectionstorage.h"


namespace ApiGear {
namespace PocoImpl {

OLinkWebsocketHandler::OLinkWebsocketHandler(IConnectionStorage& connectionStorage)
    : m_connectionStorage(connectionStorage)
{}
// TODO MAKE UNIQUE IF POSSIBLE
void OLinkWebsocketHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
    m_connectionStorage.addConnection(std::make_unique<Poco::Net::WebSocket>(request, response));
}
}}   //namespace ApiGear::PocoImpl

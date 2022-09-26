#pragma once

#include "private/iconnectionstorage.h"
#include <mutex>
#include <memory>
#include <vector>

namespace ApiGear
{

// Remote registry forward declaration.
namespace ObjectLink
{
class RemoteRegistry;
}

namespace PocoImpl
{

// OlinkRemote forward declaration
class OLinkRemote;

class ConnectionStorage : public IConnectionStorage
{
public:
	ConnectionStorage(ApiGear::ObjectLink::RemoteRegistry& registry);
	void closeConnections();

	void addConnection(std::unique_ptr<Poco::Net::WebSocket> connectionSocket);
	void notifyConnectionClosed();
private:
	ApiGear::ObjectLink::RemoteRegistry& m_registry;
	std::vector<std::shared_ptr<OLinkRemote>> m_connectionNodes;
	std::timed_mutex m_connectionsMutex;
};

}}   //namespace ApiGear::PocoImpl

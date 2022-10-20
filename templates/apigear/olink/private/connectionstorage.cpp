#include "connectionstorage.h"
#include "olinkremote.h"

#include "olink/remoteregistry.h"

#include <chrono>
#include <memory>
#include <vector>
#include <iostream>

namespace ApiGear {
namespace PocoImpl {


ConnectionStorage::ConnectionStorage(ApiGear::ObjectLink::RemoteRegistry& registry)
  :m_registry(registry)
{}

void ConnectionStorage::notifyConnectionClosed()
{
	std::vector<std::shared_ptr<OLinkRemote>> connectionNodesToRemove;
	std::unique_lock<std::mutex> lock(m_connectionsMutex);
	// Move closed connections to separate storage to first unlock the m_conectionNodes, and then
	// destroy items, which destructor may take some time to clean up connection and wait for tasks to be done.
	for (auto connection : m_connectionNodes)
	{
		if (connection->isClosed())
		{
			connectionNodesToRemove.push_back(connection);
		}
	}
	auto closedBegin = std::remove_if(m_connectionNodes.begin(),
											m_connectionNodes.end(),
											[](const auto& element){return element->isClosed(); });
	m_connectionNodes.erase(closedBegin, m_connectionNodes.end());
	lock.unlock();
}

void ConnectionStorage::addConnection(std::unique_ptr<Poco::Net::WebSocket> connectionSocket)
{
	auto newConnection = std::make_shared<OLinkRemote>(std::move(connectionSocket), *this, m_registry);
	std::unique_lock<std::mutex> lock(m_connectionsMutex);
	m_connectionNodes.push_back(newConnection);
	lock.unlock();
}

void ConnectionStorage::closeConnections()
{
	std::unique_lock<std::mutex> lock(m_connectionsMutex);
	m_connectionNodes.clear();

}


}}   //namespace ApiGear::PocoImpl

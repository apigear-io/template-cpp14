#pragma once

#include "private/connectionstorage.h"
#include "private/olinkremote.h"

#include "olink/remoteregistry.h"

#include <memory>
#include <vector>


namespace ApiGear {
namespace PocoImpl {


ConnectionStorage::ConnectionStorage(ApiGear::ObjectLink::RemoteRegistry& registry)
  :m_registry(registry)
{}

void ConnectionStorage::notifyConnectionClosed()
{
		m_connectionNodes.erase(std::remove_if(m_connectionNodes.begin(),
											   m_connectionNodes.end(),
											   [](const auto& element){return element->isMarkedForDeletion(); }),
								m_connectionNodes.end());
}

void ConnectionStorage::addConnection(std::unique_ptr<Poco::Net::WebSocket> connectionSocket)
{
	m_connectionNodes.push_back(std::make_shared<OLinkRemote>(std::move(connectionSocket), *this,  m_registry));
}

void ConnectionStorage::closeConnections()
{
	m_connectionNodes.clear();
}

}}   //namespace ApiGear::PocoImpl

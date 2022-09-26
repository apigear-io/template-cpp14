#pragma once

#include "private/connectionstorage.h"
#include "private/olinkremote.h"

#include "olink/remoteregistry.h"

#include <chrono>
#include <memory>
#include <vector>

namespace ApiGear {
namespace PocoImpl {


ConnectionStorage::ConnectionStorage(ApiGear::ObjectLink::RemoteRegistry& registry)
  :m_registry(registry)
{}

void ConnectionStorage::notifyConnectionClosed()
{
	std::unique_lock<std::timed_mutex> lock(m_connectionsMutex, std::defer_lock);
	if (m_connectionsMutex.try_lock_for(std::chrono::milliseconds(100))) {
		m_connectionNodes.erase(std::remove_if(m_connectionNodes.begin(),
												m_connectionNodes.end(),
												[](const auto& element){return element->isClosed(); }),
								m_connectionNodes.end());
	}
	m_connectionsMutex.unlock();
}

void ConnectionStorage::addConnection(std::unique_ptr<Poco::Net::WebSocket> connectionSocket)
{

	std::unique_lock<std::timed_mutex> lock(m_connectionsMutex, std::defer_lock);
	if (m_connectionsMutex.try_lock_for(std::chrono::milliseconds(1000))) {
		m_connectionNodes.push_back(std::make_shared<OLinkRemote>(std::move(connectionSocket), *this,  m_registry));
	}
	m_connectionsMutex.unlock();
}

void ConnectionStorage::closeConnections()
{
	std::unique_lock<std::timed_mutex> lock(m_connectionsMutex, std::defer_lock);
	m_connectionsMutex.try_lock_for(std::chrono::milliseconds(100));// try lock, to give time for ongoing actions if any
	m_connectionNodes.clear(); //close connections anyway
	m_connectionsMutex.unlock();
}


}}   //namespace ApiGear::PocoImpl

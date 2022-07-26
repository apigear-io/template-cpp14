/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "testbed1/generated/core/structarrayinterface.publisher.h"

#include <set>
#include <map>


namespace Test {
namespace Testbed1 {

/**
 * The implementation of a StructArrayInterfacePublisher.
 * Use this class to store clients of the StructArrayInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class StructArrayInterfacePublisherImpl : public IStructArrayInterfacePublisher
{
public:
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(IStructArrayInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IStructArrayInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropFloatChanged
    */
    long subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropFloatChanged
    */
    void unsubscribeFromPropFloatChanged(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropStringChanged
    */
    long subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropStringChanged
    */
    void unsubscribeFromPropStringChanged(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToSigBool
    */
    long subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToSigInt
    */
    long subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromSigInt
    */
    void unsubscribeFromSigInt(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToSigFloat
    */
    long subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromSigFloat
    */
    void unsubscribeFromSigFloat(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToSigString
    */
    long subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromSigString
    */
    void unsubscribeFromSigString(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::publishPropBoolChanged
    */
    void publishPropBoolChanged(const std::list<StructBool>& propBool) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishPropIntChanged
    */
    void publishPropIntChanged(const std::list<StructInt>& propInt) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishPropFloatChanged
    */
    void publishPropFloatChanged(const std::list<StructFloat>& propFloat) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishPropStringChanged
    */
    void publishPropStringChanged(const std::list<StructString>& propString) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishSigBool
    */
    void publishSigBool(const std::list<StructBool>& paramBool) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishSigInt
    */
    void publishSigInt(const std::list<StructInt>& paramInt) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishSigFloat
    */
    void publishSigFloat(const std::list<StructFloat>& paramFloat) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishSigString
    */
    void publishSigString(const std::list<StructString>& paramString) const override;
private:
    // Subscribers informed about any property change or singal emited in StructArrayInterface
    std::set<IStructArrayInterfaceSubscriber*> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the PropBool change.
    long PropBoolChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropBool change.
    std::map<long, StructArrayInterfacePropBoolPropertyCb> PropBoolCallbacks;
    // Next free unique identifier to subscribe for the PropInt change.
    long PropIntChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropInt change.
    std::map<long, StructArrayInterfacePropIntPropertyCb> PropIntCallbacks;
    // Next free unique identifier to subscribe for the PropFloat change.
    long PropFloatChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropFloat change.
    std::map<long, StructArrayInterfacePropFloatPropertyCb> PropFloatCallbacks;
    // Next free unique identifier to subscribe for the PropString change.
    long PropStringChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropString change.
    std::map<long, StructArrayInterfacePropStringPropertyCb> PropStringCallbacks;
    // Next free unique identifier to subscribe for the SigBool emission.
    long SigBoolSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigBool emission.
    std::map<long, StructArrayInterfaceSigBoolSignalCb> SigBoolCallbacks;
    // Next free unique identifier to subscribe for the SigInt emission.
    long SigIntSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigInt emission.
    std::map<long, StructArrayInterfaceSigIntSignalCb> SigIntCallbacks;
    // Next free unique identifier to subscribe for the SigFloat emission.
    long SigFloatSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigFloat emission.
    std::map<long, StructArrayInterfaceSigFloatSignalCb> SigFloatCallbacks;
    // Next free unique identifier to subscribe for the SigString emission.
    long SigStringSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigString emission.
    std::map<long, StructArrayInterfaceSigStringSignalCb> SigStringCallbacks;
};

} // namespace Testbed1
} // namespace Test

using namespace Test::Testbed1;

/**
 * Implementation StructArrayInterfacePublisherImpl
 */
void StructArrayInterfacePublisherImpl::subscribeToAllChanges(IStructArrayInterfaceSubscriber& subscriber)
{
    AllChangesSubscribers.insert(&subscriber);
}

void StructArrayInterfacePublisherImpl::unsubscribeFromAllChanges(IStructArrayInterfaceSubscriber& subscriber)
{
    AllChangesSubscribers.erase(&subscriber);
}

long StructArrayInterfacePublisherImpl::subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback)
{
    auto handleId = PropBoolChangedCallbackNextId++;
    PropBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherImpl::unsubscribeFromPropBoolChanged(long handleId)
{
    PropBoolCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherImpl::publishPropBoolChanged(const std::list<StructBool>& propBool) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnPropBoolChanged(propBool);
    }
    for(const auto& callbackEntry: PropBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propBool);
        }
    }
}

long StructArrayInterfacePublisherImpl::subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback)
{
    auto handleId = PropIntChangedCallbackNextId++;
    PropIntCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherImpl::unsubscribeFromPropIntChanged(long handleId)
{
    PropIntCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherImpl::publishPropIntChanged(const std::list<StructInt>& propInt) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnPropIntChanged(propInt);
    }
    for(const auto& callbackEntry: PropIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propInt);
        }
    }
}

long StructArrayInterfacePublisherImpl::subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback)
{
    auto handleId = PropFloatChangedCallbackNextId++;
    PropFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherImpl::unsubscribeFromPropFloatChanged(long handleId)
{
    PropFloatCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherImpl::publishPropFloatChanged(const std::list<StructFloat>& propFloat) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnPropFloatChanged(propFloat);
    }
    for(const auto& callbackEntry: PropFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propFloat);
        }
    }
}

long StructArrayInterfacePublisherImpl::subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback)
{
    auto handleId = PropStringChangedCallbackNextId++;
    PropStringCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherImpl::unsubscribeFromPropStringChanged(long handleId)
{
    PropStringCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherImpl::publishPropStringChanged(const std::list<StructString>& propString) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnPropStringChanged(propString);
    }
    for(const auto& callbackEntry: PropStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propString);
        }
    }
}

long StructArrayInterfacePublisherImpl::subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigBoolSignalCallbackNextId++;
    SigBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherImpl::unsubscribeFromSigBool(long handleId)
{
    SigBoolCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherImpl::publishSigBool(const std::list<StructBool>& paramBool) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnSigBool(paramBool);
    }
    for(const auto& callbackEntry: SigBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramBool);
        }
    }
}

long StructArrayInterfacePublisherImpl::subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigIntSignalCallbackNextId++;
    SigIntCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherImpl::unsubscribeFromSigInt(long handleId)
{
    SigIntCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherImpl::publishSigInt(const std::list<StructInt>& paramInt) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnSigInt(paramInt);
    }
    for(const auto& callbackEntry: SigIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramInt);
        }
    }
}

long StructArrayInterfacePublisherImpl::subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigFloatSignalCallbackNextId++;
    SigFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherImpl::unsubscribeFromSigFloat(long handleId)
{
    SigFloatCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherImpl::publishSigFloat(const std::list<StructFloat>& paramFloat) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnSigFloat(paramFloat);
    }
    for(const auto& callbackEntry: SigFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramFloat);
        }
    }
}

long StructArrayInterfacePublisherImpl::subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigStringSignalCallbackNextId++;
    SigStringCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherImpl::unsubscribeFromSigString(long handleId)
{
    SigStringCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherImpl::publishSigString(const std::list<StructString>& paramString) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnSigString(paramString);
    }
    for(const auto& callbackEntry: SigStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramString);
        }
    }
}

/**
 * Implementation StructArrayInterfacePublisher
 */
StructArrayInterfacePublisher::StructArrayInterfacePublisher()
    : m_impl(std::make_unique<StructArrayInterfacePublisherImpl>())
{
}

void StructArrayInterfacePublisher::subscribeToAllChanges(IStructArrayInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToAllChanges(subscriber);
}

void StructArrayInterfacePublisher::unsubscribeFromAllChanges(IStructArrayInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromAllChanges(subscriber);
}

long StructArrayInterfacePublisher::subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback)
{
    return m_impl->subscribeToPropBoolChanged(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_impl->unsubscribeFromPropBoolChanged(handleId);
}

void StructArrayInterfacePublisher::publishPropBoolChanged(const std::list<StructBool>& propBool) const
{
    m_impl->publishPropBoolChanged(propBool);
}

long StructArrayInterfacePublisher::subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback)
{
    return m_impl->subscribeToPropIntChanged(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_impl->unsubscribeFromPropIntChanged(handleId);
}

void StructArrayInterfacePublisher::publishPropIntChanged(const std::list<StructInt>& propInt) const
{
    m_impl->publishPropIntChanged(propInt);
}

long StructArrayInterfacePublisher::subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback)
{
    return m_impl->subscribeToPropFloatChanged(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_impl->unsubscribeFromPropFloatChanged(handleId);
}

void StructArrayInterfacePublisher::publishPropFloatChanged(const std::list<StructFloat>& propFloat) const
{
    m_impl->publishPropFloatChanged(propFloat);
}

long StructArrayInterfacePublisher::subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback)
{
    return m_impl->subscribeToPropStringChanged(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_impl->unsubscribeFromPropStringChanged(handleId);
}

void StructArrayInterfacePublisher::publishPropStringChanged(const std::list<StructString>& propString) const
{
    m_impl->publishPropStringChanged(propString);
}

long StructArrayInterfacePublisher::subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback)
{
    return m_impl->subscribeToSigBool(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_impl->unsubscribeFromSigBool(handleId);
}

void StructArrayInterfacePublisher::publishSigBool(const std::list<StructBool>& paramBool) const
{
    m_impl->publishSigBool(paramBool);
}

long StructArrayInterfacePublisher::subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback)
{
    return m_impl->subscribeToSigInt(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_impl->unsubscribeFromSigInt(handleId);
}

void StructArrayInterfacePublisher::publishSigInt(const std::list<StructInt>& paramInt) const
{
    m_impl->publishSigInt(paramInt);
}

long StructArrayInterfacePublisher::subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback)
{
    return m_impl->subscribeToSigFloat(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_impl->unsubscribeFromSigFloat(handleId);
}

void StructArrayInterfacePublisher::publishSigFloat(const std::list<StructFloat>& paramFloat) const
{
    m_impl->publishSigFloat(paramFloat);
}

long StructArrayInterfacePublisher::subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback)
{
    return m_impl->subscribeToSigString(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_impl->unsubscribeFromSigString(handleId);
}

void StructArrayInterfacePublisher::publishSigString(const std::list<StructString>& paramString) const
{
    m_impl->publishSigString(paramString);
}

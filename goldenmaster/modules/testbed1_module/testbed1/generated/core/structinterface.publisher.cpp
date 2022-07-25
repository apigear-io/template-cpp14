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
#include <set>
#include <map>
#include "testbed1/generated/core/structinterface.publisher.h"


namespace Test {
namespace Testbed1 {

/**
 * The implementation of a StructInterfacePublisher.
 * Use this class to store clients of the StructInterface and inform them about the change
 * on call of the  appropriate publish function.
 */
class StructInterfacePublisherImpl : public IStructInterfacePublisher
{
public:
    void subscribeToStructInterfaceChanges(IStructInterfaceSubscriber& subscriber) override;
    void unsubscribeFromStructInterfaceChanges(IStructInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(StructInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(StructInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(StructInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishPropBoolChanged(const StructBool& propBool) const override;
    void publishPropIntChanged(const StructInt& propInt) const override;
    void publishPropFloatChanged(const StructFloat& propFloat) const override;
    void publishPropStringChanged(const StructString& propString) const override;
    void publishSigBool(const StructBool& paramBool) const override;
    void publishSigInt(const StructInt& paramInt) const override;
    void publishSigFloat(const StructFloat& paramFloat) const override;
    void publishSigString(const StructString& paramString) const override;
private:
    // ISubscribers informed about any property change or singal emited in StructInterface
    std::set<IStructInterfaceSubscriber*> IStructInterfaceInterfaceSubscribers;
    // Next free unique identifier to subscribe for the PropBool change.
    long PropBoolChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropBool change.
    std::map<long, StructInterfacePropBoolPropertyCb> PropBoolCallbacks;
    // Next free unique identifier to subscribe for the PropInt change.
    long PropIntChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropInt change.
    std::map<long, StructInterfacePropIntPropertyCb> PropIntCallbacks;
    // Next free unique identifier to subscribe for the PropFloat change.
    long PropFloatChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropFloat change.
    std::map<long, StructInterfacePropFloatPropertyCb> PropFloatCallbacks;
    // Next free unique identifier to subscribe for the PropString change.
    long PropStringChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropString change.
    std::map<long, StructInterfacePropStringPropertyCb> PropStringCallbacks;
    // Next free unique identifier to subscribe for the SigBool emision.
    long SigBoolSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigBool emision.
    std::map<long, StructInterfaceSigBoolSignalCb> SigBoolCallbacks;
    // Next free unique identifier to subscribe for the SigInt emision.
    long SigIntSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigInt emision.
    std::map<long, StructInterfaceSigIntSignalCb> SigIntCallbacks;
    // Next free unique identifier to subscribe for the SigFloat emision.
    long SigFloatSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigFloat emision.
    std::map<long, StructInterfaceSigFloatSignalCb> SigFloatCallbacks;
    // Next free unique identifier to subscribe for the SigString emision.
    long SigStringSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigString emision.
    std::map<long, StructInterfaceSigStringSignalCb> SigStringCallbacks;
};

} // namespace Testbed1
} // namespace Test

using namespace Test::Testbed1;

/**
 * Implementation StructInterfacePublisherImpl
 */
void StructInterfacePublisherImpl::subscribeToStructInterfaceChanges(IStructInterfaceSubscriber& subscriber)
{
    IStructInterfaceInterfaceSubscribers.insert(&subscriber);
}

void StructInterfacePublisherImpl::unsubscribeFromStructInterfaceChanges(IStructInterfaceSubscriber& subscriber)
{
    IStructInterfaceInterfaceSubscribers.erase(&subscriber);
}

long StructInterfacePublisherImpl::subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback)
{
    auto handleId = PropBoolChangedCallbackNextId++;
    PropBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherImpl::unsubscribeFromPropBoolChanged(long handleId)
{
    PropBoolCallbacks.erase(handleId);
}

void StructInterfacePublisherImpl::publishPropBoolChanged(const StructBool& propBool) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
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

long StructInterfacePublisherImpl::subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback)
{
    auto handleId = PropIntChangedCallbackNextId++;
    PropIntCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherImpl::unsubscribeFromPropIntChanged(long handleId)
{
    PropIntCallbacks.erase(handleId);
}

void StructInterfacePublisherImpl::publishPropIntChanged(const StructInt& propInt) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
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

long StructInterfacePublisherImpl::subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback)
{
    auto handleId = PropFloatChangedCallbackNextId++;
    PropFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherImpl::unsubscribeFromPropFloatChanged(long handleId)
{
    PropFloatCallbacks.erase(handleId);
}

void StructInterfacePublisherImpl::publishPropFloatChanged(const StructFloat& propFloat) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
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

long StructInterfacePublisherImpl::subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback)
{
    auto handleId = PropStringChangedCallbackNextId++;
    PropStringCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherImpl::unsubscribeFromPropStringChanged(long handleId)
{
    PropStringCallbacks.erase(handleId);
}

void StructInterfacePublisherImpl::publishPropStringChanged(const StructString& propString) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
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

long StructInterfacePublisherImpl::subscribeToSigBool(StructInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigBoolSignalCallbackNextId++;
    SigBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherImpl::unsubscribeFromSigBool(long handleId)
{
    SigBoolCallbacks.erase(handleId);
}

void StructInterfacePublisherImpl::publishSigBool(const StructBool& paramBool) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
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

long StructInterfacePublisherImpl::subscribeToSigInt(StructInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigIntSignalCallbackNextId++;
    SigIntCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherImpl::unsubscribeFromSigInt(long handleId)
{
    SigIntCallbacks.erase(handleId);
}

void StructInterfacePublisherImpl::publishSigInt(const StructInt& paramInt) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
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

long StructInterfacePublisherImpl::subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigFloatSignalCallbackNextId++;
    SigFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherImpl::unsubscribeFromSigFloat(long handleId)
{
    SigFloatCallbacks.erase(handleId);
}

void StructInterfacePublisherImpl::publishSigFloat(const StructFloat& paramFloat) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
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

long StructInterfacePublisherImpl::subscribeToSigString(StructInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigStringSignalCallbackNextId++;
    SigStringCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherImpl::unsubscribeFromSigString(long handleId)
{
    SigStringCallbacks.erase(handleId);
}

void StructInterfacePublisherImpl::publishSigString(const StructString& paramString) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
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
 * Implementation StructInterfacePublisher
 */
StructInterfacePublisher::StructInterfacePublisher()
    : m_impl(std::make_unique<StructInterfacePublisherImpl>())
{
}

void StructInterfacePublisher::subscribeToStructInterfaceChanges(IStructInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToStructInterfaceChanges(subscriber);
}

void StructInterfacePublisher::unsubscribeFromStructInterfaceChanges(IStructInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromStructInterfaceChanges(subscriber);
}

long StructInterfacePublisher::subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback)
{
    return m_impl->subscribeToPropBoolChanged(callback);
}

void StructInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_impl->unsubscribeFromPropBoolChanged(handleId);
}

void StructInterfacePublisher::publishPropBoolChanged(const StructBool& propBool) const
{
    m_impl->publishPropBoolChanged(propBool);
}

long StructInterfacePublisher::subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback)
{
    return m_impl->subscribeToPropIntChanged(callback);
}

void StructInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_impl->unsubscribeFromPropIntChanged(handleId);
}

void StructInterfacePublisher::publishPropIntChanged(const StructInt& propInt) const
{
    m_impl->publishPropIntChanged(propInt);
}

long StructInterfacePublisher::subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback)
{
    return m_impl->subscribeToPropFloatChanged(callback);
}

void StructInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_impl->unsubscribeFromPropFloatChanged(handleId);
}

void StructInterfacePublisher::publishPropFloatChanged(const StructFloat& propFloat) const
{
    m_impl->publishPropFloatChanged(propFloat);
}

long StructInterfacePublisher::subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback)
{
    return m_impl->subscribeToPropStringChanged(callback);
}

void StructInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_impl->unsubscribeFromPropStringChanged(handleId);
}

void StructInterfacePublisher::publishPropStringChanged(const StructString& propString) const
{
    m_impl->publishPropStringChanged(propString);
}

long StructInterfacePublisher::subscribeToSigBool(StructInterfaceSigBoolSignalCb callback)
{
    return m_impl->subscribeToSigBool(callback);
}

void StructInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_impl->unsubscribeFromSigBool(handleId);
}

void StructInterfacePublisher::publishSigBool(const StructBool& paramBool) const
{
    m_impl->publishSigBool(paramBool);
}

long StructInterfacePublisher::subscribeToSigInt(StructInterfaceSigIntSignalCb callback)
{
    return m_impl->subscribeToSigInt(callback);
}

void StructInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_impl->unsubscribeFromSigInt(handleId);
}

void StructInterfacePublisher::publishSigInt(const StructInt& paramInt) const
{
    m_impl->publishSigInt(paramInt);
}

long StructInterfacePublisher::subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback)
{
    return m_impl->subscribeToSigFloat(callback);
}

void StructInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_impl->unsubscribeFromSigFloat(handleId);
}

void StructInterfacePublisher::publishSigFloat(const StructFloat& paramFloat) const
{
    m_impl->publishSigFloat(paramFloat);
}

long StructInterfacePublisher::subscribeToSigString(StructInterfaceSigStringSignalCb callback)
{
    return m_impl->subscribeToSigString(callback);
}

void StructInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_impl->unsubscribeFromSigString(handleId);
}

void StructInterfacePublisher::publishSigString(const StructString& paramString) const
{
    m_impl->publishSigString(paramString);
}

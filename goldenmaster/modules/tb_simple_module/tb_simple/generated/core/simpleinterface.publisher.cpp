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
#include "tb_simple/generated/core/simpleinterface.publisher.h"


namespace Test {
namespace TbSimple {

/**
 * The implementation of a SimpleInterfacePublisher.
 * Use this class to store clients of the SimpleInterface and inform them about the change
 * on call of the  appropriate publish function.
 */
class SimpleInterfacePublisherImpl : public ISimpleInterfacePublisher
{
public:
    void subscribeToSimpleInterfaceChanges(ISimpleInterfaceSubscriber& subscriber) override;
    void unsubscribeFromSimpleInterfaceChanges(ISimpleInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(SimpleInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishPropBoolChanged(bool propBool) const override;
    void publishPropIntChanged(int propInt) const override;
    void publishPropFloatChanged(float propFloat) const override;
    void publishPropStringChanged(const std::string& propString) const override;
    void publishSigBool(bool paramBool) const override;
    void publishSigInt(int paramInt) const override;
    void publishSigFloat(float paramFloat) const override;
    void publishSigString(const std::string& paramString) const override;
private:
    // ISubscribers informed about any property change or singal emited in SimpleInterface
    std::set<ISimpleInterfaceSubscriber*> ISimpleInterfaceInterfaceSubscribers;
    // Next free unique identifier to subscribe for the PropBool change.
    long PropBoolChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropBool change.
    std::map<long, SimpleInterfacePropBoolPropertyCb> PropBoolCallbacks;
    // Next free unique identifier to subscribe for the PropInt change.
    long PropIntChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropInt change.
    std::map<long, SimpleInterfacePropIntPropertyCb> PropIntCallbacks;
    // Next free unique identifier to subscribe for the PropFloat change.
    long PropFloatChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropFloat change.
    std::map<long, SimpleInterfacePropFloatPropertyCb> PropFloatCallbacks;
    // Next free unique identifier to subscribe for the PropString change.
    long PropStringChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropString change.
    std::map<long, SimpleInterfacePropStringPropertyCb> PropStringCallbacks;
    // Next free unique identifier to subscribe for the SigBool emision.
    long SigBoolSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigBool emision.
    std::map<long, SimpleInterfaceSigBoolSignalCb> SigBoolCallbacks;
    // Next free unique identifier to subscribe for the SigInt emision.
    long SigIntSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigInt emision.
    std::map<long, SimpleInterfaceSigIntSignalCb> SigIntCallbacks;
    // Next free unique identifier to subscribe for the SigFloat emision.
    long SigFloatSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigFloat emision.
    std::map<long, SimpleInterfaceSigFloatSignalCb> SigFloatCallbacks;
    // Next free unique identifier to subscribe for the SigString emision.
    long SigStringSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigString emision.
    std::map<long, SimpleInterfaceSigStringSignalCb> SigStringCallbacks;
};

} // namespace TbSimple
} // namespace Test

using namespace Test::TbSimple;

/**
 * Implementation SimpleInterfacePublisherImpl
 */
void SimpleInterfacePublisherImpl::subscribeToSimpleInterfaceChanges(ISimpleInterfaceSubscriber& subscriber)
{
    ISimpleInterfaceInterfaceSubscribers.insert(&subscriber);
}

void SimpleInterfacePublisherImpl::unsubscribeFromSimpleInterfaceChanges(ISimpleInterfaceSubscriber& subscriber)
{
    ISimpleInterfaceInterfaceSubscribers.erase(&subscriber);
}

long SimpleInterfacePublisherImpl::subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback)
{
    auto handleId = PropBoolChangedCallbackNextId++;
    PropBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherImpl::unsubscribeFromPropBoolChanged(long handleId)
{
    PropBoolCallbacks.erase(handleId);
}

void SimpleInterfacePublisherImpl::publishPropBoolChanged(bool propBool) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherImpl::subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback)
{
    auto handleId = PropIntChangedCallbackNextId++;
    PropIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherImpl::unsubscribeFromPropIntChanged(long handleId)
{
    PropIntCallbacks.erase(handleId);
}

void SimpleInterfacePublisherImpl::publishPropIntChanged(int propInt) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherImpl::subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback)
{
    auto handleId = PropFloatChangedCallbackNextId++;
    PropFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherImpl::unsubscribeFromPropFloatChanged(long handleId)
{
    PropFloatCallbacks.erase(handleId);
}

void SimpleInterfacePublisherImpl::publishPropFloatChanged(float propFloat) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherImpl::subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback)
{
    auto handleId = PropStringChangedCallbackNextId++;
    PropStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherImpl::unsubscribeFromPropStringChanged(long handleId)
{
    PropStringCallbacks.erase(handleId);
}

void SimpleInterfacePublisherImpl::publishPropStringChanged(const std::string& propString) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherImpl::subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigBoolSignalCallbackNextId++;
    SigBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherImpl::unsubscribeFromSigBool(long handleId)
{
    SigBoolCallbacks.erase(handleId);
}

void SimpleInterfacePublisherImpl::publishSigBool(bool paramBool) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherImpl::subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigIntSignalCallbackNextId++;
    SigIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherImpl::unsubscribeFromSigInt(long handleId)
{
    SigIntCallbacks.erase(handleId);
}

void SimpleInterfacePublisherImpl::publishSigInt(int paramInt) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherImpl::subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigFloatSignalCallbackNextId++;
    SigFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherImpl::unsubscribeFromSigFloat(long handleId)
{
    SigFloatCallbacks.erase(handleId);
}

void SimpleInterfacePublisherImpl::publishSigFloat(float paramFloat) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherImpl::subscribeToSigString(SimpleInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigStringSignalCallbackNextId++;
    SigStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherImpl::unsubscribeFromSigString(long handleId)
{
    SigStringCallbacks.erase(handleId);
}

void SimpleInterfacePublisherImpl::publishSigString(const std::string& paramString) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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
 * Implementation SimpleInterfacePublisher
 */
SimpleInterfacePublisher::SimpleInterfacePublisher()
    : m_impl(std::make_unique<SimpleInterfacePublisherImpl>())
{
}

void SimpleInterfacePublisher::subscribeToSimpleInterfaceChanges(ISimpleInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToSimpleInterfaceChanges(subscriber);
}

void SimpleInterfacePublisher::unsubscribeFromSimpleInterfaceChanges(ISimpleInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromSimpleInterfaceChanges(subscriber);
}

long SimpleInterfacePublisher::subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback)
{
    return m_impl->subscribeToPropBoolChanged(callback);
}

void SimpleInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_impl->unsubscribeFromPropBoolChanged(handleId);
}

void SimpleInterfacePublisher::publishPropBoolChanged(bool propBool) const
{
    m_impl->publishPropBoolChanged(propBool);
}

long SimpleInterfacePublisher::subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback)
{
    return m_impl->subscribeToPropIntChanged(callback);
}

void SimpleInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_impl->unsubscribeFromPropIntChanged(handleId);
}

void SimpleInterfacePublisher::publishPropIntChanged(int propInt) const
{
    m_impl->publishPropIntChanged(propInt);
}

long SimpleInterfacePublisher::subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback)
{
    return m_impl->subscribeToPropFloatChanged(callback);
}

void SimpleInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_impl->unsubscribeFromPropFloatChanged(handleId);
}

void SimpleInterfacePublisher::publishPropFloatChanged(float propFloat) const
{
    m_impl->publishPropFloatChanged(propFloat);
}

long SimpleInterfacePublisher::subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback)
{
    return m_impl->subscribeToPropStringChanged(callback);
}

void SimpleInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_impl->unsubscribeFromPropStringChanged(handleId);
}

void SimpleInterfacePublisher::publishPropStringChanged(const std::string& propString) const
{
    m_impl->publishPropStringChanged(propString);
}

long SimpleInterfacePublisher::subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback)
{
    return m_impl->subscribeToSigBool(callback);
}

void SimpleInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_impl->unsubscribeFromSigBool(handleId);
}

void SimpleInterfacePublisher::publishSigBool(bool paramBool) const
{
    m_impl->publishSigBool(paramBool);
}

long SimpleInterfacePublisher::subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback)
{
    return m_impl->subscribeToSigInt(callback);
}

void SimpleInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_impl->unsubscribeFromSigInt(handleId);
}

void SimpleInterfacePublisher::publishSigInt(int paramInt) const
{
    m_impl->publishSigInt(paramInt);
}

long SimpleInterfacePublisher::subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback)
{
    return m_impl->subscribeToSigFloat(callback);
}

void SimpleInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_impl->unsubscribeFromSigFloat(handleId);
}

void SimpleInterfacePublisher::publishSigFloat(float paramFloat) const
{
    m_impl->publishSigFloat(paramFloat);
}

long SimpleInterfacePublisher::subscribeToSigString(SimpleInterfaceSigStringSignalCb callback)
{
    return m_impl->subscribeToSigString(callback);
}

void SimpleInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_impl->unsubscribeFromSigString(handleId);
}

void SimpleInterfacePublisher::publishSigString(const std::string& paramString) const
{
    m_impl->publishSigString(paramString);
}

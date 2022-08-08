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
#include "tb_simple/generated/core/simplearrayinterface.publisher.h"

#include <vector>
#include <map>
#include <functional>
#include <algorithm>


namespace Test {
namespace TbSimple {

/**
 * The implementation of a SimpleArrayInterfacePublisher.
 * Use this class to store clients of the SimpleArrayInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class SimpleArrayInterfacePublisherImpl : public ISimpleArrayInterfacePublisher
{
public:
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISimpleArrayInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISimpleArrayInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropFloatChanged
    */
    long subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropFloatChanged
    */
    void unsubscribeFromPropFloatChanged(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropStringChanged
    */
    long subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropStringChanged
    */
    void unsubscribeFromPropStringChanged(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToSigBool
    */
    long subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToSigInt
    */
    long subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromSigInt
    */
    void unsubscribeFromSigInt(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToSigFloat
    */
    long subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromSigFloat
    */
    void unsubscribeFromSigFloat(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToSigString
    */
    long subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromSigString
    */
    void unsubscribeFromSigString(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishPropBoolChanged
    */
    void publishPropBoolChanged(const std::list<bool>& propBool) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishPropIntChanged
    */
    void publishPropIntChanged(const std::list<int>& propInt) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishPropFloatChanged
    */
    void publishPropFloatChanged(const std::list<float>& propFloat) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishPropStringChanged
    */
    void publishPropStringChanged(const std::list<std::string>& propString) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishSigBool
    */
    void publishSigBool(const std::list<bool>& paramBool) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishSigInt
    */
    void publishSigInt(const std::list<int>& paramInt) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishSigFloat
    */
    void publishSigFloat(const std::list<float>& paramFloat) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishSigString
    */
    void publishSigString(const std::list<std::string>& paramString) const override;
private:
    // Subscribers informed about any property change or singal emited in SimpleArrayInterface
    std::vector<std::reference_wrapper<ISimpleArrayInterfaceSubscriber>> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the PropBool change.
    long PropBoolChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropBool change.
    std::map<long, SimpleArrayInterfacePropBoolPropertyCb> PropBoolCallbacks;
    // Next free unique identifier to subscribe for the PropInt change.
    long PropIntChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropInt change.
    std::map<long, SimpleArrayInterfacePropIntPropertyCb> PropIntCallbacks;
    // Next free unique identifier to subscribe for the PropFloat change.
    long PropFloatChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropFloat change.
    std::map<long, SimpleArrayInterfacePropFloatPropertyCb> PropFloatCallbacks;
    // Next free unique identifier to subscribe for the PropString change.
    long PropStringChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropString change.
    std::map<long, SimpleArrayInterfacePropStringPropertyCb> PropStringCallbacks;
    // Next free unique identifier to subscribe for the SigBool emission.
    long SigBoolSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigBool emission.
    std::map<long, SimpleArrayInterfaceSigBoolSignalCb> SigBoolCallbacks;
    // Next free unique identifier to subscribe for the SigInt emission.
    long SigIntSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigInt emission.
    std::map<long, SimpleArrayInterfaceSigIntSignalCb> SigIntCallbacks;
    // Next free unique identifier to subscribe for the SigFloat emission.
    long SigFloatSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigFloat emission.
    std::map<long, SimpleArrayInterfaceSigFloatSignalCb> SigFloatCallbacks;
    // Next free unique identifier to subscribe for the SigString emission.
    long SigStringSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigString emission.
    std::map<long, SimpleArrayInterfaceSigStringSignalCb> SigStringCallbacks;
};

} // namespace TbSimple
} // namespace Test

using namespace Test::TbSimple;

/**
 * Implementation SimpleArrayInterfacePublisherImpl
 */
void SimpleArrayInterfacePublisherImpl::subscribeToAllChanges(ISimpleArrayInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == AllChangesSubscribers.end())
    {
        AllChangesSubscribers.push_back(std::reference_wrapper<ISimpleArrayInterfaceSubscriber>(subscriber));
    }
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromAllChanges(ISimpleArrayInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != AllChangesSubscribers.end())
    {
        AllChangesSubscribers.erase(found);
    }
}

long SimpleArrayInterfacePublisherImpl::subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback)
{
    auto handleId = PropBoolChangedCallbackNextId++;
    PropBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromPropBoolChanged(long handleId)
{
    PropBoolCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherImpl::publishPropBoolChanged(const std::list<bool>& propBool) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnPropBoolChanged(propBool);
    }
    for(const auto& callbackEntry: PropBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propBool);
        }
    }
}

long SimpleArrayInterfacePublisherImpl::subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback)
{
    auto handleId = PropIntChangedCallbackNextId++;
    PropIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromPropIntChanged(long handleId)
{
    PropIntCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherImpl::publishPropIntChanged(const std::list<int>& propInt) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnPropIntChanged(propInt);
    }
    for(const auto& callbackEntry: PropIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propInt);
        }
    }
}

long SimpleArrayInterfacePublisherImpl::subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback)
{
    auto handleId = PropFloatChangedCallbackNextId++;
    PropFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromPropFloatChanged(long handleId)
{
    PropFloatCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherImpl::publishPropFloatChanged(const std::list<float>& propFloat) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnPropFloatChanged(propFloat);
    }
    for(const auto& callbackEntry: PropFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propFloat);
        }
    }
}

long SimpleArrayInterfacePublisherImpl::subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback)
{
    auto handleId = PropStringChangedCallbackNextId++;
    PropStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromPropStringChanged(long handleId)
{
    PropStringCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherImpl::publishPropStringChanged(const std::list<std::string>& propString) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnPropStringChanged(propString);
    }
    for(const auto& callbackEntry: PropStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propString);
        }
    }
}

long SimpleArrayInterfacePublisherImpl::subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigBoolSignalCallbackNextId++;
    SigBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromSigBool(long handleId)
{
    SigBoolCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherImpl::publishSigBool(const std::list<bool>& paramBool) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnSigBool(paramBool);
    }
    for(const auto& callbackEntry: SigBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramBool);
        }
    }
}

long SimpleArrayInterfacePublisherImpl::subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigIntSignalCallbackNextId++;
    SigIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromSigInt(long handleId)
{
    SigIntCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherImpl::publishSigInt(const std::list<int>& paramInt) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnSigInt(paramInt);
    }
    for(const auto& callbackEntry: SigIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramInt);
        }
    }
}

long SimpleArrayInterfacePublisherImpl::subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigFloatSignalCallbackNextId++;
    SigFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromSigFloat(long handleId)
{
    SigFloatCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherImpl::publishSigFloat(const std::list<float>& paramFloat) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnSigFloat(paramFloat);
    }
    for(const auto& callbackEntry: SigFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramFloat);
        }
    }
}

long SimpleArrayInterfacePublisherImpl::subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = SigStringSignalCallbackNextId++;
    SigStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherImpl::unsubscribeFromSigString(long handleId)
{
    SigStringCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherImpl::publishSigString(const std::list<std::string>& paramString) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnSigString(paramString);
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
 * Implementation SimpleArrayInterfacePublisher
 */
SimpleArrayInterfacePublisher::SimpleArrayInterfacePublisher()
    : m_impl(std::make_unique<SimpleArrayInterfacePublisherImpl>())
{
}

void SimpleArrayInterfacePublisher::subscribeToAllChanges(ISimpleArrayInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToAllChanges(subscriber);
}

void SimpleArrayInterfacePublisher::unsubscribeFromAllChanges(ISimpleArrayInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromAllChanges(subscriber);
}

long SimpleArrayInterfacePublisher::subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback)
{
    return m_impl->subscribeToPropBoolChanged(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_impl->unsubscribeFromPropBoolChanged(handleId);
}

void SimpleArrayInterfacePublisher::publishPropBoolChanged(const std::list<bool>& propBool) const
{
    m_impl->publishPropBoolChanged(propBool);
}

long SimpleArrayInterfacePublisher::subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback)
{
    return m_impl->subscribeToPropIntChanged(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_impl->unsubscribeFromPropIntChanged(handleId);
}

void SimpleArrayInterfacePublisher::publishPropIntChanged(const std::list<int>& propInt) const
{
    m_impl->publishPropIntChanged(propInt);
}

long SimpleArrayInterfacePublisher::subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback)
{
    return m_impl->subscribeToPropFloatChanged(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_impl->unsubscribeFromPropFloatChanged(handleId);
}

void SimpleArrayInterfacePublisher::publishPropFloatChanged(const std::list<float>& propFloat) const
{
    m_impl->publishPropFloatChanged(propFloat);
}

long SimpleArrayInterfacePublisher::subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback)
{
    return m_impl->subscribeToPropStringChanged(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_impl->unsubscribeFromPropStringChanged(handleId);
}

void SimpleArrayInterfacePublisher::publishPropStringChanged(const std::list<std::string>& propString) const
{
    m_impl->publishPropStringChanged(propString);
}

long SimpleArrayInterfacePublisher::subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback)
{
    return m_impl->subscribeToSigBool(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_impl->unsubscribeFromSigBool(handleId);
}

void SimpleArrayInterfacePublisher::publishSigBool(const std::list<bool>& paramBool) const
{
    m_impl->publishSigBool(paramBool);
}

long SimpleArrayInterfacePublisher::subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback)
{
    return m_impl->subscribeToSigInt(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_impl->unsubscribeFromSigInt(handleId);
}

void SimpleArrayInterfacePublisher::publishSigInt(const std::list<int>& paramInt) const
{
    m_impl->publishSigInt(paramInt);
}

long SimpleArrayInterfacePublisher::subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback)
{
    return m_impl->subscribeToSigFloat(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_impl->unsubscribeFromSigFloat(handleId);
}

void SimpleArrayInterfacePublisher::publishSigFloat(const std::list<float>& paramFloat) const
{
    m_impl->publishSigFloat(paramFloat);
}

long SimpleArrayInterfacePublisher::subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback)
{
    return m_impl->subscribeToSigString(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_impl->unsubscribeFromSigString(handleId);
}

void SimpleArrayInterfacePublisher::publishSigString(const std::list<std::string>& paramString) const
{
    m_impl->publishSigString(paramString);
}

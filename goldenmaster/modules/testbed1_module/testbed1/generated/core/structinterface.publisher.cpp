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
#include "testbed1/generated/core/structinterface.publisher.h"
#include <algorithm>


namespace Test {
namespace Testbed1 {

/**
 * The implementation of a StructInterfacePublisher.
 * Use this class to store clients of the StructInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class StructInterfacePublisherImpl : public 
{
public:
    /**
    * Implementation of ::subscribeToAllChanges
    */
    void subscribeToAllChanges(IStructInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IStructInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of ::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of ::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of ::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of ::subscribeToPropFloatChanged
    */
    long subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback) override;
    /**
    * Implementation of ::subscribeToPropFloatChanged
    */
    void unsubscribeFromPropFloatChanged(long handleId) override;

    /**
    * Implementation of ::subscribeToPropStringChanged
    */
    long subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback) override;
    /**
    * Implementation of ::subscribeToPropStringChanged
    */
    void unsubscribeFromPropStringChanged(long handleId) override;

    /**
    * Implementation of ::subscribeToSigBool
    */
    long subscribeToSigBool(StructInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of ::subscribeToSigInt
    */
    long subscribeToSigInt(StructInterfaceSigIntSignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSigInt
    */
    void unsubscribeFromSigInt(long handleId) override;

    /**
    * Implementation of ::subscribeToSigFloat
    */
    long subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSigFloat
    */
    void unsubscribeFromSigFloat(long handleId) override;

    /**
    * Implementation of ::subscribeToSigString
    */
    long subscribeToSigString(StructInterfaceSigStringSignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSigString
    */
    void unsubscribeFromSigString(long handleId) override;

    /**
    * Implementation of ::publishPropBoolChanged
    */
    void publishPropBoolChanged(const StructBool& propBool) const override;
    /**
    * Implementation of ::publishPropIntChanged
    */
    void publishPropIntChanged(const StructInt& propInt) const override;
    /**
    * Implementation of ::publishPropFloatChanged
    */
    void publishPropFloatChanged(const StructFloat& propFloat) const override;
    /**
    * Implementation of ::publishPropStringChanged
    */
    void publishPropStringChanged(const StructString& propString) const override;
    /**
    * Implementation of ::publishSigBool
    */
    void publishSigBool(const StructBool& paramBool) const override;
    /**
    * Implementation of ::publishSigInt
    */
    void publishSigInt(const StructInt& paramInt) const override;
    /**
    * Implementation of ::publishSigFloat
    */
    void publishSigFloat(const StructFloat& paramFloat) const override;
    /**
    * Implementation of ::publishSigString
    */
    void publishSigString(const StructString& paramString) const override;
private:
    // Subscribers informed about any property change or singal emited in StructInterface
    std::set<IStructInterfaceSubscriber*> AllChangesSubscribers;
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
    // Next free unique identifier to subscribe for the SigBool emission.
    long SigBoolSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigBool emission.
    std::map<long, StructInterfaceSigBoolSignalCb> SigBoolCallbacks;
    // Next free unique identifier to subscribe for the SigInt emission.
    long SigIntSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigInt emission.
    std::map<long, StructInterfaceSigIntSignalCb> SigIntCallbacks;
    // Next free unique identifier to subscribe for the SigFloat emission.
    long SigFloatSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigFloat emission.
    std::map<long, StructInterfaceSigFloatSignalCb> SigFloatCallbacks;
    // Next free unique identifier to subscribe for the SigString emission.
    long SigStringSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigString emission.
    std::map<long, StructInterfaceSigStringSignalCb> SigStringCallbacks;
};
>>>>>>> 6b08db3 (fixes after self review, description fixes, small alignement of code)


using namespace Test::Testbed1;

void StructInterfacePublisher::subscribeToAllChanges(IStructInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IStructInterfaceSubscriber>(subscriber));
    }
}

void StructInterfacePublisher::unsubscribeFromAllChanges(IStructInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long StructInterfacePublisher::subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback)
{
    auto handleId = m_propBoolChangedCallbackNextId++;
    m_propBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_propBoolCallbacks.erase(handleId);
}

void StructInterfacePublisher::publishPropBoolChanged(const StructBool& propBool) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onPropBoolChanged(propBool);
    }
    for(const auto& callbackEntry: m_propBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propBool);
        }
    }
}

long StructInterfacePublisher::subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback)
{
    auto handleId = m_propIntChangedCallbackNextId++;
    m_propIntCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_propIntCallbacks.erase(handleId);
}

void StructInterfacePublisher::publishPropIntChanged(const StructInt& propInt) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onPropIntChanged(propInt);
    }
    for(const auto& callbackEntry: m_propIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propInt);
        }
    }
}

long StructInterfacePublisher::subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback)
{
    auto handleId = m_propFloatChangedCallbackNextId++;
    m_propFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_propFloatCallbacks.erase(handleId);
}

void StructInterfacePublisher::publishPropFloatChanged(const StructFloat& propFloat) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onPropFloatChanged(propFloat);
    }
    for(const auto& callbackEntry: m_propFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propFloat);
        }
    }
}

long StructInterfacePublisher::subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback)
{
    auto handleId = m_propStringChangedCallbackNextId++;
    m_propStringCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_propStringCallbacks.erase(handleId);
}

void StructInterfacePublisher::publishPropStringChanged(const StructString& propString) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onPropStringChanged(propString);
    }
    for(const auto& callbackEntry: m_propStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propString);
        }
    }
}

long StructInterfacePublisher::subscribeToSigBool(StructInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigBoolSignalCallbackNextId++;
    m_sigBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_sigBoolCallbacks.erase(handleId);
}

void StructInterfacePublisher::publishSigBool(const StructBool& paramBool) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSigBool(paramBool);
    }
    for(const auto& callbackEntry: m_sigBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramBool);
        }
    }
}

long StructInterfacePublisher::subscribeToSigInt(StructInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigIntSignalCallbackNextId++;
    m_sigIntCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_sigIntCallbacks.erase(handleId);
}

void StructInterfacePublisher::publishSigInt(const StructInt& paramInt) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSigInt(paramInt);
    }
    for(const auto& callbackEntry: m_sigIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramInt);
        }
    }
}

long StructInterfacePublisher::subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigFloatSignalCallbackNextId++;
    m_sigFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_sigFloatCallbacks.erase(handleId);
}

void StructInterfacePublisher::publishSigFloat(const StructFloat& paramFloat) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSigFloat(paramFloat);
    }
    for(const auto& callbackEntry: m_sigFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramFloat);
        }
    }
}

long StructInterfacePublisher::subscribeToSigString(StructInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigStringSignalCallbackNextId++;
    m_sigStringCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_sigStringCallbacks.erase(handleId);
}

void StructInterfacePublisher::publishSigString(const StructString& paramString) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSigString(paramString);
    }
    for(const auto& callbackEntry: m_sigStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramString);
        }
    }
}


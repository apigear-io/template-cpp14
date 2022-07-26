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
#include "tb_simple/generated/core/simpleinterface.publisher.h"
#include <algorithm>


namespace Test {
namespace TbSimple {

/**
 * The implementation of a SimpleInterfacePublisher.
 * Use this class to store clients of the SimpleInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class SimpleInterfacePublisherImpl : public 
{
public:
    /**
    * Implementation of ::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISimpleInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISimpleInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of ::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of ::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of ::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of ::subscribeToPropFloatChanged
    */
    long subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback) override;
    /**
    * Implementation of ::subscribeToPropFloatChanged
    */
    void unsubscribeFromPropFloatChanged(long handleId) override;

    /**
    * Implementation of ::subscribeToPropStringChanged
    */
    long subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback) override;
    /**
    * Implementation of ::subscribeToPropStringChanged
    */
    void unsubscribeFromPropStringChanged(long handleId) override;

    /**
    * Implementation of ::subscribeToSigBool
    */
    long subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of ::subscribeToSigInt
    */
    long subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSigInt
    */
    void unsubscribeFromSigInt(long handleId) override;

    /**
    * Implementation of ::subscribeToSigFloat
    */
    long subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSigFloat
    */
    void unsubscribeFromSigFloat(long handleId) override;

    /**
    * Implementation of ::subscribeToSigString
    */
    long subscribeToSigString(SimpleInterfaceSigStringSignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSigString
    */
    void unsubscribeFromSigString(long handleId) override;

    /**
    * Implementation of ::publishPropBoolChanged
    */
    void publishPropBoolChanged(bool propBool) const override;
    /**
    * Implementation of ::publishPropIntChanged
    */
    void publishPropIntChanged(int propInt) const override;
    /**
    * Implementation of ::publishPropFloatChanged
    */
    void publishPropFloatChanged(float propFloat) const override;
    /**
    * Implementation of ::publishPropStringChanged
    */
    void publishPropStringChanged(const std::string& propString) const override;
    /**
    * Implementation of ::publishSigBool
    */
    void publishSigBool(bool paramBool) const override;
    /**
    * Implementation of ::publishSigInt
    */
    void publishSigInt(int paramInt) const override;
    /**
    * Implementation of ::publishSigFloat
    */
    void publishSigFloat(float paramFloat) const override;
    /**
    * Implementation of ::publishSigString
    */
    void publishSigString(const std::string& paramString) const override;
private:
    // Subscribers informed about any property change or singal emited in SimpleInterface
    std::set<ISimpleInterfaceSubscriber*> AllChangesSubscribers;
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
    // Next free unique identifier to subscribe for the SigBool emission.
    long SigBoolSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigBool emission.
    std::map<long, SimpleInterfaceSigBoolSignalCb> SigBoolCallbacks;
    // Next free unique identifier to subscribe for the SigInt emission.
    long SigIntSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigInt emission.
    std::map<long, SimpleInterfaceSigIntSignalCb> SigIntCallbacks;
    // Next free unique identifier to subscribe for the SigFloat emission.
    long SigFloatSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigFloat emission.
    std::map<long, SimpleInterfaceSigFloatSignalCb> SigFloatCallbacks;
    // Next free unique identifier to subscribe for the SigString emission.
    long SigStringSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigString emission.
    std::map<long, SimpleInterfaceSigStringSignalCb> SigStringCallbacks;
};
>>>>>>> 6b08db3 (fixes after self review, description fixes, small alignement of code)


using namespace Test::TbSimple;

void SimpleInterfacePublisher::subscribeToAllChanges(ISimpleInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<ISimpleInterfaceSubscriber>(subscriber));
    }
}

void SimpleInterfacePublisher::unsubscribeFromAllChanges(ISimpleInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long SimpleInterfacePublisher::subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback)
{
    auto handleId = m_propBoolChangedCallbackNextId++;
    m_propBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_propBoolCallbacks.erase(handleId);
}

void SimpleInterfacePublisher::publishPropBoolChanged(bool propBool) const
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

long SimpleInterfacePublisher::subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback)
{
    auto handleId = m_propIntChangedCallbackNextId++;
    m_propIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_propIntCallbacks.erase(handleId);
}

void SimpleInterfacePublisher::publishPropIntChanged(int propInt) const
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

long SimpleInterfacePublisher::subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback)
{
    auto handleId = m_propFloatChangedCallbackNextId++;
    m_propFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_propFloatCallbacks.erase(handleId);
}

void SimpleInterfacePublisher::publishPropFloatChanged(float propFloat) const
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

long SimpleInterfacePublisher::subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback)
{
    auto handleId = m_propStringChangedCallbackNextId++;
    m_propStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_propStringCallbacks.erase(handleId);
}

void SimpleInterfacePublisher::publishPropStringChanged(const std::string& propString) const
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

long SimpleInterfacePublisher::subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigBoolSignalCallbackNextId++;
    m_sigBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_sigBoolCallbacks.erase(handleId);
}

void SimpleInterfacePublisher::publishSigBool(bool paramBool) const
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

long SimpleInterfacePublisher::subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigIntSignalCallbackNextId++;
    m_sigIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_sigIntCallbacks.erase(handleId);
}

void SimpleInterfacePublisher::publishSigInt(int paramInt) const
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

long SimpleInterfacePublisher::subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigFloatSignalCallbackNextId++;
    m_sigFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_sigFloatCallbacks.erase(handleId);
}

void SimpleInterfacePublisher::publishSigFloat(float paramFloat) const
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

long SimpleInterfacePublisher::subscribeToSigString(SimpleInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigStringSignalCallbackNextId++;
    m_sigStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_sigStringCallbacks.erase(handleId);
}

void SimpleInterfacePublisher::publishSigString(const std::string& paramString) const
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


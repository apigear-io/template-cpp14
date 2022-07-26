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
#include "testbed2/generated/core/manyparaminterface.publisher.h"
#include <algorithm>


namespace Test {
namespace Testbed2 {

/**
 * The implementation of a ManyParamInterfacePublisher.
 * Use this class to store clients of the ManyParamInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class ManyParamInterfacePublisherImpl : public 
{
public:
    /**
    * Implementation of ::subscribeToAllChanges
    */
    void subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of ::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of ::subscribeToProp3Changed
    */
    long subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback) override;
    /**
    * Implementation of ::subscribeToProp3Changed
    */
    void unsubscribeFromProp3Changed(long handleId) override;

    /**
    * Implementation of ::subscribeToProp4Changed
    */
    long subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback) override;
    /**
    * Implementation of ::subscribeToProp4Changed
    */
    void unsubscribeFromProp4Changed(long handleId) override;

    /**
    * Implementation of ::subscribeToSig1
    */
    long subscribeToSig1(ManyParamInterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ::subscribeToSig2
    */
    long subscribeToSig2(ManyParamInterfaceSig2SignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of ::subscribeToSig3
    */
    long subscribeToSig3(ManyParamInterfaceSig3SignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSig3
    */
    void unsubscribeFromSig3(long handleId) override;

    /**
    * Implementation of ::subscribeToSig4
    */
    long subscribeToSig4(ManyParamInterfaceSig4SignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSig4
    */
    void unsubscribeFromSig4(long handleId) override;

    /**
    * Implementation of ::publishProp1Changed
    */
    void publishProp1Changed(int prop1) const override;
    /**
    * Implementation of ::publishProp2Changed
    */
    void publishProp2Changed(int prop2) const override;
    /**
    * Implementation of ::publishProp3Changed
    */
    void publishProp3Changed(int prop3) const override;
    /**
    * Implementation of ::publishProp4Changed
    */
    void publishProp4Changed(int prop4) const override;
    /**
    * Implementation of ::publishSig1
    */
    void publishSig1(int param1) const override;
    /**
    * Implementation of ::publishSig2
    */
    void publishSig2(int param1,int param2) const override;
    /**
    * Implementation of ::publishSig3
    */
    void publishSig3(int param1,int param2,int param3) const override;
    /**
    * Implementation of ::publishSig4
    */
    void publishSig4(int param1,int param2,int param3,int param4) const override;
private:
    // Subscribers informed about any property change or singal emited in ManyParamInterface
    std::set<IManyParamInterfaceSubscriber*> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long Prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, ManyParamInterfaceProp1PropertyCb> Prop1Callbacks;
    // Next free unique identifier to subscribe for the Prop2 change.
    long Prop2ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop2 change.
    std::map<long, ManyParamInterfaceProp2PropertyCb> Prop2Callbacks;
    // Next free unique identifier to subscribe for the Prop3 change.
    long Prop3ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop3 change.
    std::map<long, ManyParamInterfaceProp3PropertyCb> Prop3Callbacks;
    // Next free unique identifier to subscribe for the Prop4 change.
    long Prop4ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop4 change.
    std::map<long, ManyParamInterfaceProp4PropertyCb> Prop4Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, ManyParamInterfaceSig1SignalCb> Sig1Callbacks;
    // Next free unique identifier to subscribe for the Sig2 emission.
    long Sig2SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, ManyParamInterfaceSig2SignalCb> Sig2Callbacks;
    // Next free unique identifier to subscribe for the Sig3 emission.
    long Sig3SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig3 emission.
    std::map<long, ManyParamInterfaceSig3SignalCb> Sig3Callbacks;
    // Next free unique identifier to subscribe for the Sig4 emission.
    long Sig4SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig4 emission.
    std::map<long, ManyParamInterfaceSig4SignalCb> Sig4Callbacks;
};
>>>>>>> 6b08db3 (fixes after self review, description fixes, small alignement of code)


using namespace Test::Testbed2;

void ManyParamInterfacePublisher::subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IManyParamInterfaceSubscriber>(subscriber));
    }
}

void ManyParamInterfacePublisher::unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long ManyParamInterfacePublisher::subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback)
{
    auto handleId = m_prop1ChangedCallbackNextId++;
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_prop1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp1Changed(int prop1) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp1Changed(prop1);
    }
    for(const auto& callbackEntry: m_prop1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop1);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback)
{
    auto handleId = m_prop2ChangedCallbackNextId++;
    m_prop2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_prop2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp2Changed(int prop2) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp2Changed(prop2);
    }
    for(const auto& callbackEntry: m_prop2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop2);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback)
{
    auto handleId = m_prop3ChangedCallbackNextId++;
    m_prop3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    m_prop3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp3Changed(int prop3) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp3Changed(prop3);
    }
    for(const auto& callbackEntry: m_prop3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop3);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback)
{
    auto handleId = m_prop4ChangedCallbackNextId++;
    m_prop4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp4Changed(long handleId)
{
    m_prop4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp4Changed(int prop4) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp4Changed(prop4);
    }
    for(const auto& callbackEntry: m_prop4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop4);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToSig1(ManyParamInterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig1SignalCallbackNextId++;
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_sig1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig1(int param1) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig1(param1);
    }
    for(const auto& callbackEntry: m_sig1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToSig2(ManyParamInterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig2SignalCallbackNextId++;
    m_sig2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_sig2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig2(int param1,int param2) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig2(param1,param2);
    }
    for(const auto& callbackEntry: m_sig2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToSig3(ManyParamInterfaceSig3SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig3SignalCallbackNextId++;
    m_sig3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig3(long handleId)
{
    m_sig3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig3(int param1,int param2,int param3) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig3(param1,param2,param3);
    }
    for(const auto& callbackEntry: m_sig3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2,param3);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToSig4(ManyParamInterfaceSig4SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig4SignalCallbackNextId++;
    m_sig4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig4(long handleId)
{
    m_sig4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig4(int param1,int param2,int param3,int param4) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig4(param1,param2,param3,param4);
    }
    for(const auto& callbackEntry: m_sig4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2,param3,param4);
        }
    }
}


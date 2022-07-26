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
#include "testbed2/generated/core/nestedstruct2interface.publisher.h"
#include <algorithm>


namespace Test {
namespace Testbed2 {

/**
 * The implementation of a NestedStruct2InterfacePublisher.
 * Use this class to store clients of the NestedStruct2Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class NestedStruct2InterfacePublisherImpl : public 
{
public:
    /**
    * Implementation of ::subscribeToAllChanges
    */
    void subscribeToAllChanges(INestedStruct2InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INestedStruct2InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of ::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of ::subscribeToSig1
    */
    long subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ::subscribeToSig2
    */
    long subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of ::publishProp1Changed
    */
    void publishProp1Changed(const NestedStruct1& prop1) const override;
    /**
    * Implementation of ::publishProp2Changed
    */
    void publishProp2Changed(const NestedStruct2& prop2) const override;
    /**
    * Implementation of ::publishSig1
    */
    void publishSig1(const NestedStruct1& param1) const override;
    /**
    * Implementation of ::publishSig2
    */
    void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const override;
private:
    // Subscribers informed about any property change or singal emited in NestedStruct2Interface
    std::set<INestedStruct2InterfaceSubscriber*> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long Prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, NestedStruct2InterfaceProp1PropertyCb> Prop1Callbacks;
    // Next free unique identifier to subscribe for the Prop2 change.
    long Prop2ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop2 change.
    std::map<long, NestedStruct2InterfaceProp2PropertyCb> Prop2Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, NestedStruct2InterfaceSig1SignalCb> Sig1Callbacks;
    // Next free unique identifier to subscribe for the Sig2 emission.
    long Sig2SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, NestedStruct2InterfaceSig2SignalCb> Sig2Callbacks;
};
>>>>>>> 6b08db3 (fixes after self review, description fixes, small alignement of code)


using namespace Test::Testbed2;

void NestedStruct2InterfacePublisher::subscribeToAllChanges(INestedStruct2InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<INestedStruct2InterfaceSubscriber>(subscriber));
    }
}

void NestedStruct2InterfacePublisher::unsubscribeFromAllChanges(INestedStruct2InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long NestedStruct2InterfacePublisher::subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback)
{
    auto handleId = m_prop1ChangedCallbackNextId++;
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_prop1Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisher::publishProp1Changed(const NestedStruct1& prop1) const
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

long NestedStruct2InterfacePublisher::subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback)
{
    auto handleId = m_prop2ChangedCallbackNextId++;
    m_prop2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_prop2Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisher::publishProp2Changed(const NestedStruct2& prop2) const
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

long NestedStruct2InterfacePublisher::subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig1SignalCallbackNextId++;
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_sig1Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisher::publishSig1(const NestedStruct1& param1) const
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

long NestedStruct2InterfacePublisher::subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig2SignalCallbackNextId++;
    m_sig2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_sig2Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisher::publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const
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


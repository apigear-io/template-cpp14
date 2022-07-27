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

#include <vector>
#include <map>
#include <functional>


namespace Test {
namespace Testbed2 {

/**
 * The implementation of a NestedStruct2InterfacePublisher.
 * Use this class to store clients of the NestedStruct2Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class NestedStruct2InterfacePublisherImpl : public INestedStruct2InterfacePublisher
{
public:
    /**
    * Implementation of INestedStruct2InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(INestedStruct2InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of INestedStruct2InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INestedStruct2InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of INestedStruct2InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of INestedStruct2InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of INestedStruct2InterfacePublisher::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of INestedStruct2InterfacePublisher::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of INestedStruct2InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of INestedStruct2InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of INestedStruct2InterfacePublisher::subscribeToSig2
    */
    long subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback) override;
    /**
    * Implementation of INestedStruct2InterfacePublisher::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of INestedStruct2InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const NestedStruct1& prop1) const override;
    /**
    * Implementation of INestedStruct2InterfacePublisher::publishProp2Changed
    */
    void publishProp2Changed(const NestedStruct2& prop2) const override;
    /**
    * Implementation of INestedStruct2InterfacePublisher::publishSig1
    */
    void publishSig1(const NestedStruct1& param1) const override;
    /**
    * Implementation of INestedStruct2InterfacePublisher::publishSig2
    */
    void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const override;
private:
    // Subscribers informed about any property change or singal emited in NestedStruct2Interface
    std::vector<std::reference_wrapper<INestedStruct2InterfaceSubscriber>> AllChangesSubscribers;
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

} // namespace Testbed2
} // namespace Test

using namespace Test::Testbed2;

/**
 * Implementation NestedStruct2InterfacePublisherImpl
 */
void NestedStruct2InterfacePublisherImpl::subscribeToAllChanges(INestedStruct2InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == AllChangesSubscribers.end())
    {
        AllChangesSubscribers.push_back(std::reference_wrapper<INestedStruct2InterfaceSubscriber>(subscriber));
    }
}

void NestedStruct2InterfacePublisherImpl::unsubscribeFromAllChanges(INestedStruct2InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != AllChangesSubscribers.end())
    {
        AllChangesSubscribers.erase(found);
    }
}

long NestedStruct2InterfacePublisherImpl::subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback)
{
    auto handleId = Prop1ChangedCallbackNextId++;
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisherImpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisherImpl::publishProp1Changed(const NestedStruct1& prop1) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnProp1Changed(prop1);
    }
    for(const auto& callbackEntry: Prop1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop1);
        }
    }
}

long NestedStruct2InterfacePublisherImpl::subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback)
{
    auto handleId = Prop2ChangedCallbackNextId++;
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisherImpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisherImpl::publishProp2Changed(const NestedStruct2& prop2) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnProp2Changed(prop2);
    }
    for(const auto& callbackEntry: Prop2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop2);
        }
    }
}

long NestedStruct2InterfacePublisherImpl::subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig1SignalCallbackNextId++;
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisherImpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisherImpl::publishSig1(const NestedStruct1& param1) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnSig1(param1);
    }
    for(const auto& callbackEntry: Sig1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1);
        }
    }
}

long NestedStruct2InterfacePublisherImpl::subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig2SignalCallbackNextId++;
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisherImpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisherImpl::publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnSig2(param1,param2);
    }
    for(const auto& callbackEntry: Sig2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2);
        }
    }
}

/**
 * Implementation NestedStruct2InterfacePublisher
 */
NestedStruct2InterfacePublisher::NestedStruct2InterfacePublisher()
    : m_impl(std::make_unique<NestedStruct2InterfacePublisherImpl>())
{
}

void NestedStruct2InterfacePublisher::subscribeToAllChanges(INestedStruct2InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToAllChanges(subscriber);
}

void NestedStruct2InterfacePublisher::unsubscribeFromAllChanges(INestedStruct2InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromAllChanges(subscriber);
}

long NestedStruct2InterfacePublisher::subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void NestedStruct2InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void NestedStruct2InterfacePublisher::publishProp1Changed(const NestedStruct1& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long NestedStruct2InterfacePublisher::subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void NestedStruct2InterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void NestedStruct2InterfacePublisher::publishProp2Changed(const NestedStruct2& prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long NestedStruct2InterfacePublisher::subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void NestedStruct2InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void NestedStruct2InterfacePublisher::publishSig1(const NestedStruct1& param1) const
{
    m_impl->publishSig1(param1);
}

long NestedStruct2InterfacePublisher::subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void NestedStruct2InterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void NestedStruct2InterfacePublisher::publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const
{
    m_impl->publishSig2(param1,param2);
}

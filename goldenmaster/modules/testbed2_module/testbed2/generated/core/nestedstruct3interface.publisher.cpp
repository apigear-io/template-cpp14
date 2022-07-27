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
#include "testbed2/generated/core/nestedstruct3interface.publisher.h"

#include <vector>
#include <map>
#include <functional>


namespace Test {
namespace Testbed2 {

/**
 * The implementation of a NestedStruct3InterfacePublisher.
 * Use this class to store clients of the NestedStruct3Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class NestedStruct3InterfacePublisherImpl : public INestedStruct3InterfacePublisher
{
public:
    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(INestedStruct3InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INestedStruct3InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(NestedStruct3InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(NestedStruct3InterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp3Changed
    */
    long subscribeToProp3Changed(NestedStruct3InterfaceProp3PropertyCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp3Changed
    */
    void unsubscribeFromProp3Changed(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(NestedStruct3InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToSig2
    */
    long subscribeToSig2(NestedStruct3InterfaceSig2SignalCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToSig3
    */
    long subscribeToSig3(NestedStruct3InterfaceSig3SignalCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::unsubscribeFromSig3
    */
    void unsubscribeFromSig3(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const NestedStruct1& prop1) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishProp2Changed
    */
    void publishProp2Changed(const NestedStruct2& prop2) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishProp3Changed
    */
    void publishProp3Changed(const NestedStruct3& prop3) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishSig1
    */
    void publishSig1(const NestedStruct1& param1) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishSig2
    */
    void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishSig3
    */
    void publishSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) const override;
private:
    // Subscribers informed about any property change or singal emited in NestedStruct3Interface
    std::vector<std::reference_wrapper<INestedStruct3InterfaceSubscriber>> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long Prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, NestedStruct3InterfaceProp1PropertyCb> Prop1Callbacks;
    // Next free unique identifier to subscribe for the Prop2 change.
    long Prop2ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop2 change.
    std::map<long, NestedStruct3InterfaceProp2PropertyCb> Prop2Callbacks;
    // Next free unique identifier to subscribe for the Prop3 change.
    long Prop3ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop3 change.
    std::map<long, NestedStruct3InterfaceProp3PropertyCb> Prop3Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, NestedStruct3InterfaceSig1SignalCb> Sig1Callbacks;
    // Next free unique identifier to subscribe for the Sig2 emission.
    long Sig2SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, NestedStruct3InterfaceSig2SignalCb> Sig2Callbacks;
    // Next free unique identifier to subscribe for the Sig3 emission.
    long Sig3SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig3 emission.
    std::map<long, NestedStruct3InterfaceSig3SignalCb> Sig3Callbacks;
};

} // namespace Testbed2
} // namespace Test

using namespace Test::Testbed2;

/**
 * Implementation NestedStruct3InterfacePublisherImpl
 */
void NestedStruct3InterfacePublisherImpl::subscribeToAllChanges(INestedStruct3InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == AllChangesSubscribers.end())
    {
        AllChangesSubscribers.push_back(std::reference_wrapper<INestedStruct3InterfaceSubscriber>(subscriber));
    }
}

void NestedStruct3InterfacePublisherImpl::unsubscribeFromAllChanges(INestedStruct3InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != AllChangesSubscribers.end())
    {
        AllChangesSubscribers.erase(found);
    }
}

long NestedStruct3InterfacePublisherImpl::subscribeToProp1Changed(NestedStruct3InterfaceProp1PropertyCb callback)
{
    auto handleId = Prop1ChangedCallbackNextId++;
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct3InterfacePublisherImpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void NestedStruct3InterfacePublisherImpl::publishProp1Changed(const NestedStruct1& prop1) const
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

long NestedStruct3InterfacePublisherImpl::subscribeToProp2Changed(NestedStruct3InterfaceProp2PropertyCb callback)
{
    auto handleId = Prop2ChangedCallbackNextId++;
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct3InterfacePublisherImpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void NestedStruct3InterfacePublisherImpl::publishProp2Changed(const NestedStruct2& prop2) const
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

long NestedStruct3InterfacePublisherImpl::subscribeToProp3Changed(NestedStruct3InterfaceProp3PropertyCb callback)
{
    auto handleId = Prop3ChangedCallbackNextId++;
    Prop3Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct3InterfacePublisherImpl::unsubscribeFromProp3Changed(long handleId)
{
    Prop3Callbacks.erase(handleId);
}

void NestedStruct3InterfacePublisherImpl::publishProp3Changed(const NestedStruct3& prop3) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnProp3Changed(prop3);
    }
    for(const auto& callbackEntry: Prop3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop3);
        }
    }
}

long NestedStruct3InterfacePublisherImpl::subscribeToSig1(NestedStruct3InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig1SignalCallbackNextId++;
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct3InterfacePublisherImpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void NestedStruct3InterfacePublisherImpl::publishSig1(const NestedStruct1& param1) const
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

long NestedStruct3InterfacePublisherImpl::subscribeToSig2(NestedStruct3InterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig2SignalCallbackNextId++;
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct3InterfacePublisherImpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void NestedStruct3InterfacePublisherImpl::publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const
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

long NestedStruct3InterfacePublisherImpl::subscribeToSig3(NestedStruct3InterfaceSig3SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig3SignalCallbackNextId++;
    Sig3Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct3InterfacePublisherImpl::unsubscribeFromSig3(long handleId)
{
    Sig3Callbacks.erase(handleId);
}

void NestedStruct3InterfacePublisherImpl::publishSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber.get().OnSig3(param1,param2,param3);
    }
    for(const auto& callbackEntry: Sig3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2,param3);
        }
    }
}

/**
 * Implementation NestedStruct3InterfacePublisher
 */
NestedStruct3InterfacePublisher::NestedStruct3InterfacePublisher()
    : m_impl(std::make_unique<NestedStruct3InterfacePublisherImpl>())
{
}

void NestedStruct3InterfacePublisher::subscribeToAllChanges(INestedStruct3InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToAllChanges(subscriber);
}

void NestedStruct3InterfacePublisher::unsubscribeFromAllChanges(INestedStruct3InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromAllChanges(subscriber);
}

long NestedStruct3InterfacePublisher::subscribeToProp1Changed(NestedStruct3InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void NestedStruct3InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void NestedStruct3InterfacePublisher::publishProp1Changed(const NestedStruct1& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long NestedStruct3InterfacePublisher::subscribeToProp2Changed(NestedStruct3InterfaceProp2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void NestedStruct3InterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void NestedStruct3InterfacePublisher::publishProp2Changed(const NestedStruct2& prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long NestedStruct3InterfacePublisher::subscribeToProp3Changed(NestedStruct3InterfaceProp3PropertyCb callback)
{
    return m_impl->subscribeToProp3Changed(callback);
}

void NestedStruct3InterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    m_impl->unsubscribeFromProp3Changed(handleId);
}

void NestedStruct3InterfacePublisher::publishProp3Changed(const NestedStruct3& prop3) const
{
    m_impl->publishProp3Changed(prop3);
}

long NestedStruct3InterfacePublisher::subscribeToSig1(NestedStruct3InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void NestedStruct3InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void NestedStruct3InterfacePublisher::publishSig1(const NestedStruct1& param1) const
{
    m_impl->publishSig1(param1);
}

long NestedStruct3InterfacePublisher::subscribeToSig2(NestedStruct3InterfaceSig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void NestedStruct3InterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void NestedStruct3InterfacePublisher::publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const
{
    m_impl->publishSig2(param1,param2);
}

long NestedStruct3InterfacePublisher::subscribeToSig3(NestedStruct3InterfaceSig3SignalCb callback)
{
    return m_impl->subscribeToSig3(callback);
}

void NestedStruct3InterfacePublisher::unsubscribeFromSig3(long handleId)
{
    m_impl->unsubscribeFromSig3(handleId);
}

void NestedStruct3InterfacePublisher::publishSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) const
{
    m_impl->publishSig3(param1,param2,param3);
}

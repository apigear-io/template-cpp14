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
#include "tb_same2/generated/core/samestruct2interface.publisher.h"

#include <vector>
#include <map>
#include <functional>
#include <algorithm>


namespace Test {
namespace TbSame2 {

/**
 * The implementation of a SameStruct2InterfacePublisher.
 * Use this class to store clients of the SameStruct2Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class SameStruct2InterfacePublisherImpl : public ISameStruct2InterfacePublisher
{
public:
    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISameStruct2InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISameStruct2InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(SameStruct2InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(SameStruct2InterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(SameStruct2InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToSig2
    */
    long subscribeToSig2(SameStruct2InterfaceSig2SignalCb callback) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const Struct2& prop1) const override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::publishProp2Changed
    */
    void publishProp2Changed(const Struct2& prop2) const override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::publishSig1
    */
    void publishSig1(const Struct1& param1) const override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::publishSig2
    */
    void publishSig2(const Struct1& param1,const Struct2& param2) const override;
private:
    // Subscribers informed about any property change or singal emited in SameStruct2Interface
    std::vector<std::reference_wrapper<ISameStruct2InterfaceSubscriber>> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long Prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameStruct2InterfaceProp1PropertyCb> Prop1Callbacks;
    // Next free unique identifier to subscribe for the Prop2 change.
    long Prop2ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop2 change.
    std::map<long, SameStruct2InterfaceProp2PropertyCb> Prop2Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameStruct2InterfaceSig1SignalCb> Sig1Callbacks;
    // Next free unique identifier to subscribe for the Sig2 emission.
    long Sig2SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, SameStruct2InterfaceSig2SignalCb> Sig2Callbacks;
};

} // namespace TbSame2
} // namespace Test

using namespace Test::TbSame2;

/**
 * Implementation SameStruct2InterfacePublisherImpl
 */
void SameStruct2InterfacePublisherImpl::subscribeToAllChanges(ISameStruct2InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == AllChangesSubscribers.end())
    {
        AllChangesSubscribers.push_back(std::reference_wrapper<ISameStruct2InterfaceSubscriber>(subscriber));
    }
}

void SameStruct2InterfacePublisherImpl::unsubscribeFromAllChanges(ISameStruct2InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != AllChangesSubscribers.end())
    {
        AllChangesSubscribers.erase(found);
    }
}

long SameStruct2InterfacePublisherImpl::subscribeToProp1Changed(SameStruct2InterfaceProp1PropertyCb callback)
{
    auto handleId = Prop1ChangedCallbackNextId++;
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void SameStruct2InterfacePublisherImpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void SameStruct2InterfacePublisherImpl::publishProp1Changed(const Struct2& prop1) const
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

long SameStruct2InterfacePublisherImpl::subscribeToProp2Changed(SameStruct2InterfaceProp2PropertyCb callback)
{
    auto handleId = Prop2ChangedCallbackNextId++;
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void SameStruct2InterfacePublisherImpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void SameStruct2InterfacePublisherImpl::publishProp2Changed(const Struct2& prop2) const
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

long SameStruct2InterfacePublisherImpl::subscribeToSig1(SameStruct2InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig1SignalCallbackNextId++;
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void SameStruct2InterfacePublisherImpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void SameStruct2InterfacePublisherImpl::publishSig1(const Struct1& param1) const
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

long SameStruct2InterfacePublisherImpl::subscribeToSig2(SameStruct2InterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig2SignalCallbackNextId++;
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void SameStruct2InterfacePublisherImpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void SameStruct2InterfacePublisherImpl::publishSig2(const Struct1& param1,const Struct2& param2) const
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
 * Implementation SameStruct2InterfacePublisher
 */
SameStruct2InterfacePublisher::SameStruct2InterfacePublisher()
    : m_impl(std::make_unique<SameStruct2InterfacePublisherImpl>())
{
}

void SameStruct2InterfacePublisher::subscribeToAllChanges(ISameStruct2InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToAllChanges(subscriber);
}

void SameStruct2InterfacePublisher::unsubscribeFromAllChanges(ISameStruct2InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromAllChanges(subscriber);
}

long SameStruct2InterfacePublisher::subscribeToProp1Changed(SameStruct2InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void SameStruct2InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void SameStruct2InterfacePublisher::publishProp1Changed(const Struct2& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long SameStruct2InterfacePublisher::subscribeToProp2Changed(SameStruct2InterfaceProp2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void SameStruct2InterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void SameStruct2InterfacePublisher::publishProp2Changed(const Struct2& prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long SameStruct2InterfacePublisher::subscribeToSig1(SameStruct2InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void SameStruct2InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void SameStruct2InterfacePublisher::publishSig1(const Struct1& param1) const
{
    m_impl->publishSig1(param1);
}

long SameStruct2InterfacePublisher::subscribeToSig2(SameStruct2InterfaceSig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void SameStruct2InterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void SameStruct2InterfacePublisher::publishSig2(const Struct1& param1,const Struct2& param2) const
{
    m_impl->publishSig2(param1,param2);
}

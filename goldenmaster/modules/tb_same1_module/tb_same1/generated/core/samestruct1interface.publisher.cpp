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
#include "tb_same1/generated/core/samestruct1interface.publisher.h"

#include <vector>
#include <map>
#include <functional>
#include <algorithm>


namespace Test {
namespace TbSame1 {

/**
 * The implementation of a SameStruct1InterfacePublisher.
 * Use this class to store clients of the SameStruct1Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class SameStruct1InterfacePublisherImpl : public ISameStruct1InterfacePublisher
{
public:
    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISameStruct1InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISameStruct1InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const Struct1& prop1) const override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::publishSig1
    */
    void publishSig1(const Struct1& param1) const override;
private:
    // Subscribers informed about any property change or singal emited in SameStruct1Interface
    std::vector<std::reference_wrapper<ISameStruct1InterfaceSubscriber>> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long Prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameStruct1InterfaceProp1PropertyCb> Prop1Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameStruct1InterfaceSig1SignalCb> Sig1Callbacks;
};

} // namespace TbSame1
} // namespace Test

using namespace Test::TbSame1;

/**
 * Implementation SameStruct1InterfacePublisherImpl
 */
void SameStruct1InterfacePublisherImpl::subscribeToAllChanges(ISameStruct1InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == AllChangesSubscribers.end())
    {
        AllChangesSubscribers.push_back(std::reference_wrapper<ISameStruct1InterfaceSubscriber>(subscriber));
    }
}

void SameStruct1InterfacePublisherImpl::unsubscribeFromAllChanges(ISameStruct1InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != AllChangesSubscribers.end())
    {
        AllChangesSubscribers.erase(found);
    }
}

long SameStruct1InterfacePublisherImpl::subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback)
{
    auto handleId = Prop1ChangedCallbackNextId++;
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void SameStruct1InterfacePublisherImpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void SameStruct1InterfacePublisherImpl::publishProp1Changed(const Struct1& prop1) const
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

long SameStruct1InterfacePublisherImpl::subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig1SignalCallbackNextId++;
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void SameStruct1InterfacePublisherImpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void SameStruct1InterfacePublisherImpl::publishSig1(const Struct1& param1) const
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

/**
 * Implementation SameStruct1InterfacePublisher
 */
SameStruct1InterfacePublisher::SameStruct1InterfacePublisher()
    : m_impl(std::make_unique<SameStruct1InterfacePublisherImpl>())
{
}

void SameStruct1InterfacePublisher::subscribeToAllChanges(ISameStruct1InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToAllChanges(subscriber);
}

void SameStruct1InterfacePublisher::unsubscribeFromAllChanges(ISameStruct1InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromAllChanges(subscriber);
}

long SameStruct1InterfacePublisher::subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void SameStruct1InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void SameStruct1InterfacePublisher::publishProp1Changed(const Struct1& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long SameStruct1InterfacePublisher::subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void SameStruct1InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void SameStruct1InterfacePublisher::publishSig1(const Struct1& param1) const
{
    m_impl->publishSig1(param1);
}

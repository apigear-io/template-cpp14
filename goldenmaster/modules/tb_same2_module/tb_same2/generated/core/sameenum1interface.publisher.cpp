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
#include "tb_same2/generated/core/sameenum1interface.publisher.h"

#include <vector>
#include <map>
#include <functional>


namespace Test {
namespace TbSame2 {

/**
 * The implementation of a SameEnum1InterfacePublisher.
 * Use this class to store clients of the SameEnum1Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class SameEnum1InterfacePublisherImpl : public ISameEnum1InterfacePublisher
{
public:
    /**
    * Implementation of ISameEnum1InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISameEnum1InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISameEnum1InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISameEnum1InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISameEnum1InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ISameEnum1InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ISameEnum1InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ISameEnum1InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ISameEnum1InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const Enum1Enum& prop1) const override;
    /**
    * Implementation of ISameEnum1InterfacePublisher::publishSig1
    */
    void publishSig1(const Enum1Enum& param1) const override;
private:
    // Subscribers informed about any property change or singal emited in SameEnum1Interface
    std::vector<std::reference_wrapper<ISameEnum1InterfaceSubscriber>> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long Prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameEnum1InterfaceProp1PropertyCb> Prop1Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameEnum1InterfaceSig1SignalCb> Sig1Callbacks;
};

} // namespace TbSame2
} // namespace Test

using namespace Test::TbSame2;

/**
 * Implementation SameEnum1InterfacePublisherImpl
 */
void SameEnum1InterfacePublisherImpl::subscribeToAllChanges(ISameEnum1InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == AllChangesSubscribers.end())
    {
        AllChangesSubscribers.push_back(std::reference_wrapper<ISameEnum1InterfaceSubscriber>(subscriber));
    }
}

void SameEnum1InterfacePublisherImpl::unsubscribeFromAllChanges(ISameEnum1InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(AllChangesSubscribers.begin(), AllChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != AllChangesSubscribers.end())
    {
        AllChangesSubscribers.erase(found);
    }
}

long SameEnum1InterfacePublisherImpl::subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback)
{
    auto handleId = Prop1ChangedCallbackNextId++;
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum1InterfacePublisherImpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void SameEnum1InterfacePublisherImpl::publishProp1Changed(const Enum1Enum& prop1) const
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

long SameEnum1InterfacePublisherImpl::subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig1SignalCallbackNextId++;
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum1InterfacePublisherImpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void SameEnum1InterfacePublisherImpl::publishSig1(const Enum1Enum& param1) const
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
 * Implementation SameEnum1InterfacePublisher
 */
SameEnum1InterfacePublisher::SameEnum1InterfacePublisher()
    : m_impl(std::make_unique<SameEnum1InterfacePublisherImpl>())
{
}

void SameEnum1InterfacePublisher::subscribeToAllChanges(ISameEnum1InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToAllChanges(subscriber);
}

void SameEnum1InterfacePublisher::unsubscribeFromAllChanges(ISameEnum1InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromAllChanges(subscriber);
}

long SameEnum1InterfacePublisher::subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void SameEnum1InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void SameEnum1InterfacePublisher::publishProp1Changed(const Enum1Enum& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long SameEnum1InterfacePublisher::subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void SameEnum1InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void SameEnum1InterfacePublisher::publishSig1(const Enum1Enum& param1) const
{
    m_impl->publishSig1(param1);
}

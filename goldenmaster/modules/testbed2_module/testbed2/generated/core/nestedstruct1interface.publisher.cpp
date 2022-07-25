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
#include <set>
#include <map>
#include "testbed2/generated/core/nestedstruct1interface.publisher.h"


namespace Test {
namespace Testbed2 {

/**
 * The implementation of a NestedStruct1InterfacePublisher.
 * Use this class to store clients of the NestedStruct1Interface and inform them about the change
 * on call of the  appropriate publish function.
 */
class NestedStruct1InterfacePublisherImpl : public INestedStruct1InterfacePublisher
{
public:
    void subscribeToNestedStruct1InterfaceChanges(INestedStruct1InterfaceSubscriber& subscriber) override;
    void unsubscribeFromNestedStruct1InterfaceChanges(INestedStruct1InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(NestedStruct1InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToSig1(NestedStruct1InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    void publishProp1Changed(const NestedStruct1& prop1) const override;
    void publishSig1(const NestedStruct1& param1) const override;
private:
    // ISubscribers informed about any property change or singal emited in NestedStruct1Interface
    std::set<INestedStruct1InterfaceSubscriber*> INestedStruct1InterfaceInterfaceSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long Prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, NestedStruct1InterfaceProp1PropertyCb> Prop1Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emision.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emision.
    std::map<long, NestedStruct1InterfaceSig1SignalCb> Sig1Callbacks;
};

} // namespace Testbed2
} // namespace Test

using namespace Test::Testbed2;

/**
 * Implementation NestedStruct1InterfacePublisherImpl
 */
void NestedStruct1InterfacePublisherImpl::subscribeToNestedStruct1InterfaceChanges(INestedStruct1InterfaceSubscriber& subscriber)
{
    INestedStruct1InterfaceInterfaceSubscribers.insert(&subscriber);
}

void NestedStruct1InterfacePublisherImpl::unsubscribeFromNestedStruct1InterfaceChanges(INestedStruct1InterfaceSubscriber& subscriber)
{
    INestedStruct1InterfaceInterfaceSubscribers.erase(&subscriber);
}

long NestedStruct1InterfacePublisherImpl::subscribeToProp1Changed(NestedStruct1InterfaceProp1PropertyCb callback)
{
    auto handleId = Prop1ChangedCallbackNextId++;
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct1InterfacePublisherImpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void NestedStruct1InterfacePublisherImpl::publishProp1Changed(const NestedStruct1& prop1) const
{
    for(const auto& Subscriber: INestedStruct1InterfaceInterfaceSubscribers)
    {
        Subscriber->OnProp1Changed(prop1);
    }
    for(const auto& callbackEntry: Prop1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop1);
        }
    }
}

long NestedStruct1InterfacePublisherImpl::subscribeToSig1(NestedStruct1InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig1SignalCallbackNextId++;
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct1InterfacePublisherImpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void NestedStruct1InterfacePublisherImpl::publishSig1(const NestedStruct1& param1) const
{
    for(const auto& Subscriber: INestedStruct1InterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig1(param1);
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
 * Implementation NestedStruct1InterfacePublisher
 */
NestedStruct1InterfacePublisher::NestedStruct1InterfacePublisher()
    : m_impl(std::make_unique<NestedStruct1InterfacePublisherImpl>())
{
}

void NestedStruct1InterfacePublisher::subscribeToNestedStruct1InterfaceChanges(INestedStruct1InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToNestedStruct1InterfaceChanges(subscriber);
}

void NestedStruct1InterfacePublisher::unsubscribeFromNestedStruct1InterfaceChanges(INestedStruct1InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromNestedStruct1InterfaceChanges(subscriber);
}

long NestedStruct1InterfacePublisher::subscribeToProp1Changed(NestedStruct1InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void NestedStruct1InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void NestedStruct1InterfacePublisher::publishProp1Changed(const NestedStruct1& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long NestedStruct1InterfacePublisher::subscribeToSig1(NestedStruct1InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void NestedStruct1InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void NestedStruct1InterfacePublisher::publishSig1(const NestedStruct1& param1) const
{
    m_impl->publishSig1(param1);
}

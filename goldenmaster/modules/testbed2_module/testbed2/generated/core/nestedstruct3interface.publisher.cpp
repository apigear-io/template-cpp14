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
#include "testbed2/generated/core/nestedstruct3interface.publisher.h"


namespace Test {
namespace Testbed2 {

/**
 * The implementation of a NestedStruct3InterfacePublisher.
 * Use this class to store clients of the NestedStruct3Interface and inform them about the change
 * on call of the  appropriate publish function.
 */
class NestedStruct3InterfacePublisherImpl : public INestedStruct3InterfacePublisher
{
public:
    void subscribeToNestedStruct3InterfaceChanges(INestedStruct3InterfaceSubscriber& subscriber) override;
    void unsubscribeFromNestedStruct3InterfaceChanges(INestedStruct3InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(NestedStruct3InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(NestedStruct3InterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToProp3Changed(NestedStruct3InterfaceProp3PropertyCb callback) override;
    void unsubscribeFromProp3Changed(long handleId) override;

    long subscribeToSig1(NestedStruct3InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(NestedStruct3InterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    long subscribeToSig3(NestedStruct3InterfaceSig3SignalCb callback) override;
    void unsubscribeFromSig3(long handleId) override;

    void publishProp1Changed(const NestedStruct1& prop1) const override;
    void publishProp2Changed(const NestedStruct2& prop2) const override;
    void publishProp3Changed(const NestedStruct3& prop3) const override;
    void publishSig1(const NestedStruct1& param1) const override;
    void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const override;
    void publishSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) const override;
private:
    // ISubscribers informed about any property change or singal emited in NestedStruct3Interface
    std::set<INestedStruct3InterfaceSubscriber*> INestedStruct3InterfaceInterfaceSubscribers;
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
    // Next free unique identifier to subscribe for the Sig1 emision.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emision.
    std::map<long, NestedStruct3InterfaceSig1SignalCb> Sig1Callbacks;
    // Next free unique identifier to subscribe for the Sig2 emision.
    long Sig2SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig2 emision.
    std::map<long, NestedStruct3InterfaceSig2SignalCb> Sig2Callbacks;
    // Next free unique identifier to subscribe for the Sig3 emision.
    long Sig3SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig3 emision.
    std::map<long, NestedStruct3InterfaceSig3SignalCb> Sig3Callbacks;
};

} // namespace Testbed2
} // namespace Test

using namespace Test::Testbed2;

/**
 * Implementation NestedStruct3InterfacePublisherImpl
 */
void NestedStruct3InterfacePublisherImpl::subscribeToNestedStruct3InterfaceChanges(INestedStruct3InterfaceSubscriber& subscriber)
{
    INestedStruct3InterfaceInterfaceSubscribers.insert(&subscriber);
}

void NestedStruct3InterfacePublisherImpl::unsubscribeFromNestedStruct3InterfaceChanges(INestedStruct3InterfaceSubscriber& subscriber)
{
    INestedStruct3InterfaceInterfaceSubscribers.erase(&subscriber);
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
    for(const auto& Subscriber: INestedStruct3InterfaceInterfaceSubscribers)
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
    for(const auto& Subscriber: INestedStruct3InterfaceInterfaceSubscribers)
    {
        Subscriber->OnProp2Changed(prop2);
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
    for(const auto& Subscriber: INestedStruct3InterfaceInterfaceSubscribers)
    {
        Subscriber->OnProp3Changed(prop3);
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
    for(const auto& Subscriber: INestedStruct3InterfaceInterfaceSubscribers)
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
    for(const auto& Subscriber: INestedStruct3InterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig2(param1,param2);
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
    for(const auto& Subscriber: INestedStruct3InterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig3(param1,param2,param3);
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

void NestedStruct3InterfacePublisher::subscribeToNestedStruct3InterfaceChanges(INestedStruct3InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToNestedStruct3InterfaceChanges(subscriber);
}

void NestedStruct3InterfacePublisher::unsubscribeFromNestedStruct3InterfaceChanges(INestedStruct3InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromNestedStruct3InterfaceChanges(subscriber);
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

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

#include <set>
#include <map>


namespace Test {
namespace Testbed2 {

/**
 * The implementation of a ManyParamInterfacePublisher.
 * Use this class to store clients of the ManyParamInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class ManyParamInterfacePublisherImpl : public IManyParamInterfacePublisher
{
public:
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp3Changed
    */
    long subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp3Changed
    */
    void unsubscribeFromProp3Changed(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp4Changed
    */
    long subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp4Changed
    */
    void unsubscribeFromProp4Changed(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(ManyParamInterfaceSig1SignalCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToSig2
    */
    long subscribeToSig2(ManyParamInterfaceSig2SignalCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToSig3
    */
    long subscribeToSig3(ManyParamInterfaceSig3SignalCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromSig3
    */
    void unsubscribeFromSig3(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToSig4
    */
    long subscribeToSig4(ManyParamInterfaceSig4SignalCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromSig4
    */
    void unsubscribeFromSig4(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(int prop1) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishProp2Changed
    */
    void publishProp2Changed(int prop2) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishProp3Changed
    */
    void publishProp3Changed(int prop3) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishProp4Changed
    */
    void publishProp4Changed(int prop4) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishSig1
    */
    void publishSig1(int param1) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishSig2
    */
    void publishSig2(int param1,int param2) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishSig3
    */
    void publishSig3(int param1,int param2,int param3) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishSig4
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

} // namespace Testbed2
} // namespace Test

using namespace Test::Testbed2;

/**
 * Implementation ManyParamInterfacePublisherImpl
 */
void ManyParamInterfacePublisherImpl::subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    AllChangesSubscribers.insert(&subscriber);
}

void ManyParamInterfacePublisherImpl::unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    AllChangesSubscribers.erase(&subscriber);
}

long ManyParamInterfacePublisherImpl::subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback)
{
    auto handleId = Prop1ChangedCallbackNextId++;
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherImpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherImpl::publishProp1Changed(int prop1) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
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

long ManyParamInterfacePublisherImpl::subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback)
{
    auto handleId = Prop2ChangedCallbackNextId++;
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherImpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherImpl::publishProp2Changed(int prop2) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
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

long ManyParamInterfacePublisherImpl::subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback)
{
    auto handleId = Prop3ChangedCallbackNextId++;
    Prop3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherImpl::unsubscribeFromProp3Changed(long handleId)
{
    Prop3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherImpl::publishProp3Changed(int prop3) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
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

long ManyParamInterfacePublisherImpl::subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback)
{
    auto handleId = Prop4ChangedCallbackNextId++;
    Prop4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherImpl::unsubscribeFromProp4Changed(long handleId)
{
    Prop4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherImpl::publishProp4Changed(int prop4) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnProp4Changed(prop4);
    }
    for(const auto& callbackEntry: Prop4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop4);
        }
    }
}

long ManyParamInterfacePublisherImpl::subscribeToSig1(ManyParamInterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig1SignalCallbackNextId++;
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherImpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherImpl::publishSig1(int param1) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
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

long ManyParamInterfacePublisherImpl::subscribeToSig2(ManyParamInterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig2SignalCallbackNextId++;
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherImpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherImpl::publishSig2(int param1,int param2) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
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

long ManyParamInterfacePublisherImpl::subscribeToSig3(ManyParamInterfaceSig3SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig3SignalCallbackNextId++;
    Sig3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherImpl::unsubscribeFromSig3(long handleId)
{
    Sig3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherImpl::publishSig3(int param1,int param2,int param3) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
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

long ManyParamInterfacePublisherImpl::subscribeToSig4(ManyParamInterfaceSig4SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = Sig4SignalCallbackNextId++;
    Sig4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherImpl::unsubscribeFromSig4(long handleId)
{
    Sig4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherImpl::publishSig4(int param1,int param2,int param3,int param4) const
{
    for(const auto& Subscriber: AllChangesSubscribers)
    {
        Subscriber->OnSig4(param1,param2,param3,param4);
    }
    for(const auto& callbackEntry: Sig4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2,param3,param4);
        }
    }
}

/**
 * Implementation ManyParamInterfacePublisher
 */
ManyParamInterfacePublisher::ManyParamInterfacePublisher()
    : m_impl(std::make_unique<ManyParamInterfacePublisherImpl>())
{
}

void ManyParamInterfacePublisher::subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToAllChanges(subscriber);
}

void ManyParamInterfacePublisher::unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromAllChanges(subscriber);
}

long ManyParamInterfacePublisher::subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void ManyParamInterfacePublisher::publishProp1Changed(int prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long ManyParamInterfacePublisher::subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void ManyParamInterfacePublisher::publishProp2Changed(int prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long ManyParamInterfacePublisher::subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback)
{
    return m_impl->subscribeToProp3Changed(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    m_impl->unsubscribeFromProp3Changed(handleId);
}

void ManyParamInterfacePublisher::publishProp3Changed(int prop3) const
{
    m_impl->publishProp3Changed(prop3);
}

long ManyParamInterfacePublisher::subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback)
{
    return m_impl->subscribeToProp4Changed(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromProp4Changed(long handleId)
{
    m_impl->unsubscribeFromProp4Changed(handleId);
}

void ManyParamInterfacePublisher::publishProp4Changed(int prop4) const
{
    m_impl->publishProp4Changed(prop4);
}

long ManyParamInterfacePublisher::subscribeToSig1(ManyParamInterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void ManyParamInterfacePublisher::publishSig1(int param1) const
{
    m_impl->publishSig1(param1);
}

long ManyParamInterfacePublisher::subscribeToSig2(ManyParamInterfaceSig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void ManyParamInterfacePublisher::publishSig2(int param1,int param2) const
{
    m_impl->publishSig2(param1,param2);
}

long ManyParamInterfacePublisher::subscribeToSig3(ManyParamInterfaceSig3SignalCb callback)
{
    return m_impl->subscribeToSig3(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromSig3(long handleId)
{
    m_impl->unsubscribeFromSig3(handleId);
}

void ManyParamInterfacePublisher::publishSig3(int param1,int param2,int param3) const
{
    m_impl->publishSig3(param1,param2,param3);
}

long ManyParamInterfacePublisher::subscribeToSig4(ManyParamInterfaceSig4SignalCb callback)
{
    return m_impl->subscribeToSig4(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromSig4(long handleId)
{
    m_impl->unsubscribeFromSig4(handleId);
}

void ManyParamInterfacePublisher::publishSig4(int param1,int param2,int param3,int param4) const
{
    m_impl->publishSig4(param1,param2,param3,param4);
}

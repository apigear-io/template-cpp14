

#include "testbed2/generated/core/nestedstruct2interface.publisher.h"
#include <algorithm>


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

void NestedStruct2InterfacePublisher::publishSig2(const NestedStruct1& param1, const NestedStruct2& param2) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig2(param1, param2);
    }
    for(const auto& callbackEntry: m_sig2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1, param2);
        }
    }
}


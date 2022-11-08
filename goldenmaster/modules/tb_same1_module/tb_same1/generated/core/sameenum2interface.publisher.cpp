

#include "tb_same1/generated/core/sameenum2interface.publisher.h"
#include <algorithm>


using namespace Goldenmaster::TbSame1;

void SameEnum2InterfacePublisher::subscribeToAllChanges(ISameEnum2InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<ISameEnum2InterfaceSubscriber>(subscriber));
    }
}

void SameEnum2InterfacePublisher::unsubscribeFromAllChanges(ISameEnum2InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long SameEnum2InterfacePublisher::subscribeToProp1Changed(SameEnum2InterfaceProp1PropertyCb callback)
{
    auto handleId = m_prop1ChangedCallbackNextId++;
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum2InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_prop1Callbacks.erase(handleId);
}

void SameEnum2InterfacePublisher::publishProp1Changed(Enum1Enum prop1) const
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

long SameEnum2InterfacePublisher::subscribeToProp2Changed(SameEnum2InterfaceProp2PropertyCb callback)
{
    auto handleId = m_prop2ChangedCallbackNextId++;
    m_prop2Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum2InterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_prop2Callbacks.erase(handleId);
}

void SameEnum2InterfacePublisher::publishProp2Changed(Enum2Enum prop2) const
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

long SameEnum2InterfacePublisher::subscribeToSig1(SameEnum2InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig1SignalCallbackNextId++;
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum2InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_sig1Callbacks.erase(handleId);
}

void SameEnum2InterfacePublisher::publishSig1(Enum1Enum param1) const
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

long SameEnum2InterfacePublisher::subscribeToSig2(SameEnum2InterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig2SignalCallbackNextId++;
    m_sig2Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum2InterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_sig2Callbacks.erase(handleId);
}

void SameEnum2InterfacePublisher::publishSig2(Enum1Enum param1, Enum2Enum param2) const
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


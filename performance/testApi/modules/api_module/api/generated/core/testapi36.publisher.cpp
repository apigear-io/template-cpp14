

#include "api/generated/core/testapi36.publisher.h"
#include <algorithm>


using namespace Test::Api;

void TestApi36Publisher::subscribeToAllChanges(ITestApi36Subscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<ITestApi36Subscriber>(subscriber));
    }
}

void TestApi36Publisher::unsubscribeFromAllChanges(ITestApi36Subscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long TestApi36Publisher::subscribeToPropIntChanged(TestApi36PropIntPropertyCb callback)
{
    auto handleId = m_propIntChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntCallbacksMutex);
    m_propIntCallbacks[handleId] = callback;
    return handleId;
}

void TestApi36Publisher::unsubscribeFromPropIntChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntCallbacksMutex);
    m_propIntCallbacks.erase(handleId);
}

void TestApi36Publisher::publishPropIntChanged(int propInt) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onPropIntChanged(propInt);
    }
    std::shared_lock<std::shared_timed_mutex> propIntCallbacksLock(m_propIntCallbacksMutex);
    const auto propIntCallbacks = m_propIntCallbacks;
    propIntCallbacksLock.unlock();
    for(const auto& callbackEntry: propIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propInt);
        }
    }
}

long TestApi36Publisher::subscribeToPropFloatChanged(TestApi36PropFloatPropertyCb callback)
{
    auto handleId = m_propFloatChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_propFloatCallbacksMutex);
    m_propFloatCallbacks[handleId] = callback;
    return handleId;
}

void TestApi36Publisher::unsubscribeFromPropFloatChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propFloatCallbacksMutex);
    m_propFloatCallbacks.erase(handleId);
}

void TestApi36Publisher::publishPropFloatChanged(float propFloat) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onPropFloatChanged(propFloat);
    }
    std::shared_lock<std::shared_timed_mutex> propFloatCallbacksLock(m_propFloatCallbacksMutex);
    const auto propFloatCallbacks = m_propFloatCallbacks;
    propFloatCallbacksLock.unlock();
    for(const auto& callbackEntry: propFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propFloat);
        }
    }
}

long TestApi36Publisher::subscribeToPropStringChanged(TestApi36PropStringPropertyCb callback)
{
    auto handleId = m_propStringChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_propStringCallbacksMutex);
    m_propStringCallbacks[handleId] = callback;
    return handleId;
}

void TestApi36Publisher::unsubscribeFromPropStringChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propStringCallbacksMutex);
    m_propStringCallbacks.erase(handleId);
}

void TestApi36Publisher::publishPropStringChanged(const std::string& propString) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onPropStringChanged(propString);
    }
    std::shared_lock<std::shared_timed_mutex> propStringCallbacksLock(m_propStringCallbacksMutex);
    const auto propStringCallbacks = m_propStringCallbacks;
    propStringCallbacksLock.unlock();
    for(const auto& callbackEntry: propStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propString);
        }
    }
}

long TestApi36Publisher::subscribeToSigInt(TestApi36SigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigIntSignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sigIntCallbacksMutex);
    m_sigIntCallbacks[handleId] = callback;
    return handleId;
}

void TestApi36Publisher::unsubscribeFromSigInt(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sigIntCallbacksMutex);
    m_sigIntCallbacks.erase(handleId);
}

void TestApi36Publisher::publishSigInt(int paramInt) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSigInt(paramInt);
    }
    std::shared_lock<std::shared_timed_mutex> sigIntCallbacksLock(m_sigIntCallbacksMutex);
    const auto sigIntCallbacks = m_sigIntCallbacks;
    sigIntCallbacksLock.unlock();
    for(const auto& callbackEntry: sigIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramInt);
        }
    }
}

long TestApi36Publisher::subscribeToSigFloat(TestApi36SigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigFloatSignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sigFloatCallbacksMutex);
    m_sigFloatCallbacks[handleId] = callback;
    return handleId;
}

void TestApi36Publisher::unsubscribeFromSigFloat(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sigFloatCallbacksMutex);
    m_sigFloatCallbacks.erase(handleId);
}

void TestApi36Publisher::publishSigFloat(float paramFloat) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSigFloat(paramFloat);
    }
    std::shared_lock<std::shared_timed_mutex> sigFloatCallbacksLock(m_sigFloatCallbacksMutex);
    const auto sigFloatCallbacks = m_sigFloatCallbacks;
    sigFloatCallbacksLock.unlock();
    for(const auto& callbackEntry: sigFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramFloat);
        }
    }
}

long TestApi36Publisher::subscribeToSigString(TestApi36SigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigStringSignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sigStringCallbacksMutex);
    m_sigStringCallbacks[handleId] = callback;
    return handleId;
}

void TestApi36Publisher::unsubscribeFromSigString(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sigStringCallbacksMutex);
    m_sigStringCallbacks.erase(handleId);
}

void TestApi36Publisher::publishSigString(const std::string& paramString) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSigString(paramString);
    }
    std::shared_lock<std::shared_timed_mutex> sigStringCallbacksLock(m_sigStringCallbacksMutex);
    const auto sigStringCallbacks = m_sigStringCallbacks;
    sigStringCallbacksLock.unlock();
    for(const auto& callbackEntry: sigStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramString);
        }
    }
}


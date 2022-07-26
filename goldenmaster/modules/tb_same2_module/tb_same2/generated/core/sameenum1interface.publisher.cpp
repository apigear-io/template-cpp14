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
#include <algorithm>


namespace Test {
namespace TbSame2 {

/**
 * The implementation of a SameEnum1InterfacePublisher.
 * Use this class to store clients of the SameEnum1Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class SameEnum1InterfacePublisherImpl : public 
{
public:
    /**
    * Implementation of ::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISameEnum1InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISameEnum1InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ::subscribeToSig1
    */
    long subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ::publishProp1Changed
    */
    void publishProp1Changed(const Enum1Enum& prop1) const override;
    /**
    * Implementation of ::publishSig1
    */
    void publishSig1(const Enum1Enum& param1) const override;
private:
    // Subscribers informed about any property change or singal emited in SameEnum1Interface
    std::set<ISameEnum1InterfaceSubscriber*> AllChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long Prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameEnum1InterfaceProp1PropertyCb> Prop1Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long Sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameEnum1InterfaceSig1SignalCb> Sig1Callbacks;
};
>>>>>>> 6b08db3 (fixes after self review, description fixes, small alignement of code)


using namespace Test::TbSame2;

void SameEnum1InterfacePublisher::subscribeToAllChanges(ISameEnum1InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<ISameEnum1InterfaceSubscriber>(subscriber));
    }
}

void SameEnum1InterfacePublisher::unsubscribeFromAllChanges(ISameEnum1InterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long SameEnum1InterfacePublisher::subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback)
{
    auto handleId = m_prop1ChangedCallbackNextId++;
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum1InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_prop1Callbacks.erase(handleId);
}

void SameEnum1InterfacePublisher::publishProp1Changed(const Enum1Enum& prop1) const
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

long SameEnum1InterfacePublisher::subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig1SignalCallbackNextId++;
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum1InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_sig1Callbacks.erase(handleId);
}

void SameEnum1InterfacePublisher::publishSig1(const Enum1Enum& param1) const
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


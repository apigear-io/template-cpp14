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
#pragma once

#include <future>
#include "tb_same1/generated/api/common.h"
#include "tb_same1/generated/api/datastructs.api.h"

namespace Test {
namespace TbSame1 {

class ISameEnum1InterfaceSubscriber;
class ISameEnum1InterfacePublisher;

/**
*
* ISameEnum1Interface provides an interface for
 *  - methods defined for your SameEnum1Interface 
 *  - proeperty setters and getters for defined properties
 * The ISameEnum1Interface also providess an interface to access a publisher ISameEnum1InterfacePublisher, a class used by ISameEnum1InterfaceSubscriber clients.
 * The implementation should notify the publisher ISameEnum1InterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also ISameEnum1InterfaceSubscriber, ISameEnum1InterfacePublisher
 * and the exmaple implementation SameEnum1Interface  or the
 */
class TEST_TB_SAME1_EXPORT ISameEnum1Interface
{
public:
    virtual ~ISameEnum1Interface() = default;


    virtual Enum1Enum func1(const Enum1Enum& param1) = 0;
    /**
    * Asynchronous version of func1(const Enum1Enum& param1)
    * @return Promise of type Enum1Enum which is set once the function has completed
    */
    virtual std::future<Enum1Enum> func1Async(const Enum1Enum& param1) = 0;

    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const Enum1Enum& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual const Enum1Enum& prop1() const = 0;

    /**
    * @return Publisher class ISameEnum1InterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual ISameEnum1InterfacePublisher& _getPublisher() const = 0;
};


/**
 * The ISameEnum1InterfaceSubscriber contains functions to allow informing about singals or property changes of the ISameEnum1Interface implementation.
 * The implementation for ISameEnum1Interface should provide mechanism for subscibtion of the ISameEnum1InterfaceSubscriber clients.
 * See ISameEnum1InterfacePublisher, which provides facititation for this purpose.
 * The implementation for ISameEnum1Interface should call the ISameEnum1InterfaceSubscriber interface functions on either singal emit or property change.
 * You can use ISameEnum1InterfaceSubscriber class to implement clients of the ISameEnum1Interface or the network adapter - see Olink Server and Client example.
 */
class TEST_TB_SAME1_EXPORT ISameEnum1InterfaceSubscriber
{
public:
    /**
    * Called by the ISameEnum1InterfacePublisher when the SameEnum1Interface emits sig1, if subscribed for the sig1.
    * @param param1 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig1(const Enum1Enum& param1) = 0;
    /**
    * Called by the ISameEnum1InterfacePublisher when prop1 value has changed if subscribed for the prop1 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const Enum1Enum& prop1) = 0;
};

/** Callback for changes of prop1 */
using SameEnum1InterfaceProp1PropertyCb = std::function<void(const Enum1Enum& prop1)>;
/** Callback for sig1 signal triggers */
using SameEnum1InterfaceSig1SignalCb = std::function<void(const Enum1Enum& param1)> ;


/**
 * The ISameEnum1InterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emission 
 * or a property change.
 * Implement this interface to keep track of clients of your ISameEnum1Interface implementation.
 * The publisher provides two independent methods of subscription
 *  - subscribing with a ITunerSubscriber objects - for all of the changes
 *  - subscribing any object for signle type of change property or a signal
 * The publish functions needs to be called by implementation of the ITuner on each state changed or signal emited
 * to notify all the subscribers about this change.
 */
class TEST_TB_SAME1_EXPORT ISameEnum1InterfacePublisher
{
public:
    virtual ~ISameEnum1InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the SameEnum1Interface.
    * Subscriber will be informed of any emited signal and any property changes.
    * This is parallel notification system to single subscription. If you will subscribe also for a single change
    * your subscriber will be informed twice about that change, one for each subscription mechanism.
    * @param ISameEnum1InterfaceSubscriber which is subscribed in this function to any change of the SameEnum1Interface.
    */
    virtual void subscribeToAllChanges(ISameEnum1InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the SameEnum1Interface.
    * Not all subscriptions will be removed, the ones made separately for single singal or property change stay intact.
    * Make sure to remove them.
    * @param ISameEnum1InterfaceSubscriber which subscription for any change of the SameEnum1Interface is removed.
    */
    virtual void unsubscribeFromAllChanges(ISameEnum1InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param SameEnum1InterfaceProp1PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop1 property changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp1Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    * @param SameEnum1InterfaceSig1SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the SameEnum1Interface implementation when property prop1 changes.
    * @param The new value of prop1.
    */
    virtual void publishProp1Changed(const Enum1Enum& prop1) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the SameEnum1Interface implementation when sig1 is emited.
    * @param param1 
    */
    virtual void publishSig1(const Enum1Enum& param1) const = 0;
};


} // namespace TbSame1
} // namespace Test

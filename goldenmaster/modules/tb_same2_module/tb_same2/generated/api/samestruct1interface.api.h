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
#include "tb_same2/generated/api/common.h"
#include "tb_same2/generated/api/datastructs.api.h"

namespace Test {
namespace TbSame2 {

class ISameStruct1InterfaceSubscriber;
class ISameStruct1InterfacePublisher;

/**
*
* ISameStruct1Interface provides an interface for
 *  - methods defined for your SameStruct1Interface 
 *  - proeperty setters and getters for defined properties
 * The ISameStruct1Interface also providess an interface to access a publisher ISameStruct1InterfacePublisher, a class used by ISameStruct1InterfaceSubscriber clients.
 * The implementation should notify the publisher ISameStruct1InterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also ISameStruct1InterfaceSubscriber, ISameStruct1InterfacePublisher
 * and the exmaple implementation SameStruct1Interface  or the
 */
class TEST_TB_SAME2_EXPORT ISameStruct1Interface
{
public:
    virtual ~ISameStruct1Interface() = default;


    virtual Struct1 func1(const Struct1& param1) = 0;
    /**
    * Asynchronous version of func1(const Struct1& param1)
    * @return Promise of type Struct1 which is set once the function has completed
    */
    virtual std::future<Struct1> func1Async(const Struct1& param1) = 0;

    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const Struct1& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual const Struct1& prop1() const = 0;


    /**
    * Access to a publisher, use it to subscribe for SameStruct1Interface changes and signal emission.
    * @return The publisher for SameStruct1Interface.
    */
    virtual ISameStruct1InterfacePublisher& _getPublisher() const = 0;
};


/**
 * The ISameStruct1InterfaceSubscriber contains functions to allow informing about singals or property changes of the ISameStruct1Interface implementation.
 * The implementation for ISameStruct1Interface should provide mechanism for subscibtion of the ISameStruct1InterfaceSubscriber clients.
 * See ISameStruct1InterfacePublisher, which provides facititation for this purpose.
 * The implementation for ISameStruct1Interface should call the ISameStruct1InterfaceSubscriber interface functions on either singal emit or property change.
 * You can use ISameStruct1InterfaceSubscriber class to implement clients of the ISameStruct1Interface or the network adapter - see Olink Server and Client example.
 */
class TEST_TB_SAME2_EXPORT ISameStruct1InterfaceSubscriber
{
public:
    virtual ~ISameStruct1InterfaceSubscriber() = default;
    /**
    * Called by the ISameStruct1InterfacePublisher when the SameStruct1Interface emits sig1, if subscribed for the sig1.
    * @param param1 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig1(const Struct1& param1) = 0;
    /**
    * Called by the ISameStruct1InterfacePublisher when prop1 value has changed if subscribed for the prop1 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const Struct1& prop1) = 0;
};

/** Callback for changes of prop1 */
using SameStruct1InterfaceProp1PropertyCb = std::function<void(const Struct1& prop1)>;
/** Callback for sig1 signal triggers */
using SameStruct1InterfaceSig1SignalCb = std::function<void(const Struct1& param1)> ;


/**
 * The ISameStruct1InterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emission 
 * or a property change.
 * Implement this interface to keep track of clients of your ISameStruct1Interface implementation.
 * The publisher provides two independent methods of subscription
 *  - subscribing with a ITunerSubscriber objects - for all of the changes
 *  - subscribing any object for signle type of change property or a signal
 * The publish functions needs to be called by implementation of the ITuner on each state changed or signal emited
 * to notify all the subscribers about this change.
 */
class TEST_TB_SAME2_EXPORT ISameStruct1InterfacePublisher
{
public:
    virtual ~ISameStruct1InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the SameStruct1Interface.
    * Subscriber will be informed of any emited signal and any property changes.
    * This is parallel notification system to single subscription. If you will subscribe also for a single change
    * your subscriber will be informed twice about that change, one for each subscription mechanism.
    * @param ISameStruct1InterfaceSubscriber which is subscribed in this function to any change of the SameStruct1Interface.
    */
    virtual void subscribeToAllChanges(ISameStruct1InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the SameStruct1Interface.
    * Not all subscriptions will be removed, the ones made separately for single singal or property change stay intact.
    * Make sure to remove them.
    * @param ISameStruct1InterfaceSubscriber which subscription for any change of the SameStruct1Interface is removed.
    */
    virtual void unsubscribeFromAllChanges(ISameStruct1InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    * If your subscriber uses subsrciption with ISameStruct1InterfaceSubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param SameStruct1InterfaceProp1PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop1 property changes.
    * If your subscriber uses subsrciption with ISameStruct1InterfaceSubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp1Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    * @param SameStruct1InterfaceSig1SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the SameStruct1Interface implementation when property prop1 changes.
    * @param The new value of prop1.
    */
    virtual void publishProp1Changed(const Struct1& prop1) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the SameStruct1Interface implementation when sig1 is emited.
    * @param param1 
    */
    virtual void publishSig1(const Struct1& param1) const = 0;
};


} // namespace TbSame2
} // namespace Test

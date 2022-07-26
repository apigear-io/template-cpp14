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
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/api/datastructs.api.h"

namespace Test {
namespace Testbed2 {

class INestedStruct3InterfaceSubscriber;
class INestedStruct3InterfacePublisher;

/**
*
* INestedStruct3Interface provides an interface for
 *  - methods defined for your NestedStruct3Interface 
 *  - proeperty setters and getters for defined properties
 * The INestedStruct3Interface also providess an interface to access a publisher INestedStruct3InterfacePublisher, a class used by INestedStruct3InterfaceSubscriber clients.
 * The implementation should notify the publisher INestedStruct3InterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also INestedStruct3InterfaceSubscriber, INestedStruct3InterfacePublisher
 * and the exmaple implementation NestedStruct3Interface  or the
 */
class TEST_TESTBED2_EXPORT INestedStruct3Interface
{
public:
    virtual ~INestedStruct3Interface() = default;


    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;
    /**
    * Asynchronous version of func1(const NestedStruct1& param1)
    * @return Promise of type NestedStruct1 which is set once the function has completed
    */
    virtual std::future<NestedStruct1> func1Async(const NestedStruct1& param1) = 0;


    virtual NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) = 0;
    /**
    * Asynchronous version of func2(const NestedStruct1& param1, const NestedStruct2& param2)
    * @return Promise of type NestedStruct1 which is set once the function has completed
    */
    virtual std::future<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2) = 0;


    virtual NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) = 0;
    /**
    * Asynchronous version of func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
    * @return Promise of type NestedStruct1 which is set once the function has completed
    */
    virtual std::future<NestedStruct1> func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) = 0;

    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const NestedStruct1& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual const NestedStruct1& prop1() const = 0;

    /**
    * Sets the value of the prop2 property.
    */
    virtual void setProp2(const NestedStruct2& prop2) = 0;
    /**
    * Gets the value of the prop2 property.
    */
    virtual const NestedStruct2& prop2() const = 0;

    /**
    * Sets the value of the prop3 property.
    */
    virtual void setProp3(const NestedStruct3& prop3) = 0;
    /**
    * Gets the value of the prop3 property.
    */
    virtual const NestedStruct3& prop3() const = 0;

    /**
    * @return Publisher class INestedStruct3InterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual INestedStruct3InterfacePublisher& _getPublisher() const = 0;
};


/**
 * The INestedStruct3InterfaceSubscriber contains functions to allow informing about singals or property changes of the INestedStruct3Interface implementation.
 * The implementation for INestedStruct3Interface should provide mechanism for subscibtion of the INestedStruct3InterfaceSubscriber clients.
 * See INestedStruct3InterfacePublisher, which provides facititation for this purpose.
 * The implementation for INestedStruct3Interface should call the INestedStruct3InterfaceSubscriber interface functions on either singal emit or property change.
 * You can use INestedStruct3InterfaceSubscriber class to implement clients of the INestedStruct3Interface or the network adapter - see Olink Server and Client example.
 */
class TEST_TESTBED2_EXPORT INestedStruct3InterfaceSubscriber
{
public:
    /**
    * Called by the INestedStruct3InterfacePublisher when the NestedStruct3Interface emits sig1, if subscribed for the sig1.
    * @param param1 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig1(const NestedStruct1& param1) = 0;
    /**
    * Called by the INestedStruct3InterfacePublisher when the NestedStruct3Interface emits sig2, if subscribed for the sig2.
    * @param param1 
    * @param param2 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig2(const NestedStruct1& param1,const NestedStruct2& param2) = 0;
    /**
    * Called by the INestedStruct3InterfacePublisher when the NestedStruct3Interface emits sig3, if subscribed for the sig3.
    * @param param1 
    * @param param2 
    * @param param3 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) = 0;
    /**
    * Called by the INestedStruct3InterfacePublisher when prop1 value has changed if subscribed for the prop1 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const NestedStruct1& prop1) = 0;
    /**
    * Called by the INestedStruct3InterfacePublisher when prop2 value has changed if subscribed for the prop2 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp2Changed(const NestedStruct2& prop2) = 0;
    /**
    * Called by the INestedStruct3InterfacePublisher when prop3 value has changed if subscribed for the prop3 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp3Changed(const NestedStruct3& prop3) = 0;
};

/** Callback for changes of prop1 */
using NestedStruct3InterfaceProp1PropertyCb = std::function<void(const NestedStruct1& prop1)>;
/** Callback for changes of prop2 */
using NestedStruct3InterfaceProp2PropertyCb = std::function<void(const NestedStruct2& prop2)>;
/** Callback for changes of prop3 */
using NestedStruct3InterfaceProp3PropertyCb = std::function<void(const NestedStruct3& prop3)>;
/** Callback for sig1 signal triggers */
using NestedStruct3InterfaceSig1SignalCb = std::function<void(const NestedStruct1& param1)> ;
/** Callback for sig2 signal triggers */
using NestedStruct3InterfaceSig2SignalCb = std::function<void(const NestedStruct1& param1,const NestedStruct2& param2)> ;
/** Callback for sig3 signal triggers */
using NestedStruct3InterfaceSig3SignalCb = std::function<void(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3)> ;


/**
 * The INestedStruct3InterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emission 
 * or a property change.
 * Implement this interface to keep track of clients of your INestedStruct3Interface implementation.
 * The publisher provides two independent methods of subscription
 *  - subscribing with a ITunerSubscriber objects - for all of the changes
 *  - subscribing any object for signle type of change property or a signal
 * The publish functions needs to be called by implementation of the ITuner on each state changed or signal emited
 * to notify all the subscribers about this change.
 */
class TEST_TESTBED2_EXPORT INestedStruct3InterfacePublisher
{
public:
    virtual ~INestedStruct3InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the NestedStruct3Interface.
    * Subscriber will be informed of any emited signal and any property changes.
    * This is parallel notification system to single subscription. If you will subscribe also for a single change
    * your subscriber will be informed twice about that change, one for each subscription mechanism.
    * @param INestedStruct3InterfaceSubscriber which is subscribed in this function to any change of the NestedStruct3Interface.
    */
    virtual void subscribeToAllChanges(INestedStruct3InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the NestedStruct3Interface.
    * Not all subscriptions will be removed, the ones made separately for single singal or property change stay intact.
    * Make sure to remove them.
    * @param INestedStruct3InterfaceSubscriber which subscription for any change of the NestedStruct3Interface is removed.
    */
    virtual void unsubscribeFromAllChanges(INestedStruct3InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param NestedStruct3InterfaceProp1PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp1Changed(NestedStruct3InterfaceProp1PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop1 property changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp1Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop2 value changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param NestedStruct3InterfaceProp2PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp2Changed(NestedStruct3InterfaceProp2PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop2 property changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp2Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop3 value changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param NestedStruct3InterfaceProp3PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp3Changed(NestedStruct3InterfaceProp3PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop3 property changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp3Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    * @param NestedStruct3InterfaceSig1SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig1(NestedStruct3InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    * @param NestedStruct3InterfaceSig2SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig2(NestedStruct3InterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * Use this function to subscribe for sig3 signal changes.
    * @param NestedStruct3InterfaceSig3SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig3(NestedStruct3InterfaceSig3SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig3 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig3(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the NestedStruct3Interface implementation when property prop1 changes.
    * @param The new value of prop1.
    */
    virtual void publishProp1Changed(const NestedStruct1& prop1) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the NestedStruct3Interface implementation when property prop2 changes.
    * @param The new value of prop2.
    */
    virtual void publishProp2Changed(const NestedStruct2& prop2) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the NestedStruct3Interface implementation when property prop3 changes.
    * @param The new value of prop3.
    */
    virtual void publishProp3Changed(const NestedStruct3& prop3) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the NestedStruct3Interface implementation when sig1 is emited.
    * @param param1 
    */
    virtual void publishSig1(const NestedStruct1& param1) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the NestedStruct3Interface implementation when sig2 is emited.
    * @param param1 
    * @param param2 
    */
    virtual void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the NestedStruct3Interface implementation when sig3 is emited.
    * @param param1 
    * @param param2 
    * @param param3 
    */
    virtual void publishSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) const = 0;
};


} // namespace Testbed2
} // namespace Test

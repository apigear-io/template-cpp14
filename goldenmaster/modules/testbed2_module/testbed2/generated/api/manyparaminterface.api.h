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

class IManyParamInterfaceSubscriber;
class IManyParamInterfacePublisher;

/**
*
* IManyParamInterface provides an interface for
 *  - methods defined for your ManyParamInterface 
 *  - proeperty setters and getters for defined properties
 * The IManyParamInterface also providess an interface to access a publisher IManyParamInterfacePublisher, a class used by IManyParamInterfaceSubscriber clients.
 * The implementation should notify the publisher IManyParamInterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also IManyParamInterfaceSubscriber, IManyParamInterfacePublisher
 * and the exmaple implementation ManyParamInterface  or the
 */
class TEST_TESTBED2_EXPORT IManyParamInterface
{
public:
    virtual ~IManyParamInterface() = default;


    virtual int func1(int param1) = 0;
    /**
    * Asynchronous version of func1(int param1)
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> func1Async(int param1) = 0;


    virtual int func2(int param1, int param2) = 0;
    /**
    * Asynchronous version of func2(int param1, int param2)
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> func2Async(int param1, int param2) = 0;


    virtual int func3(int param1, int param2, int param3) = 0;
    /**
    * Asynchronous version of func3(int param1, int param2, int param3)
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> func3Async(int param1, int param2, int param3) = 0;


    virtual int func4(int param1, int param2, int param3, int param4) = 0;
    /**
    * Asynchronous version of func4(int param1, int param2, int param3, int param4)
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> func4Async(int param1, int param2, int param3, int param4) = 0;

    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(int prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual int prop1() const = 0;

    /**
    * Sets the value of the prop2 property.
    */
    virtual void setProp2(int prop2) = 0;
    /**
    * Gets the value of the prop2 property.
    */
    virtual int prop2() const = 0;

    /**
    * Sets the value of the prop3 property.
    */
    virtual void setProp3(int prop3) = 0;
    /**
    * Gets the value of the prop3 property.
    */
    virtual int prop3() const = 0;

    /**
    * Sets the value of the prop4 property.
    */
    virtual void setProp4(int prop4) = 0;
    /**
    * Gets the value of the prop4 property.
    */
    virtual int prop4() const = 0;

    /**
    * @return Publisher class IManyParamInterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual IManyParamInterfacePublisher& _getPublisher() const = 0;
};


/**
 * The IManyParamInterfaceSubscriber contains functions to allow informing about singals or property changes of the IManyParamInterface implementation.
 * The implementation for IManyParamInterface should provide mechanism for subscibtion of the IManyParamInterfaceSubscriber clients.
 * See IManyParamInterfacePublisher, which provides facititation for this purpose.
 * The implementation for IManyParamInterface should call the IManyParamInterfaceSubscriber interface functions on either singal emit or property change.
 * You can use IManyParamInterfaceSubscriber class to implement clients of the IManyParamInterface or the network adapter - see Olink Server and Client example.
 */
class TEST_TESTBED2_EXPORT IManyParamInterfaceSubscriber
{
public:
    /**
    * Called by the IManyParamInterfacePublisher when the ManyParamInterface emits sig1, if subscribed for the sig1.
    * @param param1 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig1(int param1) = 0;
    /**
    * Called by the IManyParamInterfacePublisher when the ManyParamInterface emits sig2, if subscribed for the sig2.
    * @param param1 
    * @param param2 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig2(int param1,int param2) = 0;
    /**
    * Called by the IManyParamInterfacePublisher when the ManyParamInterface emits sig3, if subscribed for the sig3.
    * @param param1 
    * @param param2 
    * @param param3 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig3(int param1,int param2,int param3) = 0;
    /**
    * Called by the IManyParamInterfacePublisher when the ManyParamInterface emits sig4, if subscribed for the sig4.
    * @param param1 
    * @param param2 
    * @param param3 
    * @param param4 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig4(int param1,int param2,int param3,int param4) = 0;
    /**
    * Called by the IManyParamInterfacePublisher when prop1 value has changed if subscribed for the prop1 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(int prop1) = 0;
    /**
    * Called by the IManyParamInterfacePublisher when prop2 value has changed if subscribed for the prop2 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp2Changed(int prop2) = 0;
    /**
    * Called by the IManyParamInterfacePublisher when prop3 value has changed if subscribed for the prop3 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp3Changed(int prop3) = 0;
    /**
    * Called by the IManyParamInterfacePublisher when prop4 value has changed if subscribed for the prop4 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp4Changed(int prop4) = 0;
};

/** Callback for changes of prop1 */
using ManyParamInterfaceProp1PropertyCb = std::function<void(int prop1)>;
/** Callback for changes of prop2 */
using ManyParamInterfaceProp2PropertyCb = std::function<void(int prop2)>;
/** Callback for changes of prop3 */
using ManyParamInterfaceProp3PropertyCb = std::function<void(int prop3)>;
/** Callback for changes of prop4 */
using ManyParamInterfaceProp4PropertyCb = std::function<void(int prop4)>;
/** Callback for sig1 signal triggers */
using ManyParamInterfaceSig1SignalCb = std::function<void(int param1)> ;
/** Callback for sig2 signal triggers */
using ManyParamInterfaceSig2SignalCb = std::function<void(int param1,int param2)> ;
/** Callback for sig3 signal triggers */
using ManyParamInterfaceSig3SignalCb = std::function<void(int param1,int param2,int param3)> ;
/** Callback for sig4 signal triggers */
using ManyParamInterfaceSig4SignalCb = std::function<void(int param1,int param2,int param3,int param4)> ;


/**
 * The IManyParamInterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emission 
 * or a property change.
 * Implement this interface to keep track of clients of your IManyParamInterface implementation.
 * The publisher provides two independent methods of subscription
 *  - subscribing with a ITunerSubscriber objects - for all of the changes
 *  - subscribing any object for signle type of change property or a signal
 * The publish functions needs to be called by implementation of the ITuner on each state changed or signal emited
 * to notify all the subscribers about this change.
 */
class TEST_TESTBED2_EXPORT IManyParamInterfacePublisher
{
public:
    virtual ~IManyParamInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the ManyParamInterface.
    * Subscriber will be informed of any emited signal and any property changes.
    * This is parallel notification system to single subscription. If you will subscribe also for a single change
    * your subscriber will be informed twice about that change, one for each subscription mechanism.
    * @param IManyParamInterfaceSubscriber which is subscribed in this function to any change of the ManyParamInterface.
    */
    virtual void subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the ManyParamInterface.
    * Not all subscriptions will be removed, the ones made separately for single singal or property change stay intact.
    * Make sure to remove them.
    * @param IManyParamInterfaceSubscriber which subscription for any change of the ManyParamInterface is removed.
    */
    virtual void unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param ManyParamInterfaceProp1PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback) = 0;
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
    * @param ManyParamInterfaceProp2PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback) = 0;
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
    * @param ManyParamInterfaceProp3PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop3 property changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp3Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop4 value changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param ManyParamInterfaceProp4PropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop4 property changes.
    * If your subscriber uses subsrciption with ISubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp4Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    * @param ManyParamInterfaceSig1SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig1(ManyParamInterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    * @param ManyParamInterfaceSig2SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig2(ManyParamInterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * Use this function to subscribe for sig3 signal changes.
    * @param ManyParamInterfaceSig3SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig3(ManyParamInterfaceSig3SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig3 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig3(long handleId) = 0;

    /**
    * Use this function to subscribe for sig4 signal changes.
    * @param ManyParamInterfaceSig4SignalCb callback that will be executed on each signal emission.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig4(ManyParamInterfaceSig4SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig4 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig4(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the ManyParamInterface implementation when property prop1 changes.
    * @param The new value of prop1.
    */
    virtual void publishProp1Changed(int prop1) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the ManyParamInterface implementation when property prop2 changes.
    * @param The new value of prop2.
    */
    virtual void publishProp2Changed(int prop2) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the ManyParamInterface implementation when property prop3 changes.
    * @param The new value of prop3.
    */
    virtual void publishProp3Changed(int prop3) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the ManyParamInterface implementation when property prop4 changes.
    * @param The new value of prop4.
    */
    virtual void publishProp4Changed(int prop4) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the ManyParamInterface implementation when sig1 is emited.
    * @param param1 
    */
    virtual void publishSig1(int param1) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the ManyParamInterface implementation when sig2 is emited.
    * @param param1 
    * @param param2 
    */
    virtual void publishSig2(int param1,int param2) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the ManyParamInterface implementation when sig3 is emited.
    * @param param1 
    * @param param2 
    * @param param3 
    */
    virtual void publishSig3(int param1,int param2,int param3) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients.
    * Needs to be invoked by the ManyParamInterface implementation when sig4 is emited.
    * @param param1 
    * @param param2 
    * @param param3 
    * @param param4 
    */
    virtual void publishSig4(int param1,int param2,int param3,int param4) const = 0;
};


} // namespace Testbed2
} // namespace Test

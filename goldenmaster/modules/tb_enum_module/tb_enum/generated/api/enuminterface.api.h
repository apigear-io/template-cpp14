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
#include "tb_enum/generated/api/common.h"
#include "tb_enum/generated/api/datastructs.api.h"

namespace Test {
namespace TbEnum {

class IEnumInterfaceSubscriber;
class IEnumInterfacePublisher;

/**
*
* IEnumInterface provides an interface for
 *  - methods defined for your EnumInterface 
 *  - proeperty setters and getters for defined properties
 * The IEnumInterface also providess an interface to access a publisher IEnumInterfacePublisher, a class used by IEnumInterfaceSubscriber clients.
 * The implementation should notify the publisher IEnumInterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also IEnumInterfaceSubscriber, IEnumInterfacePublisher
 * and the exmaple implementation EnumInterface  or the
 */
class TEST_TB_ENUM_EXPORT IEnumInterface
{
public:
    virtual ~IEnumInterface() = default;


    virtual Enum0Enum func0(const Enum0Enum& param0) = 0;
    /**
    * Asynchronous version of func0(const Enum0Enum& param0)
    * @return Promise of type Enum0Enum which is set once the function has completed
    */
    virtual std::future<Enum0Enum> func0Async(const Enum0Enum& param0) = 0;


    virtual Enum1Enum func1(const Enum1Enum& param1) = 0;
    /**
    * Asynchronous version of func1(const Enum1Enum& param1)
    * @return Promise of type Enum1Enum which is set once the function has completed
    */
    virtual std::future<Enum1Enum> func1Async(const Enum1Enum& param1) = 0;


    virtual Enum2Enum func2(const Enum2Enum& param2) = 0;
    /**
    * Asynchronous version of func2(const Enum2Enum& param2)
    * @return Promise of type Enum2Enum which is set once the function has completed
    */
    virtual std::future<Enum2Enum> func2Async(const Enum2Enum& param2) = 0;


    virtual Enum3Enum func3(const Enum3Enum& param3) = 0;
    /**
    * Asynchronous version of func3(const Enum3Enum& param3)
    * @return Promise of type Enum3Enum which is set once the function has completed
    */
    virtual std::future<Enum3Enum> func3Async(const Enum3Enum& param3) = 0;

    /**
    * Sets the value of the prop0 property.
    */
    virtual void setProp0(const Enum0Enum& prop0) = 0;
    /**
    * Gets the value of the prop0 property.
    */
    virtual const Enum0Enum& prop0() const = 0;

    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const Enum1Enum& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual const Enum1Enum& prop1() const = 0;

    /**
    * Sets the value of the prop2 property.
    */
    virtual void setProp2(const Enum2Enum& prop2) = 0;
    /**
    * Gets the value of the prop2 property.
    */
    virtual const Enum2Enum& prop2() const = 0;

    /**
    * Sets the value of the prop3 property.
    */
    virtual void setProp3(const Enum3Enum& prop3) = 0;
    /**
    * Gets the value of the prop3 property.
    */
    virtual const Enum3Enum& prop3() const = 0;

    /**
    * @return Publisher class IEnumInterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual IEnumInterfacePublisher& _getPublisher() const = 0;
};


/**
 * The IEnumInterfaceSubscriber contains functions to allow informing about singals or property changes of the IEnumInterface implementation.
 * The implementation for IEnumInterface should provide mechanism for subscibtion of the IEnumInterfaceSubscriber clients.
 * The implementation for IEnumInterface should call the IEnumInterfaceSubscriber interface functions on either singal emit or property change.
 * See IEnumInterfacePublisher, which provides facititation for this purpose.
 * You can use IEnumInterfaceSubscriber class to implement clients of the IEnumInterface or the network adapter - see Olink Server and Client example.
 */
class TEST_TB_ENUM_EXPORT IEnumInterfaceSubscriber
{
public:
    /**
    * Called by the IEnumInterfacePublisher when the EnumInterface emits sig0, if subscribed for the sig0.
    * @param param0 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig0(const Enum0Enum& param0) = 0;
    /**
    * Called by the IEnumInterfacePublisher when the EnumInterface emits sig1, if subscribed for the sig1.
    * @param param1 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig1(const Enum1Enum& param1) = 0;
    /**
    * Called by the IEnumInterfacePublisher when the EnumInterface emits sig2, if subscribed for the sig2.
    * @param param2 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig2(const Enum2Enum& param2) = 0;
    /**
    * Called by the IEnumInterfacePublisher when the EnumInterface emits sig3, if subscribed for the sig3.
    * @param param3 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig3(const Enum3Enum& param3) = 0;
    /**
    * Called by the IEnumInterfacePublisher when prop0 value has changed if subscribed for the prop0 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp0Changed(const Enum0Enum& prop0) = 0;
    /**
    * Called by the IEnumInterfacePublisher when prop1 value has changed if subscribed for the prop1 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const Enum1Enum& prop1) = 0;
    /**
    * Called by the IEnumInterfacePublisher when prop2 value has changed if subscribed for the prop2 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp2Changed(const Enum2Enum& prop2) = 0;
    /**
    * Called by the IEnumInterfacePublisher when prop3 value has changed if subscribed for the prop3 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp3Changed(const Enum3Enum& prop3) = 0;
};

/** Callback for changes of prop0 */
using EnumInterfaceProp0PropertyCb = std::function<void(const Enum0Enum& prop0)>;
/** Callback for changes of prop1 */
using EnumInterfaceProp1PropertyCb = std::function<void(const Enum1Enum& prop1)>;
/** Callback for changes of prop2 */
using EnumInterfaceProp2PropertyCb = std::function<void(const Enum2Enum& prop2)>;
/** Callback for changes of prop3 */
using EnumInterfaceProp3PropertyCb = std::function<void(const Enum3Enum& prop3)>;
/** Callback for sig0 signal triggers */
using EnumInterfaceSig0SignalCb = std::function<void(const Enum0Enum& param0)> ;
/** Callback for sig1 signal triggers */
using EnumInterfaceSig1SignalCb = std::function<void(const Enum1Enum& param1)> ;
/** Callback for sig2 signal triggers */
using EnumInterfaceSig2SignalCb = std::function<void(const Enum2Enum& param2)> ;
/** Callback for sig3 signal triggers */
using EnumInterfaceSig3SignalCb = std::function<void(const Enum3Enum& param3)> ;


/**
 * The IEnumInterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emision 
 * or a property change.
 * Implement this interface to keep track of clients of your IEnumInterface implementation.
 * The second part of the IEnumInterfacePublisher interface is the notification interface.
 * It needs to be called by implementation of the IEnumInterface on each state changed or signal emited
 * and shall notify all the subscribers about this change.
 */
class TEST_TB_ENUM_EXPORT IEnumInterfacePublisher
{
public:
    virtual ~IEnumInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the EnumInterface.
    * Subscriber will be informed of any emited signal and any property changes.
    * @param IEnumInterfaceSubscriber which is subscribed in this function to any change of the EnumInterface.
    */
    virtual void subscribeToEnumInterfaceChanges(IEnumInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the EnumInterface.
    * All the subscriptions will be removed, including ones made deparately for single singal or property change.
    * @param IEnumInterfaceSubscriber which subscription for any change of the EnumInterface is removed.
    */
    virtual void unsubscribeFromEnumInterfaceChanges(IEnumInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop0 value changes.
    * @param EnumInterfaceProp0PropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp0Changed(EnumInterfaceProp0PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop0 property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp0Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    * @param EnumInterfaceProp1PropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp1Changed(EnumInterfaceProp1PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop1 property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp1Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop2 value changes.
    * @param EnumInterfaceProp2PropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop2 property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp2Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop3 value changes.
    * @param EnumInterfaceProp3PropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop3 property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp3Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig0 signal changes.
    * @param EnumInterfaceSig0SignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig0(EnumInterfaceSig0SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig0 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig0(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    * @param EnumInterfaceSig1SignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig1(EnumInterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    * @param EnumInterfaceSig2SignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig2(EnumInterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * Use this function to subscribe for sig3 signal changes.
    * @param EnumInterfaceSig3SignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig3(EnumInterfaceSig3SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig3 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig3(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.Invoked by the EnumInterface implementation.
    * @param The new value of prop0.
    */
    virtual void publishProp0Changed(const Enum0Enum& prop0) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the EnumInterface implementation.
    * @param The new value of prop1.
    */
    virtual void publishProp1Changed(const Enum1Enum& prop1) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the EnumInterface implementation.
    * @param The new value of prop2.
    */
    virtual void publishProp2Changed(const Enum2Enum& prop2) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the EnumInterface implementation.
    * @param The new value of prop3.
    */
    virtual void publishProp3Changed(const Enum3Enum& prop3) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the EnumInterface implementation.
    * @param param0 
    */
    virtual void publishSig0(const Enum0Enum& param0) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the EnumInterface implementation.
    * @param param1 
    */
    virtual void publishSig1(const Enum1Enum& param1) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the EnumInterface implementation.
    * @param param2 
    */
    virtual void publishSig2(const Enum2Enum& param2) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the EnumInterface implementation.
    * @param param3 
    */
    virtual void publishSig3(const Enum3Enum& param3) const = 0;
};


} // namespace TbEnum
} // namespace Test

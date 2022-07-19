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
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/api/datastructs.api.h"

namespace Test {
namespace Testbed1 {

class IStructInterfaceSubscriber;
class IStructInterfacePublisher;

/**
*
* IStructInterface provides an interface for
 *  - methods defined for your StructInterface 
 *  - proeperty setters and getters for defined properties
 * The IStructInterface also providess an interface to access a publisher IStructInterfacePublisher, a class used by IStructInterfaceSubscriber clients.
 * The implementation should notify the publisher IStructInterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also IStructInterfaceSubscriber, IStructInterfacePublisher
 * and the exmaple implementation StructInterface  or the
 */
class TEST_TESTBED1_EXPORT IStructInterface
{
public:
    virtual ~IStructInterface() = default;


    virtual StructBool funcBool(const StructBool& paramBool) = 0;
    /**
    * Asynchronous version of funcBool(const StructBool& paramBool)
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcBoolAsync(const StructBool& paramBool) = 0;


    virtual StructBool funcInt(const StructInt& paramInt) = 0;
    /**
    * Asynchronous version of funcInt(const StructInt& paramInt)
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcIntAsync(const StructInt& paramInt) = 0;


    virtual StructFloat funcFloat(const StructFloat& paramFloat) = 0;
    /**
    * Asynchronous version of funcFloat(const StructFloat& paramFloat)
    * @return Promise of type StructFloat which is set once the function has completed
    */
    virtual std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) = 0;


    virtual StructString funcString(const StructString& paramString) = 0;
    /**
    * Asynchronous version of funcString(const StructString& paramString)
    * @return Promise of type StructString which is set once the function has completed
    */
    virtual std::future<StructString> funcStringAsync(const StructString& paramString) = 0;

    /**
    * Sets the value of the propBool property.
    */
    virtual void setPropbool(const StructBool& propBool) = 0;
    /**
    * Gets the value of the propBool property.
    */
    virtual const StructBool& propBool() const = 0;

    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropint(const StructInt& propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual const StructInt& propInt() const = 0;

    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropfloat(const StructFloat& propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual const StructFloat& propFloat() const = 0;

    /**
    * Sets the value of the propString property.
    */
    virtual void setPropstring(const StructString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual const StructString& propString() const = 0;

    /**
    * @return Publisher class IStructInterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual IStructInterfacePublisher& _getPublisher() const = 0;
};


/**
 * The IStructInterfaceSubscriber contains functions to allow informing about singals or property changes of the IStructInterface implementation.
 * The implementation for IStructInterface should provide mechanism for subscibtion of the IStructInterfaceSubscriber clients.
 * The implementation for IStructInterface should call the IStructInterfaceSubscriber interface functions on either singal emit or property change.
 * See IStructInterfacePublisher, which provides facititation for this purpose.
 * You can use IStructInterfaceSubscriber class to implement clients of the IStructInterface or the network adapter - see Olink Server and Client example.
 */
class TEST_TESTBED1_EXPORT IStructInterfaceSubscriber
{
public:
    /**
    * Called by the IStructInterfacePublisher when the StructInterface emits sigBool, if subscribed for the sigBool.
    * @param paramBool 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigBool(const StructBool& paramBool) = 0;
    /**
    * Called by the IStructInterfacePublisher when the StructInterface emits sigInt, if subscribed for the sigInt.
    * @param paramInt 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigInt(const StructInt& paramInt) = 0;
    /**
    * Called by the IStructInterfacePublisher when the StructInterface emits sigFloat, if subscribed for the sigFloat.
    * @param paramFloat 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigFloat(const StructFloat& paramFloat) = 0;
    /**
    * Called by the IStructInterfacePublisher when the StructInterface emits sigString, if subscribed for the sigString.
    * @param paramString 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigString(const StructString& paramString) = 0;
    /**
    * Called by the IStructInterfacePublisher when propBool value has changed if subscribed for the propBool change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropBoolChanged(const StructBool& propBool) = 0;
    /**
    * Called by the IStructInterfacePublisher when propInt value has changed if subscribed for the propInt change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropIntChanged(const StructInt& propInt) = 0;
    /**
    * Called by the IStructInterfacePublisher when propFloat value has changed if subscribed for the propFloat change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropFloatChanged(const StructFloat& propFloat) = 0;
    /**
    * Called by the IStructInterfacePublisher when propString value has changed if subscribed for the propString change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropStringChanged(const StructString& propString) = 0;
};

/** Callback for changes of propBool */
using StructInterfacePropBoolPropertyCb = std::function<void(const StructBool& propBool)>;
/** Callback for changes of propInt */
using StructInterfacePropIntPropertyCb = std::function<void(const StructInt& propInt)>;
/** Callback for changes of propFloat */
using StructInterfacePropFloatPropertyCb = std::function<void(const StructFloat& propFloat)>;
/** Callback for changes of propString */
using StructInterfacePropStringPropertyCb = std::function<void(const StructString& propString)>;
/** Callback for sigBool signal triggers */
using StructInterfaceSigBoolSignalCb = std::function<void(const StructBool& paramBool)> ;
/** Callback for sigInt signal triggers */
using StructInterfaceSigIntSignalCb = std::function<void(const StructInt& paramInt)> ;
/** Callback for sigFloat signal triggers */
using StructInterfaceSigFloatSignalCb = std::function<void(const StructFloat& paramFloat)> ;
/** Callback for sigString signal triggers */
using StructInterfaceSigStringSignalCb = std::function<void(const StructString& paramString)> ;


/**
 * The IStructInterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emision 
 * or a property change.
 * Implement this interface to keep track of clients of your IStructInterface implementation.
 * The second part of the IStructInterfacePublisher interface is the notification interface.
 * It needs to be called by implementation of the IStructInterface on each state changed or signal emited
 * and shall notify all the subscribers about this change.
 */
class TEST_TESTBED1_EXPORT IStructInterfacePublisher
{
public:
    virtual ~IStructInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the StructInterface.
    * Subscriber will be informed of any emited signal and any property changes.
    * @param IStructInterfaceSubscriber which is subscribed in this function to any change of the StructInterface.
    */
    virtual void subscribeToStructInterfaceChanges(IStructInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the StructInterface.
    * All the subscriptions will be removed, including ones made deparately for single singal or property change.
    * @param IStructInterfaceSubscriber which subscription for any change of the StructInterface is removed.
    */
    virtual void unsubscribeFromStructInterfaceChanges(IStructInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for propBool value changes.
    * @param StructInterfacePropBoolPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propBool property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropBoolChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propInt value changes.
    * @param StructInterfacePropIntPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propInt property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropIntChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propFloat value changes.
    * @param StructInterfacePropFloatPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propFloat property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropFloatChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propString value changes.
    * @param StructInterfacePropStringPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propString property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropStringChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for sigBool signal changes.
    * @param StructInterfaceSigBoolSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigBool(StructInterfaceSigBoolSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigBool signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigBool(long handleId) = 0;

    /**
    * Use this function to subscribe for sigInt signal changes.
    * @param StructInterfaceSigIntSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigInt(StructInterfaceSigIntSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigInt signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigInt(long handleId) = 0;

    /**
    * Use this function to subscribe for sigFloat signal changes.
    * @param StructInterfaceSigFloatSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigFloat signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigFloat(long handleId) = 0;

    /**
    * Use this function to subscribe for sigString signal changes.
    * @param StructInterfaceSigStringSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigString(StructInterfaceSigStringSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigString signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigString(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.Invoked by the StructInterface implementation.
    * @param The new value of propBool.
    */
    virtual void publishPropBoolChanged(const StructBool& propBool) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the StructInterface implementation.
    * @param The new value of propInt.
    */
    virtual void publishPropIntChanged(const StructInt& propInt) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the StructInterface implementation.
    * @param The new value of propFloat.
    */
    virtual void publishPropFloatChanged(const StructFloat& propFloat) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the StructInterface implementation.
    * @param The new value of propString.
    */
    virtual void publishPropStringChanged(const StructString& propString) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the StructInterface implementation.
    * @param paramBool 
    */
    virtual void publishSigBool(const StructBool& paramBool) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the StructInterface implementation.
    * @param paramInt 
    */
    virtual void publishSigInt(const StructInt& paramInt) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the StructInterface implementation.
    * @param paramFloat 
    */
    virtual void publishSigFloat(const StructFloat& paramFloat) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the StructInterface implementation.
    * @param paramString 
    */
    virtual void publishSigString(const StructString& paramString) const = 0;
};


} // namespace Testbed1
} // namespace Test

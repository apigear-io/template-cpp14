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

class IStructArrayInterfaceSubscriber;
class IStructArrayInterfacePublisher;

/**
*
* IStructArrayInterface provides an interface for
 *  - methods defined for your StructArrayInterface 
 *  - proeperty setters and getters for defined properties
 * The IStructArrayInterface also providess an interface to access a publisher IStructArrayInterfacePublisher, a class used by IStructArrayInterfaceSubscriber clients.
 * The implementation should notify the publisher IStructArrayInterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also IStructArrayInterfaceSubscriber, IStructArrayInterfacePublisher
 * and the exmaple implementation StructArrayInterface  or the
 */
class TEST_TESTBED1_EXPORT IStructArrayInterface
{
public:
    virtual ~IStructArrayInterface() = default;


    virtual StructBool funcBool(const std::list<StructBool>& paramBool) = 0;
    /**
    * Asynchronous version of funcBool(const std::list<StructBool>& paramBool)
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) = 0;


    virtual StructBool funcInt(const std::list<StructInt>& paramInt) = 0;
    /**
    * Asynchronous version of funcInt(const std::list<StructInt>& paramInt)
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) = 0;


    virtual StructBool funcFloat(const std::list<StructFloat>& paramFloat) = 0;
    /**
    * Asynchronous version of funcFloat(const std::list<StructFloat>& paramFloat)
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) = 0;


    virtual StructBool funcString(const std::list<StructString>& paramString) = 0;
    /**
    * Asynchronous version of funcString(const std::list<StructString>& paramString)
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) = 0;

    /**
    * Sets the value of the propBool property.
    */
    virtual void setPropbool(const std::list<StructBool>& propBool) = 0;
    /**
    * Gets the value of the propBool property.
    */
    virtual const std::list<StructBool>& propBool() const = 0;

    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropint(const std::list<StructInt>& propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual const std::list<StructInt>& propInt() const = 0;

    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropfloat(const std::list<StructFloat>& propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual const std::list<StructFloat>& propFloat() const = 0;

    /**
    * Sets the value of the propString property.
    */
    virtual void setPropstring(const std::list<StructString>& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual const std::list<StructString>& propString() const = 0;

    /**
    * @return Publisher class IStructArrayInterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual IStructArrayInterfacePublisher& _getPublisher() const = 0;
};


/**
 * The IStructArrayInterfaceSubscriber contains functions to allow informing about singals or property changes of the IStructArrayInterface implementation.
 * The implementation for IStructArrayInterface should provide mechanism for subscibtion of the IStructArrayInterfaceSubscriber clients.
 * The implementation for IStructArrayInterface should call the IStructArrayInterfaceSubscriber interface functions on either singal emit or property change.
 * See IStructArrayInterfacePublisher, which provides facititation for this purpose.
 * You can use IStructArrayInterfaceSubscriber class to implement clients of the IStructArrayInterface or the network adapter - see Olink Server and Client example.
 */
class TEST_TESTBED1_EXPORT IStructArrayInterfaceSubscriber
{
public:
    /**
    * Called by the IStructArrayInterfacePublisher when the StructArrayInterface emits sigBool, if subscribed for the sigBool.
    * @param paramBool 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigBool(const std::list<StructBool>& paramBool) = 0;
    /**
    * Called by the IStructArrayInterfacePublisher when the StructArrayInterface emits sigInt, if subscribed for the sigInt.
    * @param paramInt 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigInt(const std::list<StructInt>& paramInt) = 0;
    /**
    * Called by the IStructArrayInterfacePublisher when the StructArrayInterface emits sigFloat, if subscribed for the sigFloat.
    * @param paramFloat 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigFloat(const std::list<StructFloat>& paramFloat) = 0;
    /**
    * Called by the IStructArrayInterfacePublisher when the StructArrayInterface emits sigString, if subscribed for the sigString.
    * @param paramString 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigString(const std::list<StructString>& paramString) = 0;
    /**
    * Called by the IStructArrayInterfacePublisher when propBool value has changed if subscribed for the propBool change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropBoolChanged(const std::list<StructBool>& propBool) = 0;
    /**
    * Called by the IStructArrayInterfacePublisher when propInt value has changed if subscribed for the propInt change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropIntChanged(const std::list<StructInt>& propInt) = 0;
    /**
    * Called by the IStructArrayInterfacePublisher when propFloat value has changed if subscribed for the propFloat change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropFloatChanged(const std::list<StructFloat>& propFloat) = 0;
    /**
    * Called by the IStructArrayInterfacePublisher when propString value has changed if subscribed for the propString change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropStringChanged(const std::list<StructString>& propString) = 0;
};

/** Callback for changes of propBool */
using StructArrayInterfacePropBoolPropertyCb = std::function<void(const std::list<StructBool>& propBool)>;
/** Callback for changes of propInt */
using StructArrayInterfacePropIntPropertyCb = std::function<void(const std::list<StructInt>& propInt)>;
/** Callback for changes of propFloat */
using StructArrayInterfacePropFloatPropertyCb = std::function<void(const std::list<StructFloat>& propFloat)>;
/** Callback for changes of propString */
using StructArrayInterfacePropStringPropertyCb = std::function<void(const std::list<StructString>& propString)>;
/** Callback for sigBool signal triggers */
using StructArrayInterfaceSigBoolSignalCb = std::function<void(const std::list<StructBool>& paramBool)> ;
/** Callback for sigInt signal triggers */
using StructArrayInterfaceSigIntSignalCb = std::function<void(const std::list<StructInt>& paramInt)> ;
/** Callback for sigFloat signal triggers */
using StructArrayInterfaceSigFloatSignalCb = std::function<void(const std::list<StructFloat>& paramFloat)> ;
/** Callback for sigString signal triggers */
using StructArrayInterfaceSigStringSignalCb = std::function<void(const std::list<StructString>& paramString)> ;


/**
 * The IStructArrayInterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emision 
 * or a property change.
 * Implement this interface to keep track of clients of your IStructArrayInterface implementation.
 * The second part of the IStructArrayInterfacePublisher interface is the notification interface.
 * It needs to be called by implementation of the IStructArrayInterface on each state changed or signal emited
 * and shall notify all the subscribers about this change.
 */
class TEST_TESTBED1_EXPORT IStructArrayInterfacePublisher
{
public:
    virtual ~IStructArrayInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the StructArrayInterface.
    * Subscriber will be informed of any emited signal and any property changes.
    * @param IStructArrayInterfaceSubscriber which is subscribed in this function to any change of the StructArrayInterface.
    */
    virtual void subscribeToStructArrayInterfaceChanges(IStructArrayInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the StructArrayInterface.
    * All the subscriptions will be removed, including ones made deparately for single singal or property change.
    * @param IStructArrayInterfaceSubscriber which subscription for any change of the StructArrayInterface is removed.
    */
    virtual void unsubscribeFromStructArrayInterfaceChanges(IStructArrayInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for propBool value changes.
    * @param StructArrayInterfacePropBoolPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propBool property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropBoolChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propInt value changes.
    * @param StructArrayInterfacePropIntPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propInt property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropIntChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propFloat value changes.
    * @param StructArrayInterfacePropFloatPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propFloat property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropFloatChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propString value changes.
    * @param StructArrayInterfacePropStringPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propString property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropStringChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for sigBool signal changes.
    * @param StructArrayInterfaceSigBoolSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigBool signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigBool(long handleId) = 0;

    /**
    * Use this function to subscribe for sigInt signal changes.
    * @param StructArrayInterfaceSigIntSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigInt signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigInt(long handleId) = 0;

    /**
    * Use this function to subscribe for sigFloat signal changes.
    * @param StructArrayInterfaceSigFloatSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigFloat signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigFloat(long handleId) = 0;

    /**
    * Use this function to subscribe for sigString signal changes.
    * @param StructArrayInterfaceSigStringSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigString signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigString(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.Invoked by the StructArrayInterface implementation.
    * @param The new value of propBool.
    */
    virtual void publishPropBoolChanged(const std::list<StructBool>& propBool) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the StructArrayInterface implementation.
    * @param The new value of propInt.
    */
    virtual void publishPropIntChanged(const std::list<StructInt>& propInt) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the StructArrayInterface implementation.
    * @param The new value of propFloat.
    */
    virtual void publishPropFloatChanged(const std::list<StructFloat>& propFloat) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the StructArrayInterface implementation.
    * @param The new value of propString.
    */
    virtual void publishPropStringChanged(const std::list<StructString>& propString) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the StructArrayInterface implementation.
    * @param paramBool 
    */
    virtual void publishSigBool(const std::list<StructBool>& paramBool) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the StructArrayInterface implementation.
    * @param paramInt 
    */
    virtual void publishSigInt(const std::list<StructInt>& paramInt) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the StructArrayInterface implementation.
    * @param paramFloat 
    */
    virtual void publishSigFloat(const std::list<StructFloat>& paramFloat) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the StructArrayInterface implementation.
    * @param paramString 
    */
    virtual void publishSigString(const std::list<StructString>& paramString) const = 0;
};


} // namespace Testbed1
} // namespace Test

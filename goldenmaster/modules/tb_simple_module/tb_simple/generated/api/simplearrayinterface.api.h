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
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/datastructs.api.h"

namespace Test {
namespace TbSimple {

class ISimpleArrayInterfaceSubscriber;
class ISimpleArrayInterfacePublisher;

/**
*
* ISimpleArrayInterface provides an interface for
 *  - methods defined for your SimpleArrayInterface 
 *  - proeperty setters and getters for defined properties
 * The ISimpleArrayInterface also providess an interface to access a publisher ISimpleArrayInterfacePublisher, a class used by ISimpleArrayInterfaceSubscriber clients.
 * The implementation should notify the publisher ISimpleArrayInterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also ISimpleArrayInterfaceSubscriber, ISimpleArrayInterfacePublisher
 * and the exmaple implementation SimpleArrayInterface  or the
 */
class TEST_TB_SIMPLE_EXPORT ISimpleArrayInterface
{
public:
    virtual ~ISimpleArrayInterface() = default;


    virtual std::list<bool> funcBool(const std::list<bool>& paramBool) = 0;
    /**
    * Asynchronous version of funcBool(const std::list<bool>& paramBool)
    * @return Promise of type std::list<bool> which is set once the function has completed
    */
    virtual std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) = 0;


    virtual std::list<int> funcInt(const std::list<int>& paramInt) = 0;
    /**
    * Asynchronous version of funcInt(const std::list<int>& paramInt)
    * @return Promise of type std::list<int> which is set once the function has completed
    */
    virtual std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) = 0;


    virtual std::list<float> funcFloat(const std::list<float>& paramFloat) = 0;
    /**
    * Asynchronous version of funcFloat(const std::list<float>& paramFloat)
    * @return Promise of type std::list<float> which is set once the function has completed
    */
    virtual std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) = 0;


    virtual std::list<std::string> funcString(const std::list<std::string>& paramString) = 0;
    /**
    * Asynchronous version of funcString(const std::list<std::string>& paramString)
    * @return Promise of type std::list<std::string> which is set once the function has completed
    */
    virtual std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) = 0;

    /**
    * Sets the value of the propBool property.
    */
    virtual void setPropbool(const std::list<bool>& propBool) = 0;
    /**
    * Gets the value of the propBool property.
    */
    virtual const std::list<bool>& propBool() const = 0;

    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropint(const std::list<int>& propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual const std::list<int>& propInt() const = 0;

    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropfloat(const std::list<float>& propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual const std::list<float>& propFloat() const = 0;

    /**
    * Sets the value of the propString property.
    */
    virtual void setPropstring(const std::list<std::string>& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual const std::list<std::string>& propString() const = 0;

    /**
    * @return Publisher class ISimpleArrayInterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual ISimpleArrayInterfacePublisher& _getPublisher() const = 0;
};


/**
 * The ISimpleArrayInterfaceSubscriber contains functions to allow informing about singals or property changes of the ISimpleArrayInterface implementation.
 * The implementation for ISimpleArrayInterface should provide mechanism for subscibtion of the ISimpleArrayInterfaceSubscriber clients.
 * The implementation for ISimpleArrayInterface should call the ISimpleArrayInterfaceSubscriber interface functions on either singal emit or property change.
 * See ISimpleArrayInterfacePublisher, which provides facititation for this purpose.
 * You can use ISimpleArrayInterfaceSubscriber class to implement clients of the ISimpleArrayInterface or the network adapter - see Olink Server and Client example.
 */
class TEST_TB_SIMPLE_EXPORT ISimpleArrayInterfaceSubscriber
{
public:
    /**
    * Called by the ISimpleArrayInterfacePublisher when the SimpleArrayInterface emits sigBool, if subscribed for the sigBool.
    * @param paramBool 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigBool(const std::list<bool>& paramBool) = 0;
    /**
    * Called by the ISimpleArrayInterfacePublisher when the SimpleArrayInterface emits sigInt, if subscribed for the sigInt.
    * @param paramInt 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigInt(const std::list<int>& paramInt) = 0;
    /**
    * Called by the ISimpleArrayInterfacePublisher when the SimpleArrayInterface emits sigFloat, if subscribed for the sigFloat.
    * @param paramFloat 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigFloat(const std::list<float>& paramFloat) = 0;
    /**
    * Called by the ISimpleArrayInterfacePublisher when the SimpleArrayInterface emits sigString, if subscribed for the sigString.
    * @param paramString 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigString(const std::list<std::string>& paramString) = 0;
    /**
    * Called by the ISimpleArrayInterfacePublisher when propBool value has changed if subscribed for the propBool change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropBoolChanged(const std::list<bool>& propBool) = 0;
    /**
    * Called by the ISimpleArrayInterfacePublisher when propInt value has changed if subscribed for the propInt change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropIntChanged(const std::list<int>& propInt) = 0;
    /**
    * Called by the ISimpleArrayInterfacePublisher when propFloat value has changed if subscribed for the propFloat change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropFloatChanged(const std::list<float>& propFloat) = 0;
    /**
    * Called by the ISimpleArrayInterfacePublisher when propString value has changed if subscribed for the propString change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropStringChanged(const std::list<std::string>& propString) = 0;
};

/** Callback for changes of propBool */
using SimpleArrayInterfacePropBoolPropertyCb = std::function<void(const std::list<bool>& propBool)>;
/** Callback for changes of propInt */
using SimpleArrayInterfacePropIntPropertyCb = std::function<void(const std::list<int>& propInt)>;
/** Callback for changes of propFloat */
using SimpleArrayInterfacePropFloatPropertyCb = std::function<void(const std::list<float>& propFloat)>;
/** Callback for changes of propString */
using SimpleArrayInterfacePropStringPropertyCb = std::function<void(const std::list<std::string>& propString)>;
/** Callback for sigBool signal triggers */
using SimpleArrayInterfaceSigBoolSignalCb = std::function<void(const std::list<bool>& paramBool)> ;
/** Callback for sigInt signal triggers */
using SimpleArrayInterfaceSigIntSignalCb = std::function<void(const std::list<int>& paramInt)> ;
/** Callback for sigFloat signal triggers */
using SimpleArrayInterfaceSigFloatSignalCb = std::function<void(const std::list<float>& paramFloat)> ;
/** Callback for sigString signal triggers */
using SimpleArrayInterfaceSigStringSignalCb = std::function<void(const std::list<std::string>& paramString)> ;


/**
 * The ISimpleArrayInterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emision 
 * or a property change.
 * Implement this interface to keep track of clients of your ISimpleArrayInterface implementation.
 * The second part of the ISimpleArrayInterfacePublisher interface is the notification interface.
 * It needs to be called by implementation of the ISimpleArrayInterface on each state changed or signal emited
 * and shall notify all the subscribers about this change.
 */
class TEST_TB_SIMPLE_EXPORT ISimpleArrayInterfacePublisher
{
public:
    virtual ~ISimpleArrayInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the SimpleArrayInterface.
    * Subscriber will be informed of any emited signal and any property changes.
    * @param ISimpleArrayInterfaceSubscriber which is subscribed in this function to any change of the SimpleArrayInterface.
    */
    virtual void subscribeToSimpleArrayInterfaceChanges(ISimpleArrayInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the SimpleArrayInterface.
    * All the subscriptions will be removed, including ones made deparately for single singal or property change.
    * @param ISimpleArrayInterfaceSubscriber which subscription for any change of the SimpleArrayInterface is removed.
    */
    virtual void unsubscribeFromSimpleArrayInterfaceChanges(ISimpleArrayInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for propBool value changes.
    * @param SimpleArrayInterfacePropBoolPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propBool property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropBoolChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propInt value changes.
    * @param SimpleArrayInterfacePropIntPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propInt property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropIntChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propFloat value changes.
    * @param SimpleArrayInterfacePropFloatPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propFloat property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropFloatChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propString value changes.
    * @param SimpleArrayInterfacePropStringPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propString property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropStringChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for sigBool signal changes.
    * @param SimpleArrayInterfaceSigBoolSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigBool signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigBool(long handleId) = 0;

    /**
    * Use this function to subscribe for sigInt signal changes.
    * @param SimpleArrayInterfaceSigIntSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigInt signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigInt(long handleId) = 0;

    /**
    * Use this function to subscribe for sigFloat signal changes.
    * @param SimpleArrayInterfaceSigFloatSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigFloat signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigFloat(long handleId) = 0;

    /**
    * Use this function to subscribe for sigString signal changes.
    * @param SimpleArrayInterfaceSigStringSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigString signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigString(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SimpleArrayInterface implementation.
    * @param The new value of propBool.
    */
    virtual void publishPropBoolChanged(const std::list<bool>& propBool) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SimpleArrayInterface implementation.
    * @param The new value of propInt.
    */
    virtual void publishPropIntChanged(const std::list<int>& propInt) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SimpleArrayInterface implementation.
    * @param The new value of propFloat.
    */
    virtual void publishPropFloatChanged(const std::list<float>& propFloat) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SimpleArrayInterface implementation.
    * @param The new value of propString.
    */
    virtual void publishPropStringChanged(const std::list<std::string>& propString) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SimpleArrayInterface implementation.
    * @param paramBool 
    */
    virtual void publishSigBool(const std::list<bool>& paramBool) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SimpleArrayInterface implementation.
    * @param paramInt 
    */
    virtual void publishSigInt(const std::list<int>& paramInt) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SimpleArrayInterface implementation.
    * @param paramFloat 
    */
    virtual void publishSigFloat(const std::list<float>& paramFloat) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SimpleArrayInterface implementation.
    * @param paramString 
    */
    virtual void publishSigString(const std::list<std::string>& paramString) const = 0;
};


} // namespace TbSimple
} // namespace Test

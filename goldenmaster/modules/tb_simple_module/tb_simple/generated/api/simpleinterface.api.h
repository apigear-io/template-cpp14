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

class ISimpleInterfaceSubscriber;
class ISimpleInterfacePublisher;

/**
*
* ISimpleInterface provides an interface for
 *  - methods defined for your SimpleInterface 
 *  - proeperty setters and getters for defined properties
 * The ISimpleInterface also providess an interface to access a publisher ISimpleInterfacePublisher, a class used by ISimpleInterfaceSubscriber clients.
 * The implementation should notify the publisher ISimpleInterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also ISimpleInterfaceSubscriber, ISimpleInterfacePublisher
 * and the exmaple implementation SimpleInterface  or the
 */
class TEST_TB_SIMPLE_EXPORT ISimpleInterface
{
public:
    virtual ~ISimpleInterface() = default;


    virtual bool funcBool(bool paramBool) = 0;
    /**
    * Asynchronous version of funcBool(bool paramBool)
    * @return Promise of type bool which is set once the function has completed
    */
    virtual std::future<bool> funcBoolAsync(bool paramBool) = 0;


    virtual int funcInt(int paramInt) = 0;
    /**
    * Asynchronous version of funcInt(int paramInt)
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> funcIntAsync(int paramInt) = 0;


    virtual float funcFloat(float paramFloat) = 0;
    /**
    * Asynchronous version of funcFloat(float paramFloat)
    * @return Promise of type float which is set once the function has completed
    */
    virtual std::future<float> funcFloatAsync(float paramFloat) = 0;


    virtual std::string funcString(const std::string& paramString) = 0;
    /**
    * Asynchronous version of funcString(const std::string& paramString)
    * @return Promise of type std::string which is set once the function has completed
    */
    virtual std::future<std::string> funcStringAsync(const std::string& paramString) = 0;

    /**
    * Sets the value of the propBool property.
    */
    virtual void setPropbool(bool propBool) = 0;
    /**
    * Gets the value of the propBool property.
    */
    virtual bool propBool() const = 0;

    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropint(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;

    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropfloat(float propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual float propFloat() const = 0;

    /**
    * Sets the value of the propString property.
    */
    virtual void setPropstring(const std::string& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual std::string propString() const = 0;

    /**
    * @return Publisher class ISimpleInterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual ISimpleInterfacePublisher& _getPublisher() const = 0;
};


/**
 * The ISimpleInterfaceSubscriber contains functions to allow informing about singals or property changes of the ISimpleInterface implementation.
 * The implementation for ISimpleInterface should provide mechanism for subscibtion of the ISimpleInterfaceSubscriber clients.
 * The implementation for ISimpleInterface should call the ISimpleInterfaceSubscriber interface functions on either singal emit or property change.
 * See ISimpleInterfacePublisher, which provides facititation for this purpose.
 * You can use ISimpleInterfaceSubscriber class to implement clients of the ISimpleInterface or the network adapter - see Olink Server and Client example.
 */
class TEST_TB_SIMPLE_EXPORT ISimpleInterfaceSubscriber
{
public:
    /**
    * Called by the ISimpleInterfacePublisher when the SimpleInterface emits sigBool, if subscribed for the sigBool.
    * @param paramBool 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigBool(bool paramBool) = 0;
    /**
    * Called by the ISimpleInterfacePublisher when the SimpleInterface emits sigInt, if subscribed for the sigInt.
    * @param paramInt 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigInt(int paramInt) = 0;
    /**
    * Called by the ISimpleInterfacePublisher when the SimpleInterface emits sigFloat, if subscribed for the sigFloat.
    * @param paramFloat 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigFloat(float paramFloat) = 0;
    /**
    * Called by the ISimpleInterfacePublisher when the SimpleInterface emits sigString, if subscribed for the sigString.
    * @param paramString 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSigString(const std::string& paramString) = 0;
    /**
    * Called by the ISimpleInterfacePublisher when propBool value has changed if subscribed for the propBool change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropBoolChanged(bool propBool) = 0;
    /**
    * Called by the ISimpleInterfacePublisher when propInt value has changed if subscribed for the propInt change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropIntChanged(int propInt) = 0;
    /**
    * Called by the ISimpleInterfacePublisher when propFloat value has changed if subscribed for the propFloat change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropFloatChanged(float propFloat) = 0;
    /**
    * Called by the ISimpleInterfacePublisher when propString value has changed if subscribed for the propString change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropStringChanged(std::string propString) = 0;
};

/** Callback for changes of propBool */
using SimpleInterfacePropBoolPropertyCb = std::function<void(bool propBool)>;
/** Callback for changes of propInt */
using SimpleInterfacePropIntPropertyCb = std::function<void(int propInt)>;
/** Callback for changes of propFloat */
using SimpleInterfacePropFloatPropertyCb = std::function<void(float propFloat)>;
/** Callback for changes of propString */
using SimpleInterfacePropStringPropertyCb = std::function<void(const std::string& propString)>;
/** Callback for sigBool signal triggers */
using SimpleInterfaceSigBoolSignalCb = std::function<void(bool paramBool)> ;
/** Callback for sigInt signal triggers */
using SimpleInterfaceSigIntSignalCb = std::function<void(int paramInt)> ;
/** Callback for sigFloat signal triggers */
using SimpleInterfaceSigFloatSignalCb = std::function<void(float paramFloat)> ;
/** Callback for sigString signal triggers */
using SimpleInterfaceSigStringSignalCb = std::function<void(const std::string& paramString)> ;


/**
 * The ISimpleInterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emision 
 * or a property change.
 * Implement this interface to keep track of clients of your ISimpleInterface implementation.
 * The second part of the ISimpleInterfacePublisher interface is the notification interface.
 * It needs to be called by implementation of the ISimpleInterface on each state changed or signal emited
 * and shall notify all the subscribers about this change.
 */
class TEST_TB_SIMPLE_EXPORT ISimpleInterfacePublisher
{
public:
    virtual ~ISimpleInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the SimpleInterface.
    * Subscriber will be informed of any emited signal and any property changes.
    * @param ISimpleInterfaceSubscriber which is subscribed in this function to any change of the SimpleInterface.
    */
    virtual void subscribeToSimpleInterfaceChanges(ISimpleInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the SimpleInterface.
    * All the subscriptions will be removed, including ones made deparately for single singal or property change.
    * @param ISimpleInterfaceSubscriber which subscription for any change of the SimpleInterface is removed.
    */
    virtual void unsubscribeFromSimpleInterfaceChanges(ISimpleInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for propBool value changes.
    * @param SimpleInterfacePropBoolPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propBool property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropBoolChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propInt value changes.
    * @param SimpleInterfacePropIntPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propInt property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropIntChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propFloat value changes.
    * @param SimpleInterfacePropFloatPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propFloat property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropFloatChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propString value changes.
    * @param SimpleInterfacePropStringPropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propString property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromPropStringChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for sigBool signal changes.
    * @param SimpleInterfaceSigBoolSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigBool signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigBool(long handleId) = 0;

    /**
    * Use this function to subscribe for sigInt signal changes.
    * @param SimpleInterfaceSigIntSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigInt signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigInt(long handleId) = 0;

    /**
    * Use this function to subscribe for sigFloat signal changes.
    * @param SimpleInterfaceSigFloatSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigFloat signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigFloat(long handleId) = 0;

    /**
    * Use this function to subscribe for sigString signal changes.
    * @param SimpleInterfaceSigStringSignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSigString(SimpleInterfaceSigStringSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigString signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSigString(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SimpleInterface implementation.
    * @param The new value of propBool.
    */
    virtual void publishPropBoolChanged(bool propBool) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SimpleInterface implementation.
    * @param The new value of propInt.
    */
    virtual void publishPropIntChanged(int propInt) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SimpleInterface implementation.
    * @param The new value of propFloat.
    */
    virtual void publishPropFloatChanged(float propFloat) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SimpleInterface implementation.
    * @param The new value of propString.
    */
    virtual void publishPropStringChanged(const std::string& propString) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SimpleInterface implementation.
    * @param paramBool 
    */
    virtual void publishSigBool(bool paramBool) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SimpleInterface implementation.
    * @param paramInt 
    */
    virtual void publishSigInt(int paramInt) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SimpleInterface implementation.
    * @param paramFloat 
    */
    virtual void publishSigFloat(float paramFloat) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SimpleInterface implementation.
    * @param paramString 
    */
    virtual void publishSigString(const std::string& paramString) const = 0;
};


} // namespace TbSimple
} // namespace Test

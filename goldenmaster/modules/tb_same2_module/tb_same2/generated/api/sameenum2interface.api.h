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

class ISameEnum2InterfaceSubscriber;
class ISameEnum2InterfacePublisher;

/**
*
* ISameEnum2Interface provides an interface for
 *  - methods defined for your SameEnum2Interface 
 *  - proeperty setters and getters for defined properties
 * The ISameEnum2Interface also providess an interface to access a publisher ISameEnum2InterfacePublisher, a class used by ISameEnum2InterfaceSubscriber clients.
 * The implementation should notify the publisher ISameEnum2InterfacePublisher about emited signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also ISameEnum2InterfaceSubscriber, ISameEnum2InterfacePublisher
 * and the exmaple implementation SameEnum2Interface  or the
 */
class TEST_TB_SAME2_EXPORT ISameEnum2Interface
{
public:
    virtual ~ISameEnum2Interface() = default;


    virtual Enum1Enum func1(const Enum1Enum& param1) = 0;
    /**
    * Asynchronous version of func1(const Enum1Enum& param1)
    * @return Promise of type Enum1Enum which is set once the function has completed
    */
    virtual std::future<Enum1Enum> func1Async(const Enum1Enum& param1) = 0;


    virtual Enum1Enum func2(const Enum1Enum& param1, const Enum2Enum& param2) = 0;
    /**
    * Asynchronous version of func2(const Enum1Enum& param1, const Enum2Enum& param2)
    * @return Promise of type Enum1Enum which is set once the function has completed
    */
    virtual std::future<Enum1Enum> func2Async(const Enum1Enum& param1, const Enum2Enum& param2) = 0;

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
    * @return Publisher class ISameEnum2InterfacePublisher responsible for clients subscribtion and notification.
    */
    virtual ISameEnum2InterfacePublisher& _getPublisher() const = 0;
};


/**
 * The ISameEnum2InterfaceSubscriber contains functions to allow informing about singals or property changes of the ISameEnum2Interface implementation.
 * The implementation for ISameEnum2Interface should provide mechanism for subscibtion of the ISameEnum2InterfaceSubscriber clients.
 * The implementation for ISameEnum2Interface should call the ISameEnum2InterfaceSubscriber interface functions on either singal emit or property change.
 * See ISameEnum2InterfacePublisher, which provides facititation for this purpose.
 * You can use ISameEnum2InterfaceSubscriber class to implement clients of the ISameEnum2Interface or the network adapter - see Olink Server and Client example.
 */
class TEST_TB_SAME2_EXPORT ISameEnum2InterfaceSubscriber
{
public:
    /**
    * Called by the ISameEnum2InterfacePublisher when the SameEnum2Interface emits sig1, if subscribed for the sig1.
    * @param param1 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig1(const Enum1Enum& param1) = 0;
    /**
    * Called by the ISameEnum2InterfacePublisher when the SameEnum2Interface emits sig2, if subscribed for the sig2.
    * @param param1 
    * @param param2 
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnSig2(const Enum1Enum& param1,const Enum2Enum& param2) = 0;
    /**
    * Called by the ISameEnum2InterfacePublisher when prop1 value has changed if subscribed for the prop1 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const Enum1Enum& prop1) = 0;
    /**
    * Called by the ISameEnum2InterfacePublisher when prop2 value has changed if subscribed for the prop2 change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp2Changed(const Enum2Enum& prop2) = 0;
};

/** Callback for changes of prop1 */
using SameEnum2InterfaceProp1PropertyCb = std::function<void(const Enum1Enum& prop1)>;
/** Callback for changes of prop2 */
using SameEnum2InterfaceProp2PropertyCb = std::function<void(const Enum2Enum& prop2)>;
/** Callback for sig1 signal triggers */
using SameEnum2InterfaceSig1SignalCb = std::function<void(const Enum1Enum& param1)> ;
/** Callback for sig2 signal triggers */
using SameEnum2InterfaceSig2SignalCb = std::function<void(const Enum1Enum& param1,const Enum2Enum& param2)> ;


/**
 * The ISameEnum2InterfacePublisher provides an api for clients to subscribe to or unsubscribe from a signal emision 
 * or a property change.
 * Implement this interface to keep track of clients of your ISameEnum2Interface implementation.
 * The second part of the ISameEnum2InterfacePublisher interface is the notification interface.
 * It needs to be called by implementation of the ISameEnum2Interface on each state changed or signal emited
 * and shall notify all the subscribers about this change.
 */
class TEST_TB_SAME2_EXPORT ISameEnum2InterfacePublisher
{
public:
    virtual ~ISameEnum2InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any change of the SameEnum2Interface.
    * Subscriber will be informed of any emited signal and any property changes.
    * @param ISameEnum2InterfaceSubscriber which is subscribed in this function to any change of the SameEnum2Interface.
    */
    virtual void subscribeToSameEnum2InterfaceChanges(ISameEnum2InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the SameEnum2Interface.
    * All the subscriptions will be removed, including ones made deparately for single singal or property change.
    * @param ISameEnum2InterfaceSubscriber which subscription for any change of the SameEnum2Interface is removed.
    */
    virtual void unsubscribeFromSameEnum2InterfaceChanges(ISameEnum2InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    * @param SameEnum2InterfaceProp1PropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp1Changed(SameEnum2InterfaceProp1PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop1 property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp1Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop2 value changes.
    * @param SameEnum2InterfaceProp2PropertyCb callback that will be executed on each change of the property.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToProp2Changed(SameEnum2InterfaceProp2PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop2 property changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromProp2Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    * @param SameEnum2InterfaceSig1SignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig1(SameEnum2InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    * @param SameEnum2InterfaceSig2SignalCb callback that will be executed on each signal emision.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSig2(SameEnum2InterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SameEnum2Interface implementation.
    * @param The new value of prop1.
    */
    virtual void publishProp1Changed(const Enum1Enum& prop1) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.Invoked by the SameEnum2Interface implementation.
    * @param The new value of prop2.
    */
    virtual void publishProp2Changed(const Enum2Enum& prop2) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SameEnum2Interface implementation.
    * @param param1 
    */
    virtual void publishSig1(const Enum1Enum& param1) const = 0;
    /**
    * Publishes the emited singal to all subscribed clients. Invoked by the SameEnum2Interface implementation.
    * @param param1 
    * @param param2 
    */
    virtual void publishSig2(const Enum1Enum& param1,const Enum2Enum& param2) const = 0;
};


} // namespace TbSame2
} // namespace Test

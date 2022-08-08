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

#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"

#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

#include <future>
#include <memory>

namespace Test {
namespace TbSame1 {

/**
* Remote SameEnum1Interface implemented with OLink. 
* Handles connnectionn with SameEnum1Interface service.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
* Use on client side to request changes of the SameEnum1Interface on the server side 
* and to subscribe for the SameEnum1Interface changes.
*/
class TEST_TB_SAME1_EXPORT RemoteSameEnum1Interface : public ISameEnum1Interface, public ApiGear::ObjectLink::IObjectSink
{
public:

/**
* ctor
* @param registry The global registry with the sinks and client nodes.
* @param client that holds the socket, manages the connection and provides ClientNode
*   which is an abstraction layer between the Client and RemoteSameEnum1Interface.
*/
    explicit RemoteSameEnum1Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~RemoteSameEnum1Interface() override;
    /**
    * Property getter
    * @return Locally stored value for Prop1.
    */
    const Enum1Enum& prop1() const override;
    /**
    * Request setting a property on the SameEnum1Interface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(const Enum1Enum& prop1) override;
    /**
    * Remote call of ISameEnum1Interface::func1 on the SameEnum1Interface service.
    * Uses func1Async
    */
    Enum1Enum func1(const Enum1Enum& param1) override;
    /**
    * Remote call of ISameEnum1Interface::func1 on the SameEnum1Interface service.
    */
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;

    /** The publisher to subscribe to. */
    ISameEnum1InterfacePublisher& _getPublisher() const override;
    
    /**
    * Informs if the connection is established and the remote interface is operable.
    * @return true if remote interface is operable, false otherwise.
    */
    bool isReady() const;

    /**
    * The name of the object for which this sink is created, object on server side has to have the same name.
    * It serves as an identifier for the client registry, it has to be uniqe for the pair sink object - client node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;
    
    /**
    * Forwards information about singal emition to publisher.
    * @param name The name of the emited signal.
    * @param args The arguments for the signal.
    */
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    
    /**
    * Forwards information about the property with the object name to publisher and updates local state.
    * @param name The name of the emited signal.
    * @param args The arguments for the signal.
    */
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    
    /** Informs this object sink that connetion was is established.
    * @param name The name of the object for which link was established.
    * @param props Initial values obtained from the SameEnum1Interface service
    * @param the initialized link endpoint for this sink.
    */
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    /**
    * Informs this objec source that the link was disconnected and cannot be used anymore.
    * WARNING DOROTA: it is never called.
    */
    void olinkOnRelease() override;

private:
    /**
    * Applies recived data to local state and publishes changes to subscribers.
    * @param the data recived from SameEnum1Interface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for Prop1 and informs subscriber about the change*/
    void setProp1Local(const Enum1Enum& prop1);
    Enum1Enum m_prop1;
    /**
    * An Olink client node used to connect with a Olink SameEnum1Interface service for object given with olinkObjectName() .
    * An abstraction layer over the socket for the RemoteSameEnum1Interface.
    * WARNING DOROTA if there's a sink already in registry for same name, it is silently disconnected, without the informing
    * it may send requests as long as the pointer to node is valid, but will not receive any data the isReady will not tell the true.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /** 
    * Registry linking client nodes with sinks for the olinkObjectName().
    * The registerd olinkObjects name must be unique.  
    */
    ApiGear::ObjectLink::ClientRegistry& m_registry;
    /** The publisher for SameEnum1Interface */
    std::unique_ptr<ISameEnum1InterfacePublisher> m_publisher;
};
} // namespace TbSame1
} // namespace Test

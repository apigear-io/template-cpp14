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

#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "olink/remotenode.h"

namespace Test {
namespace TbSame2 {

/**
* Server side for SameStruct1Interface implements the SameStruct1Interface service.
* It is a source of data for SameStruct1Interface clients.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
*/
class TEST_TB_SAME2_EXPORT SameStruct1InterfaceService : public ApiGear::ObjectLink::IObjectSource, public ISameStruct1InterfaceSubscriber
{
public:
    /**
    * ctor
    * @param SameStruct1Interface The service source object, the actual SameStruct1Interface object which is exposed for remote clients with olink.
    * @param registry The global registry that keeps track of the object source services associated with network nodes.
    */
    explicit SameStruct1InterfaceService(ISameStruct1Interface& SameStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~SameStruct1InterfaceService() override;

    /**
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be uniqe for the pair source object - remote node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;
    /**
    * Applies recived method invocation with given arguments on the SameStruct1Interface object.
    * @param name Path of the method to invoke. Contains object name and the method name.
    * @param args Arguments required to invoke a method in json format.
    * @return the result of the invoked method (if applicable) that needs to be sent back to the clients.
    */
    nlohmann::json olinkInvoke(std::string name, nlohmann::json args) override;
    /**
    * Applies recived change property request to SameStruct1Interface object.
    * @param name Path the property to change. Contains object name and the property name.
    * @param args Value in json format requested to set for the property.
    */
    void olinkSetProperty(std::string name, nlohmann::json value) override;
    /**
    * Informs this service source that the link was established.
    * @param name The name of the object for which link was established.
    * @param the initialized link endpoint.
    */
    void olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) override;
    /**
    * Informs this service source that the link was disconnected and cannot be used anymore.
    */
    void olinkUnlinked(std::string name) override;

    /**
    * Gets the current state of SameStruct1Interface object.
    * @return the set of properties with their current vlues for the SameStruct1Interface object in json format.
    */
    nlohmann::json olinkCollectProperties() override;
    /**
    * Forwards emited sig1 through network if the connection is established.
    */
    void OnSig1(const Struct1& param1) override;
    /**
    * Forwards prop1 change through network if the connection is established.
    */
    void OnProp1Changed(const Struct1& Value) override;

private:
    /**
    * The SameStruct1Interface used for object source.
    */
    ISameStruct1Interface& m_SameStruct1Interface;
    /**
    * The abstraction over the network layer for this object source.
    */
    ApiGear::ObjectLink::IRemoteNode* m_node;
    /**
    * A global registry that keeps track of object sources associated with their network layer nodes.
    */
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
};
} // namespace TbSame2
} // namespace Test

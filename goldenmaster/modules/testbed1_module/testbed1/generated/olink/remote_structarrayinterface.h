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

#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"

#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

#include <future>
#include <memory>

namespace Test {
namespace Testbed1 {

/**
* Remote StructArrayInterface implemented with OLink. 
* Handles connnectionn with StructArrayInterface service.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
* Use on client side to request changes of the StructArrayInterface on the server side 
* and to subscribe for the StructArrayInterface changes.
*/
class TEST_TESTBED1_EXPORT RemoteStructArrayInterface : public IStructArrayInterface, public ApiGear::ObjectLink::IObjectSink
{
public:

/**
* ctor
* @param registry The global registry with the sinks and client nodes.
* @param client that holds the socket, manages the connection and provides ClientNode
*   which is an abstraction layer between the Client and RemoteStructArrayInterface.
*/
    explicit RemoteStructArrayInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~RemoteStructArrayInterface() override;
    /**
    * Property getter
    * @return Locally stored value for Propbool.
    */
    const std::list<StructBool>& propBool() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the Propbool.
    */
    void setPropbool(const std::list<StructBool>& propBool) override;
    /**
    * Property getter
    * @return Locally stored value for Propint.
    */
    const std::list<StructInt>& propInt() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the Propint.
    */
    void setPropint(const std::list<StructInt>& propInt) override;
    /**
    * Property getter
    * @return Locally stored value for Propfloat.
    */
    const std::list<StructFloat>& propFloat() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the Propfloat.
    */
    void setPropfloat(const std::list<StructFloat>& propFloat) override;
    /**
    * Property getter
    * @return Locally stored value for Propstring.
    */
    const std::list<StructString>& propString() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the Propstring.
    */
    void setPropstring(const std::list<StructString>& propString) override;
    /**
    * Remote call of IStructArrayInterface::funcBool on the StructArrayInterface service.
    * Uses funcBoolAsync
    */
    StructBool funcBool(const std::list<StructBool>& paramBool) override;
    /**
    * Remote call of IStructArrayInterface::funcBool on the StructArrayInterface service.
    */
    std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) override;
    /**
    * Remote call of IStructArrayInterface::funcInt on the StructArrayInterface service.
    * Uses funcIntAsync
    */
    StructBool funcInt(const std::list<StructInt>& paramInt) override;
    /**
    * Remote call of IStructArrayInterface::funcInt on the StructArrayInterface service.
    */
    std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) override;
    /**
    * Remote call of IStructArrayInterface::funcFloat on the StructArrayInterface service.
    * Uses funcFloatAsync
    */
    StructBool funcFloat(const std::list<StructFloat>& paramFloat) override;
    /**
    * Remote call of IStructArrayInterface::funcFloat on the StructArrayInterface service.
    */
    std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) override;
    /**
    * Remote call of IStructArrayInterface::funcString on the StructArrayInterface service.
    * Uses funcStringAsync
    */
    StructBool funcString(const std::list<StructString>& paramString) override;
    /**
    * Remote call of IStructArrayInterface::funcString on the StructArrayInterface service.
    */
    std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) override;

    /** The publisher to subscribe to. */
    IStructArrayInterfacePublisher& _getPublisher() const override;
    
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
    * @param props Initial values obtained from the StructArrayInterface service
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
    * @param the data recived from StructArrayInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for Propbool and informs subscriber about the change*/
    void setPropboolLocal(const std::list<StructBool>& propBool);
    /**  Updates local value for Propint and informs subscriber about the change*/
    void setPropintLocal(const std::list<StructInt>& propInt);
    /**  Updates local value for Propfloat and informs subscriber about the change*/
    void setPropfloatLocal(const std::list<StructFloat>& propFloat);
    /**  Updates local value for Propstring and informs subscriber about the change*/
    void setPropstringLocal(const std::list<StructString>& propString);
    std::list<StructBool> m_propBool;
    std::list<StructInt> m_propInt;
    std::list<StructFloat> m_propFloat;
    std::list<StructString> m_propString;
    /**
    * An Olink client node used to connect with a Olink StructArrayInterface service for object given with olinkObjectName() .
    * An abstraction layer over the socket for the RemoteStructArrayInterface.
    * WARNING DOROTA if there's a sink already in registry for same name, it is silently disconnected, without the informing
    * it may send requests as long as the pointer to node is valid, but will not receive any data the isReady will not tell the true.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /** 
    * Registry linking client nodes with sinks for the olinkObjectName().
    * The registerd olinkObjects name must be unique.  
    */
    ApiGear::ObjectLink::ClientRegistry& m_registry;
    /** The publisher for StructArrayInterface */
    std::unique_ptr<IStructArrayInterfacePublisher> m_publisher;
};
} // namespace Testbed1
} // namespace Test

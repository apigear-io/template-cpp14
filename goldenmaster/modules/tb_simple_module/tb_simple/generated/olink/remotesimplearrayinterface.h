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

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"

#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

#include <future>
#include <memory>

namespace Test {
namespace TbSimple {

/**
* Remote SimpleArrayInterface implemented with OLink. 
* Handles connnectionn with SimpleArrayInterface service.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the SimpleArrayInterface on the server side 
* and to subscribe for the SimpleArrayInterface changes.
*/
class TEST_TB_SIMPLE_EXPORT RemoteSimpleArrayInterface : public ISimpleArrayInterface, public ApiGear::ObjectLink::IObjectSink
{
public:

    /**
    * ctor
    * @param registry The global registry with the sinks and client nodes.
    * @param client Holds the socket, manages the connection and provides ClientNode
    *   which is an abstraction layer between the Client and RemoteSimpleArrayInterface.
    */
    explicit RemoteSimpleArrayInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~RemoteSimpleArrayInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for Propbool.
    */
    const std::list<bool>& propBool() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the Propbool.
    */
    void setPropbool(const std::list<bool>& propBool) override;
    /**
    * Property getter
    * @return Locally stored locally value for Propint.
    */
    const std::list<int>& propInt() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the Propint.
    */
    void setPropint(const std::list<int>& propInt) override;
    /**
    * Property getter
    * @return Locally stored locally value for Propfloat.
    */
    const std::list<float>& propFloat() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the Propfloat.
    */
    void setPropfloat(const std::list<float>& propFloat) override;
    /**
    * Property getter
    * @return Locally stored locally value for Propstring.
    */
    const std::list<std::string>& propString() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the Propstring.
    */
    void setPropstring(const std::list<std::string>& propString) override;
    /**
    * Remote call of ISimpleArrayInterface::funcBool on the SimpleArrayInterface service.
    * Uses funcBoolAsync
    */
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    /**
    * Remote call of ISimpleArrayInterface::funcBool on the SimpleArrayInterface service.
    */
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt on the SimpleArrayInterface service.
    * Uses funcIntAsync
    */
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt on the SimpleArrayInterface service.
    */
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat on the SimpleArrayInterface service.
    * Uses funcFloatAsync
    */
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat on the SimpleArrayInterface service.
    */
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;
    /**
    * Remote call of ISimpleArrayInterface::funcString on the SimpleArrayInterface service.
    * Uses funcStringAsync
    */
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    /**
    * Remote call of ISimpleArrayInterface::funcString on the SimpleArrayInterface service.
    */
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;

    /** The publisher to subscribe to. */
    ISimpleArrayInterfacePublisher& _getPublisher() const override;
    
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
    * Forwards information about singal emission to publisher.
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
    * @param props Initial values obtained from the SimpleArrayInterface service
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
    * @param the data recived from SimpleArrayInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for Propbool and informs subscriber about the change*/
    void setPropboolLocal(const std::list<bool>& propBool);
    /**  Updates local value for Propint and informs subscriber about the change*/
    void setPropintLocal(const std::list<int>& propInt);
    /**  Updates local value for Propfloat and informs subscriber about the change*/
    void setPropfloatLocal(const std::list<float>& propFloat);
    /**  Updates local value for Propstring and informs subscriber about the change*/
    void setPropstringLocal(const std::list<std::string>& propString);
    std::list<bool> m_propBool;
    std::list<int> m_propInt;
    std::list<float> m_propFloat;
    std::list<std::string> m_propString;
    /**
    * An Olink client node used to connect with a Olink SimpleArrayInterface service for object given with olinkObjectName() .
    * An abstraction layer over the socket for the RemoteSimpleArrayInterface.
    * WARNING DOROTA if there's a sink already in registry for same name, it is silently disconnected, without the informing
    * it may send requests as long as the pointer to node is valid, but will not receive any data the isReady will not tell the true.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /** 
    * Registry linking client nodes with sinks for the olinkObjectName().
    * The registerd olinkObjects name must be unique.  
    */
    ApiGear::ObjectLink::ClientRegistry& m_registry;
    /** The publisher for SimpleArrayInterface */
    std::unique_ptr<ISimpleArrayInterfacePublisher> m_publisher;
};
} // namespace TbSimple
} // namespace Test

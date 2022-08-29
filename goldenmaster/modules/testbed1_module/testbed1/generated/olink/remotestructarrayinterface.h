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

#include "testbed1/generated/api/common.h"
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/core/structarrayinterface.data.h"

#include "apigear/olink/iolinkconnector.h"
#include "apigear/olink/logger/logger.h"
#include "olink/iobjectsink.h"

#include <future>
#include <memory>

namespace ApiGear{
namespace ObjectLink{
class IClientNode;
class ClientRegistry;
}
}

namespace Test {
namespace Testbed1 {
namespace olink {
/**
* The class for handling connetion witha a StructArrayInterface service implemented for OLink protocol. 
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the StructArrayInterface on the server side 
* and to subscribe for the StructArrayInterface changes.
*/
class TEST_TESTBED1_EXPORT RemoteStructArrayInterface : public IStructArrayInterface,
    public ApiGear::ObjectLink::IObjectSink,
    public ApiGear::Logger::Logger
{
public:

    /**
    * ctor
    * @param registry The global registry with the sinks and client nodes.
    */
    explicit RemoteStructArrayInterface(ApiGear::PocoImpl::IOlinkConnector& olinkConnector);
    virtual ~RemoteStructArrayInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for PropBool.
    */
    const std::list<StructBool>& propBool() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const std::list<StructBool>& propBool) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropInt.
    */
    const std::list<StructInt>& propInt() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const std::list<StructInt>& propInt) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropFloat.
    */
    const std::list<StructFloat>& propFloat() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const std::list<StructFloat>& propFloat) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropString.
    */
    const std::list<StructString>& propString() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const std::list<StructString>& propString) override;
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
    * Informs if the remote RemoteStructArrayInterface is ready to send and revice messages.
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
    * Information about singal emission on a server side to all subscribers.
    * @param signalId Unique identifier for the singal emited from object.
    * @param args The arguments for the signal.
    */
    void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    
    /**
    * Applies the information about the property changed on server side.
    * @param propertyId Unique identifier of a changed property in object .
    * @param value The value of the property.
    */
    void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    
    /** Informs this object sink that connetion was is established.
    * @param interfaceId The name of the object for which link was established.
    * @param props Initial values obtained from the StructArrayInterface service
    * @param the initialized link endpoint for this sink.
    */
    void olinkOnInit(const std::string& interfaceId, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node) override;
    /**
    * Informs this object source that the link was disconnected and cannot be used anymore.
    */
    void olinkOnRelease() override;

private:
    /**
    * Applies recived data to local state and publishes changes to subscribers.
    * @param the data recived from StructArrayInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for PropBool and informs subscriber about the change*/
    void setPropBoolLocal(const std::list<StructBool>& propBool);
    /**  Updates local value for PropInt and informs subscriber about the change*/
    void setPropIntLocal(const std::list<StructInt>& propInt);
    /**  Updates local value for PropFloat and informs subscriber about the change*/
    void setPropFloatLocal(const std::list<StructFloat>& propFloat);
    /**  Updates local value for PropString and informs subscriber about the change*/
    void setPropStringLocal(const std::list<StructString>& propString);
    
    /** Local storage for properties values. */
    StructArrayInterfaceData m_data;

    /** 
    * An abstraction layer over the connection with service for the RemoteStructArrayInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /**
    * A helper used to connect with a Olink StructArrayInterface service for object given with olinkObjectName()
    * takes care of setup and tear down linkage for this RemoteStructArrayInterface.
    */
    ApiGear::PocoImpl::IOlinkConnector& m_olinkConnector;
    /** The publisher for StructArrayInterface */
    std::unique_ptr<IStructArrayInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace Testbed1
} // namespace Test

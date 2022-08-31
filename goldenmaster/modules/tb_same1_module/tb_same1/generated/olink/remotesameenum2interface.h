
#pragma once

#include "tb_same1/generated/api/common.h"
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/core/sameenum2interface.data.h"

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
namespace TbSame1 {
namespace olink {
/**
* The class for handling connetion witha a SameEnum2Interface service implemented for OLink protocol. 
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the SameEnum2Interface on the server side 
* and to subscribe for the SameEnum2Interface changes.
*/
class TEST_TB_SAME1_EXPORT RemoteSameEnum2Interface : public ISameEnum2Interface,
    public ApiGear::ObjectLink::IObjectSink,
    public ApiGear::Logger::Logger
{
public:

    /**
    * ctor
    * @param registry The global registry with the sinks and client nodes.
    */
    explicit RemoteSameEnum2Interface(ApiGear::PocoImpl::IOlinkConnector& olinkConnector);
    virtual ~RemoteSameEnum2Interface() override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop1.
    */
    const Enum1Enum& getProp1() const override;
    /**
    * Request setting a property on the SameEnum2Interface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(const Enum1Enum& prop1) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop2.
    */
    const Enum2Enum& getProp2() const override;
    /**
    * Request setting a property on the SameEnum2Interface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(const Enum2Enum& prop2) override;
    /**
    * Remote call of ISameEnum2Interface::func1 on the SameEnum2Interface service.
    * Uses func1Async
    */
    Enum1Enum func1(const Enum1Enum& param1) override;
    /**
    * Remote call of ISameEnum2Interface::func1 on the SameEnum2Interface service.
    */
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    /**
    * Remote call of ISameEnum2Interface::func2 on the SameEnum2Interface service.
    * Uses func2Async
    */
    Enum1Enum func2(const Enum1Enum& param1, const Enum2Enum& param2) override;
    /**
    * Remote call of ISameEnum2Interface::func2 on the SameEnum2Interface service.
    */
    std::future<Enum1Enum> func2Async(const Enum1Enum& param1, const Enum2Enum& param2) override;

    /** The publisher to subscribe to. */
    ISameEnum2InterfacePublisher& _getPublisher() const override;
    
    /**
    * Informs if the remote RemoteSameEnum2Interface is ready to send and revice messages.
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
    * @param props Initial values obtained from the SameEnum2Interface service
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
    * @param the data recived from SameEnum2Interface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for Prop1 and informs subscriber about the change*/
    void setProp1Local(const Enum1Enum& prop1);
    /**  Updates local value for Prop2 and informs subscriber about the change*/
    void setProp2Local(const Enum2Enum& prop2);
    
    /** Local storage for properties values. */
    SameEnum2InterfaceData m_data;

    /** 
    * An abstraction layer over the connection with service for the RemoteSameEnum2Interface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /**
    * A helper used to connect with a Olink SameEnum2Interface service for object given with olinkObjectName()
    * takes care of setup and tear down linkage for this RemoteSameEnum2Interface.
    */
    ApiGear::PocoImpl::IOlinkConnector& m_olinkConnector;
    /** The publisher for SameEnum2Interface */
    std::unique_ptr<ISameEnum2InterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace TbSame1
} // namespace Test

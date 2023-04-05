
#pragma once

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "olink/iobjectsource.h"
#include "apigear/utilities/logger.h"


namespace ApiGear {
namespace ObjectLink {

class RemoteRegistry;
class IRemoteNode;

}} //namespace ApiGear::ObjectLink

namespace Test {
namespace Testbed2 {
namespace olink {
/**
* Server side for NestedStruct1Interface implements the NestedStruct1Interface service.
* It is a source of data for NestedStruct1Interface clients.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
*/
class TEST_TESTBED2_EXPORT NestedStruct1InterfaceService : public ApiGear::ObjectLink::IObjectSource, public INestedStruct1InterfaceSubscriber
{
public:
    /**
    * ctor
    * @param NestedStruct1Interface The service source object, the actual NestedStruct1Interface object which is exposed for remote clients with olink.
    * @param registry The global registry that keeps track of the object source services associated with network nodes.
    */
    explicit NestedStruct1InterfaceService(std::shared_ptr<INestedStruct1Interface> NestedStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~NestedStruct1InterfaceService() override;

    /**
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be unique for the pair source object - remote node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;
    /**
    * Applies received method invocation with given arguments on the NestedStruct1Interface object.
    * @param name Path of the method to invoke. Contains object name and the method name.
    * @param args Arguments required to invoke a method in json format.
    * @return the result of the invoked method (if applicable) that needs to be sent back to the clients.
    */
    nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) override;
    /**
    * Applies received change property request to NestedStruct1Interface object.
    * @param name Path the property to change. Contains object name and the property name.
    * @param args Value in json format requested to set for the property.
    */
    void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) override;
    /**
    * Informs this service source that the link was established.
    * @param name The name of the object for which link was established.
    * @param the initialized link endpoint.
    */
    void olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode *node) override;
    /**
    * Informs this service source that the link was disconnected and cannot be used anymore.
    */
    void olinkUnlinked(const std::string& objectId) override;

    /**
    * Gets the current state of NestedStruct1Interface object.
    * @return the set of properties with their current values for the NestedStruct1Interface object in json format.
    */
    nlohmann::json olinkCollectProperties() override;
    /**
    * Forwards emitted sig1 through network if the connection is established.
    */
    void onSig1(const NestedStruct1& param1) override;
    /**
    * Forwards prop1 change through network if the connection is established.
    */
    void onProp1Changed(const NestedStruct1& prop1) override;

private:
    /**
    * The NestedStruct1Interface used for object source.
    */
    std::shared_ptr<INestedStruct1Interface> m_NestedStruct1Interface;
    /**
    * A global registry that keeps track of object sources associated with their network layer nodes.
    */
    ApiGear::ObjectLink::RemoteRegistry& m_registry;

    /** The logger */
    std::unique_ptr<ApiGear::Utilities::Logger> m_logger;
};
} // namespace olink
} // namespace Testbed2
} // namespace Test

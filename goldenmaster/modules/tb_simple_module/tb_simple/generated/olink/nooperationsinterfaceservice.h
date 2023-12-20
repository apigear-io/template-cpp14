
#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "olink/iobjectsource.h"


namespace ApiGear {
namespace ObjectLink {

class RemoteRegistry;
class IRemoteNode;

}} //namespace ApiGear::ObjectLink

namespace Test {
namespace TbSimple {
namespace olink {
/**
* Server side for NoOperationsInterface implements the NoOperationsInterface service.
* It is a source of data for NoOperationsInterface clients.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
*/
class TEST_TB_SIMPLE_EXPORT NoOperationsInterfaceService : public ApiGear::ObjectLink::IObjectSource, public INoOperationsInterfaceSubscriber
{
public:
    /**
    * ctor
    * @param NoOperationsInterface The service source object, the actual NoOperationsInterface object which is exposed for remote clients with olink.
    * @param registry The global registry that keeps track of the object source services associated with network nodes.
    */
    explicit NoOperationsInterfaceService(std::shared_ptr<INoOperationsInterface> NoOperationsInterface, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~NoOperationsInterfaceService() override;

    /**
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be unique for the pair source object - remote node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;
    /**
    * Applies received method invocation with given arguments on the NoOperationsInterface object.
    * @param name Path of the method to invoke. Contains object name and the method name.
    * @param args Arguments required to invoke a method in json format.
    * @return the result of the invoked method (if applicable) that needs to be sent back to the clients.
    */
    ApiGear::ObjectLink::OLinkContent olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& args) override;
    /**
    * Applies received change property request to NoOperationsInterface object.
    * @param name Path the property to change. Contains object name and the property name.
    * @param args Value in json format requested to set for the property.
    */
    void olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) override;
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
    * Gets the current state of NoOperationsInterface object.
    * @return the set of properties with their current values for the NoOperationsInterface object in json format.
    */
    ApiGear::ObjectLink::OLinkContent olinkCollectProperties() override;
    /**
    * Forwards emitted sigVoid through network if the connection is established.
    */
    void onSigVoid() override;
    /**
    * Forwards emitted sigBool through network if the connection is established.
    */
    void onSigBool(bool paramBool) override;
    /**
    * Forwards propBool change through network if the connection is established.
    */
    void onPropBoolChanged(bool propBool) override;
    /**
    * Forwards propInt change through network if the connection is established.
    */
    void onPropIntChanged(int propInt) override;

private:
    /**
    * The NoOperationsInterface used for object source.
    */
    std::shared_ptr<INoOperationsInterface> m_NoOperationsInterface;
    /**
    * A global registry that keeps track of object sources associated with their network layer nodes.
    */
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
};
} // namespace olink
} // namespace TbSimple
} // namespace Test



#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/voidinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.VoidInterface";
}

VoidInterfaceService::VoidInterfaceService(std::shared_ptr<IVoidInterface> VoidInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_VoidInterface(VoidInterface)
    , m_registry(registry)
{
    m_VoidInterface->_getPublisher().subscribeToAllChanges(*this);
}

VoidInterfaceService::~VoidInterfaceService()
{
    m_VoidInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string VoidInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent VoidInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    (void) fcnArgs;
    AG_LOG_DEBUG("VoidInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "funcVoid") {
        m_VoidInterface->funcVoid();
        return {};
    }
    return {};
}

void VoidInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("VoidInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    // no properties to set
    (void) value;
    (void) memberProperty; 
}

void VoidInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("VoidInterfaceService linked " + objectId);
}

void VoidInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("VoidInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent VoidInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent( );
}
void VoidInterfaceService::onSigVoid()
{
    auto args = ApiGear::ObjectLink::argumentsToContent();
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigVoid");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}


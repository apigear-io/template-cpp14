

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/nopropertiesinterfaceservice.h"
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
const std::string interfaceId = "tb.simple.NoPropertiesInterface";
}

NoPropertiesInterfaceService::NoPropertiesInterfaceService(std::shared_ptr<INoPropertiesInterface> NoPropertiesInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NoPropertiesInterface(NoPropertiesInterface)
    , m_registry(registry)
{
    m_NoPropertiesInterface->_getPublisher().subscribeToAllChanges(*this);
}

NoPropertiesInterfaceService::~NoPropertiesInterfaceService()
{
    m_NoPropertiesInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NoPropertiesInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent NoPropertiesInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("NoPropertiesInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "funcVoid") {
        m_NoPropertiesInterface->funcVoid();
        return {};
    }
    if(memberMethod == "funcBool") {
        bool paramBool{};
        argumentsReader.read(paramBool);
        return ApiGear::ObjectLink::invokeReturnValue(m_NoPropertiesInterface->funcBool(paramBool));
    }
    return {};
}

void NoPropertiesInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("NoPropertiesInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    // no properties to set
    (void) value;
    (void) memberProperty; 
}

void NoPropertiesInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("NoPropertiesInterfaceService linked " + objectId);
}

void NoPropertiesInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("NoPropertiesInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent NoPropertiesInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent( );
}
void NoPropertiesInterfaceService::onSigVoid()
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
void NoPropertiesInterfaceService::onSigBool(bool paramBool)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramBool);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}


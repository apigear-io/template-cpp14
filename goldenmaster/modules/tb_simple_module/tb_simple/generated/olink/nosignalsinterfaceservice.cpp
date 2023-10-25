

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/nosignalsinterfaceservice.h"
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
const std::string interfaceId = "tb.simple.NoSignalsInterface";
}

NoSignalsInterfaceService::NoSignalsInterfaceService(std::shared_ptr<INoSignalsInterface> NoSignalsInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NoSignalsInterface(NoSignalsInterface)
    , m_registry(registry)
{
    m_NoSignalsInterface->_getPublisher().subscribeToAllChanges(*this);
}

NoSignalsInterfaceService::~NoSignalsInterfaceService()
{
    m_NoSignalsInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NoSignalsInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent NoSignalsInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("NoSignalsInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "funcVoid") {
        m_NoSignalsInterface->funcVoid();
        return {};
    }
    if(memberMethod == "funcBool") {
        bool paramBool{};
        argumentsReader.read(paramBool);
        return ApiGear::ObjectLink::invokeReturnValue(m_NoSignalsInterface->funcBool(paramBool));
    }
    return {};
}

void NoSignalsInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("NoSignalsInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        bool value_propBool{};
        ApiGear::ObjectLink::readValue(value, value_propBool);
        m_NoSignalsInterface->setPropBool(value_propBool);
    }
    if(memberProperty == "propInt") {
        int value_propInt{};
        ApiGear::ObjectLink::readValue(value, value_propInt);
        m_NoSignalsInterface->setPropInt(value_propInt);
    } 
}

void NoSignalsInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("NoSignalsInterfaceService linked " + objectId);
}

void NoSignalsInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("NoSignalsInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent NoSignalsInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("propBool"), m_NoSignalsInterface->getPropBool()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt"), m_NoSignalsInterface->getPropInt()) );
}
void NoSignalsInterfaceService::onPropBoolChanged(bool propBool)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propBool));
        }
    }
}
void NoSignalsInterfaceService::onPropIntChanged(int propInt)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propInt));
        }
    }
}


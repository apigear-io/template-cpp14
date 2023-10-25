

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/nooperationsinterfaceservice.h"
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
const std::string interfaceId = "tb.simple.NoOperationsInterface";
}

NoOperationsInterfaceService::NoOperationsInterfaceService(std::shared_ptr<INoOperationsInterface> NoOperationsInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NoOperationsInterface(NoOperationsInterface)
    , m_registry(registry)
{
    m_NoOperationsInterface->_getPublisher().subscribeToAllChanges(*this);
}

NoOperationsInterfaceService::~NoOperationsInterfaceService()
{
    m_NoOperationsInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NoOperationsInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent NoOperationsInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("NoOperationsInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    // no operations to invoke
    (void) fcnArgs;
    (void) memberMethod;
    return {};
}

void NoOperationsInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("NoOperationsInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        bool value_propBool{};
        ApiGear::ObjectLink::readValue(value, value_propBool);
        m_NoOperationsInterface->setPropBool(value_propBool);
    }
    if(memberProperty == "propInt") {
        int value_propInt{};
        ApiGear::ObjectLink::readValue(value, value_propInt);
        m_NoOperationsInterface->setPropInt(value_propInt);
    } 
}

void NoOperationsInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("NoOperationsInterfaceService linked " + objectId);
}

void NoOperationsInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("NoOperationsInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent NoOperationsInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("propBool"), m_NoOperationsInterface->getPropBool()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt"), m_NoOperationsInterface->getPropInt()) );
}
void NoOperationsInterfaceService::onSigVoid()
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
void NoOperationsInterfaceService::onSigBool(bool paramBool)
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
void NoOperationsInterfaceService::onPropBoolChanged(bool propBool)
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
void NoOperationsInterfaceService::onPropIntChanged(int propInt)
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


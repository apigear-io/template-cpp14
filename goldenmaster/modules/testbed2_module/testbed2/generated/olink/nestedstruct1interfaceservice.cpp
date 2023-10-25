

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/nestedstruct1interfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.NestedStruct1Interface";
}

NestedStruct1InterfaceService::NestedStruct1InterfaceService(std::shared_ptr<INestedStruct1Interface> NestedStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct1Interface(NestedStruct1Interface)
    , m_registry(registry)
{
    m_NestedStruct1Interface->_getPublisher().subscribeToAllChanges(*this);
}

NestedStruct1InterfaceService::~NestedStruct1InterfaceService()
{
    m_NestedStruct1Interface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct1InterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent NestedStruct1InterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("NestedStruct1InterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "func1") {
        NestedStruct1 param1{};
        argumentsReader.read(param1);
        return ApiGear::ObjectLink::invokeReturnValue(m_NestedStruct1Interface->func1(param1));
    }
    return {};
}

void NestedStruct1InterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("NestedStruct1InterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        NestedStruct1 value_prop1{};
        ApiGear::ObjectLink::readValue(value, value_prop1);
        m_NestedStruct1Interface->setProp1(value_prop1);
    } 
}

void NestedStruct1InterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("NestedStruct1InterfaceService linked " + objectId);
}

void NestedStruct1InterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("NestedStruct1InterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent NestedStruct1InterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("prop1"), m_NestedStruct1Interface->getProp1()) );
}
void NestedStruct1InterfaceService::onSig1(const NestedStruct1& param1)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param1);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void NestedStruct1InterfaceService::onProp1Changed(const NestedStruct1& prop1)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(prop1));
        }
    }
}


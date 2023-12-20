

#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/olink/samestruct1interfaceservice.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

namespace 
{
const std::string interfaceId = "tb.same1.SameStruct1Interface";
}

SameStruct1InterfaceService::SameStruct1InterfaceService(std::shared_ptr<ISameStruct1Interface> SameStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameStruct1Interface(SameStruct1Interface)
    , m_registry(registry)
{
    m_SameStruct1Interface->_getPublisher().subscribeToAllChanges(*this);
}

SameStruct1InterfaceService::~SameStruct1InterfaceService()
{
    m_SameStruct1Interface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameStruct1InterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent SameStruct1InterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("SameStruct1InterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "func1") {
        Struct1 param1{};
        argumentsReader.read(param1);
        return ApiGear::ObjectLink::invokeReturnValue(m_SameStruct1Interface->func1(param1));
    }
    return {};
}

void SameStruct1InterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("SameStruct1InterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Struct1 value_prop1{};
        ApiGear::ObjectLink::readValue(value, value_prop1);
        m_SameStruct1Interface->setProp1(value_prop1);
    } 
}

void SameStruct1InterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("SameStruct1InterfaceService linked " + objectId);
}

void SameStruct1InterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("SameStruct1InterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent SameStruct1InterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("prop1"), m_SameStruct1Interface->getProp1()) );
}
void SameStruct1InterfaceService::onSig1(const Struct1& param1)
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
void SameStruct1InterfaceService::onProp1Changed(const Struct1& prop1)
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


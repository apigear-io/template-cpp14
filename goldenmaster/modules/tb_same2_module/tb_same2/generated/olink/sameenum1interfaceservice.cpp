

#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/olink/sameenum1interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbSame2;
using namespace Test::TbSame2::olink;

namespace 
{
const std::string interfaceId = "tb.same2.SameEnum1Interface";
}

SameEnum1InterfaceService::SameEnum1InterfaceService(std::shared_ptr<ISameEnum1Interface> SameEnum1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameEnum1Interface(SameEnum1Interface)
    , m_registry(registry)
{
    m_SameEnum1Interface->_getPublisher().subscribeToAllChanges(*this);
}

SameEnum1InterfaceService::~SameEnum1InterfaceService()
{
    m_SameEnum1Interface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameEnum1InterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent SameEnum1InterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("SameEnum1InterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "func1") {
        Enum1Enum param1{};
        argumentsReader.read(param1);
        return ApiGear::ObjectLink::invokeReturnValue(m_SameEnum1Interface->func1(param1));
    }
    return {};
}

void SameEnum1InterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("SameEnum1InterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Enum1Enum value_prop1{};
        ApiGear::ObjectLink::readValue(value, value_prop1);
        m_SameEnum1Interface->setProp1(value_prop1);
    } 
}

void SameEnum1InterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("SameEnum1InterfaceService linked " + objectId);
}

void SameEnum1InterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("SameEnum1InterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent SameEnum1InterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("prop1"), m_SameEnum1Interface->getProp1()) );
}
void SameEnum1InterfaceService::onSig1(Enum1Enum param1)
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
void SameEnum1InterfaceService::onProp1Changed(Enum1Enum prop1)
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


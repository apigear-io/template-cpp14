

#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/olink/sameenum2interfaceservice.h"
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
const std::string interfaceId = "tb.same2.SameEnum2Interface";
}

SameEnum2InterfaceService::SameEnum2InterfaceService(std::shared_ptr<ISameEnum2Interface> SameEnum2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameEnum2Interface(SameEnum2Interface)
    , m_registry(registry)
{
    m_SameEnum2Interface->_getPublisher().subscribeToAllChanges(*this);
}

SameEnum2InterfaceService::~SameEnum2InterfaceService()
{
    m_SameEnum2Interface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameEnum2InterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent SameEnum2InterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("SameEnum2InterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "func1") {
        Enum1Enum param1{};
        argumentsReader.read(param1);
        return ApiGear::ObjectLink::invokeReturnValue(m_SameEnum2Interface->func1(param1));
    }
    if(memberMethod == "func2") {
        Enum1Enum param1{};
        argumentsReader.read(param1);
        Enum2Enum param2{};
        argumentsReader.read(param2);
        return ApiGear::ObjectLink::invokeReturnValue(m_SameEnum2Interface->func2(param1, param2));
    }
    return {};
}

void SameEnum2InterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("SameEnum2InterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Enum1Enum value_prop1{};
        ApiGear::ObjectLink::readValue(value, value_prop1);
        m_SameEnum2Interface->setProp1(value_prop1);
    }
    if(memberProperty == "prop2") {
        Enum2Enum value_prop2{};
        ApiGear::ObjectLink::readValue(value, value_prop2);
        m_SameEnum2Interface->setProp2(value_prop2);
    } 
}

void SameEnum2InterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("SameEnum2InterfaceService linked " + objectId);
}

void SameEnum2InterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("SameEnum2InterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent SameEnum2InterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("prop1"), m_SameEnum2Interface->getProp1()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop2"), m_SameEnum2Interface->getProp2()) );
}
void SameEnum2InterfaceService::onSig1(Enum1Enum param1)
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
void SameEnum2InterfaceService::onSig2(Enum1Enum param1, Enum2Enum param2)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param1, param2);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SameEnum2InterfaceService::onProp1Changed(Enum1Enum prop1)
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
void SameEnum2InterfaceService::onProp2Changed(Enum2Enum prop2)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(prop2));
        }
    }
}




#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/olink/samestruct2interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include <iostream>


using namespace Goldenmaster::TbSame2;
using namespace Goldenmaster::TbSame2::olink;

namespace 
{
const std::string interfaceId = "tb.same2.SameStruct2Interface";
}

SameStruct2InterfaceService::SameStruct2InterfaceService(std::shared_ptr<ISameStruct2Interface> SameStruct2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameStruct2Interface(SameStruct2Interface)
    , m_registry(registry)
{
    m_SameStruct2Interface->_getPublisher().subscribeToAllChanges(*this);
}

SameStruct2InterfaceService::~SameStruct2InterfaceService()
{
    m_SameStruct2Interface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameStruct2InterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SameStruct2InterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const Struct1& param1 = fcnArgs.at(0);
        Struct1 result = m_SameStruct2Interface->func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const Struct1& param1 = fcnArgs.at(0);
        const Struct2& param2 = fcnArgs.at(1);
        Struct1 result = m_SameStruct2Interface->func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void SameStruct2InterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Struct2 prop1 = value.get<Struct2>();
        m_SameStruct2Interface->setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        Struct2 prop2 = value.get<Struct2>();
        m_SameStruct2Interface->setProp2(prop2);
    } 
}

void SameStruct2InterfaceService::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void SameStruct2InterfaceService::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json SameStruct2InterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameStruct2Interface->getProp1() },
        { "prop2", m_SameStruct2Interface->getProp2() }
    });
}
void SameStruct2InterfaceService::onSig1(const Struct1& param1)
{
    const nlohmann::json args = { param1 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SameStruct2InterfaceService::onSig2(const Struct1& param1, const Struct2& param2)
{
    const nlohmann::json args = { param1, param2 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SameStruct2InterfaceService::onProp1Changed(const Struct2& prop1)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop1);
        }
    }
}
void SameStruct2InterfaceService::onProp2Changed(const Struct2& prop2)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop2);
        }
    }
}




#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/olink/sameenum2interfaceservice.adapter.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include <iostream>


using namespace Test::TbSame2;
using namespace Test::TbSame2::olink;

namespace 
{
const std::string interfaceId = "tb.same2.SameEnum2Interface";
}

SameEnum2InterfaceServiceAdapter::SameEnum2InterfaceServiceAdapter(ISameEnum2Interface& SameEnum2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameEnum2Interface(SameEnum2Interface)
    , m_registry(registry)
{
    m_SameEnum2Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addSource(*this);
}

SameEnum2InterfaceServiceAdapter::~SameEnum2InterfaceServiceAdapter()
{
    m_registry.removeSource(olinkObjectName());
    m_SameEnum2Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameEnum2InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SameEnum2InterfaceServiceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_SameEnum2Interface.func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        const Enum2Enum& param2 = fcnArgs.at(1);
        Enum1Enum result = m_SameEnum2Interface.func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void SameEnum2InterfaceServiceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_SameEnum2Interface.setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        Enum2Enum prop2 = value.get<Enum2Enum>();
        m_SameEnum2Interface.setProp2(prop2);
    } 
}

void SameEnum2InterfaceServiceAdapter::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void SameEnum2InterfaceServiceAdapter::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json SameEnum2InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameEnum2Interface.getProp1() },
        { "prop2", m_SameEnum2Interface.getProp2() }
    });
}
void SameEnum2InterfaceServiceAdapter::onSig1(const Enum1Enum& param1)
{
    const nlohmann::json args = { param1 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SameEnum2InterfaceServiceAdapter::onSig2(const Enum1Enum& param1,const Enum2Enum& param2)
{
    const nlohmann::json args = { param1, param2 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SameEnum2InterfaceServiceAdapter::onProp1Changed(const Enum1Enum& prop1)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, prop1);
        }
    }
}
void SameEnum2InterfaceServiceAdapter::onProp2Changed(const Enum2Enum& prop2)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, prop2);
        }
    }
}


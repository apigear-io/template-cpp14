

#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/olink/samestruct1interfaceservice.adapter.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include <iostream>


using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

namespace 
{
const std::string interfaceId = "tb.same1.SameStruct1Interface";
}

SameStruct1InterfaceServiceAdapter::SameStruct1InterfaceServiceAdapter(ISameStruct1Interface& SameStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameStruct1Interface(SameStruct1Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SameStruct1Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SameStruct1InterfaceServiceAdapter::~SameStruct1InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SameStruct1Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameStruct1InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SameStruct1InterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    std::string memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const Struct1& param1 = fcnArgs.at(0);
        Struct1 result = m_SameStruct1Interface.func1(param1);
        return result;
    }
    return nlohmann::json();
}

void SameStruct1InterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    std::string memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Struct1 prop1 = value.get<Struct1>();
        m_SameStruct1Interface.setProp1(prop1);
    } 
}

void SameStruct1InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SameStruct1InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SameStruct1InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameStruct1Interface.getProp1() }
    });
}
void SameStruct1InterfaceServiceAdapter::onSig1(const Struct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
        m_node->notifySignal(signalId, args);
    }
}
void SameStruct1InterfaceServiceAdapter::onProp1Changed(const Struct1& prop1)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
        m_node->notifyPropertyChange(propertyId, prop1);
    }
}


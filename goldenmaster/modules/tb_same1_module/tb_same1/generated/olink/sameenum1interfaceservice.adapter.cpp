

#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/olink/sameenum1interfaceservice.adapter.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include <iostream>


using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

namespace 
{
const std::string interfaceId = "tb.same1.SameEnum1Interface";
}

SameEnum1InterfaceServiceAdapter::SameEnum1InterfaceServiceAdapter(ISameEnum1Interface& SameEnum1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameEnum1Interface(SameEnum1Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SameEnum1Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SameEnum1InterfaceServiceAdapter::~SameEnum1InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SameEnum1Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameEnum1InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SameEnum1InterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_SameEnum1Interface.func1(param1);
        return result;
    }
    return nlohmann::json();
}

void SameEnum1InterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_SameEnum1Interface.setProp1(prop1);
    } 
}

void SameEnum1InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SameEnum1InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SameEnum1InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameEnum1Interface.getProp1() }
    });
}
void SameEnum1InterfaceServiceAdapter::onSig1(const Enum1Enum& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
        m_node->notifySignal(signalId, args);
    }
}
void SameEnum1InterfaceServiceAdapter::onProp1Changed(const Enum1Enum& prop1)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
        m_node->notifyPropertyChange(propertyId, prop1);
    }
}


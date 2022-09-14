

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/nestedstruct1interfaceservice.adapter.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>


using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.NestedStruct1Interface";
}

NestedStruct1InterfaceServiceAdapter::NestedStruct1InterfaceServiceAdapter(INestedStruct1Interface& NestedStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct1Interface(NestedStruct1Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_NestedStruct1Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

NestedStruct1InterfaceServiceAdapter::~NestedStruct1InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_NestedStruct1Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct1InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json NestedStruct1InterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_NestedStruct1Interface.func1(param1);
        return result;
    }
    return nlohmann::json();
}

void NestedStruct1InterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_NestedStruct1Interface.setProp1(prop1);
    } 
}

void NestedStruct1InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void NestedStruct1InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json NestedStruct1InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_NestedStruct1Interface.getProp1() }
    });
}
void NestedStruct1InterfaceServiceAdapter::onSig1(const NestedStruct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
        m_node->notifySignal(signalId, args);
    }
}
void NestedStruct1InterfaceServiceAdapter::onProp1Changed(const NestedStruct1& prop1)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
        m_node->notifyPropertyChange(propertyId, prop1);
    }
}




#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/nestedstruct2interfaceservice.adapter.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>


using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.NestedStruct2Interface";
}

NestedStruct2InterfaceServiceAdapter::NestedStruct2InterfaceServiceAdapter(INestedStruct2Interface& NestedStruct2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct2Interface(NestedStruct2Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_NestedStruct2Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

NestedStruct2InterfaceServiceAdapter::~NestedStruct2InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_NestedStruct2Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct2InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json NestedStruct2InterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_NestedStruct2Interface.func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        const NestedStruct2& param2 = fcnArgs.at(1);
        NestedStruct1 result = m_NestedStruct2Interface.func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void NestedStruct2InterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_NestedStruct2Interface.setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        NestedStruct2 prop2 = value.get<NestedStruct2>();
        m_NestedStruct2Interface.setProp2(prop2);
    } 
}

void NestedStruct2InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void NestedStruct2InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json NestedStruct2InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_NestedStruct2Interface.getProp1() },
        { "prop2", m_NestedStruct2Interface.getProp2() }
    });
}
void NestedStruct2InterfaceServiceAdapter::onSig1(const NestedStruct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
        m_node->notifySignal(signalId, args);
    }
}
void NestedStruct2InterfaceServiceAdapter::onSig2(const NestedStruct1& param1,const NestedStruct2& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
        m_node->notifySignal(signalId, args);
    }
}
void NestedStruct2InterfaceServiceAdapter::onProp1Changed(const NestedStruct1& prop1)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
        m_node->notifyPropertyChange(propertyId, prop1);
    }
}
void NestedStruct2InterfaceServiceAdapter::onProp2Changed(const NestedStruct2& prop2)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
        m_node->notifyPropertyChange(propertyId, prop2);
    }
}


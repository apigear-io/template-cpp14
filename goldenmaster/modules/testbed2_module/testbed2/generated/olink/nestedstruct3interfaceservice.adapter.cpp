

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/nestedstruct3interfaceservice.adapter.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>


using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.NestedStruct3Interface";
}

NestedStruct3InterfaceServiceAdapter::NestedStruct3InterfaceServiceAdapter(INestedStruct3Interface& NestedStruct3Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct3Interface(NestedStruct3Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_NestedStruct3Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

NestedStruct3InterfaceServiceAdapter::~NestedStruct3InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_NestedStruct3Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct3InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json NestedStruct3InterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    std::string memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_NestedStruct3Interface.func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        const NestedStruct2& param2 = fcnArgs.at(1);
        NestedStruct1 result = m_NestedStruct3Interface.func2(param1, param2);
        return result;
    }
    if(memberMethod == "func3") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        const NestedStruct2& param2 = fcnArgs.at(1);
        const NestedStruct3& param3 = fcnArgs.at(2);
        NestedStruct1 result = m_NestedStruct3Interface.func3(param1, param2, param3);
        return result;
    }
    return nlohmann::json();
}

void NestedStruct3InterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    std::string memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_NestedStruct3Interface.setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        NestedStruct2 prop2 = value.get<NestedStruct2>();
        m_NestedStruct3Interface.setProp2(prop2);
    }
    if(memberProperty == "prop3") {
        NestedStruct3 prop3 = value.get<NestedStruct3>();
        m_NestedStruct3Interface.setProp3(prop3);
    } 
}

void NestedStruct3InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void NestedStruct3InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json NestedStruct3InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_NestedStruct3Interface.getProp1() },
        { "prop2", m_NestedStruct3Interface.getProp2() },
        { "prop3", m_NestedStruct3Interface.getProp3() }
    });
}
void NestedStruct3InterfaceServiceAdapter::onSig1(const NestedStruct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
        m_node->notifySignal(signalId, args);
    }
}
void NestedStruct3InterfaceServiceAdapter::onSig2(const NestedStruct1& param1,const NestedStruct2& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
        m_node->notifySignal(signalId, args);
    }
}
void NestedStruct3InterfaceServiceAdapter::onSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2, param3 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3");
        m_node->notifySignal(signalId, args);
    }
}
void NestedStruct3InterfaceServiceAdapter::onProp1Changed(const NestedStruct1& prop1)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
        m_node->notifyPropertyChange(propertyId, prop1);
    }
}
void NestedStruct3InterfaceServiceAdapter::onProp2Changed(const NestedStruct2& prop2)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
        m_node->notifyPropertyChange(propertyId, prop2);
    }
}
void NestedStruct3InterfaceServiceAdapter::onProp3Changed(const NestedStruct3& prop3)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
        m_node->notifyPropertyChange(propertyId, prop3);
    }
}


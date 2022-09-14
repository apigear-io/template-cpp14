

#include "tb_enum/generated/api/datastructs.api.h"
#include "tb_enum/generated/olink/enuminterfaceservice.adapter.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"
#include <iostream>


using namespace Test::TbEnum;
using namespace Test::TbEnum::olink;

namespace 
{
const std::string interfaceId = "tb.enum.EnumInterface";
}

EnumInterfaceServiceAdapter::EnumInterfaceServiceAdapter(IEnumInterface& EnumInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_EnumInterface(EnumInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_EnumInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

EnumInterfaceServiceAdapter::~EnumInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_EnumInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string EnumInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json EnumInterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func0") {
        const Enum0Enum& param0 = fcnArgs.at(0);
        Enum0Enum result = m_EnumInterface.func0(param0);
        return result;
    }
    if(memberMethod == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_EnumInterface.func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const Enum2Enum& param2 = fcnArgs.at(0);
        Enum2Enum result = m_EnumInterface.func2(param2);
        return result;
    }
    if(memberMethod == "func3") {
        const Enum3Enum& param3 = fcnArgs.at(0);
        Enum3Enum result = m_EnumInterface.func3(param3);
        return result;
    }
    return nlohmann::json();
}

void EnumInterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop0") {
        Enum0Enum prop0 = value.get<Enum0Enum>();
        m_EnumInterface.setProp0(prop0);
    }
    if(memberProperty == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_EnumInterface.setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        Enum2Enum prop2 = value.get<Enum2Enum>();
        m_EnumInterface.setProp2(prop2);
    }
    if(memberProperty == "prop3") {
        Enum3Enum prop3 = value.get<Enum3Enum>();
        m_EnumInterface.setProp3(prop3);
    } 
}

void EnumInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void EnumInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json EnumInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop0", m_EnumInterface.getProp0() },
        { "prop1", m_EnumInterface.getProp1() },
        { "prop2", m_EnumInterface.getProp2() },
        { "prop3", m_EnumInterface.getProp3() }
    });
}
void EnumInterfaceServiceAdapter::onSig0(const Enum0Enum& param0)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param0 };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig0");
        m_node->notifySignal(signalId, args);
    }
}
void EnumInterfaceServiceAdapter::onSig1(const Enum1Enum& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
        m_node->notifySignal(signalId, args);
    }
}
void EnumInterfaceServiceAdapter::onSig2(const Enum2Enum& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param2 };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
        m_node->notifySignal(signalId, args);
    }
}
void EnumInterfaceServiceAdapter::onSig3(const Enum3Enum& param3)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param3 };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3");
        m_node->notifySignal(signalId, args);
    }
}
void EnumInterfaceServiceAdapter::onProp0Changed(const Enum0Enum& prop0)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop0");
        m_node->notifyPropertyChange(propertyId, prop0);
    }
}
void EnumInterfaceServiceAdapter::onProp1Changed(const Enum1Enum& prop1)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
        m_node->notifyPropertyChange(propertyId, prop1);
    }
}
void EnumInterfaceServiceAdapter::onProp2Changed(const Enum2Enum& prop2)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
        m_node->notifyPropertyChange(propertyId, prop2);
    }
}
void EnumInterfaceServiceAdapter::onProp3Changed(const Enum3Enum& prop3)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
        m_node->notifyPropertyChange(propertyId, prop3);
    }
}


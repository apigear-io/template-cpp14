

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/simpleinterfaceservice.adapter.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleInterface";
}

SimpleInterfaceServiceAdapter::SimpleInterfaceServiceAdapter(ISimpleInterface& SimpleInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleInterface(SimpleInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SimpleInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SimpleInterfaceServiceAdapter::~SimpleInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SimpleInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SimpleInterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const bool& paramBool = fcnArgs.at(0);
        bool result = m_SimpleInterface.funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const int& paramInt = fcnArgs.at(0);
        int result = m_SimpleInterface.funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const float& paramFloat = fcnArgs.at(0);
        float result = m_SimpleInterface.funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::string& paramString = fcnArgs.at(0);
        std::string result = m_SimpleInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleInterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        bool propBool = value.get<bool>();
        m_SimpleInterface.setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        int propInt = value.get<int>();
        m_SimpleInterface.setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        float propFloat = value.get<float>();
        m_SimpleInterface.setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        std::string propString = value.get<std::string>();
        m_SimpleInterface.setPropString(propString);
    } 
}

void SimpleInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SimpleInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SimpleInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleInterface.getPropBool() },
        { "propInt", m_SimpleInterface.getPropInt() },
        { "propFloat", m_SimpleInterface.getPropFloat() },
        { "propString", m_SimpleInterface.getPropString() }
    });
}
void SimpleInterfaceServiceAdapter::onSigBool(bool paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
        m_node->notifySignal(signalId, args);
    }
}
void SimpleInterfaceServiceAdapter::onSigInt(int paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
        m_node->notifySignal(signalId, args);
    }
}
void SimpleInterfaceServiceAdapter::onSigFloat(float paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
        m_node->notifySignal(signalId, args);
    }
}
void SimpleInterfaceServiceAdapter::onSigString(const std::string& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
        m_node->notifySignal(signalId, args);
    }
}
void SimpleInterfaceServiceAdapter::onPropBoolChanged(bool propBool)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
        m_node->notifyPropertyChange(propertyId, propBool);
    }
}
void SimpleInterfaceServiceAdapter::onPropIntChanged(int propInt)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
        m_node->notifyPropertyChange(propertyId, propInt);
    }
}
void SimpleInterfaceServiceAdapter::onPropFloatChanged(float propFloat)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
        m_node->notifyPropertyChange(propertyId, propFloat);
    }
}
void SimpleInterfaceServiceAdapter::onPropStringChanged(std::string propString)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
        m_node->notifyPropertyChange(propertyId, propString);
    }
}


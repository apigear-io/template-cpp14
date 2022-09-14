

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/olink/structinterfaceservice.adapter.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include <iostream>


using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructInterface";
}

StructInterfaceServiceAdapter::StructInterfaceServiceAdapter(IStructInterface& StructInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructInterface(StructInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_StructInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

StructInterfaceServiceAdapter::~StructInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_StructInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json StructInterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const StructBool& paramBool = fcnArgs.at(0);
        StructBool result = m_StructInterface.funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const StructInt& paramInt = fcnArgs.at(0);
        StructBool result = m_StructInterface.funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const StructFloat& paramFloat = fcnArgs.at(0);
        StructFloat result = m_StructInterface.funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const StructString& paramString = fcnArgs.at(0);
        StructString result = m_StructInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void StructInterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        StructBool propBool = value.get<StructBool>();
        m_StructInterface.setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        StructInt propInt = value.get<StructInt>();
        m_StructInterface.setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        StructFloat propFloat = value.get<StructFloat>();
        m_StructInterface.setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        StructString propString = value.get<StructString>();
        m_StructInterface.setPropString(propString);
    } 
}

void StructInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void StructInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json StructInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructInterface.getPropBool() },
        { "propInt", m_StructInterface.getPropInt() },
        { "propFloat", m_StructInterface.getPropFloat() },
        { "propString", m_StructInterface.getPropString() }
    });
}
void StructInterfaceServiceAdapter::onSigBool(const StructBool& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
        m_node->notifySignal(signalId, args);
    }
}
void StructInterfaceServiceAdapter::onSigInt(const StructInt& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
        m_node->notifySignal(signalId, args);
    }
}
void StructInterfaceServiceAdapter::onSigFloat(const StructFloat& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
        m_node->notifySignal(signalId, args);
    }
}
void StructInterfaceServiceAdapter::onSigString(const StructString& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
        m_node->notifySignal(signalId, args);
    }
}
void StructInterfaceServiceAdapter::onPropBoolChanged(const StructBool& propBool)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
        m_node->notifyPropertyChange(propertyId, propBool);
    }
}
void StructInterfaceServiceAdapter::onPropIntChanged(const StructInt& propInt)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
        m_node->notifyPropertyChange(propertyId, propInt);
    }
}
void StructInterfaceServiceAdapter::onPropFloatChanged(const StructFloat& propFloat)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
        m_node->notifyPropertyChange(propertyId, propFloat);
    }
}
void StructInterfaceServiceAdapter::onPropStringChanged(const StructString& propString)
{
    if(m_node != nullptr) {
        const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
        m_node->notifyPropertyChange(propertyId, propString);
    }
}


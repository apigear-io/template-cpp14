

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/olink/structarrayinterfaceservice.adapter.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include <iostream>


using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructArrayInterface";
}

StructArrayInterfaceServiceAdapter::StructArrayInterfaceServiceAdapter(IStructArrayInterface& StructArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructArrayInterface(StructArrayInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_StructArrayInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

StructArrayInterfaceServiceAdapter::~StructArrayInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_StructArrayInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructArrayInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json StructArrayInterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    std::string memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const std::list<StructBool>& paramBool = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const std::list<StructInt>& paramInt = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const std::list<StructFloat>& paramFloat = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::list<StructString>& paramString = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void StructArrayInterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    std::string memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        std::list<StructBool> propBool = value.get<std::list<StructBool>>();
        m_StructArrayInterface.setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        std::list<StructInt> propInt = value.get<std::list<StructInt>>();
        m_StructArrayInterface.setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        std::list<StructFloat> propFloat = value.get<std::list<StructFloat>>();
        m_StructArrayInterface.setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        std::list<StructString> propString = value.get<std::list<StructString>>();
        m_StructArrayInterface.setPropString(propString);
    } 
}

void StructArrayInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void StructArrayInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json StructArrayInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructArrayInterface.getPropBool() },
        { "propInt", m_StructArrayInterface.getPropInt() },
        { "propFloat", m_StructArrayInterface.getPropFloat() },
        { "propString", m_StructArrayInterface.getPropString() }
    });
}
void StructArrayInterfaceServiceAdapter::onSigBool(const std::list<StructBool>& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
        m_node->notifySignal(signalId, args);
    }
}
void StructArrayInterfaceServiceAdapter::onSigInt(const std::list<StructInt>& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
        m_node->notifySignal(signalId, args);
    }
}
void StructArrayInterfaceServiceAdapter::onSigFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
        m_node->notifySignal(signalId, args);
    }
}
void StructArrayInterfaceServiceAdapter::onSigString(const std::list<StructString>& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
        m_node->notifySignal(signalId, args);
    }
}
void StructArrayInterfaceServiceAdapter::onPropBoolChanged(const std::list<StructBool>& propBool)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
        m_node->notifyPropertyChange(propertyId, propBool);
    }
}
void StructArrayInterfaceServiceAdapter::onPropIntChanged(const std::list<StructInt>& propInt)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
        m_node->notifyPropertyChange(propertyId, propInt);
    }
}
void StructArrayInterfaceServiceAdapter::onPropFloatChanged(const std::list<StructFloat>& propFloat)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
        m_node->notifyPropertyChange(propertyId, propFloat);
    }
}
void StructArrayInterfaceServiceAdapter::onPropStringChanged(const std::list<StructString>& propString)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
        m_node->notifyPropertyChange(propertyId, propString);
    }
}


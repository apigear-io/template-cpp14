

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/simplearrayinterfaceservice.adapter.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleArrayInterface";
}

SimpleArrayInterfaceServiceAdapter::SimpleArrayInterfaceServiceAdapter(ISimpleArrayInterface& SimpleArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleArrayInterface(SimpleArrayInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SimpleArrayInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SimpleArrayInterfaceServiceAdapter::~SimpleArrayInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SimpleArrayInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleArrayInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SimpleArrayInterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    std::string memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const std::list<bool>& paramBool = fcnArgs.at(0);
        std::list<bool> result = m_SimpleArrayInterface.funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const std::list<int>& paramInt = fcnArgs.at(0);
        std::list<int> result = m_SimpleArrayInterface.funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const std::list<float>& paramFloat = fcnArgs.at(0);
        std::list<float> result = m_SimpleArrayInterface.funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::list<std::string>& paramString = fcnArgs.at(0);
        std::list<std::string> result = m_SimpleArrayInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleArrayInterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    std::string memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        std::list<bool> propBool = value.get<std::list<bool>>();
        m_SimpleArrayInterface.setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        std::list<int> propInt = value.get<std::list<int>>();
        m_SimpleArrayInterface.setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        std::list<float> propFloat = value.get<std::list<float>>();
        m_SimpleArrayInterface.setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        std::list<std::string> propString = value.get<std::list<std::string>>();
        m_SimpleArrayInterface.setPropString(propString);
    } 
}

void SimpleArrayInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SimpleArrayInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SimpleArrayInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleArrayInterface.getPropBool() },
        { "propInt", m_SimpleArrayInterface.getPropInt() },
        { "propFloat", m_SimpleArrayInterface.getPropFloat() },
        { "propString", m_SimpleArrayInterface.getPropString() }
    });
}
void SimpleArrayInterfaceServiceAdapter::onSigBool(const std::list<bool>& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
        m_node->notifySignal(signalId, args);
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigInt(const std::list<int>& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
        m_node->notifySignal(signalId, args);
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigFloat(const std::list<float>& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
        m_node->notifySignal(signalId, args);
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigString(const std::list<std::string>& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
        m_node->notifySignal(signalId, args);
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropBoolChanged(const std::list<bool>& propBool)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
        m_node->notifyPropertyChange(propertyId, propBool);
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropIntChanged(const std::list<int>& propInt)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
        m_node->notifyPropertyChange(propertyId, propInt);
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropFloatChanged(const std::list<float>& propFloat)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
        m_node->notifyPropertyChange(propertyId, propFloat);
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropStringChanged(const std::list<std::string>& propString)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
        m_node->notifyPropertyChange(propertyId, propString);
    }
}


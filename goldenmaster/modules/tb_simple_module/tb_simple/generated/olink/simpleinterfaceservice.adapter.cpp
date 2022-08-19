

#include "tb_simple/generated/olink/simpleinterfaceservice.adapter.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

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
    return "tb.simple.SimpleInterface";
}

nlohmann::json SimpleInterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const bool& paramBool = fcnArgs.at(0);
        bool result = m_SimpleInterface.funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const int& paramInt = fcnArgs.at(0);
        int result = m_SimpleInterface.funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const float& paramFloat = fcnArgs.at(0);
        float result = m_SimpleInterface.funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const std::string& paramString = fcnArgs.at(0);
        std::string result = m_SimpleInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleInterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        bool propBool = value.get<bool>();
        m_SimpleInterface.setPropBool(propBool);
    }
    if(path == "propInt") {
        int propInt = value.get<int>();
        m_SimpleInterface.setPropInt(propInt);
    }
    if(path == "propFloat") {
        float propFloat = value.get<float>();
        m_SimpleInterface.setPropFloat(propFloat);
    }
    if(path == "propString") {
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
        m_node->notifySignal("tb.simple.SimpleInterface/sigBool", args);
    }
}
void SimpleInterfaceServiceAdapter::onSigInt(int paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("tb.simple.SimpleInterface/sigInt", args);
    }
}
void SimpleInterfaceServiceAdapter::onSigFloat(float paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("tb.simple.SimpleInterface/sigFloat", args);
    }
}
void SimpleInterfaceServiceAdapter::onSigString(const std::string& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("tb.simple.SimpleInterface/sigString", args);
    }
}
void SimpleInterfaceServiceAdapter::onPropBoolChanged(bool propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propBool", propBool);
    }
}
void SimpleInterfaceServiceAdapter::onPropIntChanged(int propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propInt", propInt);
    }
}
void SimpleInterfaceServiceAdapter::onPropFloatChanged(float propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propFloat", propFloat);
    }
}
void SimpleInterfaceServiceAdapter::onPropStringChanged(std::string propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propString", propString);
    }
}


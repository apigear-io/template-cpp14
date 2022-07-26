/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include <iostream>
#include "tb_simple/generated/olink/simpleinterfaceservice.h"

//#include "../api/agent.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;

SimpleInterfaceService::SimpleInterfaceService(ISimpleInterface& SimpleInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleInterface(SimpleInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SimpleInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SimpleInterfaceService::~SimpleInterfaceService()
{
    m_registry.removeObjectSource(this);
    m_SimpleInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleInterfaceService::olinkObjectName() {
    return "tb.simple.SimpleInterface";
}

nlohmann::json SimpleInterfaceService::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
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

void SimpleInterfaceService::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        bool propBool = value.get<bool>();
        m_SimpleInterface.setPropbool(propBool);
    }
    if(path == "propInt") {
        int propInt = value.get<int>();
        m_SimpleInterface.setPropint(propInt);
    }
    if(path == "propFloat") {
        float propFloat = value.get<float>();
        m_SimpleInterface.setPropfloat(propFloat);
    }
    if(path == "propString") {
        std::string propString = value.get<std::string>();
        m_SimpleInterface.setPropstring(propString);
    } 
}

void SimpleInterfaceService::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SimpleInterfaceService::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SimpleInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleInterface.propBool() },
        { "propInt", m_SimpleInterface.propInt() },
        { "propFloat", m_SimpleInterface.propFloat() },
        { "propString", m_SimpleInterface.propString() }
    });
}
void SimpleInterfaceService::OnSigBool(bool paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("tb.simple.SimpleInterface/sigBool", args);
    }
}
void SimpleInterfaceService::OnSigInt(int paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("tb.simple.SimpleInterface/sigInt", args);
    }
}
void SimpleInterfaceService::OnSigFloat(float paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("tb.simple.SimpleInterface/sigFloat", args);
    }
}
void SimpleInterfaceService::OnSigString(const std::string& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("tb.simple.SimpleInterface/sigString", args);
    }
}
void SimpleInterfaceService::OnPropBoolChanged(bool propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propBool", propBool);
    }
}
void SimpleInterfaceService::OnPropIntChanged(int propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propInt", propInt);
    }
}
void SimpleInterfaceService::OnPropFloatChanged(float propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propFloat", propFloat);
    }
}
void SimpleInterfaceService::OnPropStringChanged(std::string propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propString", propString);
    }
}


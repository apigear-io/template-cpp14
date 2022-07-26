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
#include "tb_simple/generated/olink/simplearrayinterfaceservice.h"

//#include "../api/agent.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;

SimpleArrayInterfaceService::SimpleArrayInterfaceService(ISimpleArrayInterface& SimpleArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleArrayInterface(SimpleArrayInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SimpleArrayInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SimpleArrayInterfaceService::~SimpleArrayInterfaceService()
{
    m_registry.removeObjectSource(this);
    m_SimpleArrayInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleArrayInterfaceService::olinkObjectName() {
    return "tb.simple.SimpleArrayInterface";
}

nlohmann::json SimpleArrayInterfaceService::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const std::list<bool>& paramBool = fcnArgs.at(0);
        std::list<bool> result = m_SimpleArrayInterface.funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const std::list<int>& paramInt = fcnArgs.at(0);
        std::list<int> result = m_SimpleArrayInterface.funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const std::list<float>& paramFloat = fcnArgs.at(0);
        std::list<float> result = m_SimpleArrayInterface.funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const std::list<std::string>& paramString = fcnArgs.at(0);
        std::list<std::string> result = m_SimpleArrayInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleArrayInterfaceService::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        std::list<bool> propBool = value.get<std::list<bool>>();
        m_SimpleArrayInterface.setPropbool(propBool);
    }
    if(path == "propInt") {
        std::list<int> propInt = value.get<std::list<int>>();
        m_SimpleArrayInterface.setPropint(propInt);
    }
    if(path == "propFloat") {
        std::list<float> propFloat = value.get<std::list<float>>();
        m_SimpleArrayInterface.setPropfloat(propFloat);
    }
    if(path == "propString") {
        std::list<std::string> propString = value.get<std::list<std::string>>();
        m_SimpleArrayInterface.setPropstring(propString);
    } 
}

void SimpleArrayInterfaceService::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SimpleArrayInterfaceService::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SimpleArrayInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleArrayInterface.propBool() },
        { "propInt", m_SimpleArrayInterface.propInt() },
        { "propFloat", m_SimpleArrayInterface.propFloat() },
        { "propString", m_SimpleArrayInterface.propString() }
    });
}
void SimpleArrayInterfaceService::OnSigBool(const std::list<bool>& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigBool", args);
    }
}
void SimpleArrayInterfaceService::OnSigInt(const std::list<int>& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigInt", args);
    }
}
void SimpleArrayInterfaceService::OnSigFloat(const std::list<float>& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigFloat", args);
    }
}
void SimpleArrayInterfaceService::OnSigString(const std::list<std::string>& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigString", args);
    }
}
void SimpleArrayInterfaceService::OnPropBoolChanged(const std::list<bool>& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propBool", propBool);
    }
}
void SimpleArrayInterfaceService::OnPropIntChanged(const std::list<int>& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propInt", propInt);
    }
}
void SimpleArrayInterfaceService::OnPropFloatChanged(const std::list<float>& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propFloat", propFloat);
    }
}
void SimpleArrayInterfaceService::OnPropStringChanged(const std::list<std::string>& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propString", propString);
    }
}


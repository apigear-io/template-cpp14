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
#include "testbed1/generated/olink/structinterfaceservice.h"

//#include "../api/agent.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;

StructInterfaceService::StructInterfaceService(IStructInterface& StructInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructInterface(StructInterface)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_StructInterface._getPublisher().subscribeToStructInterfaceChanges(*this);
    m_registry->addObjectSource(this);
}

StructInterfaceService::~StructInterfaceService()
{
    m_registry->removeObjectSource(this);
    m_StructInterface._getPublisher().unsubscribeFromStructInterfaceChanges(*this);
}

std::string StructInterfaceService::olinkObjectName() {
    return "testbed1.StructInterface";
}

nlohmann::json StructInterfaceService::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const StructBool& paramBool = fcnArgs.at(0);
        StructBool result = m_StructInterface.funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const StructInt& paramInt = fcnArgs.at(0);
        StructBool result = m_StructInterface.funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const StructFloat& paramFloat = fcnArgs.at(0);
        StructFloat result = m_StructInterface.funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const StructString& paramString = fcnArgs.at(0);
        StructString result = m_StructInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void StructInterfaceService::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        StructBool propBool = value.get<StructBool>();
        m_StructInterface.setPropbool(propBool);
    }
    if(path == "propInt") {
        StructInt propInt = value.get<StructInt>();
        m_StructInterface.setPropint(propInt);
    }
    if(path == "propFloat") {
        StructFloat propFloat = value.get<StructFloat>();
        m_StructInterface.setPropfloat(propFloat);
    }
    if(path == "propString") {
        StructString propString = value.get<StructString>();
        m_StructInterface.setPropstring(propString);
    } 
}

void StructInterfaceService::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void StructInterfaceService::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json StructInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructInterface.propBool() },
        { "propInt", m_StructInterface.propInt() },
        { "propFloat", m_StructInterface.propFloat() },
        { "propString", m_StructInterface.propString() }
    });
}
void StructInterfaceService::OnSigBool(const StructBool& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("testbed1.StructInterface/sigBool", args);
    }
}
void StructInterfaceService::OnSigInt(const StructInt& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("testbed1.StructInterface/sigInt", args);
    }
}
void StructInterfaceService::OnSigFloat(const StructFloat& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("testbed1.StructInterface/sigFloat", args);
    }
}
void StructInterfaceService::OnSigString(const StructString& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("testbed1.StructInterface/sigString", args);
    }
}
void StructInterfaceService::OnPropBoolChanged(const StructBool& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propBool", propBool);
    }
}
void StructInterfaceService::OnPropIntChanged(const StructInt& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propInt", propInt);
    }
}
void StructInterfaceService::OnPropFloatChanged(const StructFloat& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propFloat", propFloat);
    }
}
void StructInterfaceService::OnPropStringChanged(const StructString& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propString", propString);
    }
}


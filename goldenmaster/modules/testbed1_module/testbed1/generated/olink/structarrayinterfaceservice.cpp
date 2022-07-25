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
#include "testbed1/generated/olink/structarrayinterfaceservice.h"

//#include "../api/agent.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;

StructArrayInterfaceService::StructArrayInterfaceService(IStructArrayInterface& StructArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructArrayInterface(StructArrayInterface)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_StructArrayInterface._getPublisher().subscribeToStructArrayInterfaceChanges(*this);
    m_registry->addObjectSource(this);
}

StructArrayInterfaceService::~StructArrayInterfaceService()
{
    m_registry->removeObjectSource(this);
    m_StructArrayInterface._getPublisher().unsubscribeFromStructArrayInterfaceChanges(*this);
}

std::string StructArrayInterfaceService::olinkObjectName() {
    return "testbed1.StructArrayInterface";
}

nlohmann::json StructArrayInterfaceService::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const std::list<StructBool>& paramBool = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const std::list<StructInt>& paramInt = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const std::list<StructFloat>& paramFloat = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const std::list<StructString>& paramString = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void StructArrayInterfaceService::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        std::list<StructBool> propBool = value.get<std::list<StructBool>>();
        m_StructArrayInterface.setPropbool(propBool);
    }
    if(path == "propInt") {
        std::list<StructInt> propInt = value.get<std::list<StructInt>>();
        m_StructArrayInterface.setPropint(propInt);
    }
    if(path == "propFloat") {
        std::list<StructFloat> propFloat = value.get<std::list<StructFloat>>();
        m_StructArrayInterface.setPropfloat(propFloat);
    }
    if(path == "propString") {
        std::list<StructString> propString = value.get<std::list<StructString>>();
        m_StructArrayInterface.setPropstring(propString);
    } 
}

void StructArrayInterfaceService::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void StructArrayInterfaceService::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json StructArrayInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructArrayInterface.propBool() },
        { "propInt", m_StructArrayInterface.propInt() },
        { "propFloat", m_StructArrayInterface.propFloat() },
        { "propString", m_StructArrayInterface.propString() }
    });
}
void StructArrayInterfaceService::OnSigBool(const std::list<StructBool>& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("testbed1.StructArrayInterface/sigBool", args);
    }
}
void StructArrayInterfaceService::OnSigInt(const std::list<StructInt>& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("testbed1.StructArrayInterface/sigInt", args);
    }
}
void StructArrayInterfaceService::OnSigFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("testbed1.StructArrayInterface/sigFloat", args);
    }
}
void StructArrayInterfaceService::OnSigString(const std::list<StructString>& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("testbed1.StructArrayInterface/sigString", args);
    }
}
void StructArrayInterfaceService::OnPropBoolChanged(const std::list<StructBool>& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propBool", propBool);
    }
}
void StructArrayInterfaceService::OnPropIntChanged(const std::list<StructInt>& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propInt", propInt);
    }
}
void StructArrayInterfaceService::OnPropFloatChanged(const std::list<StructFloat>& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propFloat", propFloat);
    }
}
void StructArrayInterfaceService::OnPropStringChanged(const std::list<StructString>& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propString", propString);
    }
}


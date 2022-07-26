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
#include "testbed2/generated/olink/nestedstruct3interfaceservice.h"

//#include "../api/agent.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;

NestedStruct3InterfaceService::NestedStruct3InterfaceService(INestedStruct3Interface& NestedStruct3Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct3Interface(NestedStruct3Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_NestedStruct3Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

NestedStruct3InterfaceService::~NestedStruct3InterfaceService()
{
    m_registry.removeObjectSource(this);
    m_NestedStruct3Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct3InterfaceService::olinkObjectName() {
    return "testbed2.NestedStruct3Interface";
}

nlohmann::json NestedStruct3InterfaceService::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_NestedStruct3Interface.func1(param1);
        return result;
    }
    if(path == "func2") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        const NestedStruct2& param2 = fcnArgs.at(1);
        NestedStruct1 result = m_NestedStruct3Interface.func2(param1, param2);
        return result;
    }
    if(path == "func3") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        const NestedStruct2& param2 = fcnArgs.at(1);
        const NestedStruct3& param3 = fcnArgs.at(2);
        NestedStruct1 result = m_NestedStruct3Interface.func3(param1, param2, param3);
        return result;
    }
    return nlohmann::json();
}

void NestedStruct3InterfaceService::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_NestedStruct3Interface.setProp1(prop1);
    }
    if(path == "prop2") {
        NestedStruct2 prop2 = value.get<NestedStruct2>();
        m_NestedStruct3Interface.setProp2(prop2);
    }
    if(path == "prop3") {
        NestedStruct3 prop3 = value.get<NestedStruct3>();
        m_NestedStruct3Interface.setProp3(prop3);
    } 
}

void NestedStruct3InterfaceService::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void NestedStruct3InterfaceService::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json NestedStruct3InterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_NestedStruct3Interface.prop1() },
        { "prop2", m_NestedStruct3Interface.prop2() },
        { "prop3", m_NestedStruct3Interface.prop3() }
    });
}
void NestedStruct3InterfaceService::OnSig1(const NestedStruct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("testbed2.NestedStruct3Interface/sig1", args);
    }
}
void NestedStruct3InterfaceService::OnSig2(const NestedStruct1& param1,const NestedStruct2& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        m_node->notifySignal("testbed2.NestedStruct3Interface/sig2", args);
    }
}
void NestedStruct3InterfaceService::OnSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2, param3 };
        m_node->notifySignal("testbed2.NestedStruct3Interface/sig3", args);
    }
}
void NestedStruct3InterfaceService::OnProp1Changed(const NestedStruct1& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.NestedStruct3Interface/prop1", prop1);
    }
}
void NestedStruct3InterfaceService::OnProp2Changed(const NestedStruct2& prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.NestedStruct3Interface/prop2", prop2);
    }
}
void NestedStruct3InterfaceService::OnProp3Changed(const NestedStruct3& prop3)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.NestedStruct3Interface/prop3", prop3);
    }
}


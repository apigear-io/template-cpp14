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
#include "tb_same2/generated/olink/samestruct2interfaceservice.h"

//#include "../api/agent.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

using namespace Test::TbSame2;

SameStruct2InterfaceService::SameStruct2InterfaceService(ISameStruct2Interface& SameStruct2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameStruct2Interface(SameStruct2Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SameStruct2Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SameStruct2InterfaceService::~SameStruct2InterfaceService()
{
    m_registry.removeObjectSource(this);
    m_SameStruct2Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameStruct2InterfaceService::olinkObjectName() {
    return "tb.same2.SameStruct2Interface";
}

nlohmann::json SameStruct2InterfaceService::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const Struct1& param1 = fcnArgs.at(0);
        Struct1 result = m_SameStruct2Interface.func1(param1);
        return result;
    }
    if(path == "func2") {
        const Struct1& param1 = fcnArgs.at(0);
        const Struct2& param2 = fcnArgs.at(1);
        Struct1 result = m_SameStruct2Interface.func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void SameStruct2InterfaceService::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        Struct2 prop1 = value.get<Struct2>();
        m_SameStruct2Interface.setProp1(prop1);
    }
    if(path == "prop2") {
        Struct2 prop2 = value.get<Struct2>();
        m_SameStruct2Interface.setProp2(prop2);
    } 
}

void SameStruct2InterfaceService::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SameStruct2InterfaceService::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SameStruct2InterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameStruct2Interface.prop1() },
        { "prop2", m_SameStruct2Interface.prop2() }
    });
}
void SameStruct2InterfaceService::OnSig1(const Struct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("tb.same2.SameStruct2Interface/sig1", args);
    }
}
void SameStruct2InterfaceService::OnSig2(const Struct1& param1,const Struct2& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        m_node->notifySignal("tb.same2.SameStruct2Interface/sig2", args);
    }
}
void SameStruct2InterfaceService::OnProp1Changed(const Struct2& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same2.SameStruct2Interface/prop1", prop1);
    }
}
void SameStruct2InterfaceService::OnProp2Changed(const Struct2& prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same2.SameStruct2Interface/prop2", prop2);
    }
}


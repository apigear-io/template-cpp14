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


#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/olink/sameenum2interfaceservice.adapter.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include <iostream>


using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

namespace 
{
const std::string interfaceId = "tb.same1.SameEnum2Interface";
}

SameEnum2InterfaceServiceAdapter::SameEnum2InterfaceServiceAdapter(ISameEnum2Interface& SameEnum2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameEnum2Interface(SameEnum2Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SameEnum2Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SameEnum2InterfaceServiceAdapter::~SameEnum2InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SameEnum2Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameEnum2InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SameEnum2InterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    std::string memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_SameEnum2Interface.func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        const Enum2Enum& param2 = fcnArgs.at(1);
        Enum1Enum result = m_SameEnum2Interface.func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void SameEnum2InterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    std::string memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_SameEnum2Interface.setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        Enum2Enum prop2 = value.get<Enum2Enum>();
        m_SameEnum2Interface.setProp2(prop2);
    } 
}

void SameEnum2InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SameEnum2InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SameEnum2InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameEnum2Interface.prop1() },
        { "prop2", m_SameEnum2Interface.prop2() }
    });
}
void SameEnum2InterfaceServiceAdapter::onSig1(const Enum1Enum& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
        m_node->notifySignal(signalId, args);
    }
}
void SameEnum2InterfaceServiceAdapter::onSig2(const Enum1Enum& param1,const Enum2Enum& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
        m_node->notifySignal(signalId, args);
    }
}
void SameEnum2InterfaceServiceAdapter::onProp1Changed(const Enum1Enum& prop1)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
        m_node->notifyPropertyChange(propertyId, prop1);
    }
}
void SameEnum2InterfaceServiceAdapter::onProp2Changed(const Enum2Enum& prop2)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
        m_node->notifyPropertyChange(propertyId, prop2);
    }
}


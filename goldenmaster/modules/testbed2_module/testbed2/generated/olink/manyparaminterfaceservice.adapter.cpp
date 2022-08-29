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


#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/manyparaminterfaceservice.adapter.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>


using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.ManyParamInterface";
}

ManyParamInterfaceServiceAdapter::ManyParamInterfaceServiceAdapter(IManyParamInterface& ManyParamInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_ManyParamInterface(ManyParamInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_ManyParamInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

ManyParamInterfaceServiceAdapter::~ManyParamInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_ManyParamInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string ManyParamInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json ManyParamInterfaceServiceAdapter::olinkInvoke(std::string methodId, nlohmann::json fcnArgs) {
    std::clog << methodId << std::endl;
    std::string memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const int& param1 = fcnArgs.at(0);
        int result = m_ManyParamInterface.func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        int result = m_ManyParamInterface.func2(param1, param2);
        return result;
    }
    if(memberMethod == "func3") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        const int& param3 = fcnArgs.at(2);
        int result = m_ManyParamInterface.func3(param1, param2, param3);
        return result;
    }
    if(memberMethod == "func4") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        const int& param3 = fcnArgs.at(2);
        const int& param4 = fcnArgs.at(3);
        int result = m_ManyParamInterface.func4(param1, param2, param3, param4);
        return result;
    }
    return nlohmann::json();
}

void ManyParamInterfaceServiceAdapter::olinkSetProperty(std::string propertyId, nlohmann::json value) {
    std::clog << propertyId << std::endl;
    std::string memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        int prop1 = value.get<int>();
        m_ManyParamInterface.setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        int prop2 = value.get<int>();
        m_ManyParamInterface.setProp2(prop2);
    }
    if(memberProperty == "prop3") {
        int prop3 = value.get<int>();
        m_ManyParamInterface.setProp3(prop3);
    }
    if(memberProperty == "prop4") {
        int prop4 = value.get<int>();
        m_ManyParamInterface.setProp4(prop4);
    } 
}

void ManyParamInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void ManyParamInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json ManyParamInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_ManyParamInterface.prop1() },
        { "prop2", m_ManyParamInterface.prop2() },
        { "prop3", m_ManyParamInterface.prop3() },
        { "prop4", m_ManyParamInterface.prop4() }
    });
}
void ManyParamInterfaceServiceAdapter::onSig1(int param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
        m_node->notifySignal(signalId, args);
    }
}
void ManyParamInterfaceServiceAdapter::onSig2(int param1,int param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
        m_node->notifySignal(signalId, args);
    }
}
void ManyParamInterfaceServiceAdapter::onSig3(int param1,int param2,int param3)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2, param3 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3");
        m_node->notifySignal(signalId, args);
    }
}
void ManyParamInterfaceServiceAdapter::onSig4(int param1,int param2,int param3,int param4)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2, param3, param4 };
        auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig4");
        m_node->notifySignal(signalId, args);
    }
}
void ManyParamInterfaceServiceAdapter::onProp1Changed(int prop1)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
        m_node->notifyPropertyChange(propertyId, prop1);
    }
}
void ManyParamInterfaceServiceAdapter::onProp2Changed(int prop2)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
        m_node->notifyPropertyChange(propertyId, prop2);
    }
}
void ManyParamInterfaceServiceAdapter::onProp3Changed(int prop3)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
        m_node->notifyPropertyChange(propertyId, prop3);
    }
}
void ManyParamInterfaceServiceAdapter::onProp4Changed(int prop4)
{
    if(m_node != nullptr) {
        auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop4");
        m_node->notifyPropertyChange(propertyId, prop4);
    }
}


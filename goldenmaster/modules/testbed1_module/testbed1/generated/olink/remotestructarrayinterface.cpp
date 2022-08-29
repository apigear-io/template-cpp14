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


#include "testbed1/generated/olink/remotestructarrayinterface.h"
#include "testbed1/generated/core/structarrayinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructArrayInterface";
}

RemoteStructArrayInterface::RemoteStructArrayInterface(ApiGear::PocoImpl::IOlinkConnector& olinkConnector)
    : m_olinkConnector(olinkConnector),
      m_publisher(std::make_unique<StructArrayInterfacePublisher>())
{
    m_olinkConnector.connectAndLinkObject(*this);
}

RemoteStructArrayInterface::~RemoteStructArrayInterface()
{
    m_olinkConnector.disconnectAndUnlink(olinkObjectName());
}

void RemoteStructArrayInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<std::list<StructBool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<std::list<StructInt>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<std::list<StructFloat>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<std::list<StructString>>());
    }
}

void RemoteStructArrayInterface::setPropBool(const std::list<StructBool>& propBool)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    m_node->setRemoteProperty(propertyId, propBool);
}

void RemoteStructArrayInterface::setPropBoolLocal(const std::list<StructBool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<StructBool>& RemoteStructArrayInterface::propBool() const
{
    return m_data.m_propBool;
}

void RemoteStructArrayInterface::setPropInt(const std::list<StructInt>& propInt)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    m_node->setRemoteProperty(propertyId, propInt);
}

void RemoteStructArrayInterface::setPropIntLocal(const std::list<StructInt>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<StructInt>& RemoteStructArrayInterface::propInt() const
{
    return m_data.m_propInt;
}

void RemoteStructArrayInterface::setPropFloat(const std::list<StructFloat>& propFloat)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    m_node->setRemoteProperty(propertyId, propFloat);
}

void RemoteStructArrayInterface::setPropFloatLocal(const std::list<StructFloat>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<StructFloat>& RemoteStructArrayInterface::propFloat() const
{
    return m_data.m_propFloat;
}

void RemoteStructArrayInterface::setPropString(const std::list<StructString>& propString)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    m_node->setRemoteProperty(propertyId, propString);
}

void RemoteStructArrayInterface::setPropStringLocal(const std::list<StructString>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<StructString>& RemoteStructArrayInterface::propString() const
{
    return m_data.m_propString;
}

StructBool RemoteStructArrayInterface::funcBool(const std::list<StructBool>& paramBool)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> RemoteStructArrayInterface::funcBoolAsync(const std::list<StructBool>& paramBool)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<StructBool>{};
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<StructBool> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool RemoteStructArrayInterface::funcInt(const std::list<StructInt>& paramInt)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> RemoteStructArrayInterface::funcIntAsync(const std::list<StructInt>& paramInt)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<StructBool>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<StructBool> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool RemoteStructArrayInterface::funcFloat(const std::list<StructFloat>& paramFloat)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return StructBool();
    }
    StructBool value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructBool> RemoteStructArrayInterface::funcFloatAsync(const std::list<StructFloat>& paramFloat)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<StructBool>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructBool> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool RemoteStructArrayInterface::funcString(const std::list<StructString>& paramString)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return StructBool();
    }
    StructBool value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructBool> RemoteStructArrayInterface::funcStringAsync(const std::list<StructString>& paramString)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<StructBool>{};
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructBool> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteStructArrayInterface::olinkObjectName()
{
    return interfaceId;
}

void RemoteStructArrayInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    auto signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        m_publisher->publishSigBool(args[0].get<std::list<StructBool>>());   
        return;
    }
    if(signalName == "sigInt") {
        m_publisher->publishSigInt(args[0].get<std::list<StructInt>>());   
        return;
    }
    if(signalName == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<std::list<StructFloat>>());   
        return;
    }
    if(signalName == "sigString") {
        m_publisher->publishSigString(args[0].get<std::list<StructString>>());   
        return;
    }
}

void RemoteStructArrayInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void RemoteStructArrayInterface::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteStructArrayInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteStructArrayInterface::isReady() const
{
    return m_node;
}

IStructArrayInterfacePublisher& RemoteStructArrayInterface::_getPublisher() const
{
    return *m_publisher;
}

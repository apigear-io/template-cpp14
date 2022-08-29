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


#include "tb_same2/generated/olink/remotesameenum2interface.h"
#include "tb_same2/generated/core/sameenum2interface.publisher.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::TbSame2;
using namespace Test::TbSame2::olink;

namespace 
{
const std::string interfaceId = "tb.same2.SameEnum2Interface";
}

RemoteSameEnum2Interface::RemoteSameEnum2Interface(ApiGear::PocoImpl::IOlinkConnector& olinkConnector)
    : m_olinkConnector(olinkConnector),
      m_publisher(std::make_unique<SameEnum2InterfacePublisher>())
{
    m_olinkConnector.connectAndLinkObject(*this);
}

RemoteSameEnum2Interface::~RemoteSameEnum2Interface()
{
    m_olinkConnector.disconnectAndUnlink(olinkObjectName());
}

void RemoteSameEnum2Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2Enum>());
    }
}

void RemoteSameEnum2Interface::setProp1(const Enum1Enum& prop1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, prop1);
}

void RemoteSameEnum2Interface::setProp1Local(const Enum1Enum& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& RemoteSameEnum2Interface::prop1() const
{
    return m_data.m_prop1;
}

void RemoteSameEnum2Interface::setProp2(const Enum2Enum& prop2)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    m_node->setRemoteProperty(propertyId, prop2);
}

void RemoteSameEnum2Interface::setProp2Local(const Enum2Enum& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Enum2Enum& RemoteSameEnum2Interface::prop2() const
{
    return m_data.m_prop2;
}

Enum1Enum RemoteSameEnum2Interface::func1(const Enum1Enum& param1)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> RemoteSameEnum2Interface::func1Async(const Enum1Enum& param1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<Enum1Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum RemoteSameEnum2Interface::func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return Enum1Enum::value1;
    }
    Enum1Enum value(func2Async(param1, param2).get());
    return value;
}

std::future<Enum1Enum> RemoteSameEnum2Interface::func2Async(const Enum1Enum& param1, const Enum2Enum& param2)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<Enum1Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<Enum1Enum> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1,param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSameEnum2Interface::olinkObjectName()
{
    return interfaceId;
}

void RemoteSameEnum2Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    auto signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sig1") {
        m_publisher->publishSig1(args[0].get<Enum1Enum>());   
        return;
    }
    if(signalName == "sig2") {
        m_publisher->publishSig2(args[0].get<Enum1Enum>(),args[1].get<Enum2Enum>());   
        return;
    }
}

void RemoteSameEnum2Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void RemoteSameEnum2Interface::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteSameEnum2Interface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSameEnum2Interface::isReady() const
{
    return m_node;
}

ISameEnum2InterfacePublisher& RemoteSameEnum2Interface::_getPublisher() const
{
    return *m_publisher;
}

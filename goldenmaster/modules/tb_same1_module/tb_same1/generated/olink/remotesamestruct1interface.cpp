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


#include "tb_same1/generated/olink/remotesamestruct1interface.h"
#include "tb_same1/generated/core/samestruct1interface.publisher.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

namespace 
{
const std::string interfaceId = "tb.same1.SameStruct1Interface";
}

RemoteSameStruct1Interface::RemoteSameStruct1Interface(ApiGear::PocoImpl::IOlinkConnector& olinkConnector)
    : m_olinkConnector(olinkConnector),
      m_publisher(std::make_unique<SameStruct1InterfacePublisher>())
{
    m_olinkConnector.connectAndLinkObject(*this);
}

RemoteSameStruct1Interface::~RemoteSameStruct1Interface()
{
    m_olinkConnector.disconnectAndUnlink(olinkObjectName());
}

void RemoteSameStruct1Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct1>());
    }
}

void RemoteSameStruct1Interface::setProp1(const Struct1& prop1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, prop1);
}

void RemoteSameStruct1Interface::setProp1Local(const Struct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct1& RemoteSameStruct1Interface::prop1() const
{
    return m_data.m_prop1;
}

Struct1 RemoteSameStruct1Interface::func1(const Struct1& param1)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return Struct1();
    }
    Struct1 value(func1Async(param1).get());
    return value;
}

std::future<Struct1> RemoteSameStruct1Interface::func1Async(const Struct1& param1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<Struct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Struct1> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Struct1& value = arg.value.get<Struct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSameStruct1Interface::olinkObjectName()
{
    return interfaceId;
}

void RemoteSameStruct1Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    auto signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sig1") {
        m_publisher->publishSig1(args[0].get<Struct1>());   
        return;
    }
}

void RemoteSameStruct1Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void RemoteSameStruct1Interface::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteSameStruct1Interface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSameStruct1Interface::isReady() const
{
    return m_node;
}

ISameStruct1InterfacePublisher& RemoteSameStruct1Interface::_getPublisher() const
{
    return *m_publisher;
}

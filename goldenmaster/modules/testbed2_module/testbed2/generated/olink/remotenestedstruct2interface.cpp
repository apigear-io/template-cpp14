

#include "testbed2/generated/olink/remotenestedstruct2interface.h"
#include "testbed2/generated/core/nestedstruct2interface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.NestedStruct2Interface";
}

RemoteNestedStruct2Interface::RemoteNestedStruct2Interface(ApiGear::PocoImpl::IOlinkConnector& olinkConnector)
    : m_olinkConnector(olinkConnector),
      m_publisher(std::make_unique<NestedStruct2InterfacePublisher>())
{
    m_olinkConnector.connectAndLinkObject(*this);
}

RemoteNestedStruct2Interface::~RemoteNestedStruct2Interface()
{
    m_olinkConnector.disconnectAndUnlink(olinkObjectName());
}

void RemoteNestedStruct2Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
}

void RemoteNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, prop1);
}

void RemoteNestedStruct2Interface::setProp1Local(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& RemoteNestedStruct2Interface::getProp1() const
{
    return m_data.m_prop1;
}

void RemoteNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    m_node->setRemoteProperty(propertyId, prop2);
}

void RemoteNestedStruct2Interface::setProp2Local(const NestedStruct2& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& RemoteNestedStruct2Interface::getProp2() const
{
    return m_data.m_prop2;
}

NestedStruct1 RemoteNestedStruct2Interface::func1(const NestedStruct1& param1)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> RemoteNestedStruct2Interface::func1Async(const NestedStruct1& param1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<NestedStruct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

NestedStruct1 RemoteNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return NestedStruct1();
    }
    NestedStruct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<NestedStruct1> RemoteNestedStruct2Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method, but network connection is not set for " + olinkObjectName() +" please check if IClientNode is linked for this object");
        return std::future<NestedStruct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<NestedStruct1> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1,param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteNestedStruct2Interface::olinkObjectName()
{
    return interfaceId;
}

void RemoteNestedStruct2Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    auto signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sig1") {
        m_publisher->publishSig1(args[0].get<NestedStruct1>());   
        return;
    }
    if(signalName == "sig2") {
        m_publisher->publishSig2(args[0].get<NestedStruct1>(),args[1].get<NestedStruct2>());   
        return;
    }
}

void RemoteNestedStruct2Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void RemoteNestedStruct2Interface::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteNestedStruct2Interface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteNestedStruct2Interface::isReady() const
{
    return m_node;
}

INestedStruct2InterfacePublisher& RemoteNestedStruct2Interface::_getPublisher() const
{
    return *m_publisher;
}

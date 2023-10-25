

#include "tb_same1/generated/olink/samestruct2interfaceclient.h"
#include "tb_same1/generated/core/samestruct2interface.publisher.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

namespace 
{
const std::string interfaceId = "tb.same1.SameStruct2Interface";
}

SameStruct2InterfaceClient::SameStruct2InterfaceClient()
    : m_publisher(std::make_unique<SameStruct2InterfacePublisher>())
{}

void SameStruct2InterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "prop1") {
        Struct2 value_prop1 {};
        readValue(value, value_prop1);
        setProp1Local(value_prop1);
    }
    else if ( propertyName == "prop2") {
        Struct2 value_prop2 {};
        readValue(value, value_prop2);
        setProp2Local(value_prop2);
    }
}

void SameStruct2InterfaceClient::setProp1(const Struct2& prop1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop1));
}

void SameStruct2InterfaceClient::setProp1Local(const Struct2& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct2& SameStruct2InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void SameStruct2InterfaceClient::setProp2(const Struct2& prop2)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop2));
}

void SameStruct2InterfaceClient::setProp2Local(const Struct2& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Struct2& SameStruct2InterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

Struct1 SameStruct2InterfaceClient::func1(const Struct1& param1)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Struct1();
    }
    Struct1 value(func1Async(param1).get());
    return value;
}

std::future<Struct1> SameStruct2InterfaceClient::func1Async(const Struct1& param1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Struct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Struct1> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    Struct1 result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

Struct1 SameStruct2InterfaceClient::func2(const Struct1& param1, const Struct2& param2)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Struct1();
    }
    Struct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<Struct1> SameStruct2InterfaceClient::func2Async(const Struct1& param1, const Struct2& param2)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Struct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<Struct1> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1, param2 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    Struct1 result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string SameStruct2InterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void SameStruct2InterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sig1") {Struct1 arg_param1 {};
        argumentsReader.read(arg_param1);m_publisher->publishSig1(arg_param1);   
        return;
    }
    if(signalName == "sig2") {Struct1 arg_param1 {};
        argumentsReader.read(arg_param1);Struct2 arg_param2 {};
        argumentsReader.read(arg_param2);m_publisher->publishSig2(arg_param1,arg_param2);   
        return;
    }
}

void SameStruct2InterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void SameStruct2InterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    ApiGear::ObjectLink::OLinContentStreamReader reader(props);
    size_t propertyCount = reader.argumentsCount();
    ApiGear::ObjectLink::InitialProperty currentProperty;
    for (size_t i = 0; i < propertyCount; i++)
    {
        reader.read(currentProperty);
        applyProperty(currentProperty.propertyName, currentProperty.propertyValue);
    }
}

void SameStruct2InterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool SameStruct2InterfaceClient::isReady() const
{
    return m_node != nullptr;
}

ISameStruct2InterfacePublisher& SameStruct2InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

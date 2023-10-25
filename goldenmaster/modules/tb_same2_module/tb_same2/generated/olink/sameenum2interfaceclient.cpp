

#include "tb_same2/generated/olink/sameenum2interfaceclient.h"
#include "tb_same2/generated/core/sameenum2interface.publisher.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::TbSame2;
using namespace Test::TbSame2::olink;

namespace 
{
const std::string interfaceId = "tb.same2.SameEnum2Interface";
}

SameEnum2InterfaceClient::SameEnum2InterfaceClient()
    : m_publisher(std::make_unique<SameEnum2InterfacePublisher>())
{}

void SameEnum2InterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "prop1") {
        Enum1Enum value_prop1 {};
        readValue(value, value_prop1);
        setProp1Local(value_prop1);
    }
    else if ( propertyName == "prop2") {
        Enum2Enum value_prop2 {};
        readValue(value, value_prop2);
        setProp2Local(value_prop2);
    }
}

void SameEnum2InterfaceClient::setProp1(Enum1Enum prop1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop1));
}

void SameEnum2InterfaceClient::setProp1Local(Enum1Enum prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

Enum1Enum SameEnum2InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void SameEnum2InterfaceClient::setProp2(Enum2Enum prop2)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop2));
}

void SameEnum2InterfaceClient::setProp2Local(Enum2Enum prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

Enum2Enum SameEnum2InterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

Enum1Enum SameEnum2InterfaceClient::func1(Enum1Enum param1)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> SameEnum2InterfaceClient::func1Async(Enum1Enum param1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Enum1Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    Enum1Enum result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum SameEnum2InterfaceClient::func2(Enum1Enum param1, Enum2Enum param2)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Enum1Enum::value1;
    }
    Enum1Enum value(func2Async(param1, param2).get());
    return value;
}

std::future<Enum1Enum> SameEnum2InterfaceClient::func2Async(Enum1Enum param1, Enum2Enum param2)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Enum1Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<Enum1Enum> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1, param2 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    Enum1Enum result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string SameEnum2InterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void SameEnum2InterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sig1") {Enum1Enum arg_param1 {};
        argumentsReader.read(arg_param1);m_publisher->publishSig1(arg_param1);   
        return;
    }
    if(signalName == "sig2") {Enum1Enum arg_param1 {};
        argumentsReader.read(arg_param1);Enum2Enum arg_param2 {};
        argumentsReader.read(arg_param2);m_publisher->publishSig2(arg_param1,arg_param2);   
        return;
    }
}

void SameEnum2InterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void SameEnum2InterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void SameEnum2InterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool SameEnum2InterfaceClient::isReady() const
{
    return m_node != nullptr;
}

ISameEnum2InterfacePublisher& SameEnum2InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}



#include "tb_same1/generated/olink/sameenum1interfaceclient.h"
#include "tb_same1/generated/core/sameenum1interface.publisher.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

namespace 
{
const std::string interfaceId = "tb.same1.SameEnum1Interface";
}

SameEnum1InterfaceClient::SameEnum1InterfaceClient()
    : m_publisher(std::make_unique<SameEnum1InterfacePublisher>())
{}

void SameEnum1InterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "prop1") {
        Enum1Enum value_prop1 {};
        readValue(value, value_prop1);
        setProp1Local(value_prop1);
    }
}

void SameEnum1InterfaceClient::setProp1(Enum1Enum prop1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop1));
}

void SameEnum1InterfaceClient::setProp1Local(Enum1Enum prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

Enum1Enum SameEnum1InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

Enum1Enum SameEnum1InterfaceClient::func1(Enum1Enum param1)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> SameEnum1InterfaceClient::func1Async(Enum1Enum param1)
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

std::string SameEnum1InterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void SameEnum1InterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sig1") {Enum1Enum arg_param1 {};
        argumentsReader.read(arg_param1);m_publisher->publishSig1(arg_param1);   
        return;
    }
}

void SameEnum1InterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void SameEnum1InterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void SameEnum1InterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool SameEnum1InterfaceClient::isReady() const
{
    return m_node != nullptr;
}

ISameEnum1InterfacePublisher& SameEnum1InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

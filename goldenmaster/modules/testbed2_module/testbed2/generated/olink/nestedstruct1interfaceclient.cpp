

#include "testbed2/generated/olink/nestedstruct1interfaceclient.h"
#include "testbed2/generated/core/nestedstruct1interface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.NestedStruct1Interface";
}

NestedStruct1InterfaceClient::NestedStruct1InterfaceClient()
    : m_publisher(std::make_unique<NestedStruct1InterfacePublisher>())
{}

void NestedStruct1InterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "prop1") {
        NestedStruct1 value_prop1 {};
        readValue(value, value_prop1);
        setProp1Local(value_prop1);
    }
}

void NestedStruct1InterfaceClient::setProp1(const NestedStruct1& prop1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop1));
}

void NestedStruct1InterfaceClient::setProp1Local(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct1InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

NestedStruct1 NestedStruct1InterfaceClient::func1(const NestedStruct1& param1)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> NestedStruct1InterfaceClient::func1Async(const NestedStruct1& param1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<NestedStruct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    NestedStruct1 result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string NestedStruct1InterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void NestedStruct1InterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sig1") {NestedStruct1 arg_param1 {};
        argumentsReader.read(arg_param1);m_publisher->publishSig1(arg_param1);   
        return;
    }
}

void NestedStruct1InterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void NestedStruct1InterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void NestedStruct1InterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool NestedStruct1InterfaceClient::isReady() const
{
    return m_node != nullptr;
}

INestedStruct1InterfacePublisher& NestedStruct1InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

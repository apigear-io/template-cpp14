

#include "testbed2/generated/olink/manyparaminterfaceclient.h"
#include "testbed2/generated/core/manyparaminterface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.ManyParamInterface";
}

ManyParamInterfaceClient::ManyParamInterfaceClient()
    : m_publisher(std::make_unique<ManyParamInterfacePublisher>())
{}

void ManyParamInterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "prop1") {
        int value_prop1 {};
        readValue(value, value_prop1);
        setProp1Local(value_prop1);
    }
    else if ( propertyName == "prop2") {
        int value_prop2 {};
        readValue(value, value_prop2);
        setProp2Local(value_prop2);
    }
    else if ( propertyName == "prop3") {
        int value_prop3 {};
        readValue(value, value_prop3);
        setProp3Local(value_prop3);
    }
    else if ( propertyName == "prop4") {
        int value_prop4 {};
        readValue(value, value_prop4);
        setProp4Local(value_prop4);
    }
}

void ManyParamInterfaceClient::setProp1(int prop1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop1));
}

void ManyParamInterfaceClient::setProp1Local(int prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

int ManyParamInterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void ManyParamInterfaceClient::setProp2(int prop2)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop2));
}

void ManyParamInterfaceClient::setProp2Local(int prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

int ManyParamInterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

void ManyParamInterfaceClient::setProp3(int prop3)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop3));
}

void ManyParamInterfaceClient::setProp3Local(int prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

int ManyParamInterfaceClient::getProp3() const
{
    return m_data.m_prop3;
}

void ManyParamInterfaceClient::setProp4(int prop4)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop4");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(prop4));
}

void ManyParamInterfaceClient::setProp4Local(int prop4)
{
    if (m_data.m_prop4 != prop4) {
        m_data.m_prop4 = prop4;
        m_publisher->publishProp4Changed(prop4);
    }
}

int ManyParamInterfaceClient::getProp4() const
{
    return m_data.m_prop4;
}

int ManyParamInterfaceClient::func1(int param1)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(func1Async(param1).get());
    return value;
}

std::future<int> ManyParamInterfaceClient::func1Async(int param1)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<int> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    int result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

int ManyParamInterfaceClient::func2(int param1, int param2)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(func2Async(param1, param2).get());
    return value;
}

std::future<int> ManyParamInterfaceClient::func2Async(int param1, int param2)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<int> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1, param2 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    int result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

int ManyParamInterfaceClient::func3(int param1, int param2, int param3)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(func3Async(param1, param2, param3).get());
    return value;
}

std::future<int> ManyParamInterfaceClient::func3Async(int param1, int param2, int param3)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            std::promise<int> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func3");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1, param2, param3 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    int result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

int ManyParamInterfaceClient::func4(int param1, int param2, int param3, int param4)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(func4Async(param1, param2, param3, param4).get());
    return value;
}

std::future<int> ManyParamInterfaceClient::func4Async(int param1, int param2, int param3, int param4)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3,
                    param4]()
        {
            std::promise<int> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func4");
            auto args = ApiGear::ObjectLink::argumentsToContent( param1, param2, param3, param4 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    int result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string ManyParamInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void ManyParamInterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sig1") {int arg_param1 {};
        argumentsReader.read(arg_param1);m_publisher->publishSig1(arg_param1);   
        return;
    }
    if(signalName == "sig2") {int arg_param1 {};
        argumentsReader.read(arg_param1);int arg_param2 {};
        argumentsReader.read(arg_param2);m_publisher->publishSig2(arg_param1,arg_param2);   
        return;
    }
    if(signalName == "sig3") {int arg_param1 {};
        argumentsReader.read(arg_param1);int arg_param2 {};
        argumentsReader.read(arg_param2);int arg_param3 {};
        argumentsReader.read(arg_param3);m_publisher->publishSig3(arg_param1,arg_param2,arg_param3);   
        return;
    }
    if(signalName == "sig4") {int arg_param1 {};
        argumentsReader.read(arg_param1);int arg_param2 {};
        argumentsReader.read(arg_param2);int arg_param3 {};
        argumentsReader.read(arg_param3);int arg_param4 {};
        argumentsReader.read(arg_param4);m_publisher->publishSig4(arg_param1,arg_param2,arg_param3,arg_param4);   
        return;
    }
}

void ManyParamInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void ManyParamInterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void ManyParamInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool ManyParamInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

IManyParamInterfacePublisher& ManyParamInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

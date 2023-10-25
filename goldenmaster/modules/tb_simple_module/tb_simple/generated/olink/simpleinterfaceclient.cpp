

#include "tb_simple/generated/olink/simpleinterfaceclient.h"
#include "tb_simple/generated/core/simpleinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleInterface";
}

SimpleInterfaceClient::SimpleInterfaceClient()
    : m_publisher(std::make_unique<SimpleInterfacePublisher>())
{}

void SimpleInterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "propBool") {
        bool value_propBool {};
        readValue(value, value_propBool);
        setPropBoolLocal(value_propBool);
    }
    else if ( propertyName == "propInt") {
        int value_propInt {};
        readValue(value, value_propInt);
        setPropIntLocal(value_propInt);
    }
    else if ( propertyName == "propInt32") {
        int32_t value_propInt32 {};
        readValue(value, value_propInt32);
        setPropInt32Local(value_propInt32);
    }
    else if ( propertyName == "propInt64") {
        int64_t value_propInt64 {};
        readValue(value, value_propInt64);
        setPropInt64Local(value_propInt64);
    }
    else if ( propertyName == "propFloat") {
        float value_propFloat {};
        readValue(value, value_propFloat);
        setPropFloatLocal(value_propFloat);
    }
    else if ( propertyName == "propFloat32") {
        float value_propFloat32 {};
        readValue(value, value_propFloat32);
        setPropFloat32Local(value_propFloat32);
    }
    else if ( propertyName == "propFloat64") {
        double value_propFloat64 {};
        readValue(value, value_propFloat64);
        setPropFloat64Local(value_propFloat64);
    }
    else if ( propertyName == "propString") {
        std::string value_propString {};
        readValue(value, value_propString);
        setPropStringLocal(value_propString);
    }
}

void SimpleInterfaceClient::setPropBool(bool propBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propBool));
}

void SimpleInterfaceClient::setPropBoolLocal(bool propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool SimpleInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void SimpleInterfaceClient::setPropInt(int propInt)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt));
}

void SimpleInterfaceClient::setPropIntLocal(int propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int SimpleInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void SimpleInterfaceClient::setPropInt32(int32_t propInt32)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt32");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt32));
}

void SimpleInterfaceClient::setPropInt32Local(int32_t propInt32)
{
    if (m_data.m_propInt32 != propInt32) {
        m_data.m_propInt32 = propInt32;
        m_publisher->publishPropInt32Changed(propInt32);
    }
}

int32_t SimpleInterfaceClient::getPropInt32() const
{
    return m_data.m_propInt32;
}

void SimpleInterfaceClient::setPropInt64(int64_t propInt64)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt64");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt64));
}

void SimpleInterfaceClient::setPropInt64Local(int64_t propInt64)
{
    if (m_data.m_propInt64 != propInt64) {
        m_data.m_propInt64 = propInt64;
        m_publisher->publishPropInt64Changed(propInt64);
    }
}

int64_t SimpleInterfaceClient::getPropInt64() const
{
    return m_data.m_propInt64;
}

void SimpleInterfaceClient::setPropFloat(float propFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat));
}

void SimpleInterfaceClient::setPropFloatLocal(float propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

float SimpleInterfaceClient::getPropFloat() const
{
    return m_data.m_propFloat;
}

void SimpleInterfaceClient::setPropFloat32(float propFloat32)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat32");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat32));
}

void SimpleInterfaceClient::setPropFloat32Local(float propFloat32)
{
    if (m_data.m_propFloat32 != propFloat32) {
        m_data.m_propFloat32 = propFloat32;
        m_publisher->publishPropFloat32Changed(propFloat32);
    }
}

float SimpleInterfaceClient::getPropFloat32() const
{
    return m_data.m_propFloat32;
}

void SimpleInterfaceClient::setPropFloat64(double propFloat64)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat64");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat64));
}

void SimpleInterfaceClient::setPropFloat64Local(double propFloat64)
{
    if (m_data.m_propFloat64 != propFloat64) {
        m_data.m_propFloat64 = propFloat64;
        m_publisher->publishPropFloat64Changed(propFloat64);
    }
}

double SimpleInterfaceClient::getPropFloat64() const
{
    return m_data.m_propFloat64;
}

void SimpleInterfaceClient::setPropString(const std::string& propString)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propString));
}

void SimpleInterfaceClient::setPropStringLocal(const std::string& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::string& SimpleInterfaceClient::getPropString() const
{
    return m_data.m_propString;
}

void SimpleInterfaceClient::funcNoReturnValue(bool paramBool)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    ApiGear::ObjectLink::InvokeReplyFunc func = [this](ApiGear::ObjectLink::InvokeReplyArg arg)
        {
            (void) this;
            (void) arg;
        };
    auto args = ApiGear::ObjectLink::argumentsToContent( paramBool );
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcNoReturnValue");
    m_node->invokeRemote(operationId, args, func);
}

std::future<void> SimpleInterfaceClient::funcNoReturnValueAsync(bool paramBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<void>{};
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<void> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcNoReturnValue");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramBool );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    (void) arg;
                    resultPromise.set_value();
                });
            return resultPromise.get_future().get();
        }
    );
}

bool SimpleInterfaceClient::funcBool(bool paramBool)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return false;
    }
    bool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<bool> SimpleInterfaceClient::funcBoolAsync(bool paramBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<bool>{};
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<bool> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramBool );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    bool result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

int SimpleInterfaceClient::funcInt(int paramInt)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(funcIntAsync(paramInt).get());
    return value;
}

std::future<int> SimpleInterfaceClient::funcIntAsync(int paramInt)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<int> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramInt );
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

int32_t SimpleInterfaceClient::funcInt32(int32_t paramInt32)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int32_t value(funcInt32Async(paramInt32).get());
    return value;
}

std::future<int32_t> SimpleInterfaceClient::funcInt32Async(int32_t paramInt32)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int32_t>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt32]()
        {
            std::promise<int32_t> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt32");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramInt32 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    int32_t result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

int64_t SimpleInterfaceClient::funcInt64(int64_t paramInt64)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0LL;
    }
    int64_t value(funcInt64Async(paramInt64).get());
    return value;
}

std::future<int64_t> SimpleInterfaceClient::funcInt64Async(int64_t paramInt64)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int64_t>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt64]()
        {
            std::promise<int64_t> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt64");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramInt64 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    int64_t result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

float SimpleInterfaceClient::funcFloat(float paramFloat)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0.0f;
    }
    float value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<float> SimpleInterfaceClient::funcFloatAsync(float paramFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<float>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<float> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramFloat );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    float result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

float SimpleInterfaceClient::funcFloat32(float paramFloat32)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0.0f;
    }
    float value(funcFloat32Async(paramFloat32).get());
    return value;
}

std::future<float> SimpleInterfaceClient::funcFloat32Async(float paramFloat32)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<float>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat32]()
        {
            std::promise<float> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat32");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramFloat32 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    float result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

double SimpleInterfaceClient::funcFloat64(double paramFloat)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0.0;
    }
    double value(funcFloat64Async(paramFloat).get());
    return value;
}

std::future<double> SimpleInterfaceClient::funcFloat64Async(double paramFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<double>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<double> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat64");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramFloat );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    double result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string SimpleInterfaceClient::funcString(const std::string& paramString)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::string();
    }
    std::string value(funcStringAsync(paramString).get());
    return value;
}

std::future<std::string> SimpleInterfaceClient::funcStringAsync(const std::string& paramString)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::string>{};
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<std::string> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramString );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::string result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string SimpleInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void SimpleInterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sigBool") {bool arg_paramBool {};
        argumentsReader.read(arg_paramBool);m_publisher->publishSigBool(arg_paramBool);   
        return;
    }
    if(signalName == "sigInt") {int arg_paramInt {};
        argumentsReader.read(arg_paramInt);m_publisher->publishSigInt(arg_paramInt);   
        return;
    }
    if(signalName == "sigInt32") {int32_t arg_paramInt32 {};
        argumentsReader.read(arg_paramInt32);m_publisher->publishSigInt32(arg_paramInt32);   
        return;
    }
    if(signalName == "sigInt64") {int64_t arg_paramInt64 {};
        argumentsReader.read(arg_paramInt64);m_publisher->publishSigInt64(arg_paramInt64);   
        return;
    }
    if(signalName == "sigFloat") {float arg_paramFloat {};
        argumentsReader.read(arg_paramFloat);m_publisher->publishSigFloat(arg_paramFloat);   
        return;
    }
    if(signalName == "sigFloat32") {float arg_paramFloa32 {};
        argumentsReader.read(arg_paramFloa32);m_publisher->publishSigFloat32(arg_paramFloa32);   
        return;
    }
    if(signalName == "sigFloat64") {double arg_paramFloat64 {};
        argumentsReader.read(arg_paramFloat64);m_publisher->publishSigFloat64(arg_paramFloat64);   
        return;
    }
    if(signalName == "sigString") {std::string arg_paramString {};
        argumentsReader.read(arg_paramString);m_publisher->publishSigString(arg_paramString);   
        return;
    }
}

void SimpleInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void SimpleInterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void SimpleInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool SimpleInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

ISimpleInterfacePublisher& SimpleInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

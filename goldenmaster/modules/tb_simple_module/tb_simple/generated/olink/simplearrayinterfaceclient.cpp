

#include "tb_simple/generated/olink/simplearrayinterfaceclient.h"
#include "tb_simple/generated/core/simplearrayinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleArrayInterface";
}

SimpleArrayInterfaceClient::SimpleArrayInterfaceClient()
    : m_publisher(std::make_unique<SimpleArrayInterfacePublisher>())
{}

void SimpleArrayInterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "propBool") {
        std::list<bool> value_propBool {};
        readValue(value, value_propBool);
        setPropBoolLocal(value_propBool);
    }
    else if ( propertyName == "propInt") {
        std::list<int> value_propInt {};
        readValue(value, value_propInt);
        setPropIntLocal(value_propInt);
    }
    else if ( propertyName == "propInt32") {
        std::list<int32_t> value_propInt32 {};
        readValue(value, value_propInt32);
        setPropInt32Local(value_propInt32);
    }
    else if ( propertyName == "propInt64") {
        std::list<int64_t> value_propInt64 {};
        readValue(value, value_propInt64);
        setPropInt64Local(value_propInt64);
    }
    else if ( propertyName == "propFloat") {
        std::list<float> value_propFloat {};
        readValue(value, value_propFloat);
        setPropFloatLocal(value_propFloat);
    }
    else if ( propertyName == "propFloat32") {
        std::list<float> value_propFloat32 {};
        readValue(value, value_propFloat32);
        setPropFloat32Local(value_propFloat32);
    }
    else if ( propertyName == "propFloat64") {
        std::list<double> value_propFloat64 {};
        readValue(value, value_propFloat64);
        setPropFloat64Local(value_propFloat64);
    }
    else if ( propertyName == "propString") {
        std::list<std::string> value_propString {};
        readValue(value, value_propString);
        setPropStringLocal(value_propString);
    }
}

void SimpleArrayInterfaceClient::setPropBool(const std::list<bool>& propBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propBool));
}

void SimpleArrayInterfaceClient::setPropBoolLocal(const std::list<bool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<bool>& SimpleArrayInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void SimpleArrayInterfaceClient::setPropInt(const std::list<int>& propInt)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt));
}

void SimpleArrayInterfaceClient::setPropIntLocal(const std::list<int>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<int>& SimpleArrayInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void SimpleArrayInterfaceClient::setPropInt32(const std::list<int32_t>& propInt32)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt32");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt32));
}

void SimpleArrayInterfaceClient::setPropInt32Local(const std::list<int32_t>& propInt32)
{
    if (m_data.m_propInt32 != propInt32) {
        m_data.m_propInt32 = propInt32;
        m_publisher->publishPropInt32Changed(propInt32);
    }
}

const std::list<int32_t>& SimpleArrayInterfaceClient::getPropInt32() const
{
    return m_data.m_propInt32;
}

void SimpleArrayInterfaceClient::setPropInt64(const std::list<int64_t>& propInt64)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt64");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt64));
}

void SimpleArrayInterfaceClient::setPropInt64Local(const std::list<int64_t>& propInt64)
{
    if (m_data.m_propInt64 != propInt64) {
        m_data.m_propInt64 = propInt64;
        m_publisher->publishPropInt64Changed(propInt64);
    }
}

const std::list<int64_t>& SimpleArrayInterfaceClient::getPropInt64() const
{
    return m_data.m_propInt64;
}

void SimpleArrayInterfaceClient::setPropFloat(const std::list<float>& propFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat));
}

void SimpleArrayInterfaceClient::setPropFloatLocal(const std::list<float>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<float>& SimpleArrayInterfaceClient::getPropFloat() const
{
    return m_data.m_propFloat;
}

void SimpleArrayInterfaceClient::setPropFloat32(const std::list<float>& propFloat32)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat32");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat32));
}

void SimpleArrayInterfaceClient::setPropFloat32Local(const std::list<float>& propFloat32)
{
    if (m_data.m_propFloat32 != propFloat32) {
        m_data.m_propFloat32 = propFloat32;
        m_publisher->publishPropFloat32Changed(propFloat32);
    }
}

const std::list<float>& SimpleArrayInterfaceClient::getPropFloat32() const
{
    return m_data.m_propFloat32;
}

void SimpleArrayInterfaceClient::setPropFloat64(const std::list<double>& propFloat64)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat64");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat64));
}

void SimpleArrayInterfaceClient::setPropFloat64Local(const std::list<double>& propFloat64)
{
    if (m_data.m_propFloat64 != propFloat64) {
        m_data.m_propFloat64 = propFloat64;
        m_publisher->publishPropFloat64Changed(propFloat64);
    }
}

const std::list<double>& SimpleArrayInterfaceClient::getPropFloat64() const
{
    return m_data.m_propFloat64;
}

void SimpleArrayInterfaceClient::setPropString(const std::list<std::string>& propString)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propString));
}

void SimpleArrayInterfaceClient::setPropStringLocal(const std::list<std::string>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<std::string>& SimpleArrayInterfaceClient::getPropString() const
{
    return m_data.m_propString;
}

std::list<bool> SimpleArrayInterfaceClient::funcBool(const std::list<bool>& paramBool)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<bool>();
    }
    std::list<bool> value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<std::list<bool>> SimpleArrayInterfaceClient::funcBoolAsync(const std::list<bool>& paramBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<bool>>{};
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<std::list<bool>> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramBool );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::list<bool> result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<int> SimpleArrayInterfaceClient::funcInt(const std::list<int>& paramInt)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<int>();
    }
    std::list<int> value(funcIntAsync(paramInt).get());
    return value;
}

std::future<std::list<int>> SimpleArrayInterfaceClient::funcIntAsync(const std::list<int>& paramInt)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<int>>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<std::list<int>> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramInt );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::list<int> result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<int32_t> SimpleArrayInterfaceClient::funcInt32(const std::list<int32_t>& paramInt32)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<int32_t>();
    }
    std::list<int32_t> value(funcInt32Async(paramInt32).get());
    return value;
}

std::future<std::list<int32_t>> SimpleArrayInterfaceClient::funcInt32Async(const std::list<int32_t>& paramInt32)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<int32_t>>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt32]()
        {
            std::promise<std::list<int32_t>> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt32");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramInt32 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::list<int32_t> result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<int64_t> SimpleArrayInterfaceClient::funcInt64(const std::list<int64_t>& paramInt64)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<int64_t>();
    }
    std::list<int64_t> value(funcInt64Async(paramInt64).get());
    return value;
}

std::future<std::list<int64_t>> SimpleArrayInterfaceClient::funcInt64Async(const std::list<int64_t>& paramInt64)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<int64_t>>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt64]()
        {
            std::promise<std::list<int64_t>> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt64");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramInt64 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::list<int64_t> result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<float> SimpleArrayInterfaceClient::funcFloat(const std::list<float>& paramFloat)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<float>();
    }
    std::list<float> value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<std::list<float>> SimpleArrayInterfaceClient::funcFloatAsync(const std::list<float>& paramFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<float>>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<std::list<float>> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramFloat );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::list<float> result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<float> SimpleArrayInterfaceClient::funcFloat32(const std::list<float>& paramFloat32)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<float>();
    }
    std::list<float> value(funcFloat32Async(paramFloat32).get());
    return value;
}

std::future<std::list<float>> SimpleArrayInterfaceClient::funcFloat32Async(const std::list<float>& paramFloat32)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<float>>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat32]()
        {
            std::promise<std::list<float>> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat32");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramFloat32 );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::list<float> result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<double> SimpleArrayInterfaceClient::funcFloat64(const std::list<double>& paramFloat)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<double>();
    }
    std::list<double> value(funcFloat64Async(paramFloat).get());
    return value;
}

std::future<std::list<double>> SimpleArrayInterfaceClient::funcFloat64Async(const std::list<double>& paramFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<double>>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<std::list<double>> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat64");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramFloat );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::list<double> result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<std::string> SimpleArrayInterfaceClient::funcString(const std::list<std::string>& paramString)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<std::string>();
    }
    std::list<std::string> value(funcStringAsync(paramString).get());
    return value;
}

std::future<std::list<std::string>> SimpleArrayInterfaceClient::funcStringAsync(const std::list<std::string>& paramString)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<std::string>>{};
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<std::list<std::string>> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramString );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    std::list<std::string> result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string SimpleArrayInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void SimpleArrayInterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sigBool") {std::list<bool> arg_paramBool {};
        argumentsReader.read(arg_paramBool);m_publisher->publishSigBool(arg_paramBool);   
        return;
    }
    if(signalName == "sigInt") {std::list<int> arg_paramInt {};
        argumentsReader.read(arg_paramInt);m_publisher->publishSigInt(arg_paramInt);   
        return;
    }
    if(signalName == "sigInt32") {std::list<int32_t> arg_paramInt32 {};
        argumentsReader.read(arg_paramInt32);m_publisher->publishSigInt32(arg_paramInt32);   
        return;
    }
    if(signalName == "sigInt64") {std::list<int64_t> arg_paramInt64 {};
        argumentsReader.read(arg_paramInt64);m_publisher->publishSigInt64(arg_paramInt64);   
        return;
    }
    if(signalName == "sigFloat") {std::list<float> arg_paramFloat {};
        argumentsReader.read(arg_paramFloat);m_publisher->publishSigFloat(arg_paramFloat);   
        return;
    }
    if(signalName == "sigFloat32") {std::list<float> arg_paramFloa32 {};
        argumentsReader.read(arg_paramFloa32);m_publisher->publishSigFloat32(arg_paramFloa32);   
        return;
    }
    if(signalName == "sigFloat64") {std::list<double> arg_paramFloat64 {};
        argumentsReader.read(arg_paramFloat64);m_publisher->publishSigFloat64(arg_paramFloat64);   
        return;
    }
    if(signalName == "sigString") {std::list<std::string> arg_paramString {};
        argumentsReader.read(arg_paramString);m_publisher->publishSigString(arg_paramString);   
        return;
    }
}

void SimpleArrayInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void SimpleArrayInterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void SimpleArrayInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool SimpleArrayInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

ISimpleArrayInterfacePublisher& SimpleArrayInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}



#include "testbed1/generated/olink/structinterfaceclient.h"
#include "testbed1/generated/core/structinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructInterface";
}

StructInterfaceClient::StructInterfaceClient()
    : m_publisher(std::make_unique<StructInterfacePublisher>())
{}

void StructInterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "propBool") {
        StructBool value_propBool {};
        readValue(value, value_propBool);
        setPropBoolLocal(value_propBool);
    }
    else if ( propertyName == "propInt") {
        StructInt value_propInt {};
        readValue(value, value_propInt);
        setPropIntLocal(value_propInt);
    }
    else if ( propertyName == "propFloat") {
        StructFloat value_propFloat {};
        readValue(value, value_propFloat);
        setPropFloatLocal(value_propFloat);
    }
    else if ( propertyName == "propString") {
        StructString value_propString {};
        readValue(value, value_propString);
        setPropStringLocal(value_propString);
    }
}

void StructInterfaceClient::setPropBool(const StructBool& propBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propBool));
}

void StructInterfaceClient::setPropBoolLocal(const StructBool& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const StructBool& StructInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void StructInterfaceClient::setPropInt(const StructInt& propInt)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt));
}

void StructInterfaceClient::setPropIntLocal(const StructInt& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const StructInt& StructInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void StructInterfaceClient::setPropFloat(const StructFloat& propFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat));
}

void StructInterfaceClient::setPropFloatLocal(const StructFloat& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const StructFloat& StructInterfaceClient::getPropFloat() const
{
    return m_data.m_propFloat;
}

void StructInterfaceClient::setPropString(const StructString& propString)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propString));
}

void StructInterfaceClient::setPropStringLocal(const StructString& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const StructString& StructInterfaceClient::getPropString() const
{
    return m_data.m_propString;
}

StructBool StructInterfaceClient::funcBool(const StructBool& paramBool)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> StructInterfaceClient::funcBoolAsync(const StructBool& paramBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<StructBool>{};
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<StructBool> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramBool );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    StructBool result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool StructInterfaceClient::funcInt(const StructInt& paramInt)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> StructInterfaceClient::funcIntAsync(const StructInt& paramInt)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<StructBool>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<StructBool> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramInt );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    StructBool result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructFloat StructInterfaceClient::funcFloat(const StructFloat& paramFloat)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return StructFloat();
    }
    StructFloat value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructFloat> StructInterfaceClient::funcFloatAsync(const StructFloat& paramFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<StructFloat>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructFloat> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramFloat );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    StructFloat result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructString StructInterfaceClient::funcString(const StructString& paramString)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return StructString();
    }
    StructString value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructString> StructInterfaceClient::funcStringAsync(const StructString& paramString)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<StructString>{};
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructString> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramString );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    StructString result{};
                    readValue(arg.value, result);
                    resultPromise.set_value(result);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string StructInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void StructInterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sigBool") {StructBool arg_paramBool {};
        argumentsReader.read(arg_paramBool);m_publisher->publishSigBool(arg_paramBool);   
        return;
    }
    if(signalName == "sigInt") {StructInt arg_paramInt {};
        argumentsReader.read(arg_paramInt);m_publisher->publishSigInt(arg_paramInt);   
        return;
    }
    if(signalName == "sigFloat") {StructFloat arg_paramFloat {};
        argumentsReader.read(arg_paramFloat);m_publisher->publishSigFloat(arg_paramFloat);   
        return;
    }
    if(signalName == "sigString") {StructString arg_paramString {};
        argumentsReader.read(arg_paramString);m_publisher->publishSigString(arg_paramString);   
        return;
    }
}

void StructInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void StructInterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void StructInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool StructInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

IStructInterfacePublisher& StructInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

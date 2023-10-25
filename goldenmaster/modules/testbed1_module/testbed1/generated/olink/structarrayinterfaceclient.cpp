

#include "testbed1/generated/olink/structarrayinterfaceclient.h"
#include "testbed1/generated/core/structarrayinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructArrayInterface";
}

StructArrayInterfaceClient::StructArrayInterfaceClient()
    : m_publisher(std::make_unique<StructArrayInterfacePublisher>())
{}

void StructArrayInterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "propBool") {
        std::list<StructBool> value_propBool {};
        readValue(value, value_propBool);
        setPropBoolLocal(value_propBool);
    }
    else if ( propertyName == "propInt") {
        std::list<StructInt> value_propInt {};
        readValue(value, value_propInt);
        setPropIntLocal(value_propInt);
    }
    else if ( propertyName == "propFloat") {
        std::list<StructFloat> value_propFloat {};
        readValue(value, value_propFloat);
        setPropFloatLocal(value_propFloat);
    }
    else if ( propertyName == "propString") {
        std::list<StructString> value_propString {};
        readValue(value, value_propString);
        setPropStringLocal(value_propString);
    }
}

void StructArrayInterfaceClient::setPropBool(const std::list<StructBool>& propBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propBool));
}

void StructArrayInterfaceClient::setPropBoolLocal(const std::list<StructBool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<StructBool>& StructArrayInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void StructArrayInterfaceClient::setPropInt(const std::list<StructInt>& propInt)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt));
}

void StructArrayInterfaceClient::setPropIntLocal(const std::list<StructInt>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<StructInt>& StructArrayInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void StructArrayInterfaceClient::setPropFloat(const std::list<StructFloat>& propFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat));
}

void StructArrayInterfaceClient::setPropFloatLocal(const std::list<StructFloat>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<StructFloat>& StructArrayInterfaceClient::getPropFloat() const
{
    return m_data.m_propFloat;
}

void StructArrayInterfaceClient::setPropString(const std::list<StructString>& propString)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propString));
}

void StructArrayInterfaceClient::setPropStringLocal(const std::list<StructString>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<StructString>& StructArrayInterfaceClient::getPropString() const
{
    return m_data.m_propString;
}

StructBool StructArrayInterfaceClient::funcBool(const std::list<StructBool>& paramBool)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> StructArrayInterfaceClient::funcBoolAsync(const std::list<StructBool>& paramBool)
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

StructBool StructArrayInterfaceClient::funcInt(const std::list<StructInt>& paramInt)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> StructArrayInterfaceClient::funcIntAsync(const std::list<StructInt>& paramInt)
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

StructBool StructArrayInterfaceClient::funcFloat(const std::list<StructFloat>& paramFloat)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return StructBool();
    }
    StructBool value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructBool> StructArrayInterfaceClient::funcFloatAsync(const std::list<StructFloat>& paramFloat)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<StructBool>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructBool> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramFloat );
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

StructBool StructArrayInterfaceClient::funcString(const std::list<StructString>& paramString)
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return StructBool();
    }
    StructBool value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructBool> StructArrayInterfaceClient::funcStringAsync(const std::list<StructString>& paramString)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<StructBool>{};
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructBool> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            auto args = ApiGear::ObjectLink::argumentsToContent( paramString );
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

std::string StructArrayInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void StructArrayInterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sigBool") {std::list<StructBool> arg_paramBool {};
        argumentsReader.read(arg_paramBool);m_publisher->publishSigBool(arg_paramBool);   
        return;
    }
    if(signalName == "sigInt") {std::list<StructInt> arg_paramInt {};
        argumentsReader.read(arg_paramInt);m_publisher->publishSigInt(arg_paramInt);   
        return;
    }
    if(signalName == "sigFloat") {std::list<StructFloat> arg_paramFloat {};
        argumentsReader.read(arg_paramFloat);m_publisher->publishSigFloat(arg_paramFloat);   
        return;
    }
    if(signalName == "sigString") {std::list<StructString> arg_paramString {};
        argumentsReader.read(arg_paramString);m_publisher->publishSigString(arg_paramString);   
        return;
    }
}

void StructArrayInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void StructArrayInterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void StructArrayInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool StructArrayInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

IStructArrayInterfacePublisher& StructArrayInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}



#include "testbed1/generated/olink/structinterfaceclient.h"
#include "testbed1/generated/core/structinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"
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

void StructInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<StructBool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<StructInt>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<StructFloat>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<StructString>());
    }
}

void StructInterfaceClient::setPropBool(const StructBool& propBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    m_node->setRemoteProperty(propertyId, propBool);
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
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    m_node->setRemoteProperty(propertyId, propInt);
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
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    m_node->setRemoteProperty(propertyId, propFloat);
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
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    m_node->setRemoteProperty(propertyId, propString);
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
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
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
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
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
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructFloat& value = arg.value.get<StructFloat>();
                    resultPromise.set_value(value);
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
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructString& value = arg.value.get<StructString>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string StructInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void StructInterfaceClient::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        m_publisher->publishSigBool(args[0].get<StructBool>());   
        return;
    }
    if(signalName == "sigInt") {
        m_publisher->publishSigInt(args[0].get<StructInt>());   
        return;
    }
    if(signalName == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<StructFloat>());   
        return;
    }
    if(signalName == "sigString") {
        m_publisher->publishSigString(args[0].get<StructString>());   
        return;
    }
}

void StructInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void StructInterfaceClient::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
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

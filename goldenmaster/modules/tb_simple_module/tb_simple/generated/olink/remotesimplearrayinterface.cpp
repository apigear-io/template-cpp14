

#include "tb_simple/generated/olink/remotesimplearrayinterface.h"
#include "tb_simple/generated/core/simplearrayinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleArrayInterface";
}

RemoteSimpleArrayInterface::RemoteSimpleArrayInterface(ApiGear::PocoImpl::IOlinkConnector& olinkConnector)
    : m_olinkConnector(olinkConnector),
      m_publisher(std::make_unique<SimpleArrayInterfacePublisher>())
{
    m_olinkConnector.connectAndLinkObject(*this);
}

RemoteSimpleArrayInterface::~RemoteSimpleArrayInterface()
{
    m_olinkConnector.disconnectAndUnlink(olinkObjectName());
}

void RemoteSimpleArrayInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<std::list<bool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<std::list<int>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<std::list<float>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<std::list<std::string>>());
    }
}

void RemoteSimpleArrayInterface::setPropBool(const std::list<bool>& propBool)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    m_node->setRemoteProperty(propertyId, propBool);
}

void RemoteSimpleArrayInterface::setPropBoolLocal(const std::list<bool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<bool>& RemoteSimpleArrayInterface::getPropBool() const
{
    return m_data.m_propBool;
}

void RemoteSimpleArrayInterface::setPropInt(const std::list<int>& propInt)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    m_node->setRemoteProperty(propertyId, propInt);
}

void RemoteSimpleArrayInterface::setPropIntLocal(const std::list<int>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<int>& RemoteSimpleArrayInterface::getPropInt() const
{
    return m_data.m_propInt;
}

void RemoteSimpleArrayInterface::setPropFloat(const std::list<float>& propFloat)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    m_node->setRemoteProperty(propertyId, propFloat);
}

void RemoteSimpleArrayInterface::setPropFloatLocal(const std::list<float>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<float>& RemoteSimpleArrayInterface::getPropFloat() const
{
    return m_data.m_propFloat;
}

void RemoteSimpleArrayInterface::setPropString(const std::list<std::string>& propString)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    m_node->setRemoteProperty(propertyId, propString);
}

void RemoteSimpleArrayInterface::setPropStringLocal(const std::list<std::string>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<std::string>& RemoteSimpleArrayInterface::getPropString() const
{
    return m_data.m_propString;
}

std::list<bool> RemoteSimpleArrayInterface::funcBool(const std::list<bool>& paramBool)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<bool>();
    }
    std::list<bool> value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<std::list<bool>> RemoteSimpleArrayInterface::funcBoolAsync(const std::list<bool>& paramBool)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<bool>>{};
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<std::list<bool>> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<bool>& value = arg.value.get<std::list<bool>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<int> RemoteSimpleArrayInterface::funcInt(const std::list<int>& paramInt)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<int>();
    }
    std::list<int> value(funcIntAsync(paramInt).get());
    return value;
}

std::future<std::list<int>> RemoteSimpleArrayInterface::funcIntAsync(const std::list<int>& paramInt)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<int>>{};
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<std::list<int>> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<int>& value = arg.value.get<std::list<int>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<float> RemoteSimpleArrayInterface::funcFloat(const std::list<float>& paramFloat)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<float>();
    }
    std::list<float> value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<std::list<float>> RemoteSimpleArrayInterface::funcFloatAsync(const std::list<float>& paramFloat)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<float>>{};
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<std::list<float>> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<float>& value = arg.value.get<std::list<float>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<std::string> RemoteSimpleArrayInterface::funcString(const std::list<std::string>& paramString)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::list<std::string>();
    }
    std::list<std::string> value(funcStringAsync(paramString).get());
    return value;
}

std::future<std::list<std::string>> RemoteSimpleArrayInterface::funcStringAsync(const std::list<std::string>& paramString)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<std::list<std::string>>{};
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<std::list<std::string>> resultPromise;
            auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<std::string>& value = arg.value.get<std::list<std::string>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSimpleArrayInterface::olinkObjectName()
{
    return interfaceId;
}

void RemoteSimpleArrayInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    auto signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        m_publisher->publishSigBool(args[0].get<std::list<bool>>());   
        return;
    }
    if(signalName == "sigInt") {
        m_publisher->publishSigInt(args[0].get<std::list<int>>());   
        return;
    }
    if(signalName == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<std::list<float>>());   
        return;
    }
    if(signalName == "sigString") {
        m_publisher->publishSigString(args[0].get<std::list<std::string>>());   
        return;
    }
}

void RemoteSimpleArrayInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void RemoteSimpleArrayInterface::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteSimpleArrayInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSimpleArrayInterface::isReady() const
{
    return m_node;
}

ISimpleArrayInterfacePublisher& RemoteSimpleArrayInterface::_getPublisher() const
{
    return *m_publisher;
}



#include "tb_simple/generated/olink/nopropertiesinterfaceclient.h"
#include "tb_simple/generated/core/nopropertiesinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.NoPropertiesInterface";
}

NoPropertiesInterfaceClient::NoPropertiesInterfaceClient()
    : m_publisher(std::make_unique<NoPropertiesInterfacePublisher>())
{}

void NoPropertiesInterfaceClient::applyState(const nlohmann::json& fields) 
{// no properties to apply state
    (void) fields;
}

void NoPropertiesInterfaceClient::funcVoid()
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    ApiGear::ObjectLink::InvokeReplyFunc func = [this](ApiGear::ObjectLink::InvokeReplyArg arg)
        {
            (void) this;
            (void) arg;
        };
    const nlohmann::json &args = nlohmann::json::array({  });
    const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcVoid");
    m_node->invokeRemote(operationId, args, func);
}

std::future<void> NoPropertiesInterfaceClient::funcVoidAsync()
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<void>{};
    }
    return std::async(std::launch::async, [this]()
        {
            std::promise<void> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcVoid");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    (void) arg;
                    resultPromise.set_value();
                });
            return resultPromise.get_future().get();
        }
    );
}

bool NoPropertiesInterfaceClient::funcBool(bool paramBool)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return false;
    }
    bool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<bool> NoPropertiesInterfaceClient::funcBoolAsync(bool paramBool)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<bool>{};
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<bool> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const bool& value = arg.value.get<bool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string NoPropertiesInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void NoPropertiesInterfaceClient::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sigVoid") {
        m_publisher->publishSigVoid();   
        return;
    }
    if(signalName == "sigBool") {
        m_publisher->publishSigBool(args[0].get<bool>());   
        return;
    }
}

void NoPropertiesInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void NoPropertiesInterfaceClient::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void NoPropertiesInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool NoPropertiesInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

INoPropertiesInterfacePublisher& NoPropertiesInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

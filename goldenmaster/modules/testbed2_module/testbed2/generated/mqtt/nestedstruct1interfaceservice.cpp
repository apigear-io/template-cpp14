#include "testbed2/generated/mqtt/nestedstruct1interfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>

using namespace Test::Testbed2;
using namespace Test::Testbed2::mqtt;

NestedStruct1InterfaceService::NestedStruct1InterfaceService(INestedStruct1Interface& impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl._getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1"), this);

}

NestedStruct1InterfaceService::~NestedStruct1InterfaceService()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1"), this);
}

void NestedStruct1InterfaceService::onConnected()
{
    // send current values
    onProp1Changed(m_impl.getProp1());
}

void NestedStruct1InterfaceService::onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop1") {
        auto prop1 = json_args.get<NestedStruct1>();
        m_impl.setProp1(prop1);
        return;
    }


    if(name == "func1") {
        const NestedStruct1& param1 = json_args.at(0).get<NestedStruct1>();
        auto result = m_impl.func1(param1);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void NestedStruct1InterfaceService::onSig1(const NestedStruct1& param1)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig1");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NestedStruct1InterfaceService::onProp1Changed(const NestedStruct1& prop1)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop1");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}

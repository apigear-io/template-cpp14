#pragma once

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT NestedStruct3InterfaceService : public virtual ApiGear::MQTT::ISink, public INestedStruct3InterfaceSubscriber
{
public:
    explicit NestedStruct3InterfaceService(std::shared_ptr<INestedStruct3Interface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NestedStruct3InterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // INestedStruct3InterfaceSubscriber interface
    void onSig1(const NestedStruct1& param1) override;
    void onSig2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    void onSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    void onProp1Changed(const NestedStruct1& prop1) override;
    void onProp2Changed(const NestedStruct2& prop2) override;
    void onProp3Changed(const NestedStruct3& prop3) override;

private:
    std::shared_ptr<INestedStruct3Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace Testbed2
} // namespace Test
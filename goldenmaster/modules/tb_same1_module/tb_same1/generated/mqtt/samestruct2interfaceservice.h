#pragma once

#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSame1 {
namespace MQTT {
class TEST_TB_SAME1_EXPORT SameStruct2InterfaceService : public virtual ApiGear::MQTT::ISink, public ISameStruct2InterfaceSubscriber
{
public:
    explicit SameStruct2InterfaceService(std::shared_ptr<ISameStruct2Interface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameStruct2InterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // ISameStruct2InterfaceSubscriber interface
    void onSig1(const Struct1& param1) override;
    void onSig2(const Struct1& param1, const Struct2& param2) override;
    void onProp1Changed(const Struct2& prop1) override;
    void onProp2Changed(const Struct2& prop2) override;

private:
    std::shared_ptr<ISameStruct2Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace TbSame1
} // namespace Test
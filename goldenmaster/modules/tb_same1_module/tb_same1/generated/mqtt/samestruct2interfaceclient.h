#pragma once

#include <future>
#include "tb_same1/generated/api/common.h"
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/core/samestruct2interface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace TbSame1 {
namespace MQTT {
class TEST_TB_SAME1_EXPORT SameStruct2InterfaceClient : public ISameStruct2Interface
{
public:
    explicit SameStruct2InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameStruct2InterfaceClient() override;
    const Struct2& getProp1() const override;
    void setProp1(const Struct2& prop1) override;
    const Struct2& getProp2() const override;
    void setProp2(const Struct2& prop2) override;
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;
    ISameStruct2InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const std::string& topic, const std::string& args);
    void onInvokeReply(const std::string& args, const std::string& correlationData);
    /// @brief sets the value for the property Prop1 coming from the service
    /// @param args contains the param of the type Struct2
    void setProp1Local(const std::string& args);
    /// @brief sets the value for the property Prop2 coming from the service
    /// @param args contains the param of the type Struct2
    void setProp2Local(const std::string& args);

private:
    bool m_isReady;
    /** Local storage for properties values. */
    SameStruct2InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for SameStruct2Interface */
    std::unique_ptr<ISameStruct2InterfacePublisher> m_publisher;

    /**
     * @brief register a response handler for an operation invocation
     * 
     * @param handler function to be called on return
     * @return int unique id of the call
     */
    int registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler);
    std::mutex m_responseHandlerMutex;
    std::map<int, ApiGear::MQTT::InvokeReplyFunc> m_responseHandlerMap;

    /// @brief has all the topics of this client and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace TbSame1
} // namespace Test

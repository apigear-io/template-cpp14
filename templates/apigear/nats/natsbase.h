#pragma once

#include <memory>
#include <string>
#include "nlohmann/json.hpp"
#include "natscommon.h"
#include "natstypes.h"
#include <mutex>
#include <condition_variable>

namespace ApiGear {
namespace Nats {

class APIGEAR_NATS_EXPORT Base
{
public:
    explicit Base();
    virtual ~Base() = default;

    void connect(std::string address);
    uint32_t subscribe(std::string topic);
    void unsubscribe(std::string topic);//TODO uint32_t
    void publish(std::string topic, std::string payload);

    uint32_t addOnConnectedCallback(OnConnectionStatusChangedCallBackFunction callback);
    void removeOnConnectedCallback(uint32_t id);
    bool isConnected() const;
private:
    bool onConnectedChanged();
    std::mutex m_onConnectionStatusChangedCallbacksMutex;
    std::map<uint32_t, OnConnectionStatusChangedCallBackFunction> m_onConnectionStatusChangedCallbacks;

    std::shared_ptr<class CWrapper> m_cwrapper;
};
} // namespace Nats
} // namespace ApiGear

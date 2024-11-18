#pragma once

#include <queue>
#include <set>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <atomic>
#include <thread>
#include <condition_variable>
#include "natstypes.h"
#include "nlohmann/json.hpp"
#pragma warning (push, 0)
#include <nats.h>
#pragma warning(pop)


namespace ApiGear {
namespace Nats {

/**
 * @brief This a simple c++ wrapper for the c Nats implementation
 * 
 * Since in Nats there are only clients connected to a central broker,
 * the ApiGear service and client side use this class to connect to each other via the broker.
 */
class CWrapper : public std::enable_shared_from_this<CWrapper>
{
public:
    static std::shared_ptr<CWrapper> create()
    {
        return std::shared_ptr<CWrapper>(new CWrapper());
    };
    virtual ~CWrapper();


    std::shared_ptr<CWrapper> getPtr()
    {
        return shared_from_this();
    }

    void connect(std::string address);
    uint32_t addOnConnectedCallback(OnConnectionStatusChangedCallBackFunction);
    void removeOnConnectedCallback(uint32_t id);

    void subscribe(std::string topic);
    void unsubscribe(std::string topic);
    void publish(std::string topic, std::string payload);
    ConnectionStatus getStatus();

private:
    natsConnection* m_connection = NULL;
    natsSubscription* m_subscription = NULL;

    std::condition_variable m_synchConnectionStatus;
    std::mutex m_synchConnectionStatusMutex;
    std::atomic<bool> m_connected{ false };
    std::mutex m_onConnectionStatusChangedCallbacksMutex;
    std::map<int, OnConnectionStatusChangedCallBackFunction> m_onConnectionStatusChangedCallbacks;

    explicit CWrapper();
};
} // namespace Nats
} // namespace ApiGear

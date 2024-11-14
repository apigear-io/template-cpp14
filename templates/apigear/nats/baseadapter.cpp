#include "apigear/nats/baseadapter.h"
#include "apigear/utilities/logger.h"

using namespace ApiGear::Nats;

BaseAdapter::BaseAdapter(std::shared_ptr<Client> client)
    : m_client(client)
    , m_isAlive(std::make_shared<bool>(true))
{

    m_initialized = std::vector<bool>(getPropertiesSize(), false);
    if (m_client->isConnected())
    {
        subscribeTopics();
        getInitialState();
    }
    else
    {
        m_client->addOnConnectedCallback([this](bool is_connected)
            {
                if (is_connected)
                {
                    subscribeTopics();
                    // on reconnect always get the latest state, the server side might have changed.
                    getInitialState();
                    if (_is_ready())
                    {
                        _is_readyChanges.publishChange(true);
                    }
                }
                else
                {
                    m_initialized = std::vector<bool>(getPropertiesSize(), false);
                    _is_readyChanges.publishChange(false);
                }
            });
    }
}

BaseAdapter::~BaseAdapter()
{
    unsubscribeTopics();
}

void BaseAdapter::subscribeTopic(const std::string& topic, SimpleOnMessageCallback callback)
{
    std::weak_ptr<bool> isAlive(m_isAlive);
    std::shared_ptr<Client> client = m_client;
    auto safeOnSubscribed = [isAlive, client, this](int64_t id, const std::string& topic, bool is_subscribed)
        {
            if (isAlive.lock())
            {
                onSubscribed(id, topic, is_subscribed);
            }
            else if (is_subscribed)
            {
                client->unsubscribe(id);
            }
        };
    if (!isAlreadyAdded(topic))
    {
        m_client->subscribe(topic, callback, safeOnSubscribed);
    }
}

void BaseAdapter::getInitValue(const std::string& topic, uint32_t index, std::function<void(std::string)> valueSetter)
{
    m_client->request(topic, "", 
        [this, index, valueSetter](std::string value) {
            valueSetter(value);
            m_initialized[index] = true;
            if (_is_ready()) 
            { 
                _is_readyChanges.publishChange(true);
            } 
        });
}
//TODO mutex encore
bool BaseAdapter::isAlreadyAdded(const std::string& topic)
{
    auto already_added = m_subscribedTopics.find(topic);
    return already_added != m_subscribedTopics.end() &&
        (already_added->second.status == ApiGear::Nats::SubscriptionStatus::subscribed ||
            already_added->second.status == ApiGear::Nats::SubscriptionStatus::subscribing);
}

void BaseAdapter::unsubscribeTopics()
{
    for (auto topic : m_subscribedTopics)
    {
        if (topic.second.status == ApiGear::Nats::SubscriptionStatus::subscribed)
        {
            topic.second.status = ApiGear::Nats::SubscriptionStatus::unsubscribing;
            m_client->unsubscribe(topic.second.id);
        }
        else if (topic.second.status != ApiGear::Nats::SubscriptionStatus::subscribing)
        {
            topic.second.status = ApiGear::Nats::SubscriptionStatus::to_unsubscribe;
        }
    }
}

void BaseAdapter::onSubscribed(int64_t id, const std::string& topic, bool is_subscribed)
{
    auto subscription = m_subscribedTopics.find(topic);
    if (is_subscribed)
    {
        if (subscription != m_subscribedTopics.end() && subscription->second.status == ApiGear::Nats::SubscriptionStatus::to_unsubscribe)
        {
            m_client->unsubscribe(id);
            m_subscribedTopics[topic] = SubscriptionInfo(ApiGear::Nats::SubscriptionStatus::unsubscribing);
        }
        m_subscribedTopics[topic] = SubscriptionInfo(ApiGear::Nats::SubscriptionStatus::subscribed, id);
    }
    else
    {
        if (subscription != m_subscribedTopics.end())
        {
            subscription->second.status = ApiGear::Nats::SubscriptionStatus::unsubscribed;
        }
        AG_LOG_ERROR("failed to subscribe " + topic);
    }
    auto still_not_all_subscribed = std::find_if(m_subscribedTopics.begin(), m_subscribedTopics.end(),
        [](auto& element) {return element.second.status != ApiGear::Nats::SubscriptionStatus::subscribed; })
        != m_subscribedTopics.end();
    if (!still_not_all_subscribed)
    {
        if (_is_ready())
        {
            _is_readyChanges.publishChange(true);
        }
    }

}

unsigned long BaseAdapter::_subscribeForIsReady(std::function<void(bool)> sub_function)
{
    return _is_readyChanges.subscribeForChange(sub_function);
}

void BaseAdapter::_unsubscribeFromIsReady(unsigned long id)
{
    _is_readyChanges.unsubscribeFromChange(id);
}

bool BaseAdapter::_is_ready()
{
    auto still_not_all_subscribed = std::find_if(m_subscribedTopics.begin(),
        m_subscribedTopics.end(),
        [this](auto& element) {return element.second.status != ApiGear::Nats::SubscriptionStatus::subscribed; })
        != m_subscribedTopics.end();
    auto still_not_initialized = std::find_if(m_initialized.begin(), m_initialized.end(), [this](auto element) { return element == false; })
        != m_initialized.end();
    return m_client->isConnected() &&
        !still_not_all_subscribed &&
        !still_not_initialized;
}

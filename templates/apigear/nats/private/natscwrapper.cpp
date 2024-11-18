#include <iostream>
#include "natscwrapper.h"
#include "utilities/logger.h"
#include <memory>
#include <functional>

using namespace ApiGear::Nats;

struct NatsSubscriptionDeleter
{
    void operator()(natsSubscription* s)
    {
        natsSubscription_Destroy(s);
    }
};
struct NatsMsgDeleter
{
    void operator()(natsMsg* msg)
    {
        natsMsg_Destroy(msg);
    }
};

struct cleanSubscriptionResourcesContext {
    int64_t id;
    std::weak_ptr<CWrapper> client;
};

static void onMsg(natsConnection* /*connection*/, natsSubscription* /*subscription*/, natsMsg* msg, void* context)
{
    // Make sure msg will be properly destroyed.
    std::shared_ptr<natsMsg> message(msg, NatsMsgDeleter());
    CWrapper::SimpleCallbackWrapper* callbackWrapper = static_cast<CWrapper::SimpleCallbackWrapper*>(context);
    std::cout<<"Received msg: "<<  natsMsg_GetSubject(message.get()) << " : "<<natsMsg_GetData(message.get()) << std::endl;
    if (callbackWrapper && callbackWrapper->callback)
    {
        callbackWrapper->callback(natsMsg_GetData(msg));
    }
    else
    {
        std::cout << "no callback" << std::endl;
        //TODO HANDLE / LOG 
    }
}

static void onError(natsConnection* /*connection*/, natsSubscription* subscription, natsStatus status, void* /*closure*/)
{
    if (status != NATS_OK)
    {
        //TODO LOG
    }
}

static void conntectionHandler(natsConnection* connection, void* context)
{
    auto status = natsConnection_Status(connection);
    std::cout << "connection handler " << static_cast<int>(status)<< std::endl;
    auto callbackStruct = static_cast<CWrapper::ConnectionCallbackContext*>(context);
    if (callbackStruct && callbackStruct->function)
    {
        callbackStruct->function();
    }
    else
    {
        //TODO LOG
    }
}

static void removeSubscriptionResources(void* context)
{
    cleanSubscriptionResourcesContext* ctx = static_cast<cleanSubscriptionResourcesContext*>(context);
    if (!ctx)
    {
    }
    else if (auto client = ctx->client.lock())
    {
        client->cleanSubscription(ctx->id);
    }
    delete ctx;
}


CWrapper::CWrapper()
{


}

CWrapper::~CWrapper()
{
    natsConnection_Close(m_connection.get());
}




void CWrapper::NatsConnectionDeleter::operator()(natsConnection* conn)
{
    natsConnection_Destroy(conn);
};




void CWrapper::connect(std::string address, std::function<void(void)> connectionStateChangedCallback)
{
    //TODO ensure that context is valid even if class is destroyed already;
    m_connectionStateChangedCallback = ConnectionCallbackContext{ connectionStateChangedCallback };

    natsOptions* opts;
    auto status = natsOptions_Create(&opts);
    if (status != NATS_OK) { /*handle*/ return; }
    //status = natsOptions_SetEventLoop(natsOptions * opts, void* loop, natsEvLoop_Attach 	attachCb, natsEvLoop_ReadAddRemove 	readCb, natsEvLoop_WriteAddRemove 	writeCb, natsEvLoop_Detach 	detachCb);
    if (status != NATS_OK) { /*handle*/ return; }
    //set error handler
    status = natsOptions_SetErrorHandler(opts, onError, NULL);
    if (status != NATS_OK) { /*handle*/ return; }
    status = natsOptions_SetURL(opts, address.c_str());
    if (status != NATS_OK) { /*handle*/ return; }
    status = natsOptions_SetDisconnectedCB(opts, conntectionHandler, &m_connectionStateChangedCallback);
    if (status != NATS_OK) { /*handle*/ return; }
    status = natsOptions_SetReconnectedCB(opts, conntectionHandler, &m_connectionStateChangedCallback);
    if (status != NATS_OK) { /*handle*/ return; }
    status = natsOptions_SetRetryOnFailedConnect(opts, true, conntectionHandler, &m_connectionStateChangedCallback);
    if (status != NATS_OK) { /*handle*/ return; }
    status = natsOptions_SetClosedCB(opts, conntectionHandler, &m_connectionStateChangedCallback);
    if (status != NATS_OK) { /*handle*/ return; }
    status = natsOptions_UseGlobalMessageDelivery(opts, true);
    if (status != NATS_OK) { /*handle*/ return; }
    natsConnection* connection = NULL;
    status = natsConnection_Connect(&connection, opts);
    m_connection.reset(connection);
    if (status != NATS_OK) { /*TODO HANDLE */ return;}
    natsOptions_Destroy(opts); // use custom deleter with this function call? and similar for all other nats *
}

ConnectionStatus CWrapper::getStatus()
{
    auto status = natsConnection_Status(m_connection.get());
    switch (status)
    {
        case NATS_CONN_STATUS_DISCONNECTED: return ConnectionStatus::disconnected;
        case NATS_CONN_STATUS_CONNECTING: return ConnectionStatus::connecting;
        case NATS_CONN_STATUS_CONNECTED: return ConnectionStatus::connected;
        case NATS_CONN_STATUS_CLOSED: return ConnectionStatus::closed;
        case NATS_CONN_STATUS_RECONNECTING: return ConnectionStatus::reconnecting;
        case NATS_CONN_STATUS_DRAINING_SUBS: return ConnectionStatus::draining_subs;
        case NATS_CONN_STATUS_DRAINING_PUBS: return ConnectionStatus::draining_pubs;
    }
    return ConnectionStatus::disconnected;
}

//TODO pass eiher const& or string_view
int64_t CWrapper::subscribe(std::string topic, SimpleOnMessageCallback callback)
{
    // store callback
    std::unique_lock<std::mutex> lockCallback(m_simpleCallbacksMutex);
    m_simpleCallbacks.emplace_back(std::make_shared<SimpleCallbackWrapper>(callback));
    auto storedCallback = m_simpleCallbacks.back();
    lockCallback.unlock();
    // nats library prepares a subscription which later will be stored, it is this class responsibility to free the resources.
    natsSubscription* tmp;
    auto status = natsConnection_Subscribe(&tmp, m_connection.get(), topic.c_str(), onMsg, storedCallback.get());
    std::shared_ptr< natsSubscription> sub(tmp, NatsSubscriptionDeleter());

    if (status != NATS_OK) { /*TODO HANDLE */ };
    std::unique_lock<std::mutex> lockSubscription{ m_subscriptionsMutex };
    m_subscriptions.push_back(sub);
    auto subscription_ptr = m_subscriptions.back().get();
    lockSubscription.unlock();
    // id can be obtained only after successful subscription
    auto id = natsSubscription_GetID(subscription_ptr);
    storedCallback->id = id;
    // This callback removes all resources, the nats library states that after unsubscribe call there might be still message to serve
    // Nats library guarantees that after SetOnCompleteCB there will be no more calls for message handler for this subscription and resources can be safely cleaned up.
    status = natsSubscription_SetOnCompleteCB(subscription_ptr, &removeSubscriptionResources, new cleanSubscriptionResourcesContext{ id, shared_from_this() });
    if (status != NATS_OK) { /*TODO HANDLE */ };
    return id;
}

void CWrapper::unsubscribe(int64_t id)
{
    std::unique_lock<std::mutex> lock{ m_subscriptionsMutex };
    auto found = find_if(m_subscriptions.begin(), m_subscriptions.end(), [id](auto element) { return  natsSubscription_GetID(element.get()) == id; });
    lock.unlock();
    auto status = natsSubscription_Unsubscribe((*found).get());
    if (status != NATS_OK) { /*TODO HANDLE */ };
}

void CWrapper::cleanSubscription(int64_t id)
{
    std::unique_lock<std::mutex> lockSubscriptions{ m_subscriptionsMutex };
    auto foundSubscription = find_if(m_subscriptions.begin(), m_subscriptions.end(), [id](auto element) { return  natsSubscription_GetID(element.get()) == id; });
    m_subscriptions.erase(foundSubscription);
    lockSubscriptions.unlock();
    std::unique_lock<std::mutex> lockCallbacks{ m_simpleCallbacksMutex };
    auto foundCallback = find_if(m_simpleCallbacks.begin(), m_simpleCallbacks.end(), [id](auto element) { return  element->id == id; });
    m_simpleCallbacks.erase(foundCallback);
    lockCallbacks.unlock();
}

void CWrapper::publish(std::string topic, std::string payload)
{
    auto status = natsConnection_PublishString(m_connection.get(), topic.c_str(), payload.c_str());
    if (status != NATS_OK) { /*handle*/ return; }
}


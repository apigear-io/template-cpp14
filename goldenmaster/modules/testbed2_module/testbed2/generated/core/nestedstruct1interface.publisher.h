#pragma once

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/api/nestedstruct1interface.api.h"
#include "testbed2/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace Testbed2 {

/**
 * The implementation of a NestedStruct1InterfacePublisher.
 * Use this class to store clients of the NestedStruct1Interface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TESTBED2_EXPORT NestedStruct1InterfacePublisher : public INestedStruct1InterfacePublisher
{
public:
    /**
    * Implementation of INestedStruct1InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(INestedStruct1InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of INestedStruct1InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INestedStruct1InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of INestedStruct1InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(NestedStruct1InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of INestedStruct1InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of INestedStruct1InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(NestedStruct1InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of INestedStruct1InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of INestedStruct1InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const NestedStruct1& prop1) const override;
    /**
    * Implementation of INestedStruct1InterfacePublisher::publishSig1
    */
    void publishSig1(const NestedStruct1& param1) const override;
private:
    // Subscribers informed about any property change or signal emitted in NestedStruct1Interface
    std::vector<std::reference_wrapper<INestedStruct1InterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the Prop1 change.
    std::atomic<long> m_prop1ChangedCallbackNextId {0};
    // Subscribed callbacks for the Prop1 change.
    std::map<long, NestedStruct1InterfaceProp1PropertyCb> m_prop1Callbacks;
    // Mutex for m_prop1Callbacks
    mutable std::shared_timed_mutex m_prop1CallbacksMutex;
    // Next free unique identifier to subscribe for the Sig1 emission.
    std::atomic<long> m_sig1SignalCallbackNextId {0};
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, NestedStruct1InterfaceSig1SignalCb > m_sig1Callbacks;
    // Mutex for m_sig1SignalCallbackNextId and m_sig1Callbacks
    mutable std::shared_timed_mutex m_sig1CallbacksMutex;
};

} // namespace Testbed2
} // namespace Test

/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <memory>
#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/api/nestedstruct1interface.api.h"
#include "testbed2/generated/api/common.h"

namespace Test {
namespace Testbed2 {
/**
 * The implementation of a NestedStruct1InterfacePublisher.
 * The class uses pointer to implementation as a member to reduce compile time in case of the implementation changes.
 * and provides only forwarding calls to the actual implementation.
 * see NestedStruct1InterfacePublisherImpl for the implementation.
 * 
 */
class TEST_TESTBED2_EXPORT NestedStruct1InterfacePublisher: public INestedStruct1InterfacePublisher
{
public:
    explicit NestedStruct1InterfacePublisher();
    virtual ~NestedStruct1InterfacePublisher() = default;

    // NestedStruct1InterfacePublisher is not copyable
    NestedStruct1InterfacePublisher(const NestedStruct1InterfacePublisher& a) = delete;
    NestedStruct1InterfacePublisher& operator=(const NestedStruct1InterfacePublisher& a) = delete;
    // NestedStruct1InterfacePublisher is not movable
    NestedStruct1InterfacePublisher(NestedStruct1InterfacePublisher&& a) = delete;
    NestedStruct1InterfacePublisher& operator=(NestedStruct1InterfacePublisher&& a) = delete;

    void subscribeToAllChanges(INestedStruct1InterfaceSubscriber& subscriber) override;
    void unsubscribeFromAllChanges(INestedStruct1InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(NestedStruct1InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToSig1(NestedStruct1InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    void publishSig1(const NestedStruct1& param1) const override;
    void publishProp1Changed(const NestedStruct1& prop1) const override;
private:
    std::unique_ptr<INestedStruct1InterfacePublisher> m_impl;
};

} // namespace Testbed2
} // namespace Test

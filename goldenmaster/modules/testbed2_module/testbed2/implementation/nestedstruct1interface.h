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
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/core/nestedstruct1interface.data.h"
#include <memory>

namespace Test {
namespace Testbed2 {

/**
* The NestedStruct1Interface implementation.
*/
class TEST_TESTBED2_EXPORT NestedStruct1Interface : public INestedStruct1Interface
{
public:
    explicit NestedStruct1Interface();
    ~NestedStruct1Interface();
public:
    void setProp1(const NestedStruct1& prop1) override;
    const NestedStruct1& prop1() const override;
    
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
        
    /**
    * Access to a publisher, use it to subscribe for NestedStruct1Interface changes and signal emission.
    * @return The publisher for NestedStruct1Interface.
    */
    INestedStruct1InterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the NestedStruct1Interface. */
    std::unique_ptr<INestedStruct1InterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for NestedStruct1Interface. */
    NestedStruct1InterfaceData m_data;
};
} // namespace Testbed2
} // namespace Test

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
#include "generated/api/tb_same2.h"
#include "generated/api/tb_same2_common.h"

namespace Test {
namespace TbSame2 {

class TEST_TB_SAME2_EXPORT SameStruct2Interface : public ISameStruct2Interface
{
public:
    explicit SameStruct2Interface();
    ~SameStruct2Interface();
public:
    // property prop1
    void setProp1(const Struct2& prop1) override;
    const Struct2& prop1() const override;
    
    // property prop2
    void setProp2(const Struct2& prop2) override;
    const Struct2& prop2() const override;
    
    // operations
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;

    ISameStruct2InterfacePublisher* _getPublisher() const override;
private:
    struct SameStruct2InterfaceData;
    std::unique_ptr<SameStruct2InterfaceData> d_ptr;
};
} // namespace TbSame2
} // namespace Test

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
#include "tb_same1_datastructs.api.h"

namespace Test {
namespace TbSame1 {

// ********************************************************************
// Enumeration Enum1
// ********************************************************************
Enum1Enum toEnum1Enum(std::uint8_t v, bool *ok)
{
    if (ok != nullptr) {
        *ok = true;
    }
    switch (v) {
        case 1: return Enum1Enum::value1;
        case 2: return Enum1Enum::value2;
        default:
            if (ok != nullptr) {
                *ok = false;
            }
            return Enum1Enum::value1;
    }
}

// ********************************************************************
// Enumeration Enum2
// ********************************************************************
Enum2Enum toEnum2Enum(std::uint8_t v, bool *ok)
{
    if (ok != nullptr) {
        *ok = true;
    }
    switch (v) {
        case 1: return Enum2Enum::value1;
        case 2: return Enum2Enum::value2;
        default:
            if (ok != nullptr) {
                *ok = false;
            }
            return Enum2Enum::value1;
    }
}
// ********************************************************************
// Struct Struct1
// ********************************************************************
Struct1::Struct1() = default;
Struct1::Struct1(
    int field1,
    int field2,
    int field3):
    field1(field1),
    field2(field2),
    field3(field3)
{
}

bool operator==(const Struct1& lhs, const Struct1& rhs) noexcept
{
    return (
        lhs.field1 == rhs.field1 &&
        lhs.field2 == rhs.field2 &&
        lhs.field3 == rhs.field3

    );
}

bool operator!=(const Struct1& lhs, const Struct1& rhs) noexcept
{
    return !(lhs == rhs);
}
// ********************************************************************
// Struct Struct2
// ********************************************************************
Struct2::Struct2() = default;
Struct2::Struct2(
    int field1,
    int field2,
    int field3):
    field1(field1),
    field2(field2),
    field3(field3)
{
}

bool operator==(const Struct2& lhs, const Struct2& rhs) noexcept
{
    return (
        lhs.field1 == rhs.field1 &&
        lhs.field2 == rhs.field2 &&
        lhs.field3 == rhs.field3

    );
}

bool operator!=(const Struct2& lhs, const Struct2& rhs) noexcept
{
    return !(lhs == rhs);
}
} // namespace TbSame1
} // namespace Test

#include "testbed1/generated/api/datastructs.api.h"

namespace Goldenmaster {
namespace Testbed1 {
// ********************************************************************
// Struct StructBool
// ********************************************************************
StructBool::StructBool() = default;
StructBool::StructBool(bool fieldBool):
    fieldBool(fieldBool)
{
}

bool operator==(const StructBool& lhs, const StructBool& rhs) noexcept
{
    return (
        lhs.fieldBool == rhs.fieldBool

    );
}

bool operator!=(const StructBool& lhs, const StructBool& rhs) noexcept
{
    return !(lhs == rhs);
}
// ********************************************************************
// Struct StructInt
// ********************************************************************
StructInt::StructInt() = default;
StructInt::StructInt(int fieldInt):
    fieldInt(fieldInt)
{
}

bool operator==(const StructInt& lhs, const StructInt& rhs) noexcept
{
    return (
        lhs.fieldInt == rhs.fieldInt

    );
}

bool operator!=(const StructInt& lhs, const StructInt& rhs) noexcept
{
    return !(lhs == rhs);
}
// ********************************************************************
// Struct StructFloat
// ********************************************************************
StructFloat::StructFloat() = default;
StructFloat::StructFloat(float fieldFloat):
    fieldFloat(fieldFloat)
{
}

bool operator==(const StructFloat& lhs, const StructFloat& rhs) noexcept
{
    return (
        lhs.fieldFloat == rhs.fieldFloat

    );
}

bool operator!=(const StructFloat& lhs, const StructFloat& rhs) noexcept
{
    return !(lhs == rhs);
}
// ********************************************************************
// Struct StructString
// ********************************************************************
StructString::StructString() = default;
StructString::StructString(const std::string& fieldString):
    fieldString(fieldString)
{
}

bool operator==(const StructString& lhs, const StructString& rhs) noexcept
{
    return (
        lhs.fieldString == rhs.fieldString

    );
}

bool operator!=(const StructString& lhs, const StructString& rhs) noexcept
{
    return !(lhs == rhs);
}
} // namespace Testbed1
} // namespace Goldenmaster

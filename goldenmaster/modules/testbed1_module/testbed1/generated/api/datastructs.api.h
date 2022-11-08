#pragma once

#include <cinttypes>
#include <string>
#include <list>

#include "testbed1/generated/api/common.h"

namespace Goldenmaster {
namespace Testbed1 {
struct StructBool;
struct StructInt;
struct StructFloat;
struct StructString;

/**
 * Struct StructBool
 */
struct GOLDENMASTER_TESTBED1_EXPORT StructBool
{
    StructBool();
    StructBool(bool fieldBool);

    bool fieldBool{};

};
bool GOLDENMASTER_TESTBED1_EXPORT operator==(const StructBool &, const StructBool &) noexcept;
bool GOLDENMASTER_TESTBED1_EXPORT operator!=(const StructBool &, const StructBool &) noexcept;

/**
 * Struct StructInt
 */
struct GOLDENMASTER_TESTBED1_EXPORT StructInt
{
    StructInt();
    StructInt(int fieldInt);

    int fieldInt{};

};
bool GOLDENMASTER_TESTBED1_EXPORT operator==(const StructInt &, const StructInt &) noexcept;
bool GOLDENMASTER_TESTBED1_EXPORT operator!=(const StructInt &, const StructInt &) noexcept;

/**
 * Struct StructFloat
 */
struct GOLDENMASTER_TESTBED1_EXPORT StructFloat
{
    StructFloat();
    StructFloat(float fieldFloat);

    float fieldFloat{};

};
bool GOLDENMASTER_TESTBED1_EXPORT operator==(const StructFloat &, const StructFloat &) noexcept;
bool GOLDENMASTER_TESTBED1_EXPORT operator!=(const StructFloat &, const StructFloat &) noexcept;

/**
 * Struct StructString
 */
struct GOLDENMASTER_TESTBED1_EXPORT StructString
{
    StructString();
    StructString(const std::string& fieldString);

    std::string fieldString{};

};
bool GOLDENMASTER_TESTBED1_EXPORT operator==(const StructString &, const StructString &) noexcept;
bool GOLDENMASTER_TESTBED1_EXPORT operator!=(const StructString &, const StructString &) noexcept;
} // namespace Testbed1
} // namespace Goldenmaster

#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/api/common.h"

namespace Goldenmaster {
namespace Testbed1 {
/** Function that converts json formated data into StructBool.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p StructBool that will be filled with data from j.
*  In case data is malformed or not convertable to StructBool the function will throw.
*/
void GOLDENMASTER_TESTBED1_EXPORT from_json(const nlohmann::json& j, StructBool& p);
/** Function that converts json formated data into StructBool
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input StructBool/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED1_EXPORT to_json(nlohmann::json& j, const StructBool& p);
/** Function that converts json formated data into StructInt.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p StructInt that will be filled with data from j.
*  In case data is malformed or not convertable to StructInt the function will throw.
*/
void GOLDENMASTER_TESTBED1_EXPORT from_json(const nlohmann::json& j, StructInt& p);
/** Function that converts json formated data into StructInt
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input StructInt/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED1_EXPORT to_json(nlohmann::json& j, const StructInt& p);
/** Function that converts json formated data into StructFloat.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p StructFloat that will be filled with data from j.
*  In case data is malformed or not convertable to StructFloat the function will throw.
*/
void GOLDENMASTER_TESTBED1_EXPORT from_json(const nlohmann::json& j, StructFloat& p);
/** Function that converts json formated data into StructFloat
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input StructFloat/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED1_EXPORT to_json(nlohmann::json& j, const StructFloat& p);
/** Function that converts json formated data into StructString.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p StructString that will be filled with data from j.
*  In case data is malformed or not convertable to StructString the function will throw.
*/
void GOLDENMASTER_TESTBED1_EXPORT from_json(const nlohmann::json& j, StructString& p);
/** Function that converts json formated data into StructString
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input StructString/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED1_EXPORT to_json(nlohmann::json& j, const StructString& p);
} // namespace Testbed1
} // namespace Goldenmaster

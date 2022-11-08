#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/api/common.h"

namespace Goldenmaster {
namespace Testbed2 {
/** Function that converts json formated data into Struct1.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p Struct1 that will be filled with data from j.
*  In case data is malformed or not convertable to Struct1 the function will throw.
*/
void GOLDENMASTER_TESTBED2_EXPORT from_json(const nlohmann::json& j, Struct1& p);
/** Function that converts json formated data into Struct1
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input Struct1/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED2_EXPORT to_json(nlohmann::json& j, const Struct1& p);
/** Function that converts json formated data into Struct2.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p Struct2 that will be filled with data from j.
*  In case data is malformed or not convertable to Struct2 the function will throw.
*/
void GOLDENMASTER_TESTBED2_EXPORT from_json(const nlohmann::json& j, Struct2& p);
/** Function that converts json formated data into Struct2
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input Struct2/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED2_EXPORT to_json(nlohmann::json& j, const Struct2& p);
/** Function that converts json formated data into Struct3.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p Struct3 that will be filled with data from j.
*  In case data is malformed or not convertable to Struct3 the function will throw.
*/
void GOLDENMASTER_TESTBED2_EXPORT from_json(const nlohmann::json& j, Struct3& p);
/** Function that converts json formated data into Struct3
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input Struct3/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED2_EXPORT to_json(nlohmann::json& j, const Struct3& p);
/** Function that converts json formated data into Struct4.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p Struct4 that will be filled with data from j.
*  In case data is malformed or not convertable to Struct4 the function will throw.
*/
void GOLDENMASTER_TESTBED2_EXPORT from_json(const nlohmann::json& j, Struct4& p);
/** Function that converts json formated data into Struct4
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input Struct4/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED2_EXPORT to_json(nlohmann::json& j, const Struct4& p);
/** Function that converts json formated data into NestedStruct1.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p NestedStruct1 that will be filled with data from j.
*  In case data is malformed or not convertable to NestedStruct1 the function will throw.
*/
void GOLDENMASTER_TESTBED2_EXPORT from_json(const nlohmann::json& j, NestedStruct1& p);
/** Function that converts json formated data into NestedStruct1
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input NestedStruct1/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED2_EXPORT to_json(nlohmann::json& j, const NestedStruct1& p);
/** Function that converts json formated data into NestedStruct2.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p NestedStruct2 that will be filled with data from j.
*  In case data is malformed or not convertable to NestedStruct2 the function will throw.
*/
void GOLDENMASTER_TESTBED2_EXPORT from_json(const nlohmann::json& j, NestedStruct2& p);
/** Function that converts json formated data into NestedStruct2
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input NestedStruct2/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED2_EXPORT to_json(nlohmann::json& j, const NestedStruct2& p);
/** Function that converts json formated data into NestedStruct3.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p NestedStruct3 that will be filled with data from j.
*  In case data is malformed or not convertable to NestedStruct3 the function will throw.
*/
void GOLDENMASTER_TESTBED2_EXPORT from_json(const nlohmann::json& j, NestedStruct3& p);
/** Function that converts json formated data into NestedStruct3
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input NestedStruct3/'}
' from which json data will be filled
*/
void GOLDENMASTER_TESTBED2_EXPORT to_json(nlohmann::json& j, const NestedStruct3& p);
} // namespace Testbed2
} // namespace Goldenmaster

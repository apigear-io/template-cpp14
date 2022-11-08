#include "tb_same2/generated/core/tb_same2.json.adapter.h"

namespace Goldenmaster {
namespace TbSame2 {
void from_json(const nlohmann::json& j, Struct1& p) {
    p = Struct1(
        j.at("field1").get<int>(),
        j.at("field2").get<int>(),
        j.at("field3").get<int>()
    );
}
void to_json(nlohmann::json& j, const Struct1& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2},
        {"field3", p.field3}
        };
}
void from_json(const nlohmann::json& j, Struct2& p) {
    p = Struct2(
        j.at("field1").get<int>(),
        j.at("field2").get<int>(),
        j.at("field3").get<int>()
    );
}
void to_json(nlohmann::json& j, const Struct2& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2},
        {"field3", p.field3}
        };
}
} // namespace TbSame2
} // namespace Goldenmaster

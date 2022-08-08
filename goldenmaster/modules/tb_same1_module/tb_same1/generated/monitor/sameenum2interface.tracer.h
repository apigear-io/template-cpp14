#pragma once

#include "tb_same1/generated/api/tb_same1.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

class SameEnum2InterfaceTracer
{
public:
  SameEnum2InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~SameEnum2InterfaceTracer() = default;
  
  void capture_state(ISameEnum2Interface* obj);
  void trace_func1(const Enum1Enum& param1);
  void trace_func2(const Enum1Enum& param1, const Enum2Enum& param2);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace TbSame1
} // namespace Test
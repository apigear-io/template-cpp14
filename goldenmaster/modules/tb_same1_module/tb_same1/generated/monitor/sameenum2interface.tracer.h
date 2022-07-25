#pragma once

#include "tb_same1/generated/api/tb_same1.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

/**
* A helper class for monitoring.
* Decorates the to PocoImpl::Tracer calls with information about state and operations specific for SameEnum2Interface.
*/
class SameEnum2InterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  SameEnum2InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~SameEnum2InterfaceTracer() = default;
  /**
  * Prepares the SameEnum2Interface object state in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum2Interface object to trace.
  */
  void capture_state(ISameEnum2Interface* obj);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum2Interface object to trace.
  */
  void trace_func1(const Enum1Enum& param1);
  /**
  * Prepares information about the func2 call in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum2Interface object to trace.
  */
  void trace_func2(const Enum1Enum& param1, const Enum2Enum& param2);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSame1
} // namespace Test

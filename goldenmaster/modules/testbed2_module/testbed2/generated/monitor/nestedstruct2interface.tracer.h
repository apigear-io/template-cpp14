#pragma once

#include "testbed2/generated/api/testbed2.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

/**
* A helper class for monitoring.
* Decorates the to PocoImpl::Tracer calls with information about state and operations specific for NestedStruct2Interface.
*/
class NestedStruct2InterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  NestedStruct2InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~NestedStruct2InterfaceTracer() = default;
  /**
  * Prepares the NestedStruct2Interface object state in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct2Interface object to trace.
  */
  void capture_state(INestedStruct2Interface* obj);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct2Interface object to trace.
  */
  void trace_func1(const NestedStruct1& param1);
  /**
  * Prepares information about the func2 call in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct2Interface object to trace.
  */
  void trace_func2(const NestedStruct1& param1, const NestedStruct2& param2);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace Testbed2
} // namespace Test

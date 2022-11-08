#include "apigear/tracer/tracer.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"
#include "tb_enum/generated/monitor/enuminterface.tracer.h"

using namespace Goldenmaster::TbEnum;

EnumInterfaceTracer::EnumInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void EnumInterfaceTracer::capture_state(IEnumInterface* obj)
{
    nlohmann::json fields_;
    fields_["prop0"] = obj->getProp0();
    fields_["prop1"] = obj->getProp1();
    fields_["prop2"] = obj->getProp2();
    fields_["prop3"] = obj->getProp3();
    m_tracer.state("tb.enum.EnumInterface#_state", fields_);
}

void EnumInterfaceTracer::trace_func0(Enum0Enum param0)
{
    nlohmann::json fields_;
    fields_["param0"] = param0;
    m_tracer.call("tb.enum.EnumInterface#func0", fields_);
}

void EnumInterfaceTracer::trace_func1(Enum1Enum param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.call("tb.enum.EnumInterface#func1", fields_);
}

void EnumInterfaceTracer::trace_func2(Enum2Enum param2)
{
    nlohmann::json fields_;
    fields_["param2"] = param2;
    m_tracer.call("tb.enum.EnumInterface#func2", fields_);
}

void EnumInterfaceTracer::trace_func3(Enum3Enum param3)
{
    nlohmann::json fields_;
    fields_["param3"] = param3;
    m_tracer.call("tb.enum.EnumInterface#func3", fields_);
}
void EnumInterfaceTracer::trace_sig0(Enum0Enum param0)
{
    nlohmann::json fields_;
    fields_["param0"] = param0;
    m_tracer.signal("tb.enum.EnumInterface#sig0", fields_);
}
void EnumInterfaceTracer::trace_sig1(Enum1Enum param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.signal("tb.enum.EnumInterface#sig1", fields_);
}
void EnumInterfaceTracer::trace_sig2(Enum2Enum param2)
{
    nlohmann::json fields_;
    fields_["param2"] = param2;
    m_tracer.signal("tb.enum.EnumInterface#sig2", fields_);
}
void EnumInterfaceTracer::trace_sig3(Enum3Enum param3)
{
    nlohmann::json fields_;
    fields_["param3"] = param3;
    m_tracer.signal("tb.enum.EnumInterface#sig3", fields_);
}
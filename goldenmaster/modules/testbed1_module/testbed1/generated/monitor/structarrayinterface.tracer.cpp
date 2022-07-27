#include "apigear/tracer/tracer.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include "testbed1/generated/monitor/structarrayinterface.tracer.h"

using namespace Test::Testbed1;

StructArrayInterfaceTracer::StructArrayInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void StructArrayInterfaceTracer::capture_state(IStructArrayInterface* obj)
{
    nlohmann::json fields_;
    fields_["propBool"] = obj->propBool();
    fields_["propInt"] = obj->propInt();
    fields_["propFloat"] = obj->propFloat();
    fields_["propString"] = obj->propString();
    m_tracer.state("testbed1.StructArrayInterface#_state", fields_);
}

void StructArrayInterfaceTracer::trace_funcBool(const std::list<StructBool>& paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.call("testbed1.StructArrayInterface#funcBool", fields_);
}

void StructArrayInterfaceTracer::trace_funcInt(const std::list<StructInt>& paramInt)
{
    nlohmann::json fields_;
    fields_["paramInt"] = paramInt;
    m_tracer.call("testbed1.StructArrayInterface#funcInt", fields_);
}

void StructArrayInterfaceTracer::trace_funcFloat(const std::list<StructFloat>& paramFloat)
{
    nlohmann::json fields_;
    fields_["paramFloat"] = paramFloat;
    m_tracer.call("testbed1.StructArrayInterface#funcFloat", fields_);
}

void StructArrayInterfaceTracer::trace_funcString(const std::list<StructString>& paramString)
{
    nlohmann::json fields_;
    fields_["paramString"] = paramString;
    m_tracer.call("testbed1.StructArrayInterface#funcString", fields_);
}

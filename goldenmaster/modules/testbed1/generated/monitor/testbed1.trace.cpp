#include "apigear/tracer/tracer.h"
#include "testbed1.trace.h"
#include "generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;

StructInterfaceTracer::StructInterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void StructInterfaceTracer::capture_state(IStructInterface* obj)
{
    nlohmann::json fields_;
    fields_["propBool"] = obj->propBool();
    fields_["propInt"] = obj->propInt();
    fields_["propFloat"] = obj->propFloat();
    fields_["propString"] = obj->propString();
    m_tracer->state("testbed1.StructInterface#_state", fields_);
}

void StructInterfaceTracer::trace_funcBool(const StructBool& paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer->call("testbed1.StructInterface#funcBool", fields_);
}

void StructInterfaceTracer::trace_funcInt(const StructInt& paramInt)
{
    nlohmann::json fields_;
    fields_["paramInt"] = paramInt;
    m_tracer->call("testbed1.StructInterface#funcInt", fields_);
}

void StructInterfaceTracer::trace_funcFloat(const StructFloat& paramFloat)
{
    nlohmann::json fields_;
    fields_["paramFloat"] = paramFloat;
    m_tracer->call("testbed1.StructInterface#funcFloat", fields_);
}

void StructInterfaceTracer::trace_funcString(const StructString& paramString)
{
    nlohmann::json fields_;
    fields_["paramString"] = paramString;
    m_tracer->call("testbed1.StructInterface#funcString", fields_);
}

StructArrayInterfaceTracer::StructArrayInterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
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
    m_tracer->state("testbed1.StructArrayInterface#_state", fields_);
}

void StructArrayInterfaceTracer::trace_funcBool(const std::list<StructBool>& paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer->call("testbed1.StructArrayInterface#funcBool", fields_);
}

void StructArrayInterfaceTracer::trace_funcInt(const std::list<StructInt>& paramInt)
{
    nlohmann::json fields_;
    fields_["paramInt"] = paramInt;
    m_tracer->call("testbed1.StructArrayInterface#funcInt", fields_);
}

void StructArrayInterfaceTracer::trace_funcFloat(const std::list<StructFloat>& paramFloat)
{
    nlohmann::json fields_;
    fields_["paramFloat"] = paramFloat;
    m_tracer->call("testbed1.StructArrayInterface#funcFloat", fields_);
}

void StructArrayInterfaceTracer::trace_funcString(const std::list<StructString>& paramString)
{
    nlohmann::json fields_;
    fields_["paramString"] = paramString;
    m_tracer->call("testbed1.StructArrayInterface#funcString", fields_);
}
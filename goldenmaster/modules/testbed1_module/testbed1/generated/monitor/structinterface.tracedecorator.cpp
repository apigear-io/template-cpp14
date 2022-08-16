/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "testbed1/generated/monitor/structinterface.tracedecorator.h"
#include "testbed1/generated/monitor/structinterface.tracer.h"

using namespace Test::Testbed1;
StructInterfaceTraceDecorator::StructInterfaceTraceDecorator(IStructInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<StructInterfaceTracer>(tracer))
    , m_impl(impl)
{
    m_sigBoolSubscriptionToken = m_impl._getPublisher().subscribeToSigBool(
    [this](const StructBool& paramBool)
    {
        m_tracer->trace_SigBool(paramBool);
    }
    );
    m_sigIntSubscriptionToken = m_impl._getPublisher().subscribeToSigInt(
    [this](const StructInt& paramInt)
    {
        m_tracer->trace_SigInt(paramInt);
    }
    );
    m_sigFloatSubscriptionToken = m_impl._getPublisher().subscribeToSigFloat(
    [this](const StructFloat& paramFloat)
    {
        m_tracer->trace_SigFloat(paramFloat);
    }
    );
    m_sigStringSubscriptionToken = m_impl._getPublisher().subscribeToSigString(
    [this](const StructString& paramString)
    {
        m_tracer->trace_SigString(paramString);
    }
    );
}
StructInterfaceTraceDecorator::~StructInterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromSigBool(m_sigBoolSubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSigInt(m_sigIntSubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSigFloat(m_sigFloatSubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSigString(m_sigStringSubscriptionToken);
}

std::unique_ptr<StructInterfaceTraceDecorator> StructInterfaceTraceDecorator::connect(IStructInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<StructInterfaceTraceDecorator>(new StructInterfaceTraceDecorator(impl, tracer));
}
/**
   \brief 
*/
StructBool StructInterfaceTraceDecorator::funcBool(const StructBool& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBool(paramBool);
}
std::future<StructBool> StructInterfaceTraceDecorator::funcBoolAsync(const StructBool& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBoolAsync(paramBool);
}
/**
   \brief 
*/
StructBool StructInterfaceTraceDecorator::funcInt(const StructInt& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcInt(paramInt);
}
std::future<StructBool> StructInterfaceTraceDecorator::funcIntAsync(const StructInt& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcIntAsync(paramInt);
}
/**
   \brief 
*/
StructFloat StructInterfaceTraceDecorator::funcFloat(const StructFloat& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloat(paramFloat);
}
std::future<StructFloat> StructInterfaceTraceDecorator::funcFloatAsync(const StructFloat& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
StructString StructInterfaceTraceDecorator::funcString(const StructString& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcString(paramString);
}
std::future<StructString> StructInterfaceTraceDecorator::funcStringAsync(const StructString& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcStringAsync(paramString);
}
void StructInterfaceTraceDecorator::setPropBool(const StructBool& propBool)
{
    m_tracer->capture_state(this);
    m_impl.setPropBool(propBool);
    m_impl.setPropBool(propBool);
}

const StructBool& StructInterfaceTraceDecorator::propBool() const
{
    return m_impl.propBool();
}
void StructInterfaceTraceDecorator::setPropInt(const StructInt& propInt)
{
    m_tracer->capture_state(this);
    m_impl.setPropInt(propInt);
    m_impl.setPropInt(propInt);
}

const StructInt& StructInterfaceTraceDecorator::propInt() const
{
    return m_impl.propInt();
}
void StructInterfaceTraceDecorator::setPropFloat(const StructFloat& propFloat)
{
    m_tracer->capture_state(this);
    m_impl.setPropFloat(propFloat);
    m_impl.setPropFloat(propFloat);
}

const StructFloat& StructInterfaceTraceDecorator::propFloat() const
{
    return m_impl.propFloat();
}
void StructInterfaceTraceDecorator::setPropString(const StructString& propString)
{
    m_tracer->capture_state(this);
    m_impl.setPropString(propString);
    m_impl.setPropString(propString);
}

const StructString& StructInterfaceTraceDecorator::propString() const
{
    return m_impl.propString();
}

IStructInterfacePublisher& StructInterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
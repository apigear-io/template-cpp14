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


#include "tb_simple/generated/monitor/simplearrayinterface.tracedecorator.h"
#include "tb_simple/generated/monitor/simplearrayinterface.tracer.h"

using namespace Test::TbSimple;
SimpleArrayInterfaceTraceDecorator::SimpleArrayInterfaceTraceDecorator(ISimpleArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<SimpleArrayInterfaceTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
SimpleArrayInterfaceTraceDecorator::~SimpleArrayInterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<SimpleArrayInterfaceTraceDecorator> SimpleArrayInterfaceTraceDecorator::connect(ISimpleArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<SimpleArrayInterfaceTraceDecorator>(new SimpleArrayInterfaceTraceDecorator(impl, tracer));
}
std::list<bool> SimpleArrayInterfaceTraceDecorator::funcBool(const std::list<bool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBool(paramBool);
}
std::future<std::list<bool>> SimpleArrayInterfaceTraceDecorator::funcBoolAsync(const std::list<bool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBoolAsync(paramBool);
}
std::list<int> SimpleArrayInterfaceTraceDecorator::funcInt(const std::list<int>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcInt(paramInt);
}
std::future<std::list<int>> SimpleArrayInterfaceTraceDecorator::funcIntAsync(const std::list<int>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcIntAsync(paramInt);
}
std::list<float> SimpleArrayInterfaceTraceDecorator::funcFloat(const std::list<float>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloat(paramFloat);
}
std::future<std::list<float>> SimpleArrayInterfaceTraceDecorator::funcFloatAsync(const std::list<float>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloatAsync(paramFloat);
}
std::list<std::string> SimpleArrayInterfaceTraceDecorator::funcString(const std::list<std::string>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcString(paramString);
}
std::future<std::list<std::string>> SimpleArrayInterfaceTraceDecorator::funcStringAsync(const std::list<std::string>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcStringAsync(paramString);
}
void SimpleArrayInterfaceTraceDecorator::setPropBool(const std::list<bool>& propBool)
{
    m_impl.setPropBool(propBool);
}

const std::list<bool>& SimpleArrayInterfaceTraceDecorator::propBool() const
{
    return m_impl.propBool();
}
void SimpleArrayInterfaceTraceDecorator::setPropInt(const std::list<int>& propInt)
{
    m_impl.setPropInt(propInt);
}

const std::list<int>& SimpleArrayInterfaceTraceDecorator::propInt() const
{
    return m_impl.propInt();
}
void SimpleArrayInterfaceTraceDecorator::setPropFloat(const std::list<float>& propFloat)
{
    m_impl.setPropFloat(propFloat);
}

const std::list<float>& SimpleArrayInterfaceTraceDecorator::propFloat() const
{
    return m_impl.propFloat();
}
void SimpleArrayInterfaceTraceDecorator::setPropString(const std::list<std::string>& propString)
{
    m_impl.setPropString(propString);
}

const std::list<std::string>& SimpleArrayInterfaceTraceDecorator::propString() const
{
    return m_impl.propString();
}
void SimpleArrayInterfaceTraceDecorator::onSigBool(const std::list<bool>& paramBool)
{
    m_tracer->trace_sigBool(paramBool);
}

void SimpleArrayInterfaceTraceDecorator::onSigInt(const std::list<int>& paramInt)
{
    m_tracer->trace_sigInt(paramInt);
}

void SimpleArrayInterfaceTraceDecorator::onSigFloat(const std::list<float>& paramFloat)
{
    m_tracer->trace_sigFloat(paramFloat);
}

void SimpleArrayInterfaceTraceDecorator::onSigString(const std::list<std::string>& paramString)
{
    m_tracer->trace_sigString(paramString);
}

void SimpleArrayInterfaceTraceDecorator::onPropBoolChanged(const std::list<bool>& /*propBool*/)
{
    m_tracer->capture_state(this);
}

void SimpleArrayInterfaceTraceDecorator::onPropIntChanged(const std::list<int>& /*propInt*/)
{
    m_tracer->capture_state(this);
}

void SimpleArrayInterfaceTraceDecorator::onPropFloatChanged(const std::list<float>& /*propFloat*/)
{
    m_tracer->capture_state(this);
}

void SimpleArrayInterfaceTraceDecorator::onPropStringChanged(const std::list<std::string>& /*propString*/)
{
    m_tracer->capture_state(this);
}



ISimpleArrayInterfacePublisher& SimpleArrayInterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
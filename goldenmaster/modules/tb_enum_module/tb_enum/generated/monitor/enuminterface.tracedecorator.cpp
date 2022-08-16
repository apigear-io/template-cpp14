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


#include "tb_enum/generated/monitor/enuminterface.tracedecorator.h"
#include "tb_enum/generated/monitor/enuminterface.tracer.h"

using namespace Test::TbEnum;
EnumInterfaceTraceDecorator::EnumInterfaceTraceDecorator(IEnumInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<EnumInterfaceTracer>(tracer))
    , m_impl(impl)
{
    m_sig0SubscriptionToken = m_impl._getPublisher().subscribeToSig0(
    [this](const Enum0Enum& param0)
    {
        m_tracer->trace_sig0(param0);
    }
    );
    m_sig1SubscriptionToken = m_impl._getPublisher().subscribeToSig1(
    [this](const Enum1Enum& param1)
    {
        m_tracer->trace_sig1(param1);
    }
    );
    m_sig2SubscriptionToken = m_impl._getPublisher().subscribeToSig2(
    [this](const Enum2Enum& param2)
    {
        m_tracer->trace_sig2(param2);
    }
    );
    m_sig3SubscriptionToken = m_impl._getPublisher().subscribeToSig3(
    [this](const Enum3Enum& param3)
    {
        m_tracer->trace_sig3(param3);
    }
    );
}
EnumInterfaceTraceDecorator::~EnumInterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromSig0(m_sig0SubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSig1(m_sig1SubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSig2(m_sig2SubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSig3(m_sig3SubscriptionToken);
}

std::unique_ptr<EnumInterfaceTraceDecorator> EnumInterfaceTraceDecorator::connect(IEnumInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<EnumInterfaceTraceDecorator>(new EnumInterfaceTraceDecorator(impl, tracer));
}
/**
   \brief 
*/
Enum0Enum EnumInterfaceTraceDecorator::func0(const Enum0Enum& param0)
{
    m_tracer->trace_func0(param0);
    return m_impl.func0(param0);
}
std::future<Enum0Enum> EnumInterfaceTraceDecorator::func0Async(const Enum0Enum& param0)
{
    m_tracer->trace_func0(param0);
    return m_impl.func0Async(param0);
}
/**
   \brief 
*/
Enum1Enum EnumInterfaceTraceDecorator::func1(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1(param1);
}
std::future<Enum1Enum> EnumInterfaceTraceDecorator::func1Async(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1Async(param1);
}
/**
   \brief 
*/
Enum2Enum EnumInterfaceTraceDecorator::func2(const Enum2Enum& param2)
{
    m_tracer->trace_func2(param2);
    return m_impl.func2(param2);
}
std::future<Enum2Enum> EnumInterfaceTraceDecorator::func2Async(const Enum2Enum& param2)
{
    m_tracer->trace_func2(param2);
    return m_impl.func2Async(param2);
}
/**
   \brief 
*/
Enum3Enum EnumInterfaceTraceDecorator::func3(const Enum3Enum& param3)
{
    m_tracer->trace_func3(param3);
    return m_impl.func3(param3);
}
std::future<Enum3Enum> EnumInterfaceTraceDecorator::func3Async(const Enum3Enum& param3)
{
    m_tracer->trace_func3(param3);
    return m_impl.func3Async(param3);
}
void EnumInterfaceTraceDecorator::setProp0(const Enum0Enum& prop0)
{
    m_tracer->capture_state(this);
    m_impl.setProp0(prop0);
    m_impl.setProp0(prop0);
}

const Enum0Enum& EnumInterfaceTraceDecorator::prop0() const
{
    return m_impl.prop0();
}
void EnumInterfaceTraceDecorator::setProp1(const Enum1Enum& prop1)
{
    m_tracer->capture_state(this);
    m_impl.setProp1(prop1);
    m_impl.setProp1(prop1);
}

const Enum1Enum& EnumInterfaceTraceDecorator::prop1() const
{
    return m_impl.prop1();
}
void EnumInterfaceTraceDecorator::setProp2(const Enum2Enum& prop2)
{
    m_tracer->capture_state(this);
    m_impl.setProp2(prop2);
    m_impl.setProp2(prop2);
}

const Enum2Enum& EnumInterfaceTraceDecorator::prop2() const
{
    return m_impl.prop2();
}
void EnumInterfaceTraceDecorator::setProp3(const Enum3Enum& prop3)
{
    m_tracer->capture_state(this);
    m_impl.setProp3(prop3);
    m_impl.setProp3(prop3);
}

const Enum3Enum& EnumInterfaceTraceDecorator::prop3() const
{
    return m_impl.prop3();
}

IEnumInterfacePublisher& EnumInterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
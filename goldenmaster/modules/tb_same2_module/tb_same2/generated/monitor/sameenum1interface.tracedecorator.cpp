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


#include "tb_same2/generated/monitor/sameenum1interface.tracedecorator.h"
#include "tb_same2/generated/monitor/sameenum1interface.tracer.h"

using namespace Test::TbSame2;
SameEnum1InterfaceTraceDecorator::SameEnum1InterfaceTraceDecorator(ISameEnum1Interface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<SameEnum1InterfaceTracer>(tracer))
    , m_impl(impl)
{
    m_sig1SubscriptionToken = m_impl._getPublisher().subscribeToSig1(
    [this](const Enum1Enum& param1)
    {
        (void) param1; // To suppress unreferenced formal parameter error
        /**m_tracer->trace_Sig1(param1)*/
    }
    );
}
SameEnum1InterfaceTraceDecorator::~SameEnum1InterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromSig1(m_sig1SubscriptionToken);
}

std::unique_ptr<SameEnum1InterfaceTraceDecorator> SameEnum1InterfaceTraceDecorator::connect(ISameEnum1Interface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<SameEnum1InterfaceTraceDecorator>(new SameEnum1InterfaceTraceDecorator(impl, tracer));
}
/**
   \brief 
*/
Enum1Enum SameEnum1InterfaceTraceDecorator::func1(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1(param1);
}
std::future<Enum1Enum> SameEnum1InterfaceTraceDecorator::func1Async(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1Async(param1);
}
void SameEnum1InterfaceTraceDecorator::setProp1(const Enum1Enum& prop1)
{
    m_tracer->capture_state(this);
    m_impl.setProp1(prop1);
    m_impl.setProp1(prop1);
}

const Enum1Enum& SameEnum1InterfaceTraceDecorator::prop1() const
{
    return m_impl.prop1();
}

ISameEnum1InterfacePublisher& SameEnum1InterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
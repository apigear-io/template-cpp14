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


#include "testbed2/generated/monitor/manyparaminterface.tracedecorator.h"
#include "testbed2/generated/monitor/manyparaminterface.tracer.h"

using namespace Test::Testbed2;
ManyParamInterfaceTraceDecorator::ManyParamInterfaceTraceDecorator(IManyParamInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<ManyParamInterfaceTracer>(tracer))
    , m_impl(impl)
{
    m_sig1SubscriptionToken = m_impl._getPublisher().subscribeToSig1(
    [this](int param1)
    {
        (void) param1; // To suppress unreferenced formal parameter error
        /**m_tracer->trace_Sig1(param1)*/
    }
    );
    m_sig2SubscriptionToken = m_impl._getPublisher().subscribeToSig2(
    [this](int param1,int param2)
    {
        (void) param1; // To suppress unreferenced formal parameter error
        (void) param2; // To suppress unreferenced formal parameter error
        /**m_tracer->trace_Sig2(param1,param2)*/
    }
    );
    m_sig3SubscriptionToken = m_impl._getPublisher().subscribeToSig3(
    [this](int param1,int param2,int param3)
    {
        (void) param1; // To suppress unreferenced formal parameter error
        (void) param2; // To suppress unreferenced formal parameter error
        (void) param3; // To suppress unreferenced formal parameter error
        /**m_tracer->trace_Sig3(param1,param2,param3)*/
    }
    );
    m_sig4SubscriptionToken = m_impl._getPublisher().subscribeToSig4(
    [this](int param1,int param2,int param3,int param4)
    {
        (void) param1; // To suppress unreferenced formal parameter error
        (void) param2; // To suppress unreferenced formal parameter error
        (void) param3; // To suppress unreferenced formal parameter error
        (void) param4; // To suppress unreferenced formal parameter error
        /**m_tracer->trace_Sig4(param1,param2,param3,param4)*/
    }
    );
}
ManyParamInterfaceTraceDecorator::~ManyParamInterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromSig1(m_sig1SubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSig2(m_sig2SubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSig3(m_sig3SubscriptionToken);
    m_impl._getPublisher().unsubscribeFromSig4(m_sig4SubscriptionToken);
}

std::unique_ptr<ManyParamInterfaceTraceDecorator> ManyParamInterfaceTraceDecorator::connect(IManyParamInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<ManyParamInterfaceTraceDecorator>(new ManyParamInterfaceTraceDecorator(impl, tracer));
}
/**
   \brief 
*/
int ManyParamInterfaceTraceDecorator::func1(int param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1(param1);
}
std::future<int> ManyParamInterfaceTraceDecorator::func1Async(int param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1Async(param1);
}
/**
   \brief 
*/
int ManyParamInterfaceTraceDecorator::func2(int param1, int param2)
{
    m_tracer->trace_func2(param1,param2);
    return m_impl.func2(param1,param2);
}
std::future<int> ManyParamInterfaceTraceDecorator::func2Async(int param1, int param2)
{
    m_tracer->trace_func2(param1,param2);
    return m_impl.func2Async(param1,param2);
}
/**
   \brief 
*/
int ManyParamInterfaceTraceDecorator::func3(int param1, int param2, int param3)
{
    m_tracer->trace_func3(param1,param2,param3);
    return m_impl.func3(param1,param2,param3);
}
std::future<int> ManyParamInterfaceTraceDecorator::func3Async(int param1, int param2, int param3)
{
    m_tracer->trace_func3(param1,param2,param3);
    return m_impl.func3Async(param1,param2,param3);
}
/**
   \brief 
*/
int ManyParamInterfaceTraceDecorator::func4(int param1, int param2, int param3, int param4)
{
    m_tracer->trace_func4(param1,param2,param3,param4);
    return m_impl.func4(param1,param2,param3,param4);
}
std::future<int> ManyParamInterfaceTraceDecorator::func4Async(int param1, int param2, int param3, int param4)
{
    m_tracer->trace_func4(param1,param2,param3,param4);
    return m_impl.func4Async(param1,param2,param3,param4);
}
void ManyParamInterfaceTraceDecorator::setProp1(int prop1)
{
    m_tracer->capture_state(this);
    m_impl.setProp1(prop1);
    m_impl.setProp1(prop1);
}

int ManyParamInterfaceTraceDecorator::prop1() const
{
    return m_impl.prop1();
}
void ManyParamInterfaceTraceDecorator::setProp2(int prop2)
{
    m_tracer->capture_state(this);
    m_impl.setProp2(prop2);
    m_impl.setProp2(prop2);
}

int ManyParamInterfaceTraceDecorator::prop2() const
{
    return m_impl.prop2();
}
void ManyParamInterfaceTraceDecorator::setProp3(int prop3)
{
    m_tracer->capture_state(this);
    m_impl.setProp3(prop3);
    m_impl.setProp3(prop3);
}

int ManyParamInterfaceTraceDecorator::prop3() const
{
    return m_impl.prop3();
}
void ManyParamInterfaceTraceDecorator::setProp4(int prop4)
{
    m_tracer->capture_state(this);
    m_impl.setProp4(prop4);
    m_impl.setProp4(prop4);
}

int ManyParamInterfaceTraceDecorator::prop4() const
{
    return m_impl.prop4();
}

IManyParamInterfacePublisher& ManyParamInterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
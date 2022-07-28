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

#pragma once
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed1 {

class StructInterfaceTracer;

class TEST_TESTBED1_EXPORT StructInterfaceTraceDecorator : public IStructInterface
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The StructInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit StructInterfaceTraceDecorator(IStructInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the StructInterfaceTraceDecorator object.
    * @param impl The StructInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<StructInterfaceTraceDecorator> connect(IStructInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~StructInterfaceTraceDecorator();

    /** Traces funcBool and forwards call to StructInterface implementation. */
    StructBool funcBool(const StructBool& paramBool) override;
    /** Traces funcBool and forwards call to StructInterface implementation. */
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;
    
    /** Traces funcInt and forwards call to StructInterface implementation. */
    StructBool funcInt(const StructInt& paramInt) override;
    /** Traces funcInt and forwards call to StructInterface implementation. */
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;
    
    /** Traces funcFloat and forwards call to StructInterface implementation. */
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    /** Traces funcFloat and forwards call to StructInterface implementation. */
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;
    
    /** Traces funcString and forwards call to StructInterface implementation. */
    StructString funcString(const StructString& paramString) override;
    /** Traces funcString and forwards call to StructInterface implementation. */
    std::future<StructString> funcStringAsync(const StructString& paramString) override;
    
    /** Traces set PropBool and forwards call to StructInterface implementation. */
    void setPropbool(const StructBool& propBool) override;
    /** Forwards call to StructInterface implementation. */
    const StructBool& propBool() const override;
    
    /** Traces set PropInt and forwards call to StructInterface implementation. */
    void setPropint(const StructInt& propInt) override;
    /** Forwards call to StructInterface implementation. */
    const StructInt& propInt() const override;
    
    /** Traces set PropFloat and forwards call to StructInterface implementation. */
    void setPropfloat(const StructFloat& propFloat) override;
    /** Forwards call to StructInterface implementation. */
    const StructFloat& propFloat() const override;
    
    /** Traces set PropString and forwards call to StructInterface implementation. */
    void setPropstring(const StructString& propString) override;
    /** Forwards call to StructInterface implementation. */
    const StructString& propString() const override;
    
    /**
    * Access to a publisher, use it to subscribe for StructInterface changes and signal emission.
    * @return The publisher for StructInterface.
    */
    IStructInterfacePublisher& _getPublisher() const override;
private:
    /** Subscription token for sigBool callback */
    long m_sigBoolSubscriptionToken;
    /** Subscription token for sigInt callback */
    long m_sigIntSubscriptionToken;
    /** Subscription token for sigFloat callback */
    long m_sigFloatSubscriptionToken;
    /** Subscription token for sigString callback */
    long m_sigStringSubscriptionToken;

    /** A tracer that provides the traces for given StructInterface object. */
    std::unique_ptr<StructInterfaceTracer> m_tracer;
    /** The StructInterface object which is traced */
    IStructInterface& m_impl;
};
} // namespace Testbed1
} // namespace Test

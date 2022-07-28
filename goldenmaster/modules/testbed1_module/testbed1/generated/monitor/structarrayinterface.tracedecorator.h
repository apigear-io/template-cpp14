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

class StructArrayInterfaceTracer;

class TEST_TESTBED1_EXPORT StructArrayInterfaceTraceDecorator : public IStructArrayInterface
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The StructArrayInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit StructArrayInterfaceTraceDecorator(IStructArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the StructArrayInterfaceTraceDecorator object.
    * @param impl The StructArrayInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<StructArrayInterfaceTraceDecorator> connect(IStructArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~StructArrayInterfaceTraceDecorator();

    /** Traces funcBool and forwards call to StructArrayInterface implementation. */
    StructBool funcBool(const std::list<StructBool>& paramBool) override;
    /** Traces funcBool and forwards call to StructArrayInterface implementation. */
    std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) override;
    
    /** Traces funcInt and forwards call to StructArrayInterface implementation. */
    StructBool funcInt(const std::list<StructInt>& paramInt) override;
    /** Traces funcInt and forwards call to StructArrayInterface implementation. */
    std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) override;
    
    /** Traces funcFloat and forwards call to StructArrayInterface implementation. */
    StructBool funcFloat(const std::list<StructFloat>& paramFloat) override;
    /** Traces funcFloat and forwards call to StructArrayInterface implementation. */
    std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) override;
    
    /** Traces funcString and forwards call to StructArrayInterface implementation. */
    StructBool funcString(const std::list<StructString>& paramString) override;
    /** Traces funcString and forwards call to StructArrayInterface implementation. */
    std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) override;
    
    /** Traces set PropBool and forwards call to StructArrayInterface implementation. */
    void setPropBool(const std::list<StructBool>& propBool) override;
    /** Forwards call to StructArrayInterface implementation. */
    const std::list<StructBool>& propBool() const override;
    
    /** Traces set PropInt and forwards call to StructArrayInterface implementation. */
    void setPropInt(const std::list<StructInt>& propInt) override;
    /** Forwards call to StructArrayInterface implementation. */
    const std::list<StructInt>& propInt() const override;
    
    /** Traces set PropFloat and forwards call to StructArrayInterface implementation. */
    void setPropFloat(const std::list<StructFloat>& propFloat) override;
    /** Forwards call to StructArrayInterface implementation. */
    const std::list<StructFloat>& propFloat() const override;
    
    /** Traces set PropString and forwards call to StructArrayInterface implementation. */
    void setPropString(const std::list<StructString>& propString) override;
    /** Forwards call to StructArrayInterface implementation. */
    const std::list<StructString>& propString() const override;
    
    /**
    * Access to a publisher, use it to subscribe for StructArrayInterface changes and signal emission.
    * @return The publisher for StructArrayInterface.
    */
    IStructArrayInterfacePublisher& _getPublisher() const override;
private:
    /** Subscription token for sigBool callback */
    long m_sigBoolSubscriptionToken;
    /** Subscription token for sigInt callback */
    long m_sigIntSubscriptionToken;
    /** Subscription token for sigFloat callback */
    long m_sigFloatSubscriptionToken;
    /** Subscription token for sigString callback */
    long m_sigStringSubscriptionToken;

    /** A tracer that provides the traces for given StructArrayInterface object. */
    std::unique_ptr<StructArrayInterfaceTracer> m_tracer;
    /** The StructArrayInterface object which is traced */
    IStructArrayInterface& m_impl;
};
} // namespace Testbed1
} // namespace Test

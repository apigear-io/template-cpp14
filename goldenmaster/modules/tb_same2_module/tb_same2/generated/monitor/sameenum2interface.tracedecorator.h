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
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame2 {

class SameEnum2InterfaceTracer;

class TEST_TB_SAME2_EXPORT SameEnum2InterfaceTraceDecorator : public ISameEnum2Interface
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The SameEnum2Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit SameEnum2InterfaceTraceDecorator(ISameEnum2Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the SameEnum2InterfaceTraceDecorator object.
    * @param impl The SameEnum2Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<SameEnum2InterfaceTraceDecorator> connect(ISameEnum2Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~SameEnum2InterfaceTraceDecorator();

    /** Traces func1 and forwards call to SameEnum2Interface implementation. */
    Enum1Enum func1(const Enum1Enum& param1) override;
    /** Traces func1 and forwards call to SameEnum2Interface implementation. */
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    
    /** Traces func2 and forwards call to SameEnum2Interface implementation. */
    Enum1Enum func2(const Enum1Enum& param1, const Enum2Enum& param2) override;
    /** Traces func2 and forwards call to SameEnum2Interface implementation. */
    std::future<Enum1Enum> func2Async(const Enum1Enum& param1, const Enum2Enum& param2) override;
    
    /** Traces set Prop1 and forwards call to SameEnum2Interface implementation. */
    void setProp1(const Enum1Enum& prop1) override;
    /** Forwards call to SameEnum2Interface implementation. */
    const Enum1Enum& prop1() const override;
    
    /** Traces set Prop2 and forwards call to SameEnum2Interface implementation. */
    void setProp2(const Enum2Enum& prop2) override;
    /** Forwards call to SameEnum2Interface implementation. */
    const Enum2Enum& prop2() const override;
    
    /**
    * Access to a publisher, use it to subscribe for SameEnum2Interface changes and signal emission.
    * @return The publisher for SameEnum2Interface.
    */
    ISameEnum2InterfacePublisher& _getPublisher() const override;
private:
    /** Subscription token for sig1 callback */
    long m_sig1SubscriptionToken;
    /** Subscription token for sig2 callback */
    long m_sig2SubscriptionToken;

    /** A tracer that provides the traces for given SameEnum2Interface object. */
    std::unique_ptr<SameEnum2InterfaceTracer> m_tracer;
    /** The SameEnum2Interface object which is traced */
    ISameEnum2Interface& m_impl;
};
} // namespace TbSame2
} // namespace Test

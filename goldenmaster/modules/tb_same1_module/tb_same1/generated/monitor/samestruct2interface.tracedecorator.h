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
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

class SameStruct2InterfaceTracer;

class TEST_TB_SAME1_EXPORT SameStruct2InterfaceTraceDecorator : public ISameStruct2Interface
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The SameStruct2Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit SameStruct2InterfaceTraceDecorator(ISameStruct2Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the SameStruct2InterfaceTraceDecorator object.
    * @param impl The SameStruct2Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<SameStruct2InterfaceTraceDecorator> connect(ISameStruct2Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~SameStruct2InterfaceTraceDecorator();

    /** Traces func1 and forwards call to SameStruct2Interface implementation. */
    Struct1 func1(const Struct1& param1) override;
    /** Traces func1 and forwards call to SameStruct2Interface implementation. */
    std::future<Struct1> func1Async(const Struct1& param1) override;
    
    /** Traces func2 and forwards call to SameStruct2Interface implementation. */
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    /** Traces func2 and forwards call to SameStruct2Interface implementation. */
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;
    
    /** Traces set Prop1 and forwards call to SameStruct2Interface implementation. */
    void setProp1(const Struct2& prop1) override;
    /** Forwards call to SameStruct2Interface implementation. */
    const Struct2& prop1() const override;
    
    /** Traces set Prop2 and forwards call to SameStruct2Interface implementation. */
    void setProp2(const Struct2& prop2) override;
    /** Forwards call to SameStruct2Interface implementation. */
    const Struct2& prop2() const override;
    
    /**
    * Access to a publisher, use it to subscribe for SameStruct2Interface changes and signal emission.
    * @return The publisher for SameStruct2Interface.
    */
    ISameStruct2InterfacePublisher& _getPublisher() const override;
private:
    /** Subscription token for sig1 callback */
    long m_sig1SubscriptionToken;
    /** Subscription token for sig2 callback */
    long m_sig2SubscriptionToken;

    /** A tracer that provides the traces for given SameStruct2Interface object. */
    std::unique_ptr<SameStruct2InterfaceTracer> m_tracer;
    /** The SameStruct2Interface object which is traced */
    ISameStruct2Interface& m_impl;
};
} // namespace TbSame1
} // namespace Test

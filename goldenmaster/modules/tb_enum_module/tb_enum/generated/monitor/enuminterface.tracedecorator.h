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
#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbEnum {

class EnumInterfaceTracer;

class TEST_TB_ENUM_EXPORT EnumInterfaceTraceDecorator : public IEnumInterface
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The EnumInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit EnumInterfaceTraceDecorator(IEnumInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the EnumInterfaceTraceDecorator object.
    * @param impl The EnumInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<EnumInterfaceTraceDecorator> connect(IEnumInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~EnumInterfaceTraceDecorator();

    /** Traces func0 and forwards call to EnumInterface implementation. */
    Enum0Enum func0(const Enum0Enum& param0) override;
    /** Traces func0 and forwards call to EnumInterface implementation. */
    std::future<Enum0Enum> func0Async(const Enum0Enum& param0) override;
    
    /** Traces func1 and forwards call to EnumInterface implementation. */
    Enum1Enum func1(const Enum1Enum& param1) override;
    /** Traces func1 and forwards call to EnumInterface implementation. */
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    
    /** Traces func2 and forwards call to EnumInterface implementation. */
    Enum2Enum func2(const Enum2Enum& param2) override;
    /** Traces func2 and forwards call to EnumInterface implementation. */
    std::future<Enum2Enum> func2Async(const Enum2Enum& param2) override;
    
    /** Traces func3 and forwards call to EnumInterface implementation. */
    Enum3Enum func3(const Enum3Enum& param3) override;
    /** Traces func3 and forwards call to EnumInterface implementation. */
    std::future<Enum3Enum> func3Async(const Enum3Enum& param3) override;
    
    /** Traces set Prop0 and forwards call to EnumInterface implementation. */
    void setProp0(const Enum0Enum& prop0) override;
    /** Forwards call to EnumInterface implementation. */
    const Enum0Enum& prop0() const override;
    
    /** Traces set Prop1 and forwards call to EnumInterface implementation. */
    void setProp1(const Enum1Enum& prop1) override;
    /** Forwards call to EnumInterface implementation. */
    const Enum1Enum& prop1() const override;
    
    /** Traces set Prop2 and forwards call to EnumInterface implementation. */
    void setProp2(const Enum2Enum& prop2) override;
    /** Forwards call to EnumInterface implementation. */
    const Enum2Enum& prop2() const override;
    
    /** Traces set Prop3 and forwards call to EnumInterface implementation. */
    void setProp3(const Enum3Enum& prop3) override;
    /** Forwards call to EnumInterface implementation. */
    const Enum3Enum& prop3() const override;
    
    /**
    * Access to a publisher, use it to subscribe for EnumInterface changes and signal emission.
    * @return The publisher for EnumInterface.
    */
    IEnumInterfacePublisher& _getPublisher() const override;
private:
    /** Subscription token for sig0 callback */
    long m_sig0SubscriptionToken;
    /** Subscription token for sig1 callback */
    long m_sig1SubscriptionToken;
    /** Subscription token for sig2 callback */
    long m_sig2SubscriptionToken;
    /** Subscription token for sig3 callback */
    long m_sig3SubscriptionToken;

    /** A tracer that provides the traces for given EnumInterface object. */
    std::unique_ptr<EnumInterfaceTracer> m_tracer;
    /** The EnumInterface object which is traced */
    IEnumInterface& m_impl;
};
} // namespace TbEnum
} // namespace Test

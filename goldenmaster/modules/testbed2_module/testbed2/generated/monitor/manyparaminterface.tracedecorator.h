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
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

class ManyParamInterfaceTracer;

class TEST_TESTBED2_EXPORT ManyParamInterfaceTraceDecorator : public IManyParamInterface
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The ManyParamInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit ManyParamInterfaceTraceDecorator(IManyParamInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the ManyParamInterfaceTraceDecorator object.
    * @param impl The ManyParamInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<ManyParamInterfaceTraceDecorator> connect(IManyParamInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~ManyParamInterfaceTraceDecorator();

    /** Traces func1 and forwards call to ManyParamInterface implementation. */
    int func1(int param1) override;
    /** Traces func1 and forwards call to ManyParamInterface implementation. */
    std::future<int> func1Async(int param1) override;
    
    /** Traces func2 and forwards call to ManyParamInterface implementation. */
    int func2(int param1, int param2) override;
    /** Traces func2 and forwards call to ManyParamInterface implementation. */
    std::future<int> func2Async(int param1, int param2) override;
    
    /** Traces func3 and forwards call to ManyParamInterface implementation. */
    int func3(int param1, int param2, int param3) override;
    /** Traces func3 and forwards call to ManyParamInterface implementation. */
    std::future<int> func3Async(int param1, int param2, int param3) override;
    
    /** Traces func4 and forwards call to ManyParamInterface implementation. */
    int func4(int param1, int param2, int param3, int param4) override;
    /** Traces func4 and forwards call to ManyParamInterface implementation. */
    std::future<int> func4Async(int param1, int param2, int param3, int param4) override;
    
    /** Traces set Prop1 and forwards call to ManyParamInterface implementation. */
    void setProp1(int prop1) override;
    /** Forwards call to ManyParamInterface implementation. */
    int prop1() const override;
    
    /** Traces set Prop2 and forwards call to ManyParamInterface implementation. */
    void setProp2(int prop2) override;
    /** Forwards call to ManyParamInterface implementation. */
    int prop2() const override;
    
    /** Traces set Prop3 and forwards call to ManyParamInterface implementation. */
    void setProp3(int prop3) override;
    /** Forwards call to ManyParamInterface implementation. */
    int prop3() const override;
    
    /** Traces set Prop4 and forwards call to ManyParamInterface implementation. */
    void setProp4(int prop4) override;
    /** Forwards call to ManyParamInterface implementation. */
    int prop4() const override;
    
    /**
    * Access to a publisher, use it to subscribe for ManyParamInterface changes and signal emission.
    * @return The publisher for ManyParamInterface.
    */
    IManyParamInterfacePublisher& _getPublisher() const override;
private:
    /** Subscription token for sig1 callback */
    long m_sig1SubscriptionToken;
    /** Subscription token for sig2 callback */
    long m_sig2SubscriptionToken;
    /** Subscription token for sig3 callback */
    long m_sig3SubscriptionToken;
    /** Subscription token for sig4 callback */
    long m_sig4SubscriptionToken;

    /** A tracer that provides the traces for given ManyParamInterface object. */
    std::unique_ptr<ManyParamInterfaceTracer> m_tracer;
    /** The ManyParamInterface object which is traced */
    IManyParamInterface& m_impl;
};
} // namespace Testbed2
} // namespace Test

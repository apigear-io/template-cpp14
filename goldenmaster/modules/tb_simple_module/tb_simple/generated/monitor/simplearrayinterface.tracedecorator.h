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
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

class SimpleArrayInterfaceTracer;

class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfaceTraceDecorator : public ISimpleArrayInterface
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The SimpleArrayInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit SimpleArrayInterfaceTraceDecorator(ISimpleArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the SimpleArrayInterfaceTraceDecorator object.
    * @param impl The SimpleArrayInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<SimpleArrayInterfaceTraceDecorator> connect(ISimpleArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~SimpleArrayInterfaceTraceDecorator();

    /** Traces funcBool and forwards call to SimpleArrayInterface implementation. */
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    /** Traces funcBool and forwards call to SimpleArrayInterface implementation. */
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;
    
    /** Traces funcInt and forwards call to SimpleArrayInterface implementation. */
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    /** Traces funcInt and forwards call to SimpleArrayInterface implementation. */
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;
    
    /** Traces funcFloat and forwards call to SimpleArrayInterface implementation. */
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    /** Traces funcFloat and forwards call to SimpleArrayInterface implementation. */
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;
    
    /** Traces funcString and forwards call to SimpleArrayInterface implementation. */
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    /** Traces funcString and forwards call to SimpleArrayInterface implementation. */
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;
    
    /** Traces set PropBool and forwards call to SimpleArrayInterface implementation. */
    void setPropbool(const std::list<bool>& propBool) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    const std::list<bool>& propBool() const override;
    
    /** Traces set PropInt and forwards call to SimpleArrayInterface implementation. */
    void setPropint(const std::list<int>& propInt) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    const std::list<int>& propInt() const override;
    
    /** Traces set PropFloat and forwards call to SimpleArrayInterface implementation. */
    void setPropfloat(const std::list<float>& propFloat) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    const std::list<float>& propFloat() const override;
    
    /** Traces set PropString and forwards call to SimpleArrayInterface implementation. */
    void setPropstring(const std::list<std::string>& propString) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    const std::list<std::string>& propString() const override;
    
    /**
    * Access to a publisher, use it to subscribe for SimpleArrayInterface changes and signal emission.
    * @return The publisher for SimpleArrayInterface.
    */
    ISimpleArrayInterfacePublisher& _getPublisher() const override;
private:
    /** Subscription token for sigBool callback */
    long m_sigBoolSubscriptionToken;
    /** Subscription token for sigInt callback */
    long m_sigIntSubscriptionToken;
    /** Subscription token for sigFloat callback */
    long m_sigFloatSubscriptionToken;
    /** Subscription token for sigString callback */
    long m_sigStringSubscriptionToken;

    /** A tracer that provides the traces for given SimpleArrayInterface object. */
    std::unique_ptr<SimpleArrayInterfaceTracer> m_tracer;
    /** The SimpleArrayInterface object which is traced */
    ISimpleArrayInterface& m_impl;
};
} // namespace TbSimple
} // namespace Test

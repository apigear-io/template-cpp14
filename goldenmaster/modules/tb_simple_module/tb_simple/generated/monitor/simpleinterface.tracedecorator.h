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

class SimpleInterfaceTracer;

class TEST_TB_SIMPLE_EXPORT SimpleInterfaceTraceDecorator : public ISimpleInterface, public ISimpleInterfaceSubscriber
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The SimpleInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit SimpleInterfaceTraceDecorator(ISimpleInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the SimpleInterfaceTraceDecorator object.
    * @param impl The SimpleInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<SimpleInterfaceTraceDecorator> connect(ISimpleInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~SimpleInterfaceTraceDecorator();

    /** Traces funcBool and forwards call to SimpleInterface implementation. */
    bool funcBool(bool paramBool) override;
    /** Traces funcBool and forwards call to SimpleInterface implementation. */
    std::future<bool> funcBoolAsync(bool paramBool) override;
    
    /** Traces funcInt and forwards call to SimpleInterface implementation. */
    int funcInt(int paramInt) override;
    /** Traces funcInt and forwards call to SimpleInterface implementation. */
    std::future<int> funcIntAsync(int paramInt) override;
    
    /** Traces funcFloat and forwards call to SimpleInterface implementation. */
    float funcFloat(float paramFloat) override;
    /** Traces funcFloat and forwards call to SimpleInterface implementation. */
    std::future<float> funcFloatAsync(float paramFloat) override;
    
    /** Traces funcString and forwards call to SimpleInterface implementation. */
    std::string funcString(const std::string& paramString) override;
    /** Traces funcString and forwards call to SimpleInterface implementation. */
    std::future<std::string> funcStringAsync(const std::string& paramString) override;
    
    /** Forwards call to SimpleInterface implementation. */
    void setPropBool(bool propBool) override;
    /** Forwards call to SimpleInterface implementation. */
    bool propBool() const override;
    
    /** Forwards call to SimpleInterface implementation. */
    void setPropInt(int propInt) override;
    /** Forwards call to SimpleInterface implementation. */
    int propInt() const override;
    
    /** Forwards call to SimpleInterface implementation. */
    void setPropFloat(float propFloat) override;
    /** Forwards call to SimpleInterface implementation. */
    float propFloat() const override;
    
    /** Forwards call to SimpleInterface implementation. */
    void setPropString(const std::string& propString) override;
    /** Forwards call to SimpleInterface implementation. */
    std::string propString() const override;
    
    /**
    Traces sigBool emission.
    */
    void onSigBool(bool paramBool) override;
    /**
    Traces sigInt emission.
    */
    void onSigInt(int paramInt) override;
    /**
    Traces sigFloat emission.
    */
    void onSigFloat(float paramFloat) override;
    /**
    Traces sigString emission.
    */
    void onSigString(const std::string& paramString) override;
    /**
    Traces propBool changed.
    */
    void onPropBoolChanged(bool propBool) override;
    /**
    Traces propInt changed.
    */
    void onPropIntChanged(int propInt) override;
    /**
    Traces propFloat changed.
    */
    void onPropFloatChanged(float propFloat) override;
    /**
    Traces propString changed.
    */
    void onPropStringChanged(std::string propString) override;

    /**
    * Access to a publisher, use it to subscribe for SimpleInterface changes and signal emission.
    * @return The publisher for SimpleInterface.
    */
    ISimpleInterfacePublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given SimpleInterface object. */
    std::unique_ptr<SimpleInterfaceTracer> m_tracer;
    /** The SimpleInterface object which is traced */
    ISimpleInterface& m_impl;
};
} // namespace TbSimple
} // namespace Test

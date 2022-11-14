
#pragma once
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

class SimpleArrayInterfaceTracer;

class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfaceTraceDecorator : public ISimpleArrayInterface, public ISimpleArrayInterfaceSubscriber
{
protected:
    /** 
    * ctor
    * Subscribes for signal emission.
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
    * Unsubscribes from signal emission.
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
    
    /** Forwards call to SimpleArrayInterface implementation. */
    void setPropBool(const std::list<bool>& propBool) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    const std::list<bool>& getPropBool() const override;
    
    /** Forwards call to SimpleArrayInterface implementation. */
    void setPropInt(const std::list<int>& propInt) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    const std::list<int>& getPropInt() const override;
    
    /** Forwards call to SimpleArrayInterface implementation. */
    void setPropFloat(const std::list<float>& propFloat) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    const std::list<float>& getPropFloat() const override;
    
    /** Forwards call to SimpleArrayInterface implementation. */
    void setPropString(const std::list<std::string>& propString) override;
    /** Forwards call to SimpleArrayInterface implementation. */
    const std::list<std::string>& getPropString() const override;
    
    /**
    Traces sigBool emission.
    */
    void onSigBool(const std::list<bool>& paramBool) override;
    /**
    Traces sigInt emission.
    */
    void onSigInt(const std::list<int>& paramInt) override;
    /**
    Traces sigFloat emission.
    */
    void onSigFloat(const std::list<float>& paramFloat) override;
    /**
    Traces sigString emission.
    */
    void onSigString(const std::list<std::string>& paramString) override;
    /**
    Traces propBool changed.
    */
    void onPropBoolChanged(const std::list<bool>& propBool) override;
    /**
    Traces propInt changed.
    */
    void onPropIntChanged(const std::list<int>& propInt) override;
    /**
    Traces propFloat changed.
    */
    void onPropFloatChanged(const std::list<float>& propFloat) override;
    /**
    Traces propString changed.
    */
    void onPropStringChanged(const std::list<std::string>& propString) override;

    /**
    * Access to a publisher, use it to subscribe for SimpleArrayInterface changes and signal emission.
    * @return The publisher for SimpleArrayInterface.
    */
    ISimpleArrayInterfacePublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given SimpleArrayInterface object. */
    std::unique_ptr<SimpleArrayInterfaceTracer> m_tracer;
    /** The SimpleArrayInterface object which is traced */
    ISimpleArrayInterface& m_impl;
};
} // namespace TbSimple
} // namespace Test

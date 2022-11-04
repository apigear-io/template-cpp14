
#pragma once
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

class SameEnum2InterfaceTracer;

class TEST_TB_SAME1_EXPORT SameEnum2InterfaceTraceDecorator : public ISameEnum2Interface, public ISameEnum2InterfaceSubscriber
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
    
    /** Forwards call to SameEnum2Interface implementation. */
    void setProp1(const Enum1Enum& prop1) override;
    /** Forwards call to SameEnum2Interface implementation. */
    const Enum1Enum& getProp1() const override;
    
    /** Forwards call to SameEnum2Interface implementation. */
    void setProp2(const Enum2Enum& prop2) override;
    /** Forwards call to SameEnum2Interface implementation. */
    const Enum2Enum& getProp2() const override;
    
    /**
    Traces sig1 emission.
    */
    void onSig1(const Enum1Enum& param1) override;
    /**
    Traces sig2 emission.
    */
    void onSig2(const Enum1Enum& param1, const Enum2Enum& param2) override;
    /**
    Traces prop1 changed.
    */
    void onProp1Changed(const Enum1Enum& prop1) override;
    /**
    Traces prop2 changed.
    */
    void onProp2Changed(const Enum2Enum& prop2) override;

    /**
    * Access to a publisher, use it to subscribe for SameEnum2Interface changes and signal emission.
    * @return The publisher for SameEnum2Interface.
    */
    ISameEnum2InterfacePublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given SameEnum2Interface object. */
    std::unique_ptr<SameEnum2InterfaceTracer> m_tracer;
    /** The SameEnum2Interface object which is traced */
    ISameEnum2Interface& m_impl;
};
} // namespace TbSame1
} // namespace Test

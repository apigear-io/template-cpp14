
#pragma once
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "tb_same2/generated/core/sameenum2interface.data.h"
#include <memory>

namespace Test {
namespace TbSame2 {

/**
* The SameEnum2Interface implementation.
*/
class TEST_TB_SAME2_EXPORT SameEnum2Interface : public ISameEnum2Interface
{
public:
    explicit SameEnum2Interface();
    ~SameEnum2Interface();
public:
    void setProp1(const Enum1Enum& prop1) override;
    const Enum1Enum& getProp1() const override;
    
    void setProp2(const Enum2Enum& prop2) override;
    const Enum2Enum& getProp2() const override;
    
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
        
    Enum1Enum func2(const Enum1Enum& param1, const Enum2Enum& param2) override;
    std::future<Enum1Enum> func2Async(const Enum1Enum& param1, const Enum2Enum& param2) override;
        
    /**
    * Access to a publisher, use it to subscribe for SameEnum2Interface changes and signal emission.
    * @return The publisher for SameEnum2Interface.
    */
    ISameEnum2InterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the SameEnum2Interface. */
    std::unique_ptr<ISameEnum2InterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for SameEnum2Interface. */
    SameEnum2InterfaceData m_data;
};
} // namespace TbSame2
} // namespace Test

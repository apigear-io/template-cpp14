
#pragma once
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/core/manyparaminterface.data.h"
#include <memory>

namespace Test {
namespace Testbed2 {

/**
* The ManyParamInterface implementation.
*/
class TEST_TESTBED2_EXPORT ManyParamInterface : public IManyParamInterface
{
public:
    explicit ManyParamInterface();
    ~ManyParamInterface();
public:
    void setProp1(int prop1) override;
    int prop1() const override;
    
    void setProp2(int prop2) override;
    int prop2() const override;
    
    void setProp3(int prop3) override;
    int prop3() const override;
    
    void setProp4(int prop4) override;
    int prop4() const override;
    
    int func1(int param1) override;
    std::future<int> func1Async(int param1) override;
        
    int func2(int param1, int param2) override;
    std::future<int> func2Async(int param1, int param2) override;
        
    int func3(int param1, int param2, int param3) override;
    std::future<int> func3Async(int param1, int param2, int param3) override;
        
    int func4(int param1, int param2, int param3, int param4) override;
    std::future<int> func4Async(int param1, int param2, int param3, int param4) override;
        
    /**
    * Access to a publisher, use it to subscribe for ManyParamInterface changes and signal emission.
    * @return The publisher for ManyParamInterface.
    */
    IManyParamInterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the ManyParamInterface. */
    std::unique_ptr<IManyParamInterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for ManyParamInterface. */
    ManyParamInterfaceData m_data;
};
} // namespace Testbed2
} // namespace Test

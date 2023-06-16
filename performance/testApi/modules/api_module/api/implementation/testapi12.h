
#pragma once
#include "api/generated/api/api.h"
#include "api/generated/api/common.h"
#include "api/generated/core/testapi12.data.h"
#include <memory>

namespace Test {
namespace Api {

/**
* The TestApi12 implementation.
*/
class TEST_API_EXPORT TestApi12 : public ITestApi12
{
public:
    explicit TestApi12();
    ~TestApi12();
public:
    void setPropInt(int propInt) override;
    int getPropInt() const override;
    
    void setPropFloat(float propFloat) override;
    float getPropFloat() const override;
    
    void setPropString(const std::string& propString) override;
    const std::string& getPropString() const override;
    
    int funcInt(int paramInt) override;
    std::future<int> funcIntAsync(int paramInt) override;
        
    float funcFloat(float paramFloat) override;
    std::future<float> funcFloatAsync(float paramFloat) override;
        
    std::string funcString(const std::string& paramString) override;
    std::future<std::string> funcStringAsync(const std::string& paramString) override;
        
    /**
    * Access to a publisher, use it to subscribe for TestApi12 changes and signal emission.
    * @return The publisher for TestApi12.
    */
    ITestApi12Publisher& _getPublisher() const override;
private:
    /** The publisher for the TestApi12. */
    std::unique_ptr<ITestApi12Publisher> m_publisher;
    /** The helper structure to store all the properties for TestApi12. */
    TestApi12Data m_data;
};
} // namespace Api
} // namespace Test

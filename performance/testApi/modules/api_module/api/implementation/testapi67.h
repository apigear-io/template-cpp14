
#pragma once
#include "api/generated/api/api.h"
#include "api/generated/api/common.h"
#include "api/generated/core/testapi67.data.h"
#include <memory>

namespace Test {
namespace Api {

/**
* The TestApi67 implementation.
*/
class TEST_API_EXPORT TestApi67 : public ITestApi67
{
public:
    explicit TestApi67();
    ~TestApi67();
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
    * Access to a publisher, use it to subscribe for TestApi67 changes and signal emission.
    * @return The publisher for TestApi67.
    */
    ITestApi67Publisher& _getPublisher() const override;
private:
    /** The publisher for the TestApi67. */
    std::unique_ptr<ITestApi67Publisher> m_publisher;
    /** The helper structure to store all the properties for TestApi67. */
    TestApi67Data m_data;
};
} // namespace Api
} // namespace Test

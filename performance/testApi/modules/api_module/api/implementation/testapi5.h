
#pragma once
#include "api/generated/api/api.h"
#include "api/generated/api/common.h"
#include "api/generated/core/testapi5.data.h"
#include <memory>

namespace Test {
namespace Api {

/**
* The TestApi5 implementation.
*/
class TEST_API_EXPORT TestApi5 : public ITestApi5
{
public:
    explicit TestApi5();
    ~TestApi5();
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
    * Access to a publisher, use it to subscribe for TestApi5 changes and signal emission.
    * @return The publisher for TestApi5.
    */
    ITestApi5Publisher& _getPublisher() const override;
private:
    /** The publisher for the TestApi5. */
    std::unique_ptr<ITestApi5Publisher> m_publisher;
    /** The helper structure to store all the properties for TestApi5. */
    TestApi5Data m_data;
};
} // namespace Api
} // namespace Test

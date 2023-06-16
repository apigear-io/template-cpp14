
#pragma once
#include "api/generated/api/api.h"
#include "api/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace Api {

/** 
* @brief The TestApi33ThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the TestApi33 interface.
* @see TestApi33
*
\code{.cpp}
using namespace Test::Api;

std::unique_ptr<ITestApi33> testTestApi33 = std::make_unique<TestApi33ThreadSafeDecorator>(std::make_shared<TestApi33>());

// Thread safe access
auto propInt = testTestApi33->getPropInt();
testTestApi33->setPropInt(0);
auto propFloat = testTestApi33->getPropFloat();
testTestApi33->setPropFloat(0.0f);
auto propString = testTestApi33->getPropString();
testTestApi33->setPropString(std::string());
\endcode
*/
class TEST_API_EXPORT TestApi33ThreadSafeDecorator : public ITestApi33
{
public:
    /** 
    * ctor
    * @param impl The TestApi33 object to make thread safe.
    */
    explicit TestApi33ThreadSafeDecorator(std::shared_ptr<ITestApi33> impl);

    /** 
    * Forwards call to TestApi33 implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    int funcInt(int paramInt) override;
    /** 
    * Forwards call to TestApi33 implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<int> funcIntAsync(int paramInt) override;

    /** 
    * Forwards call to TestApi33 implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    float funcFloat(float paramFloat) override;
    /** 
    * Forwards call to TestApi33 implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<float> funcFloatAsync(float paramFloat) override;

    /** 
    * Forwards call to TestApi33 implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::string funcString(const std::string& paramString) override;
    /** 
    * Forwards call to TestApi33 implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<std::string> funcStringAsync(const std::string& paramString) override;

    /** Guards and forwards call to TestApi33 implementation. */
    void setPropInt(int propInt) override;
    /** Guards and forwards call to TestApi33 implementation. */
    int getPropInt() const override;

    /** Guards and forwards call to TestApi33 implementation. */
    void setPropFloat(float propFloat) override;
    /** Guards and forwards call to TestApi33 implementation. */
    float getPropFloat() const override;

    /** Guards and forwards call to TestApi33 implementation. */
    void setPropString(const std::string& propString) override;
    /** Guards and forwards call to TestApi33 implementation. */
    const std::string& getPropString() const override;

    /**
    * Access to a publisher, use it to subscribe for TestApi33 changes and signal emission.
    * This call is thread safe.
    * @return The publisher for TestApi33.
    */
    ITestApi33Publisher& _getPublisher() const override;
private:
    /** The TestApi33 object which is guarded */
    std::shared_ptr<ITestApi33> m_impl;
    // Mutex for propInt property
    mutable std::shared_timed_mutex m_propIntMutex;
    // Mutex for propFloat property
    mutable std::shared_timed_mutex m_propFloatMutex;
    // Mutex for propString property
    mutable std::shared_timed_mutex m_propStringMutex;
};
} // namespace Api
} // namespace Test

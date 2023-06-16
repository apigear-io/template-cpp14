

#include "api/generated/core/testapi2.threadsafedecorator.h"

using namespace Test::Api;
TestApi2ThreadSafeDecorator::TestApi2ThreadSafeDecorator(std::shared_ptr<ITestApi2> impl)
    : m_impl(impl)
{
}
int TestApi2ThreadSafeDecorator::funcInt(int paramInt)
{
    return m_impl->funcInt(paramInt);
}

std::future<int> TestApi2ThreadSafeDecorator::funcIntAsync(int paramInt)
{
    return m_impl->funcIntAsync(paramInt);
}
float TestApi2ThreadSafeDecorator::funcFloat(float paramFloat)
{
    return m_impl->funcFloat(paramFloat);
}

std::future<float> TestApi2ThreadSafeDecorator::funcFloatAsync(float paramFloat)
{
    return m_impl->funcFloatAsync(paramFloat);
}
std::string TestApi2ThreadSafeDecorator::funcString(const std::string& paramString)
{
    return m_impl->funcString(paramString);
}

std::future<std::string> TestApi2ThreadSafeDecorator::funcStringAsync(const std::string& paramString)
{
    return m_impl->funcStringAsync(paramString);
}
void TestApi2ThreadSafeDecorator::setPropInt(int propInt)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntMutex);
    m_impl->setPropInt(propInt);
}

int TestApi2ThreadSafeDecorator::getPropInt() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propIntMutex);
    return m_impl->getPropInt();
}
void TestApi2ThreadSafeDecorator::setPropFloat(float propFloat)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propFloatMutex);
    m_impl->setPropFloat(propFloat);
}

float TestApi2ThreadSafeDecorator::getPropFloat() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propFloatMutex);
    return m_impl->getPropFloat();
}
void TestApi2ThreadSafeDecorator::setPropString(const std::string& propString)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propStringMutex);
    m_impl->setPropString(propString);
}

const std::string& TestApi2ThreadSafeDecorator::getPropString() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propStringMutex);
    return m_impl->getPropString();
}

ITestApi2Publisher& TestApi2ThreadSafeDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
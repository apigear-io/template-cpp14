
#pragma once
#include "tb_names/generated/api/tb_names.h"
#include "tb_names/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace TbNames {

/** 
* @brief The NamEsThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the Nam_Es interface.
* @see Nam_Es
*
\code{.cpp}
using namespace Test::TbNames;

std::unique_ptr<INamEs> testNamEs = std::make_unique<NamEsThreadSafeDecorator>(std::make_shared<NamEs>());

// Thread safe access
auto switch = testNamEs->getSwitch();
testNamEs->setSwitch(false);
auto someProperty = testNamEs->getSomeProperty();
testNamEs->setSomeProperty(0);
auto somePoperty2 = testNamEs->getSomePoperty2();
testNamEs->setSomePoperty2(0);
\endcode
*/
class TEST_TB_NAMES_EXPORT NamEsThreadSafeDecorator : public INamEs
{
public:
    /** 
    * ctor
    * @param impl The Nam_Es object to make thread safe.
    */
    explicit NamEsThreadSafeDecorator(std::shared_ptr<INamEs> impl);

    /** 
    * Forwards call to Nam_Es implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    void sOME_FUNCTION(bool SOME_PARAM) override;
    /** 
    * Forwards call to Nam_Es implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<void> sOME_FUNCTIONAsync(bool SOME_PARAM) override;

    /** 
    * Forwards call to Nam_Es implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    void some_Function2(bool Some_Param) override;
    /** 
    * Forwards call to Nam_Es implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<void> some_Function2Async(bool Some_Param) override;

    /** Guards and forwards call to Nam_Es implementation. */
    void setSwitch(bool Switch) override;
    /** Guards and forwards call to Nam_Es implementation. */
    bool getSwitch() const override;

    /** Guards and forwards call to Nam_Es implementation. */
    void setSomeProperty(int SOME_PROPERTY) override;
    /** Guards and forwards call to Nam_Es implementation. */
    int getSomeProperty() const override;

    /** Guards and forwards call to Nam_Es implementation. */
    void setSomePoperty2(int Some_Poperty2) override;
    /** Guards and forwards call to Nam_Es implementation. */
    int getSomePoperty2() const override;

    /**
    * Access to a publisher, use it to subscribe for Nam_Es changes and signal emission.
    * This call is thread safe.
    * @return The publisher for Nam_Es.
    */
    INamEsPublisher& _getPublisher() const override;
private:
    /** The Nam_Es object which is guarded */
    std::shared_ptr<INamEs> m_impl;
    // Mutex for switch property
    mutable std::shared_timed_mutex m_switchMutex;
    // Mutex for someProperty property
    mutable std::shared_timed_mutex m_somePropertyMutex;
    // Mutex for somePoperty2 property
    mutable std::shared_timed_mutex m_somePoperty2Mutex;
};
} // namespace TbNames
} // namespace Test

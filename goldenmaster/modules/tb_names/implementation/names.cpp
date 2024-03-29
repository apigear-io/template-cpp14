

#include "tb_names/implementation/names.h"
#include "tb_names/generated/core/names.publisher.h"
#include "tb_names/generated/core/names.data.h"

using namespace Test::TbNames;

NamEs::NamEs()
    : m_publisher(std::make_unique<NamEsPublisher>())
{
}
NamEs::~NamEs()
{
}

void NamEs::setSwitch(bool Switch)
{
    if (m_data.m_Switch != Switch) {
        m_data.m_Switch = Switch;
        m_publisher->publishSwitchChanged(Switch);
    }
}

bool NamEs::getSwitch() const
{
    return m_data.m_Switch;
}

void NamEs::setSomeProperty(int SOME_PROPERTY)
{
    if (m_data.m_SOME_PROPERTY != SOME_PROPERTY) {
        m_data.m_SOME_PROPERTY = SOME_PROPERTY;
        m_publisher->publishSomePropertyChanged(SOME_PROPERTY);
    }
}

int NamEs::getSomeProperty() const
{
    return m_data.m_SOME_PROPERTY;
}

void NamEs::setSomePoperty2(int Some_Poperty2)
{
    if (m_data.m_Some_Poperty2 != Some_Poperty2) {
        m_data.m_Some_Poperty2 = Some_Poperty2;
        m_publisher->publishSomePoperty2Changed(Some_Poperty2);
    }
}

int NamEs::getSomePoperty2() const
{
    return m_data.m_Some_Poperty2;
}

void NamEs::sOME_FUNCTION(bool SOME_PARAM)
{
    (void) SOME_PARAM; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
}

std::future<void> NamEs::sOME_FUNCTIONAsync(bool SOME_PARAM)
{
    return std::async(std::launch::async, [this,
                    SOME_PARAM]()
        {
            return sOME_FUNCTION(SOME_PARAM);
        }
    );
}

void NamEs::some_Function2(bool Some_Param)
{
    (void) Some_Param; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
}

std::future<void> NamEs::some_Function2Async(bool Some_Param)
{
    return std::async(std::launch::async, [this,
                    Some_Param]()
        {
            return some_Function2(Some_Param);
        }
    );
}

INamEsPublisher& NamEs::_getPublisher() const
{
    return *m_publisher;
}



#include "tb_simple/generated/core/nooperationsinterface.threadsafedecorator.h"

using namespace Test::TbSimple;
NoOperationsInterfaceThreadSafeDecorator::NoOperationsInterfaceThreadSafeDecorator(std::shared_ptr<INoOperationsInterface> impl)
    : m_impl(impl)
{
}
void NoOperationsInterfaceThreadSafeDecorator::setPropBool(bool propBool)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propBoolMutex);
    m_impl->setPropBool(propBool);
}

bool NoOperationsInterfaceThreadSafeDecorator::getPropBool() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propBoolMutex);
    return m_impl->getPropBool();
}
void NoOperationsInterfaceThreadSafeDecorator::setPropInt(int propInt)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntMutex);
    m_impl->setPropInt(propInt);
}

int NoOperationsInterfaceThreadSafeDecorator::getPropInt() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propIntMutex);
    return m_impl->getPropInt();
}

INoOperationsInterfacePublisher& NoOperationsInterfaceThreadSafeDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
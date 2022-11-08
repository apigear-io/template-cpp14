

#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/generated/core/manyparaminterface.publisher.h"
#include "testbed2/generated/core/manyparaminterface.data.h"

using namespace Goldenmaster::Testbed2;

ManyParamInterface::ManyParamInterface()
    : m_publisher(std::make_unique<ManyParamInterfacePublisher>())
{
}
ManyParamInterface::~ManyParamInterface()
{
}

void ManyParamInterface::setProp1(int prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

int ManyParamInterface::getProp1() const
{
    return m_data.m_prop1;
}

void ManyParamInterface::setProp2(int prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

int ManyParamInterface::getProp2() const
{
    return m_data.m_prop2;
}

void ManyParamInterface::setProp3(int prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

int ManyParamInterface::getProp3() const
{
    return m_data.m_prop3;
}

void ManyParamInterface::setProp4(int prop4)
{
    if (m_data.m_prop4 != prop4) {
        m_data.m_prop4 = prop4;
        m_publisher->publishProp4Changed(prop4);
    }
}

int ManyParamInterface::getProp4() const
{
    return m_data.m_prop4;
}

int ManyParamInterface::func1(int param1)
{
    (void) param1; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<int> ManyParamInterface::func1Async(int param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

int ManyParamInterface::func2(int param1, int param2)
{
    (void) param1; // suppress the 'Unreferenced Formal Parameter' warning.
    (void) param2; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<int> ManyParamInterface::func2Async(int param1, int param2)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            return func2(param1, param2);
        }
    );
}

int ManyParamInterface::func3(int param1, int param2, int param3)
{
    (void) param1; // suppress the 'Unreferenced Formal Parameter' warning.
    (void) param2; // suppress the 'Unreferenced Formal Parameter' warning.
    (void) param3; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<int> ManyParamInterface::func3Async(int param1, int param2, int param3)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            return func3(param1, param2, param3);
        }
    );
}

int ManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    (void) param1; // suppress the 'Unreferenced Formal Parameter' warning.
    (void) param2; // suppress the 'Unreferenced Formal Parameter' warning.
    (void) param3; // suppress the 'Unreferenced Formal Parameter' warning.
    (void) param4; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<int> ManyParamInterface::func4Async(int param1, int param2, int param3, int param4)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3,
                    param4]()
        {
            return func4(param1, param2, param3, param4);
        }
    );
}

IManyParamInterfacePublisher& ManyParamInterface::_getPublisher() const
{
    return *m_publisher;
}

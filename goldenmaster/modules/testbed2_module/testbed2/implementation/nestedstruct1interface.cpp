

#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/generated/core/nestedstruct1interface.publisher.h"
#include "testbed2/generated/core/nestedstruct1interface.data.h"

using namespace Goldenmaster::Testbed2;

NestedStruct1Interface::NestedStruct1Interface()
    : m_publisher(std::make_unique<NestedStruct1InterfacePublisher>())
{
}
NestedStruct1Interface::~NestedStruct1Interface()
{
}

void NestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct1Interface::getProp1() const
{
    return m_data.m_prop1;
}

NestedStruct1 NestedStruct1Interface::func1(const NestedStruct1& param1)
{
    (void) param1; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<NestedStruct1> NestedStruct1Interface::func1Async(const NestedStruct1& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

INestedStruct1InterfacePublisher& NestedStruct1Interface::_getPublisher() const
{
    return *m_publisher;
}

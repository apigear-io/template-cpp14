/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/generated/core/nestedstruct3interface.publisher.h"

using namespace Test::Testbed2;

struct NestedStruct3Interface::NestedStruct3InterfaceData
{
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;
    NestedStruct3 m_prop3;
};

NestedStruct3Interface::NestedStruct3Interface()
    : m_publisher(std::make_unique<NestedStruct3InterfacePublisher>()),
      m_data(std::make_unique<NestedStruct3Interface::NestedStruct3InterfaceData>())
{
}
NestedStruct3Interface::~NestedStruct3Interface()
{
}

void NestedStruct3Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_data->m_prop1 != prop1) {
        m_data->m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct3Interface::prop1() const
{
    return m_data->m_prop1;
}

void NestedStruct3Interface::setProp2(const NestedStruct2& prop2)
{
    if (m_data->m_prop2 != prop2) {
        m_data->m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& NestedStruct3Interface::prop2() const
{
    return m_data->m_prop2;
}

void NestedStruct3Interface::setProp3(const NestedStruct3& prop3)
{
    if (m_data->m_prop3 != prop3) {
        m_data->m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

const NestedStruct3& NestedStruct3Interface::prop3() const
{
    return m_data->m_prop3;
}

NestedStruct1 NestedStruct3Interface::func1(const NestedStruct1& param1)
{
    (void) param1; //suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<NestedStruct1> NestedStruct3Interface::func1Async(const NestedStruct1& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

NestedStruct1 NestedStruct3Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    (void) param1; //suppress the 'Unreferenced Formal Parameter' warning.
    (void) param2; //suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<NestedStruct1> NestedStruct3Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            return func2(param1,param2);
        }
    );
}

NestedStruct1 NestedStruct3Interface::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    (void) param1; //suppress the 'Unreferenced Formal Parameter' warning.
    (void) param2; //suppress the 'Unreferenced Formal Parameter' warning.
    (void) param3; //suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<NestedStruct1> NestedStruct3Interface::func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            return func3(param1,param2,param3);
        }
    );
}

INestedStruct3InterfacePublisher& NestedStruct3Interface::_getPublisher() const
{
    return *m_publisher;
}

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


#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/generated/core/samestruct2interface.publisher.h"

using namespace Test::TbSame1;

struct SameStruct2Interface::SameStruct2InterfaceData
{
    Struct2 m_prop1;
    Struct2 m_prop2;
};

SameStruct2Interface::SameStruct2Interface()
    : m_publisher(std::make_unique<SameStruct2InterfacePublisher>()),
      m_data(std::make_unique<SameStruct2Interface::SameStruct2InterfaceData>())
{
}
SameStruct2Interface::~SameStruct2Interface()
{
}

void SameStruct2Interface::setProp1(const Struct2& prop1)
{
    if (m_data->m_prop1 != prop1) {
        m_data->m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct2& SameStruct2Interface::prop1() const
{
    return m_data->m_prop1;
}

void SameStruct2Interface::setProp2(const Struct2& prop2)
{
    if (m_data->m_prop2 != prop2) {
        m_data->m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Struct2& SameStruct2Interface::prop2() const
{
    return m_data->m_prop2;
}

Struct1 SameStruct2Interface::func1(const Struct1& param1)
{
    (void) param1; //Supress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<Struct1> SameStruct2Interface::func1Async(const Struct1& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

Struct1 SameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    (void) param1; //Supress the 'Unreferenced Formal Parameter' warning.
    (void) param2; //Supress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<Struct1> SameStruct2Interface::func2Async(const Struct1& param1, const Struct2& param2)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            return func2(param1,param2);
        }
    );
}

ISameStruct2InterfacePublisher& SameStruct2Interface::_getPublisher() const
{
    return *m_publisher;
}

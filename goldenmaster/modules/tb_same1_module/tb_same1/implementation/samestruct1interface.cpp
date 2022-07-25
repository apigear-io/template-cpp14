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


#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/generated/core/samestruct1interface.publisher.h"

using namespace Test::TbSame1;

struct SameStruct1Interface::SameStruct1InterfaceData
{
    Struct1 m_prop1;
};

SameStruct1Interface::SameStruct1Interface()
    : m_publisher(std::make_unique<SameStruct1InterfacePublisher>()),
      m_data(std::make_unique<SameStruct1Interface::SameStruct1InterfaceData>())
{
}
SameStruct1Interface::~SameStruct1Interface()
{
}

void SameStruct1Interface::setProp1(const Struct1& prop1)
{
    if (m_data->m_prop1 != prop1) {
        m_data->m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct1& SameStruct1Interface::prop1() const
{
    return m_data->m_prop1;
}

Struct1 SameStruct1Interface::func1(const Struct1& param1)
{
    (void) param1; //Supress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<Struct1> SameStruct1Interface::func1Async(const Struct1& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

ISameStruct1InterfacePublisher& SameStruct1Interface::_getPublisher() const
{
    return *m_publisher;
}

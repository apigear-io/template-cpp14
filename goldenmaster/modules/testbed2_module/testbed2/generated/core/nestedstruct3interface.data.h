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
#pragma once

#include "testbed2/generated/api/testbed2.h"


namespace Test
{
namespace Testbed2
{

/**
* A helper structure for implementations of NestedStruct3Interface. Stores all the properties.
*/
struct NestedStruct3InterfaceData
{
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;
    NestedStruct3 m_prop3;
};

}
}
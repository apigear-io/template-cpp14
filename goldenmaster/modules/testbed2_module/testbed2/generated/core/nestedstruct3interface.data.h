#pragma once

#include "testbed2/generated/api/testbed2.h"


namespace Goldenmaster
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
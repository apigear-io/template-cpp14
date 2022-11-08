#pragma once

#include "tb_enum/generated/api/tb_enum.h"


namespace Goldenmaster
{
namespace TbEnum
{

/**
* A helper structure for implementations of EnumInterface. Stores all the properties.
*/
struct EnumInterfaceData
{
    Enum0Enum m_prop0;
    Enum1Enum m_prop1;
    Enum2Enum m_prop2;
    Enum3Enum m_prop3;
};

}
}
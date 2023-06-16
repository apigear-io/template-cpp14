#pragma once

#include "api/generated/api/api.h"


namespace Test
{
namespace Api
{

/**
* A helper structure for implementations of TestApi73. Stores all the properties.
*/
struct TestApi73Data
{
    int m_propInt {0};
    float m_propFloat {0.0f};
    std::string m_propString {std::string()};
};

}
}
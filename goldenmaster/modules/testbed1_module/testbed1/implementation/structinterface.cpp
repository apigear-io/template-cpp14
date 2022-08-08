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


#include "testbed1/implementation/structinterface.h"
#include "testbed1/generated/core/structinterface.publisher.h"

using namespace Test::Testbed1;

struct StructInterface::StructInterfaceData
{
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
};

StructInterface::StructInterface()
    : m_publisher(std::make_unique<StructInterfacePublisher>()),
      m_data(std::make_unique<StructInterface::StructInterfaceData>())
{
}
StructInterface::~StructInterface()
{
}

void StructInterface::setPropbool(const StructBool& propBool)
{
    if (m_data->m_propBool != propBool) {
        m_data->m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const StructBool& StructInterface::propBool() const
{
    return m_data->m_propBool;
}

void StructInterface::setPropint(const StructInt& propInt)
{
    if (m_data->m_propInt != propInt) {
        m_data->m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const StructInt& StructInterface::propInt() const
{
    return m_data->m_propInt;
}

void StructInterface::setPropfloat(const StructFloat& propFloat)
{
    if (m_data->m_propFloat != propFloat) {
        m_data->m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const StructFloat& StructInterface::propFloat() const
{
    return m_data->m_propFloat;
}

void StructInterface::setPropstring(const StructString& propString)
{
    if (m_data->m_propString != propString) {
        m_data->m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const StructString& StructInterface::propString() const
{
    return m_data->m_propString;
}

StructBool StructInterface::funcBool(const StructBool& paramBool)
{
    (void) paramBool; //Supress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<StructBool> StructInterface::funcBoolAsync(const StructBool& paramBool)
{
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            return funcBool(paramBool);
        }
    );
}

StructBool StructInterface::funcInt(const StructInt& paramInt)
{
    (void) paramInt; //Supress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<StructBool> StructInterface::funcIntAsync(const StructInt& paramInt)
{
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            return funcInt(paramInt);
        }
    );
}

StructFloat StructInterface::funcFloat(const StructFloat& paramFloat)
{
    (void) paramFloat; //Supress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<StructFloat> StructInterface::funcFloatAsync(const StructFloat& paramFloat)
{
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            return funcFloat(paramFloat);
        }
    );
}

StructString StructInterface::funcString(const StructString& paramString)
{
    (void) paramString; //Supress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<StructString> StructInterface::funcStringAsync(const StructString& paramString)
{
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            return funcString(paramString);
        }
    );
}

IStructInterfacePublisher& StructInterface::_getPublisher() const
{
    return *m_publisher;
}

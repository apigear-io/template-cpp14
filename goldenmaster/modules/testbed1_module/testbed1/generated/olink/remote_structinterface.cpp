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



#include "testbed1/generated/olink/remote_structinterface.h"
#include "testbed1/generated/core/structinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;

RemoteStructInterface::RemoteStructInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    :
    m_propBool(StructBool()),
    m_propInt(StructInt()),
    m_propFloat(StructFloat()),
    m_propString(StructString()),
    m_registry(registry),
    m_publisher(std::make_unique<StructInterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("testbed1.StructInterface");
}

RemoteStructInterface::~RemoteStructInterface()
{
    m_registry.removeObjectSink(this);
}

void RemoteStructInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropboolLocal(fields["propBool"].get<StructBool>());
    }
    if(fields.contains("propInt")) {
        setPropintLocal(fields["propInt"].get<StructInt>());
    }
    if(fields.contains("propFloat")) {
        setPropfloatLocal(fields["propFloat"].get<StructFloat>());
    }
    if(fields.contains("propString")) {
        setPropstringLocal(fields["propString"].get<StructString>());
    }
}

void RemoteStructInterface::setPropbool(const StructBool& propBool)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propBool", propBool);
}

void RemoteStructInterface::setPropboolLocal(const StructBool& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const StructBool& RemoteStructInterface::propBool() const
{
    return m_propBool;
}

void RemoteStructInterface::setPropint(const StructInt& propInt)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propInt", propInt);
}

void RemoteStructInterface::setPropintLocal(const StructInt& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const StructInt& RemoteStructInterface::propInt() const
{
    return m_propInt;
}

void RemoteStructInterface::setPropfloat(const StructFloat& propFloat)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propFloat", propFloat);
}

void RemoteStructInterface::setPropfloatLocal(const StructFloat& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const StructFloat& RemoteStructInterface::propFloat() const
{
    return m_propFloat;
}

void RemoteStructInterface::setPropstring(const StructString& propString)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propString", propString);
}

void RemoteStructInterface::setPropstringLocal(const StructString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const StructString& RemoteStructInterface::propString() const
{
    return m_propString;
}

StructBool RemoteStructInterface::funcBool(const StructBool& paramBool)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> RemoteStructInterface::funcBoolAsync(const StructBool& paramBool)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructInterface/funcBool",
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool RemoteStructInterface::funcInt(const StructInt& paramInt)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> RemoteStructInterface::funcIntAsync(const StructInt& paramInt)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructInterface/funcInt",
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructFloat RemoteStructInterface::funcFloat(const StructFloat& paramFloat)
{
    if(m_node == nullptr) {
        return StructFloat();
    }
    StructFloat value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructFloat> RemoteStructInterface::funcFloatAsync(const StructFloat& paramFloat)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructFloat> resultPromise;
            m_node->invokeRemote("testbed1.StructInterface/funcFloat",
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructFloat& value = arg.value.get<StructFloat>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructString RemoteStructInterface::funcString(const StructString& paramString)
{
    if(m_node == nullptr) {
        return StructString();
    }
    StructString value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructString> RemoteStructInterface::funcStringAsync(const StructString& paramString)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructString> resultPromise;
            m_node->invokeRemote("testbed1.StructInterface/funcString",
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructString& value = arg.value.get<StructString>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteStructInterface::olinkObjectName()
{
    return "testbed1.StructInterface";
}

void RemoteStructInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sigBool") {
        m_publisher->publishSigBool(args[0].get<StructBool>());   
        return;
    }
    if(path == "sigInt") {
        m_publisher->publishSigInt(args[0].get<StructInt>());   
        return;
    }
    if(path == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<StructFloat>());   
        return;
    }
    if(path == "sigString") {
        m_publisher->publishSigString(args[0].get<StructString>());   
        return;
    }
}

void RemoteStructInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteStructInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteStructInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteStructInterface::isReady() const
{
    return m_node != nullptr;
}

IStructInterfacePublisher& RemoteStructInterface::_getPublisher() const
{
    return *m_publisher;
}

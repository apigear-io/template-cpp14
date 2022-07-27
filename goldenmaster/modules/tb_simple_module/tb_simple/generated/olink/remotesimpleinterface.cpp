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



#include "tb_simple/generated/olink/remotesimpleinterface.h"
#include "tb_simple/generated/core/simpleinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;

RemoteSimpleInterface::RemoteSimpleInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    :
    m_propBool(false),
    m_propInt(0),
    m_propFloat(0.0f),
    m_propString(std::string()),
    m_registry(registry),
    m_publisher(std::make_unique<SimpleInterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("tb.simple.SimpleInterface");
}

RemoteSimpleInterface::~RemoteSimpleInterface()
{
    m_registry.removeObjectSink(this);
}

void RemoteSimpleInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropboolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropintLocal(fields["propInt"].get<int>());
    }
    if(fields.contains("propFloat")) {
        setPropfloatLocal(fields["propFloat"].get<float>());
    }
    if(fields.contains("propString")) {
        setPropstringLocal(fields["propString"].get<std::string>());
    }
}

void RemoteSimpleInterface::setPropbool(bool propBool)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propBool", propBool);
}

void RemoteSimpleInterface::setPropboolLocal(bool propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool RemoteSimpleInterface::propBool() const
{
    return m_propBool;
}

void RemoteSimpleInterface::setPropint(int propInt)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt", propInt);
}

void RemoteSimpleInterface::setPropintLocal(int propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int RemoteSimpleInterface::propInt() const
{
    return m_propInt;
}

void RemoteSimpleInterface::setPropfloat(float propFloat)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat", propFloat);
}

void RemoteSimpleInterface::setPropfloatLocal(float propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

float RemoteSimpleInterface::propFloat() const
{
    return m_propFloat;
}

void RemoteSimpleInterface::setPropstring(const std::string& propString)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propString", propString);
}

void RemoteSimpleInterface::setPropstringLocal(const std::string& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

std::string RemoteSimpleInterface::propString() const
{
    return m_propString;
}

bool RemoteSimpleInterface::funcBool(bool paramBool)
{
    if(m_node == nullptr) {
        return false;
    }
    bool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<bool> RemoteSimpleInterface::funcBoolAsync(bool paramBool)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<bool> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleInterface/funcBool",
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const bool& value = arg.value.get<bool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

int RemoteSimpleInterface::funcInt(int paramInt)
{
    if(m_node == nullptr) {
        return 0;
    }
    int value(funcIntAsync(paramInt).get());
    return value;
}

std::future<int> RemoteSimpleInterface::funcIntAsync(int paramInt)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<int> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleInterface/funcInt",
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

float RemoteSimpleInterface::funcFloat(float paramFloat)
{
    if(m_node == nullptr) {
        return 0.0f;
    }
    float value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<float> RemoteSimpleInterface::funcFloatAsync(float paramFloat)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<float> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleInterface/funcFloat",
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const float& value = arg.value.get<float>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSimpleInterface::funcString(const std::string& paramString)
{
    if(m_node == nullptr) {
        return std::string();
    }
    std::string value(funcStringAsync(paramString).get());
    return value;
}

std::future<std::string> RemoteSimpleInterface::funcStringAsync(const std::string& paramString)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<std::string> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleInterface/funcString",
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::string& value = arg.value.get<std::string>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSimpleInterface::olinkObjectName()
{
    return "tb.simple.SimpleInterface";
}

void RemoteSimpleInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sigBool") {
        m_publisher->publishSigBool(args[0].get<bool>());   
        return;
    }
    if(path == "sigInt") {
        m_publisher->publishSigInt(args[0].get<int>());   
        return;
    }
    if(path == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<float>());   
        return;
    }
    if(path == "sigString") {
        m_publisher->publishSigString(args[0].get<std::string>());   
        return;
    }
}

void RemoteSimpleInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteSimpleInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteSimpleInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSimpleInterface::isReady() const
{
    return m_node != nullptr;
}

ISimpleInterfacePublisher& RemoteSimpleInterface::_getPublisher() const
{
    return *m_publisher;
}



#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/simpleinterfaceservice.adapter.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleInterface";
}

SimpleInterfaceServiceAdapter::SimpleInterfaceServiceAdapter(ISimpleInterface& SimpleInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleInterface(SimpleInterface)
    , m_registry(registry)
{
    m_SimpleInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addSource(*this);
}

SimpleInterfaceServiceAdapter::~SimpleInterfaceServiceAdapter()
{
    m_registry.removeSource(olinkObjectName());
    m_SimpleInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SimpleInterfaceServiceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const bool& paramBool = fcnArgs.at(0);
        bool result = m_SimpleInterface.funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const int& paramInt = fcnArgs.at(0);
        int result = m_SimpleInterface.funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const float& paramFloat = fcnArgs.at(0);
        float result = m_SimpleInterface.funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::string& paramString = fcnArgs.at(0);
        std::string result = m_SimpleInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleInterfaceServiceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        bool propBool = value.get<bool>();
        m_SimpleInterface.setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        int propInt = value.get<int>();
        m_SimpleInterface.setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        float propFloat = value.get<float>();
        m_SimpleInterface.setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        std::string propString = value.get<std::string>();
        m_SimpleInterface.setPropString(propString);
    } 
}

void SimpleInterfaceServiceAdapter::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void SimpleInterfaceServiceAdapter::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json SimpleInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleInterface.getPropBool() },
        { "propInt", m_SimpleInterface.getPropInt() },
        { "propFloat", m_SimpleInterface.getPropFloat() },
        { "propString", m_SimpleInterface.getPropString() }
    });
}
void SimpleInterfaceServiceAdapter::onSigBool(bool paramBool)
{
    const nlohmann::json args = { paramBool };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceServiceAdapter::onSigInt(int paramInt)
{
    const nlohmann::json args = { paramInt };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceServiceAdapter::onSigFloat(float paramFloat)
{
    const nlohmann::json args = { paramFloat };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceServiceAdapter::onSigString(const std::string& paramString)
{
    const nlohmann::json args = { paramString };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceServiceAdapter::onPropBoolChanged(bool propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void SimpleInterfaceServiceAdapter::onPropIntChanged(int propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, propInt);
        }
    }
}
void SimpleInterfaceServiceAdapter::onPropFloatChanged(float propFloat)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, propFloat);
        }
    }
}
void SimpleInterfaceServiceAdapter::onPropStringChanged(std::string propString)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, propString);
        }
    }
}


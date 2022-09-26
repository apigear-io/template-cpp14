

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/simplearrayinterfaceservice.adapter.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleArrayInterface";
}

SimpleArrayInterfaceServiceAdapter::SimpleArrayInterfaceServiceAdapter(ISimpleArrayInterface& SimpleArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleArrayInterface(SimpleArrayInterface)
    , m_registry(registry)
{
    m_SimpleArrayInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addSource(*this);
}

SimpleArrayInterfaceServiceAdapter::~SimpleArrayInterfaceServiceAdapter()
{
    m_registry.removeSource(olinkObjectName());
    m_SimpleArrayInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleArrayInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SimpleArrayInterfaceServiceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const std::list<bool>& paramBool = fcnArgs.at(0);
        std::list<bool> result = m_SimpleArrayInterface.funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const std::list<int>& paramInt = fcnArgs.at(0);
        std::list<int> result = m_SimpleArrayInterface.funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const std::list<float>& paramFloat = fcnArgs.at(0);
        std::list<float> result = m_SimpleArrayInterface.funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::list<std::string>& paramString = fcnArgs.at(0);
        std::list<std::string> result = m_SimpleArrayInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleArrayInterfaceServiceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        std::list<bool> propBool = value.get<std::list<bool>>();
        m_SimpleArrayInterface.setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        std::list<int> propInt = value.get<std::list<int>>();
        m_SimpleArrayInterface.setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        std::list<float> propFloat = value.get<std::list<float>>();
        m_SimpleArrayInterface.setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        std::list<std::string> propString = value.get<std::list<std::string>>();
        m_SimpleArrayInterface.setPropString(propString);
    } 
}

void SimpleArrayInterfaceServiceAdapter::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void SimpleArrayInterfaceServiceAdapter::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json SimpleArrayInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleArrayInterface.getPropBool() },
        { "propInt", m_SimpleArrayInterface.getPropInt() },
        { "propFloat", m_SimpleArrayInterface.getPropFloat() },
        { "propString", m_SimpleArrayInterface.getPropString() }
    });
}
void SimpleArrayInterfaceServiceAdapter::onSigBool(const std::list<bool>& paramBool)
{
    const nlohmann::json args = { paramBool };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigInt(const std::list<int>& paramInt)
{
    const nlohmann::json args = { paramInt };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigFloat(const std::list<float>& paramFloat)
{
    const nlohmann::json args = { paramFloat };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigString(const std::list<std::string>& paramString)
{
    const nlohmann::json args = { paramString };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropBoolChanged(const std::list<bool>& propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropIntChanged(const std::list<int>& propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, propInt);
        }
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropFloatChanged(const std::list<float>& propFloat)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, propFloat);
        }
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropStringChanged(const std::list<std::string>& propString)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, propString);
        }
    }
}


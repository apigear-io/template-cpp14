

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/simpleinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleInterface";
}

SimpleInterfaceService::SimpleInterfaceService(std::shared_ptr<ISimpleInterface> SimpleInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleInterface(SimpleInterface)
    , m_registry(registry)
{
    m_SimpleInterface->_getPublisher().subscribeToAllChanges(*this);
}

SimpleInterfaceService::~SimpleInterfaceService()
{
    m_SimpleInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent SimpleInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("SimpleInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "funcNoReturnValue") {
        bool paramBool{};
        argumentsReader.read(paramBool);
        m_SimpleInterface->funcNoReturnValue(paramBool);
        return {};
    }
    if(memberMethod == "funcBool") {
        bool paramBool{};
        argumentsReader.read(paramBool);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleInterface->funcBool(paramBool));
    }
    if(memberMethod == "funcInt") {
        int paramInt{};
        argumentsReader.read(paramInt);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleInterface->funcInt(paramInt));
    }
    if(memberMethod == "funcInt32") {
        int32_t paramInt32{};
        argumentsReader.read(paramInt32);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleInterface->funcInt32(paramInt32));
    }
    if(memberMethod == "funcInt64") {
        int64_t paramInt64{};
        argumentsReader.read(paramInt64);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleInterface->funcInt64(paramInt64));
    }
    if(memberMethod == "funcFloat") {
        float paramFloat{};
        argumentsReader.read(paramFloat);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleInterface->funcFloat(paramFloat));
    }
    if(memberMethod == "funcFloat32") {
        float paramFloat32{};
        argumentsReader.read(paramFloat32);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleInterface->funcFloat32(paramFloat32));
    }
    if(memberMethod == "funcFloat64") {
        double paramFloat{};
        argumentsReader.read(paramFloat);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleInterface->funcFloat64(paramFloat));
    }
    if(memberMethod == "funcString") {
        std::string paramString{};
        argumentsReader.read(paramString);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleInterface->funcString(paramString));
    }
    return {};
}

void SimpleInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("SimpleInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        bool value_propBool{};
        ApiGear::ObjectLink::readValue(value, value_propBool);
        m_SimpleInterface->setPropBool(value_propBool);
    }
    if(memberProperty == "propInt") {
        int value_propInt{};
        ApiGear::ObjectLink::readValue(value, value_propInt);
        m_SimpleInterface->setPropInt(value_propInt);
    }
    if(memberProperty == "propInt32") {
        int32_t value_propInt32{};
        ApiGear::ObjectLink::readValue(value, value_propInt32);
        m_SimpleInterface->setPropInt32(value_propInt32);
    }
    if(memberProperty == "propInt64") {
        int64_t value_propInt64{};
        ApiGear::ObjectLink::readValue(value, value_propInt64);
        m_SimpleInterface->setPropInt64(value_propInt64);
    }
    if(memberProperty == "propFloat") {
        float value_propFloat{};
        ApiGear::ObjectLink::readValue(value, value_propFloat);
        m_SimpleInterface->setPropFloat(value_propFloat);
    }
    if(memberProperty == "propFloat32") {
        float value_propFloat32{};
        ApiGear::ObjectLink::readValue(value, value_propFloat32);
        m_SimpleInterface->setPropFloat32(value_propFloat32);
    }
    if(memberProperty == "propFloat64") {
        double value_propFloat64{};
        ApiGear::ObjectLink::readValue(value, value_propFloat64);
        m_SimpleInterface->setPropFloat64(value_propFloat64);
    }
    if(memberProperty == "propString") {
        std::string value_propString{};
        ApiGear::ObjectLink::readValue(value, value_propString);
        m_SimpleInterface->setPropString(value_propString);
    } 
}

void SimpleInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("SimpleInterfaceService linked " + objectId);
}

void SimpleInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("SimpleInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent SimpleInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("propBool"), m_SimpleInterface->getPropBool()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt"), m_SimpleInterface->getPropInt()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt32"), m_SimpleInterface->getPropInt32()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt64"), m_SimpleInterface->getPropInt64()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propFloat"), m_SimpleInterface->getPropFloat()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propFloat32"), m_SimpleInterface->getPropFloat32()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propFloat64"), m_SimpleInterface->getPropFloat64()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propString"), m_SimpleInterface->getPropString()) );
}
void SimpleInterfaceService::onSigBool(bool paramBool)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramBool);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceService::onSigInt(int paramInt)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramInt);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceService::onSigInt32(int32_t paramInt32)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramInt32);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt32");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceService::onSigInt64(int64_t paramInt64)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramInt64);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt64");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceService::onSigFloat(float paramFloat)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramFloat);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceService::onSigFloat32(float paramFloa32)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramFloa32);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat32");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceService::onSigFloat64(double paramFloat64)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramFloat64);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat64");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceService::onSigString(const std::string& paramString)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(paramString);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleInterfaceService::onPropBoolChanged(bool propBool)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propBool));
        }
    }
}
void SimpleInterfaceService::onPropIntChanged(int propInt)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propInt));
        }
    }
}
void SimpleInterfaceService::onPropInt32Changed(int32_t propInt32)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt32");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propInt32));
        }
    }
}
void SimpleInterfaceService::onPropInt64Changed(int64_t propInt64)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt64");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propInt64));
        }
    }
}
void SimpleInterfaceService::onPropFloatChanged(float propFloat)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat));
        }
    }
}
void SimpleInterfaceService::onPropFloat32Changed(float propFloat32)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat32");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat32));
        }
    }
}
void SimpleInterfaceService::onPropFloat64Changed(double propFloat64)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat64");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propFloat64));
        }
    }
}
void SimpleInterfaceService::onPropStringChanged(const std::string& propString)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(propString));
        }
    }
}


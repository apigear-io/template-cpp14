

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/simplearrayinterfaceservice.h"
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
const std::string interfaceId = "tb.simple.SimpleArrayInterface";
}

SimpleArrayInterfaceService::SimpleArrayInterfaceService(std::shared_ptr<ISimpleArrayInterface> SimpleArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleArrayInterface(SimpleArrayInterface)
    , m_registry(registry)
{
    m_SimpleArrayInterface->_getPublisher().subscribeToAllChanges(*this);
}

SimpleArrayInterfaceService::~SimpleArrayInterfaceService()
{
    m_SimpleArrayInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleArrayInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent SimpleArrayInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("SimpleArrayInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "funcBool") {
        std::list<bool> paramBool{};
        argumentsReader.read(paramBool);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleArrayInterface->funcBool(paramBool));
    }
    if(memberMethod == "funcInt") {
        std::list<int> paramInt{};
        argumentsReader.read(paramInt);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleArrayInterface->funcInt(paramInt));
    }
    if(memberMethod == "funcInt32") {
        std::list<int32_t> paramInt32{};
        argumentsReader.read(paramInt32);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleArrayInterface->funcInt32(paramInt32));
    }
    if(memberMethod == "funcInt64") {
        std::list<int64_t> paramInt64{};
        argumentsReader.read(paramInt64);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleArrayInterface->funcInt64(paramInt64));
    }
    if(memberMethod == "funcFloat") {
        std::list<float> paramFloat{};
        argumentsReader.read(paramFloat);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleArrayInterface->funcFloat(paramFloat));
    }
    if(memberMethod == "funcFloat32") {
        std::list<float> paramFloat32{};
        argumentsReader.read(paramFloat32);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleArrayInterface->funcFloat32(paramFloat32));
    }
    if(memberMethod == "funcFloat64") {
        std::list<double> paramFloat{};
        argumentsReader.read(paramFloat);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleArrayInterface->funcFloat64(paramFloat));
    }
    if(memberMethod == "funcString") {
        std::list<std::string> paramString{};
        argumentsReader.read(paramString);
        return ApiGear::ObjectLink::invokeReturnValue(m_SimpleArrayInterface->funcString(paramString));
    }
    return {};
}

void SimpleArrayInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("SimpleArrayInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        std::list<bool> value_propBool{};
        ApiGear::ObjectLink::readValue(value, value_propBool);
        m_SimpleArrayInterface->setPropBool(value_propBool);
    }
    if(memberProperty == "propInt") {
        std::list<int> value_propInt{};
        ApiGear::ObjectLink::readValue(value, value_propInt);
        m_SimpleArrayInterface->setPropInt(value_propInt);
    }
    if(memberProperty == "propInt32") {
        std::list<int32_t> value_propInt32{};
        ApiGear::ObjectLink::readValue(value, value_propInt32);
        m_SimpleArrayInterface->setPropInt32(value_propInt32);
    }
    if(memberProperty == "propInt64") {
        std::list<int64_t> value_propInt64{};
        ApiGear::ObjectLink::readValue(value, value_propInt64);
        m_SimpleArrayInterface->setPropInt64(value_propInt64);
    }
    if(memberProperty == "propFloat") {
        std::list<float> value_propFloat{};
        ApiGear::ObjectLink::readValue(value, value_propFloat);
        m_SimpleArrayInterface->setPropFloat(value_propFloat);
    }
    if(memberProperty == "propFloat32") {
        std::list<float> value_propFloat32{};
        ApiGear::ObjectLink::readValue(value, value_propFloat32);
        m_SimpleArrayInterface->setPropFloat32(value_propFloat32);
    }
    if(memberProperty == "propFloat64") {
        std::list<double> value_propFloat64{};
        ApiGear::ObjectLink::readValue(value, value_propFloat64);
        m_SimpleArrayInterface->setPropFloat64(value_propFloat64);
    }
    if(memberProperty == "propString") {
        std::list<std::string> value_propString{};
        ApiGear::ObjectLink::readValue(value, value_propString);
        m_SimpleArrayInterface->setPropString(value_propString);
    } 
}

void SimpleArrayInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("SimpleArrayInterfaceService linked " + objectId);
}

void SimpleArrayInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("SimpleArrayInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent SimpleArrayInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("propBool"), m_SimpleArrayInterface->getPropBool()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt"), m_SimpleArrayInterface->getPropInt()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt32"), m_SimpleArrayInterface->getPropInt32()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt64"), m_SimpleArrayInterface->getPropInt64()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propFloat"), m_SimpleArrayInterface->getPropFloat()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propFloat32"), m_SimpleArrayInterface->getPropFloat32()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propFloat64"), m_SimpleArrayInterface->getPropFloat64()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propString"), m_SimpleArrayInterface->getPropString()) );
}
void SimpleArrayInterfaceService::onSigBool(const std::list<bool>& paramBool)
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
void SimpleArrayInterfaceService::onSigInt(const std::list<int>& paramInt)
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
void SimpleArrayInterfaceService::onSigInt32(const std::list<int32_t>& paramInt32)
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
void SimpleArrayInterfaceService::onSigInt64(const std::list<int64_t>& paramInt64)
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
void SimpleArrayInterfaceService::onSigFloat(const std::list<float>& paramFloat)
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
void SimpleArrayInterfaceService::onSigFloat32(const std::list<float>& paramFloa32)
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
void SimpleArrayInterfaceService::onSigFloat64(const std::list<double>& paramFloat64)
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
void SimpleArrayInterfaceService::onSigString(const std::list<std::string>& paramString)
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
void SimpleArrayInterfaceService::onPropBoolChanged(const std::list<bool>& propBool)
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
void SimpleArrayInterfaceService::onPropIntChanged(const std::list<int>& propInt)
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
void SimpleArrayInterfaceService::onPropInt32Changed(const std::list<int32_t>& propInt32)
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
void SimpleArrayInterfaceService::onPropInt64Changed(const std::list<int64_t>& propInt64)
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
void SimpleArrayInterfaceService::onPropFloatChanged(const std::list<float>& propFloat)
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
void SimpleArrayInterfaceService::onPropFloat32Changed(const std::list<float>& propFloat32)
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
void SimpleArrayInterfaceService::onPropFloat64Changed(const std::list<double>& propFloat64)
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
void SimpleArrayInterfaceService::onPropStringChanged(const std::list<std::string>& propString)
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


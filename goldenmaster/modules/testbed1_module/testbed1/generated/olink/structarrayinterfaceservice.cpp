

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/olink/structarrayinterfaceservice.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructArrayInterface";
}

StructArrayInterfaceService::StructArrayInterfaceService(std::shared_ptr<IStructArrayInterface> StructArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructArrayInterface(StructArrayInterface)
    , m_registry(registry)
{
    m_StructArrayInterface->_getPublisher().subscribeToAllChanges(*this);
}

StructArrayInterfaceService::~StructArrayInterfaceService()
{
    m_StructArrayInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructArrayInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent StructArrayInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("StructArrayInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "funcBool") {
        std::list<StructBool> paramBool{};
        argumentsReader.read(paramBool);
        return ApiGear::ObjectLink::invokeReturnValue(m_StructArrayInterface->funcBool(paramBool));
    }
    if(memberMethod == "funcInt") {
        std::list<StructInt> paramInt{};
        argumentsReader.read(paramInt);
        return ApiGear::ObjectLink::invokeReturnValue(m_StructArrayInterface->funcInt(paramInt));
    }
    if(memberMethod == "funcFloat") {
        std::list<StructFloat> paramFloat{};
        argumentsReader.read(paramFloat);
        return ApiGear::ObjectLink::invokeReturnValue(m_StructArrayInterface->funcFloat(paramFloat));
    }
    if(memberMethod == "funcString") {
        std::list<StructString> paramString{};
        argumentsReader.read(paramString);
        return ApiGear::ObjectLink::invokeReturnValue(m_StructArrayInterface->funcString(paramString));
    }
    return {};
}

void StructArrayInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("StructArrayInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        std::list<StructBool> value_propBool{};
        ApiGear::ObjectLink::readValue(value, value_propBool);
        m_StructArrayInterface->setPropBool(value_propBool);
    }
    if(memberProperty == "propInt") {
        std::list<StructInt> value_propInt{};
        ApiGear::ObjectLink::readValue(value, value_propInt);
        m_StructArrayInterface->setPropInt(value_propInt);
    }
    if(memberProperty == "propFloat") {
        std::list<StructFloat> value_propFloat{};
        ApiGear::ObjectLink::readValue(value, value_propFloat);
        m_StructArrayInterface->setPropFloat(value_propFloat);
    }
    if(memberProperty == "propString") {
        std::list<StructString> value_propString{};
        ApiGear::ObjectLink::readValue(value, value_propString);
        m_StructArrayInterface->setPropString(value_propString);
    } 
}

void StructArrayInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("StructArrayInterfaceService linked " + objectId);
}

void StructArrayInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("StructArrayInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent StructArrayInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("propBool"), m_StructArrayInterface->getPropBool()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt"), m_StructArrayInterface->getPropInt()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propFloat"), m_StructArrayInterface->getPropFloat()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propString"), m_StructArrayInterface->getPropString()) );
}
void StructArrayInterfaceService::onSigBool(const std::list<StructBool>& paramBool)
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
void StructArrayInterfaceService::onSigInt(const std::list<StructInt>& paramInt)
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
void StructArrayInterfaceService::onSigFloat(const std::list<StructFloat>& paramFloat)
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
void StructArrayInterfaceService::onSigString(const std::list<StructString>& paramString)
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
void StructArrayInterfaceService::onPropBoolChanged(const std::list<StructBool>& propBool)
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
void StructArrayInterfaceService::onPropIntChanged(const std::list<StructInt>& propInt)
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
void StructArrayInterfaceService::onPropFloatChanged(const std::list<StructFloat>& propFloat)
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
void StructArrayInterfaceService::onPropStringChanged(const std::list<StructString>& propString)
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


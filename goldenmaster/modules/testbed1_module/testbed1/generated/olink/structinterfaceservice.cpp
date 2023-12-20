

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/olink/structinterfaceservice.h"
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
const std::string interfaceId = "testbed1.StructInterface";
}

StructInterfaceService::StructInterfaceService(std::shared_ptr<IStructInterface> StructInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructInterface(StructInterface)
    , m_registry(registry)
{
    m_StructInterface->_getPublisher().subscribeToAllChanges(*this);
}

StructInterfaceService::~StructInterfaceService()
{
    m_StructInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent StructInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("StructInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "funcBool") {
        StructBool paramBool{};
        argumentsReader.read(paramBool);
        return ApiGear::ObjectLink::invokeReturnValue(m_StructInterface->funcBool(paramBool));
    }
    if(memberMethod == "funcInt") {
        StructInt paramInt{};
        argumentsReader.read(paramInt);
        return ApiGear::ObjectLink::invokeReturnValue(m_StructInterface->funcInt(paramInt));
    }
    if(memberMethod == "funcFloat") {
        StructFloat paramFloat{};
        argumentsReader.read(paramFloat);
        return ApiGear::ObjectLink::invokeReturnValue(m_StructInterface->funcFloat(paramFloat));
    }
    if(memberMethod == "funcString") {
        StructString paramString{};
        argumentsReader.read(paramString);
        return ApiGear::ObjectLink::invokeReturnValue(m_StructInterface->funcString(paramString));
    }
    return {};
}

void StructInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("StructInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        StructBool value_propBool{};
        ApiGear::ObjectLink::readValue(value, value_propBool);
        m_StructInterface->setPropBool(value_propBool);
    }
    if(memberProperty == "propInt") {
        StructInt value_propInt{};
        ApiGear::ObjectLink::readValue(value, value_propInt);
        m_StructInterface->setPropInt(value_propInt);
    }
    if(memberProperty == "propFloat") {
        StructFloat value_propFloat{};
        ApiGear::ObjectLink::readValue(value, value_propFloat);
        m_StructInterface->setPropFloat(value_propFloat);
    }
    if(memberProperty == "propString") {
        StructString value_propString{};
        ApiGear::ObjectLink::readValue(value, value_propString);
        m_StructInterface->setPropString(value_propString);
    } 
}

void StructInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("StructInterfaceService linked " + objectId);
}

void StructInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("StructInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent StructInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("propBool"), m_StructInterface->getPropBool()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propInt"), m_StructInterface->getPropInt()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propFloat"), m_StructInterface->getPropFloat()),
        ApiGear::ObjectLink::toInitialProperty(std::string("propString"), m_StructInterface->getPropString()) );
}
void StructInterfaceService::onSigBool(const StructBool& paramBool)
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
void StructInterfaceService::onSigInt(const StructInt& paramInt)
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
void StructInterfaceService::onSigFloat(const StructFloat& paramFloat)
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
void StructInterfaceService::onSigString(const StructString& paramString)
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
void StructInterfaceService::onPropBoolChanged(const StructBool& propBool)
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
void StructInterfaceService::onPropIntChanged(const StructInt& propInt)
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
void StructInterfaceService::onPropFloatChanged(const StructFloat& propFloat)
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
void StructInterfaceService::onPropStringChanged(const StructString& propString)
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


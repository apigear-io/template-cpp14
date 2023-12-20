

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/manyparaminterfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.ManyParamInterface";
}

ManyParamInterfaceService::ManyParamInterfaceService(std::shared_ptr<IManyParamInterface> ManyParamInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_ManyParamInterface(ManyParamInterface)
    , m_registry(registry)
{
    m_ManyParamInterface->_getPublisher().subscribeToAllChanges(*this);
}

ManyParamInterfaceService::~ManyParamInterfaceService()
{
    m_ManyParamInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string ManyParamInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent ManyParamInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("ManyParamInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "func1") {
        int param1{};
        argumentsReader.read(param1);
        return ApiGear::ObjectLink::invokeReturnValue(m_ManyParamInterface->func1(param1));
    }
    if(memberMethod == "func2") {
        int param1{};
        argumentsReader.read(param1);
        int param2{};
        argumentsReader.read(param2);
        return ApiGear::ObjectLink::invokeReturnValue(m_ManyParamInterface->func2(param1, param2));
    }
    if(memberMethod == "func3") {
        int param1{};
        argumentsReader.read(param1);
        int param2{};
        argumentsReader.read(param2);
        int param3{};
        argumentsReader.read(param3);
        return ApiGear::ObjectLink::invokeReturnValue(m_ManyParamInterface->func3(param1, param2, param3));
    }
    if(memberMethod == "func4") {
        int param1{};
        argumentsReader.read(param1);
        int param2{};
        argumentsReader.read(param2);
        int param3{};
        argumentsReader.read(param3);
        int param4{};
        argumentsReader.read(param4);
        return ApiGear::ObjectLink::invokeReturnValue(m_ManyParamInterface->func4(param1, param2, param3, param4));
    }
    return {};
}

void ManyParamInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("ManyParamInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        int value_prop1{};
        ApiGear::ObjectLink::readValue(value, value_prop1);
        m_ManyParamInterface->setProp1(value_prop1);
    }
    if(memberProperty == "prop2") {
        int value_prop2{};
        ApiGear::ObjectLink::readValue(value, value_prop2);
        m_ManyParamInterface->setProp2(value_prop2);
    }
    if(memberProperty == "prop3") {
        int value_prop3{};
        ApiGear::ObjectLink::readValue(value, value_prop3);
        m_ManyParamInterface->setProp3(value_prop3);
    }
    if(memberProperty == "prop4") {
        int value_prop4{};
        ApiGear::ObjectLink::readValue(value, value_prop4);
        m_ManyParamInterface->setProp4(value_prop4);
    } 
}

void ManyParamInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("ManyParamInterfaceService linked " + objectId);
}

void ManyParamInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("ManyParamInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent ManyParamInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("prop1"), m_ManyParamInterface->getProp1()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop2"), m_ManyParamInterface->getProp2()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop3"), m_ManyParamInterface->getProp3()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop4"), m_ManyParamInterface->getProp4()) );
}
void ManyParamInterfaceService::onSig1(int param1)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param1);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void ManyParamInterfaceService::onSig2(int param1, int param2)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param1, param2);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void ManyParamInterfaceService::onSig3(int param1, int param2, int param3)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param1, param2, param3);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void ManyParamInterfaceService::onSig4(int param1, int param2, int param3, int param4)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param1, param2, param3, param4);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig4");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void ManyParamInterfaceService::onProp1Changed(int prop1)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(prop1));
        }
    }
}
void ManyParamInterfaceService::onProp2Changed(int prop2)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(prop2));
        }
    }
}
void ManyParamInterfaceService::onProp3Changed(int prop3)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(prop3));
        }
    }
}
void ManyParamInterfaceService::onProp4Changed(int prop4)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop4");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(prop4));
        }
    }
}


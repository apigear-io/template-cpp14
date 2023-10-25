

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/nestedstruct3interfaceservice.h"
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
const std::string interfaceId = "testbed2.NestedStruct3Interface";
}

NestedStruct3InterfaceService::NestedStruct3InterfaceService(std::shared_ptr<INestedStruct3Interface> NestedStruct3Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct3Interface(NestedStruct3Interface)
    , m_registry(registry)
{
    m_NestedStruct3Interface->_getPublisher().subscribeToAllChanges(*this);
}

NestedStruct3InterfaceService::~NestedStruct3InterfaceService()
{
    m_NestedStruct3Interface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct3InterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent NestedStruct3InterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("NestedStruct3InterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "func1") {
        NestedStruct1 param1{};
        argumentsReader.read(param1);
        return ApiGear::ObjectLink::invokeReturnValue(m_NestedStruct3Interface->func1(param1));
    }
    if(memberMethod == "func2") {
        NestedStruct1 param1{};
        argumentsReader.read(param1);
        NestedStruct2 param2{};
        argumentsReader.read(param2);
        return ApiGear::ObjectLink::invokeReturnValue(m_NestedStruct3Interface->func2(param1, param2));
    }
    if(memberMethod == "func3") {
        NestedStruct1 param1{};
        argumentsReader.read(param1);
        NestedStruct2 param2{};
        argumentsReader.read(param2);
        NestedStruct3 param3{};
        argumentsReader.read(param3);
        return ApiGear::ObjectLink::invokeReturnValue(m_NestedStruct3Interface->func3(param1, param2, param3));
    }
    return {};
}

void NestedStruct3InterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("NestedStruct3InterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        NestedStruct1 value_prop1{};
        ApiGear::ObjectLink::readValue(value, value_prop1);
        m_NestedStruct3Interface->setProp1(value_prop1);
    }
    if(memberProperty == "prop2") {
        NestedStruct2 value_prop2{};
        ApiGear::ObjectLink::readValue(value, value_prop2);
        m_NestedStruct3Interface->setProp2(value_prop2);
    }
    if(memberProperty == "prop3") {
        NestedStruct3 value_prop3{};
        ApiGear::ObjectLink::readValue(value, value_prop3);
        m_NestedStruct3Interface->setProp3(value_prop3);
    } 
}

void NestedStruct3InterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("NestedStruct3InterfaceService linked " + objectId);
}

void NestedStruct3InterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("NestedStruct3InterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent NestedStruct3InterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("prop1"), m_NestedStruct3Interface->getProp1()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop2"), m_NestedStruct3Interface->getProp2()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop3"), m_NestedStruct3Interface->getProp3()) );
}
void NestedStruct3InterfaceService::onSig1(const NestedStruct1& param1)
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
void NestedStruct3InterfaceService::onSig2(const NestedStruct1& param1, const NestedStruct2& param2)
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
void NestedStruct3InterfaceService::onSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
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
void NestedStruct3InterfaceService::onProp1Changed(const NestedStruct1& prop1)
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
void NestedStruct3InterfaceService::onProp2Changed(const NestedStruct2& prop2)
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
void NestedStruct3InterfaceService::onProp3Changed(const NestedStruct3& prop3)
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


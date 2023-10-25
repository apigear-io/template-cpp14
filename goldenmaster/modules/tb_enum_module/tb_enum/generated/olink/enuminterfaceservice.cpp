

#include "tb_enum/generated/api/datastructs.api.h"
#include "tb_enum/generated/olink/enuminterfaceservice.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbEnum;
using namespace Test::TbEnum::olink;

namespace 
{
const std::string interfaceId = "tb.enum.EnumInterface";
}

EnumInterfaceService::EnumInterfaceService(std::shared_ptr<IEnumInterface> EnumInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_EnumInterface(EnumInterface)
    , m_registry(registry)
{
    m_EnumInterface->_getPublisher().subscribeToAllChanges(*this);
}

EnumInterfaceService::~EnumInterfaceService()
{
    m_EnumInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string EnumInterfaceService::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent EnumInterfaceService::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
    AG_LOG_DEBUG("EnumInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
    if(memberMethod == "func0") {
        Enum0Enum param0{};
        argumentsReader.read(param0);
        return ApiGear::ObjectLink::invokeReturnValue(m_EnumInterface->func0(param0));
    }
    if(memberMethod == "func1") {
        Enum1Enum param1{};
        argumentsReader.read(param1);
        return ApiGear::ObjectLink::invokeReturnValue(m_EnumInterface->func1(param1));
    }
    if(memberMethod == "func2") {
        Enum2Enum param2{};
        argumentsReader.read(param2);
        return ApiGear::ObjectLink::invokeReturnValue(m_EnumInterface->func2(param2));
    }
    if(memberMethod == "func3") {
        Enum3Enum param3{};
        argumentsReader.read(param3);
        return ApiGear::ObjectLink::invokeReturnValue(m_EnumInterface->func3(param3));
    }
    return {};
}

void EnumInterfaceService::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("EnumInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop0") {
        Enum0Enum value_prop0{};
        ApiGear::ObjectLink::readValue(value, value_prop0);
        m_EnumInterface->setProp0(value_prop0);
    }
    if(memberProperty == "prop1") {
        Enum1Enum value_prop1{};
        ApiGear::ObjectLink::readValue(value, value_prop1);
        m_EnumInterface->setProp1(value_prop1);
    }
    if(memberProperty == "prop2") {
        Enum2Enum value_prop2{};
        ApiGear::ObjectLink::readValue(value, value_prop2);
        m_EnumInterface->setProp2(value_prop2);
    }
    if(memberProperty == "prop3") {
        Enum3Enum value_prop3{};
        ApiGear::ObjectLink::readValue(value, value_prop3);
        m_EnumInterface->setProp3(value_prop3);
    } 
}

void EnumInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("EnumInterfaceService linked " + objectId);
}

void EnumInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("EnumInterfaceService unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent EnumInterfaceService::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
        ApiGear::ObjectLink::toInitialProperty(std::string("prop0"), m_EnumInterface->getProp0()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop1"), m_EnumInterface->getProp1()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop2"), m_EnumInterface->getProp2()),
        ApiGear::ObjectLink::toInitialProperty(std::string("prop3"), m_EnumInterface->getProp3()) );
}
void EnumInterfaceService::onSig0(Enum0Enum param0)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param0);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig0");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void EnumInterfaceService::onSig1(Enum1Enum param1)
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
void EnumInterfaceService::onSig2(Enum2Enum param2)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param2);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void EnumInterfaceService::onSig3(Enum3Enum param3)
{
    auto args = ApiGear::ObjectLink::argumentsToContent(param3);
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void EnumInterfaceService::onProp0Changed(Enum0Enum prop0)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop0");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent(prop0));
        }
    }
}
void EnumInterfaceService::onProp1Changed(Enum1Enum prop1)
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
void EnumInterfaceService::onProp2Changed(Enum2Enum prop2)
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
void EnumInterfaceService::onProp3Changed(Enum3Enum prop3)
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


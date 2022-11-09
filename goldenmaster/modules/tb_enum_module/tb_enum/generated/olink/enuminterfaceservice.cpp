

#include "tb_enum/generated/api/datastructs.api.h"
#include "tb_enum/generated/olink/enuminterfaceservice.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

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

nlohmann::json EnumInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func0") {
        const Enum0Enum& param0 = fcnArgs.at(0);
        Enum0Enum result = m_EnumInterface->func0(param0);
        return result;
    }
    if(memberMethod == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_EnumInterface->func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const Enum2Enum& param2 = fcnArgs.at(0);
        Enum2Enum result = m_EnumInterface->func2(param2);
        return result;
    }
    if(memberMethod == "func3") {
        const Enum3Enum& param3 = fcnArgs.at(0);
        Enum3Enum result = m_EnumInterface->func3(param3);
        return result;
    }
    return nlohmann::json();
}

void EnumInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop0") {
        Enum0Enum prop0 = value.get<Enum0Enum>();
        m_EnumInterface->setProp0(prop0);
    }
    if(memberProperty == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_EnumInterface->setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        Enum2Enum prop2 = value.get<Enum2Enum>();
        m_EnumInterface->setProp2(prop2);
    }
    if(memberProperty == "prop3") {
        Enum3Enum prop3 = value.get<Enum3Enum>();
        m_EnumInterface->setProp3(prop3);
    } 
}

void EnumInterfaceService::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void EnumInterfaceService::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json EnumInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop0", m_EnumInterface->getProp0() },
        { "prop1", m_EnumInterface->getProp1() },
        { "prop2", m_EnumInterface->getProp2() },
        { "prop3", m_EnumInterface->getProp3() }
    });
}
void EnumInterfaceService::onSig0(Enum0Enum param0)
{
    const nlohmann::json args = { param0 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig0");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void EnumInterfaceService::onSig1(Enum1Enum param1)
{
    const nlohmann::json args = { param1 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void EnumInterfaceService::onSig2(Enum2Enum param2)
{
    const nlohmann::json args = { param2 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void EnumInterfaceService::onSig3(Enum3Enum param3)
{
    const nlohmann::json args = { param3 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void EnumInterfaceService::onProp0Changed(Enum0Enum prop0)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop0");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop0);
        }
    }
}
void EnumInterfaceService::onProp1Changed(Enum1Enum prop1)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop1);
        }
    }
}
void EnumInterfaceService::onProp2Changed(Enum2Enum prop2)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop2);
        }
    }
}
void EnumInterfaceService::onProp3Changed(Enum3Enum prop3)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop3);
        }
    }
}


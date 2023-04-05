

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/nestedstruct3interfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
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
    , m_logger(std::make_unique<ApiGear::Utilities::Logger>())
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

nlohmann::json NestedStruct3InterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    m_logger->emitLog(ApiGear::Utilities::LogLevel::Debug, methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_NestedStruct3Interface->func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        const NestedStruct2& param2 = fcnArgs.at(1);
        NestedStruct1 result = m_NestedStruct3Interface->func2(param1, param2);
        return result;
    }
    if(memberMethod == "func3") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        const NestedStruct2& param2 = fcnArgs.at(1);
        const NestedStruct3& param3 = fcnArgs.at(2);
        NestedStruct1 result = m_NestedStruct3Interface->func3(param1, param2, param3);
        return result;
    }
    return nlohmann::json();
}

void NestedStruct3InterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    m_logger->emitLog(ApiGear::Utilities::LogLevel::Debug, propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_NestedStruct3Interface->setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        NestedStruct2 prop2 = value.get<NestedStruct2>();
        m_NestedStruct3Interface->setProp2(prop2);
    }
    if(memberProperty == "prop3") {
        NestedStruct3 prop3 = value.get<NestedStruct3>();
        m_NestedStruct3Interface->setProp3(prop3);
    } 
}

void NestedStruct3InterfaceService::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    m_logger->emitLog(ApiGear::Utilities::LogLevel::Debug, objetId);
}

void NestedStruct3InterfaceService::olinkUnlinked(const std::string& objetId){
    m_logger->emitLog(ApiGear::Utilities::LogLevel::Debug, objetId);
}

nlohmann::json NestedStruct3InterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_NestedStruct3Interface->getProp1() },
        { "prop2", m_NestedStruct3Interface->getProp2() },
        { "prop3", m_NestedStruct3Interface->getProp3() }
    });
}
void NestedStruct3InterfaceService::onSig1(const NestedStruct1& param1)
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
void NestedStruct3InterfaceService::onSig2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    const nlohmann::json args = { param1, param2 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void NestedStruct3InterfaceService::onSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    const nlohmann::json args = { param1, param2, param3 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void NestedStruct3InterfaceService::onProp1Changed(const NestedStruct1& prop1)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop1);
        }
    }
}
void NestedStruct3InterfaceService::onProp2Changed(const NestedStruct2& prop2)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop2);
        }
    }
}
void NestedStruct3InterfaceService::onProp3Changed(const NestedStruct3& prop3)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop3);
        }
    }
}


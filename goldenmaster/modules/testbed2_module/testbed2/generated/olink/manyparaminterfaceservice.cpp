

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/manyparaminterfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
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

nlohmann::json ManyParamInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    AG_LOG_DEBUG(methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const int& param1 = fcnArgs.at(0);
        int result = m_ManyParamInterface->func1(param1);
        return result;
    }
    if(memberMethod == "func2") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        int result = m_ManyParamInterface->func2(param1, param2);
        return result;
    }
    if(memberMethod == "func3") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        const int& param3 = fcnArgs.at(2);
        int result = m_ManyParamInterface->func3(param1, param2, param3);
        return result;
    }
    if(memberMethod == "func4") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        const int& param3 = fcnArgs.at(2);
        const int& param4 = fcnArgs.at(3);
        int result = m_ManyParamInterface->func4(param1, param2, param3, param4);
        return result;
    }
    return nlohmann::json();
}

void ManyParamInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    AG_LOG_DEBUG(propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        int prop1 = value.get<int>();
        m_ManyParamInterface->setProp1(prop1);
    }
    if(memberProperty == "prop2") {
        int prop2 = value.get<int>();
        m_ManyParamInterface->setProp2(prop2);
    }
    if(memberProperty == "prop3") {
        int prop3 = value.get<int>();
        m_ManyParamInterface->setProp3(prop3);
    }
    if(memberProperty == "prop4") {
        int prop4 = value.get<int>();
        m_ManyParamInterface->setProp4(prop4);
    } 
}

void ManyParamInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG(objectId);
}

void ManyParamInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG(objectId);
}

nlohmann::json ManyParamInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_ManyParamInterface->getProp1() },
        { "prop2", m_ManyParamInterface->getProp2() },
        { "prop3", m_ManyParamInterface->getProp3() },
        { "prop4", m_ManyParamInterface->getProp4() }
    });
}
void ManyParamInterfaceService::onSig1(int param1)
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
void ManyParamInterfaceService::onSig2(int param1, int param2)
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
void ManyParamInterfaceService::onSig3(int param1, int param2, int param3)
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
void ManyParamInterfaceService::onSig4(int param1, int param2, int param3, int param4)
{
    const nlohmann::json args = { param1, param2, param3, param4 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig4");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void ManyParamInterfaceService::onProp1Changed(int prop1)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop1);
        }
    }
}
void ManyParamInterfaceService::onProp2Changed(int prop2)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop2);
        }
    }
}
void ManyParamInterfaceService::onProp3Changed(int prop3)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop3);
        }
    }
}
void ManyParamInterfaceService::onProp4Changed(int prop4)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop4");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop4);
        }
    }
}




#include "api/generated/api/datastructs.api.h"
#include "api/generated/olink/testapi41service.h"
#include "api/generated/core/api.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::Api;
using namespace Test::Api::olink;

namespace 
{
const std::string interfaceId = "api.TestApi41";
}

TestApi41Service::TestApi41Service(std::shared_ptr<ITestApi41> TestApi41, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_TestApi41(TestApi41)
    , m_registry(registry)
{
    m_TestApi41->_getPublisher().subscribeToAllChanges(*this);
}

TestApi41Service::~TestApi41Service()
{
    m_TestApi41->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string TestApi41Service::olinkObjectName() {
    return interfaceId;
}

nlohmann::json TestApi41Service::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    AG_LOG_DEBUG("TestApi41Service invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcInt") {
        const int& paramInt = fcnArgs.at(0);
        int result = m_TestApi41->funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const float& paramFloat = fcnArgs.at(0);
        float result = m_TestApi41->funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::string& paramString = fcnArgs.at(0);
        std::string result = m_TestApi41->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void TestApi41Service::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    AG_LOG_DEBUG("TestApi41Service set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propInt") {
        int propInt = value.get<int>();
        m_TestApi41->setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        float propFloat = value.get<float>();
        m_TestApi41->setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        std::string propString = value.get<std::string>();
        m_TestApi41->setPropString(propString);
    } 
}

void TestApi41Service::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("TestApi41Service linked " + objectId);
}

void TestApi41Service::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("TestApi41Service unlinked " + objectId);
}

nlohmann::json TestApi41Service::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propInt", m_TestApi41->getPropInt() },
        { "propFloat", m_TestApi41->getPropFloat() },
        { "propString", m_TestApi41->getPropString() }
    });
}
void TestApi41Service::onSigInt(int paramInt)
{
    const nlohmann::json args = { paramInt };
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void TestApi41Service::onSigFloat(float paramFloat)
{
    const nlohmann::json args = { paramFloat };
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void TestApi41Service::onSigString(const std::string& paramString)
{
    const nlohmann::json args = { paramString };
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void TestApi41Service::onPropIntChanged(int propInt)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt);
        }
    }
}
void TestApi41Service::onPropFloatChanged(float propFloat)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat);
        }
    }
}
void TestApi41Service::onPropStringChanged(const std::string& propString)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propString);
        }
    }
}


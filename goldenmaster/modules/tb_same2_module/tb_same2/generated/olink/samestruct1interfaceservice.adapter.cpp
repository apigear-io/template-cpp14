

#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/olink/samestruct1interfaceservice.adapter.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include <iostream>


using namespace Test::TbSame2;
using namespace Test::TbSame2::olink;

namespace 
{
const std::string interfaceId = "tb.same2.SameStruct1Interface";
}

SameStruct1InterfaceServiceAdapter::SameStruct1InterfaceServiceAdapter(ISameStruct1Interface& SameStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameStruct1Interface(SameStruct1Interface)
    , m_registry(registry)
{
    m_SameStruct1Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addSource(*this);
}

SameStruct1InterfaceServiceAdapter::~SameStruct1InterfaceServiceAdapter()
{
    m_registry.removeSource(olinkObjectName());
    m_SameStruct1Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameStruct1InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SameStruct1InterfaceServiceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const Struct1& param1 = fcnArgs.at(0);
        Struct1 result = m_SameStruct1Interface.func1(param1);
        return result;
    }
    return nlohmann::json();
}

void SameStruct1InterfaceServiceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Struct1 prop1 = value.get<Struct1>();
        m_SameStruct1Interface.setProp1(prop1);
    } 
}

void SameStruct1InterfaceServiceAdapter::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void SameStruct1InterfaceServiceAdapter::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json SameStruct1InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameStruct1Interface.getProp1() }
    });
}
void SameStruct1InterfaceServiceAdapter::onSig1(const Struct1& param1)
{
    const nlohmann::json args = { param1 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        if(node != nullptr) {
            node->notifySignal(signalId, args);
        }
    }
}
void SameStruct1InterfaceServiceAdapter::onProp1Changed(const Struct1& prop1)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        if(node != nullptr) {
            node->notifyPropertyChange(propertyId, prop1);
        }
    }
}


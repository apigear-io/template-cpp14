

#include "tb_simple/generated/olink/nooperationsinterfaceclient.h"
#include "tb_simple/generated/core/nooperationsinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.NoOperationsInterface";
}

NoOperationsInterfaceClient::NoOperationsInterfaceClient()
    : m_publisher(std::make_unique<NoOperationsInterfacePublisher>())
{}

void NoOperationsInterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{
    if ( propertyName == "propBool") {
        bool value_propBool {};
        readValue(value, value_propBool);
        setPropBoolLocal(value_propBool);
    }
    else if ( propertyName == "propInt") {
        int value_propInt {};
        readValue(value, value_propInt);
        setPropIntLocal(value_propInt);
    }
}

void NoOperationsInterfaceClient::setPropBool(bool propBool)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propBool));
}

void NoOperationsInterfaceClient::setPropBoolLocal(bool propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool NoOperationsInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void NoOperationsInterfaceClient::setPropInt(int propInt)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    m_node->setRemoteProperty(propertyId, ApiGear::ObjectLink::propertyToContent(propInt));
}

void NoOperationsInterfaceClient::setPropIntLocal(int propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int NoOperationsInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

std::string NoOperationsInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void NoOperationsInterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sigVoid") {m_publisher->publishSigVoid();   
        return;
    }
    if(signalName == "sigBool") {bool arg_paramBool {};
        argumentsReader.read(arg_paramBool);m_publisher->publishSigBool(arg_paramBool);   
        return;
    }
}

void NoOperationsInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void NoOperationsInterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    ApiGear::ObjectLink::OLinContentStreamReader reader(props);
    size_t propertyCount = reader.argumentsCount();
    ApiGear::ObjectLink::InitialProperty currentProperty;
    for (size_t i = 0; i < propertyCount; i++)
    {
        reader.read(currentProperty);
        applyProperty(currentProperty.propertyName, currentProperty.propertyValue);
    }
}

void NoOperationsInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool NoOperationsInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

INoOperationsInterfacePublisher& NoOperationsInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

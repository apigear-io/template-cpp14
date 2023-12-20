

#include "tb_simple/generated/olink/voidinterfaceclient.h"
#include "tb_simple/generated/core/voidinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iclientnode.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.VoidInterface";
}

VoidInterfaceClient::VoidInterfaceClient()
    : m_publisher(std::make_unique<VoidInterfacePublisher>())
{}

void VoidInterfaceClient::applyProperty(const std::string& propertyName, const ApiGear::ObjectLink::OLinkContent& value)
{// no properties to apply state
    (void) propertyName;
    (void) value;
}

void VoidInterfaceClient::funcVoid()
{
     if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    ApiGear::ObjectLink::InvokeReplyFunc func = [this](ApiGear::ObjectLink::InvokeReplyArg arg)
        {
            (void) this;
            (void) arg;
        };
    auto args = ApiGear::ObjectLink::argumentsToContent(  );
    static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcVoid");
    m_node->invokeRemote(operationId, args, func);
}

std::future<void> VoidInterfaceClient::funcVoidAsync()
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<void>{};
    }
    return std::async(std::launch::async, [this]()
        {
            std::promise<void> resultPromise;
            static const auto operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcVoid");
            auto args = ApiGear::ObjectLink::argumentsToContent(  );
            m_node->invokeRemote(operationId, args,
                   [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    (void) arg;
                    resultPromise.set_value();
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string VoidInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void VoidInterfaceClient::olinkOnSignal(const std::string& signalId, const ApiGear::ObjectLink::OLinkContent& args)
{
    (void) args;
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(args);
    if(signalName == "sigVoid") {m_publisher->publishSigVoid();   
        return;
    }
}

void VoidInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void VoidInterfaceClient::olinkOnInit(const std::string& /*name*/, const ApiGear::ObjectLink::OLinkContent& props, ApiGear::ObjectLink::IClientNode *node)
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

void VoidInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool VoidInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

IVoidInterfacePublisher& VoidInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}

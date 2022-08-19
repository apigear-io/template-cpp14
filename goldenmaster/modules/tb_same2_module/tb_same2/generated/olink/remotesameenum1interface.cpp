

#include "tb_same2/generated/olink/remotesameenum1interface.h"
#include "tb_same2/generated/core/sameenum1interface.publisher.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

using namespace Test::TbSame2;
using namespace Test::TbSame2::olink;

RemoteSameEnum1Interface::RemoteSameEnum1Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_registry(registry),
      m_publisher(std::make_unique<SameEnum1InterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("tb.same2.SameEnum1Interface");
}

RemoteSameEnum1Interface::~RemoteSameEnum1Interface()
{
    m_registry.removeObjectSink(this);
}

void RemoteSameEnum1Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
}

void RemoteSameEnum1Interface::setProp1(const Enum1Enum& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameEnum1Interface/prop1", prop1);
}

void RemoteSameEnum1Interface::setProp1Local(const Enum1Enum& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& RemoteSameEnum1Interface::getProp1() const
{
    return m_data.m_prop1;
}

Enum1Enum RemoteSameEnum1Interface::func1(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> RemoteSameEnum1Interface::func1Async(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            m_node->invokeRemote("tb.same2.SameEnum1Interface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSameEnum1Interface::olinkObjectName()
{
    return "tb.same2.SameEnum1Interface";
}

void RemoteSameEnum1Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<Enum1Enum>());   
        return;
    }
}

void RemoteSameEnum1Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteSameEnum1Interface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name; //suppress the 'Unreferenced Formal Parameter' warning.
    m_node = node;
    applyState(props);
}

void RemoteSameEnum1Interface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSameEnum1Interface::isReady() const
{
    return m_node != nullptr;
}

ISameEnum1InterfacePublisher& RemoteSameEnum1Interface::_getPublisher() const
{
    return *m_publisher;
}

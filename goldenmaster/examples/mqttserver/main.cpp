#include <iostream>
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/generated/mqtt/manyparaminterfaceservice.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/generated/mqtt/nestedstruct1interfaceservice.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/generated/mqtt/nestedstruct2interfaceservice.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/generated/mqtt/nestedstruct3interfaceservice.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/generated/mqtt/enuminterfaceservice.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/generated/mqtt/samestruct1interfaceservice.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/generated/mqtt/samestruct2interfaceservice.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/generated/mqtt/sameenum1interfaceservice.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/generated/mqtt/sameenum2interfaceservice.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/generated/mqtt/samestruct1interfaceservice.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/generated/mqtt/samestruct2interfaceservice.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/generated/mqtt/sameenum1interfaceservice.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/generated/mqtt/sameenum2interfaceservice.h"
#include "tb_simple/implementation/voidinterface.h"
#include "tb_simple/generated/mqtt/voidinterfaceservice.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/generated/mqtt/simpleinterfaceservice.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/generated/mqtt/simplearrayinterfaceservice.h"
#include "tb_simple/implementation/nopropertiesinterface.h"
#include "tb_simple/generated/mqtt/nopropertiesinterfaceservice.h"
#include "tb_simple/implementation/nooperationsinterface.h"
#include "tb_simple/generated/mqtt/nooperationsinterfaceservice.h"
#include "tb_simple/implementation/nosignalsinterface.h"
#include "tb_simple/generated/mqtt/nosignalsinterfaceservice.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/generated/mqtt/structinterfaceservice.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/generated/mqtt/structarrayinterfaceservice.h"
#include "apigear/mqtt/mqttcppclient.h"
#include <random>

using namespace Test;

int main(){
    std::mt19937 randomNumberGenerator (std::random_device{}());
    std::uniform_int_distribution<> distribution (0, 100000);

    auto randomId = distribution(randomNumberGenerator);
    // MQTT clients need to have unique identifiers
    auto mqttclient = std::make_shared<ApiGear::MQTTImpl::Client>("testServer"+std::to_string(randomId));
    mqttclient->connectToHost("");
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::ManyParamInterface>();
    Testbed2::mqtt::ManyParamInterfaceService testTestbed2ManyParamInterfaceService(*testTestbed2ManyParamInterface, mqttclient);
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1Interface = std::make_unique<Testbed2::NestedStruct1Interface>();
    Testbed2::mqtt::NestedStruct1InterfaceService testTestbed2NestedStruct1InterfaceService(*testTestbed2NestedStruct1Interface, mqttclient);
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::NestedStruct2Interface>();
    Testbed2::mqtt::NestedStruct2InterfaceService testTestbed2NestedStruct2InterfaceService(*testTestbed2NestedStruct2Interface, mqttclient);
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3Interface = std::make_unique<Testbed2::NestedStruct3Interface>();
    Testbed2::mqtt::NestedStruct3InterfaceService testTestbed2NestedStruct3InterfaceService(*testTestbed2NestedStruct3Interface, mqttclient);
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterface = std::make_unique<TbEnum::EnumInterface>();
    TbEnum::mqtt::EnumInterfaceService testTbEnumEnumInterfaceService(*testTbEnumEnumInterface, mqttclient);
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1Interface = std::make_unique<TbSame1::SameStruct1Interface>();
    TbSame1::mqtt::SameStruct1InterfaceService testTbSame1SameStruct1InterfaceService(*testTbSame1SameStruct1Interface, mqttclient);
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::SameStruct2Interface>();
    TbSame1::mqtt::SameStruct2InterfaceService testTbSame1SameStruct2InterfaceService(*testTbSame1SameStruct2Interface, mqttclient);
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1Interface = std::make_unique<TbSame1::SameEnum1Interface>();
    TbSame1::mqtt::SameEnum1InterfaceService testTbSame1SameEnum1InterfaceService(*testTbSame1SameEnum1Interface, mqttclient);
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2Interface = std::make_unique<TbSame1::SameEnum2Interface>();
    TbSame1::mqtt::SameEnum2InterfaceService testTbSame1SameEnum2InterfaceService(*testTbSame1SameEnum2Interface, mqttclient);
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1Interface = std::make_unique<TbSame2::SameStruct1Interface>();
    TbSame2::mqtt::SameStruct1InterfaceService testTbSame2SameStruct1InterfaceService(*testTbSame2SameStruct1Interface, mqttclient);
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2Interface = std::make_unique<TbSame2::SameStruct2Interface>();
    TbSame2::mqtt::SameStruct2InterfaceService testTbSame2SameStruct2InterfaceService(*testTbSame2SameStruct2Interface, mqttclient);
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1Interface = std::make_unique<TbSame2::SameEnum1Interface>();
    TbSame2::mqtt::SameEnum1InterfaceService testTbSame2SameEnum1InterfaceService(*testTbSame2SameEnum1Interface, mqttclient);
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::SameEnum2Interface>();
    TbSame2::mqtt::SameEnum2InterfaceService testTbSame2SameEnum2InterfaceService(*testTbSame2SameEnum2Interface, mqttclient);
    std::unique_ptr<TbSimple::IVoidInterface> testTbSimpleVoidInterface = std::make_unique<TbSimple::VoidInterface>();
    TbSimple::mqtt::VoidInterfaceService testTbSimpleVoidInterfaceService(*testTbSimpleVoidInterface, mqttclient);
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::SimpleInterface>();
    TbSimple::mqtt::SimpleInterfaceService testTbSimpleSimpleInterfaceService(*testTbSimpleSimpleInterface, mqttclient);
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::SimpleArrayInterface>();
    TbSimple::mqtt::SimpleArrayInterfaceService testTbSimpleSimpleArrayInterfaceService(*testTbSimpleSimpleArrayInterface, mqttclient);
    std::unique_ptr<TbSimple::INoPropertiesInterface> testTbSimpleNoPropertiesInterface = std::make_unique<TbSimple::NoPropertiesInterface>();
    TbSimple::mqtt::NoPropertiesInterfaceService testTbSimpleNoPropertiesInterfaceService(*testTbSimpleNoPropertiesInterface, mqttclient);
    std::unique_ptr<TbSimple::INoOperationsInterface> testTbSimpleNoOperationsInterface = std::make_unique<TbSimple::NoOperationsInterface>();
    TbSimple::mqtt::NoOperationsInterfaceService testTbSimpleNoOperationsInterfaceService(*testTbSimpleNoOperationsInterface, mqttclient);
    std::unique_ptr<TbSimple::INoSignalsInterface> testTbSimpleNoSignalsInterface = std::make_unique<TbSimple::NoSignalsInterface>();
    TbSimple::mqtt::NoSignalsInterfaceService testTbSimpleNoSignalsInterfaceService(*testTbSimpleNoSignalsInterface, mqttclient);
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::StructInterface>();
    Testbed1::mqtt::StructInterfaceService testTestbed1StructInterfaceService(*testTestbed1StructInterface, mqttclient);
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterface = std::make_unique<Testbed1::StructArrayInterface>();
    Testbed1::mqtt::StructArrayInterfaceService testTestbed1StructArrayInterfaceService(*testTestbed1StructArrayInterface, mqttclient);

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            mqttclient->disconnect();
            keepRunning = false;
        } else {
        }
    } while(keepRunning);

    return 0;
}


#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/generated/olink/manyparaminterfaceservice.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/generated/olink/nestedstruct1interfaceservice.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/generated/olink/nestedstruct2interfaceservice.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/generated/olink/nestedstruct3interfaceservice.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/generated/olink/enuminterfaceservice.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/generated/olink/samestruct1interfaceservice.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/generated/olink/samestruct2interfaceservice.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/generated/olink/sameenum1interfaceservice.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/generated/olink/sameenum2interfaceservice.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/generated/olink/samestruct1interfaceservice.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/generated/olink/samestruct2interfaceservice.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/generated/olink/sameenum1interfaceservice.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/generated/olink/sameenum2interfaceservice.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/generated/olink/simpleinterfaceservice.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/generated/olink/simplearrayinterfaceservice.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/generated/olink/structinterfaceservice.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/generated/olink/structarrayinterfaceservice.h"

#include "olink/consolelogger.h"
#include "olink/remoteregistry.h"
#include "apigear/olink/olinkhost.h"

#include <iostream>

using namespace Goldenmaster;

int main(){
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::ObjectLink::ConsoleLogger logger;
    registry.onLog(logger.logFunc());
    
    ApiGear::PocoImpl::OLinkHost testserver(registry);
    auto testbed2ManyParamInterface = std::make_shared<Testbed2::ManyParamInterface>();
    auto testbed2OlinkManyParamInterfaceService = std::make_shared<Testbed2::olink::ManyParamInterfaceService>(testbed2ManyParamInterface, registry);
    registry.addSource(testbed2OlinkManyParamInterfaceService);
    auto testbed2NestedStruct1Interface = std::make_shared<Testbed2::NestedStruct1Interface>();
    auto testbed2OlinkNestedStruct1InterfaceService = std::make_shared<Testbed2::olink::NestedStruct1InterfaceService>(testbed2NestedStruct1Interface, registry);
    registry.addSource(testbed2OlinkNestedStruct1InterfaceService);
    auto testbed2NestedStruct2Interface = std::make_shared<Testbed2::NestedStruct2Interface>();
    auto testbed2OlinkNestedStruct2InterfaceService = std::make_shared<Testbed2::olink::NestedStruct2InterfaceService>(testbed2NestedStruct2Interface, registry);
    registry.addSource(testbed2OlinkNestedStruct2InterfaceService);
    auto testbed2NestedStruct3Interface = std::make_shared<Testbed2::NestedStruct3Interface>();
    auto testbed2OlinkNestedStruct3InterfaceService = std::make_shared<Testbed2::olink::NestedStruct3InterfaceService>(testbed2NestedStruct3Interface, registry);
    registry.addSource(testbed2OlinkNestedStruct3InterfaceService);
    auto tbEnumEnumInterface = std::make_shared<TbEnum::EnumInterface>();
    auto tbEnumOlinkEnumInterfaceService = std::make_shared<TbEnum::olink::EnumInterfaceService>(tbEnumEnumInterface, registry);
    registry.addSource(tbEnumOlinkEnumInterfaceService);
    auto tbSame1SameStruct1Interface = std::make_shared<TbSame1::SameStruct1Interface>();
    auto tbSame1OlinkSameStruct1InterfaceService = std::make_shared<TbSame1::olink::SameStruct1InterfaceService>(tbSame1SameStruct1Interface, registry);
    registry.addSource(tbSame1OlinkSameStruct1InterfaceService);
    auto tbSame1SameStruct2Interface = std::make_shared<TbSame1::SameStruct2Interface>();
    auto tbSame1OlinkSameStruct2InterfaceService = std::make_shared<TbSame1::olink::SameStruct2InterfaceService>(tbSame1SameStruct2Interface, registry);
    registry.addSource(tbSame1OlinkSameStruct2InterfaceService);
    auto tbSame1SameEnum1Interface = std::make_shared<TbSame1::SameEnum1Interface>();
    auto tbSame1OlinkSameEnum1InterfaceService = std::make_shared<TbSame1::olink::SameEnum1InterfaceService>(tbSame1SameEnum1Interface, registry);
    registry.addSource(tbSame1OlinkSameEnum1InterfaceService);
    auto tbSame1SameEnum2Interface = std::make_shared<TbSame1::SameEnum2Interface>();
    auto tbSame1OlinkSameEnum2InterfaceService = std::make_shared<TbSame1::olink::SameEnum2InterfaceService>(tbSame1SameEnum2Interface, registry);
    registry.addSource(tbSame1OlinkSameEnum2InterfaceService);
    auto tbSame2SameStruct1Interface = std::make_shared<TbSame2::SameStruct1Interface>();
    auto tbSame2OlinkSameStruct1InterfaceService = std::make_shared<TbSame2::olink::SameStruct1InterfaceService>(tbSame2SameStruct1Interface, registry);
    registry.addSource(tbSame2OlinkSameStruct1InterfaceService);
    auto tbSame2SameStruct2Interface = std::make_shared<TbSame2::SameStruct2Interface>();
    auto tbSame2OlinkSameStruct2InterfaceService = std::make_shared<TbSame2::olink::SameStruct2InterfaceService>(tbSame2SameStruct2Interface, registry);
    registry.addSource(tbSame2OlinkSameStruct2InterfaceService);
    auto tbSame2SameEnum1Interface = std::make_shared<TbSame2::SameEnum1Interface>();
    auto tbSame2OlinkSameEnum1InterfaceService = std::make_shared<TbSame2::olink::SameEnum1InterfaceService>(tbSame2SameEnum1Interface, registry);
    registry.addSource(tbSame2OlinkSameEnum1InterfaceService);
    auto tbSame2SameEnum2Interface = std::make_shared<TbSame2::SameEnum2Interface>();
    auto tbSame2OlinkSameEnum2InterfaceService = std::make_shared<TbSame2::olink::SameEnum2InterfaceService>(tbSame2SameEnum2Interface, registry);
    registry.addSource(tbSame2OlinkSameEnum2InterfaceService);
    auto tbSimpleSimpleInterface = std::make_shared<TbSimple::SimpleInterface>();
    auto tbSimpleOlinkSimpleInterfaceService = std::make_shared<TbSimple::olink::SimpleInterfaceService>(tbSimpleSimpleInterface, registry);
    registry.addSource(tbSimpleOlinkSimpleInterfaceService);
    auto tbSimpleSimpleArrayInterface = std::make_shared<TbSimple::SimpleArrayInterface>();
    auto tbSimpleOlinkSimpleArrayInterfaceService = std::make_shared<TbSimple::olink::SimpleArrayInterfaceService>(tbSimpleSimpleArrayInterface, registry);
    registry.addSource(tbSimpleOlinkSimpleArrayInterfaceService);
    auto testbed1StructInterface = std::make_shared<Testbed1::StructInterface>();
    auto testbed1OlinkStructInterfaceService = std::make_shared<Testbed1::olink::StructInterfaceService>(testbed1StructInterface, registry);
    registry.addSource(testbed1OlinkStructInterfaceService);
    auto testbed1StructArrayInterface = std::make_shared<Testbed1::StructArrayInterface>();
    auto testbed1OlinkStructArrayInterfaceService = std::make_shared<Testbed1::olink::StructArrayInterfaceService>(testbed1StructArrayInterface, registry);
    registry.addSource(testbed1OlinkStructArrayInterfaceService);

    testserver.listen(8000);

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            testserver.close();
            keepRunning = false;
        }
    } while(keepRunning);
    registry.removeSource(testbed2OlinkManyParamInterfaceService->olinkObjectName());
    registry.removeSource(testbed2OlinkNestedStruct1InterfaceService->olinkObjectName());
    registry.removeSource(testbed2OlinkNestedStruct2InterfaceService->olinkObjectName());
    registry.removeSource(testbed2OlinkNestedStruct3InterfaceService->olinkObjectName());
    registry.removeSource(tbEnumOlinkEnumInterfaceService->olinkObjectName());
    registry.removeSource(tbSame1OlinkSameStruct1InterfaceService->olinkObjectName());
    registry.removeSource(tbSame1OlinkSameStruct2InterfaceService->olinkObjectName());
    registry.removeSource(tbSame1OlinkSameEnum1InterfaceService->olinkObjectName());
    registry.removeSource(tbSame1OlinkSameEnum2InterfaceService->olinkObjectName());
    registry.removeSource(tbSame2OlinkSameStruct1InterfaceService->olinkObjectName());
    registry.removeSource(tbSame2OlinkSameStruct2InterfaceService->olinkObjectName());
    registry.removeSource(tbSame2OlinkSameEnum1InterfaceService->olinkObjectName());
    registry.removeSource(tbSame2OlinkSameEnum2InterfaceService->olinkObjectName());
    registry.removeSource(tbSimpleOlinkSimpleInterfaceService->olinkObjectName());
    registry.removeSource(tbSimpleOlinkSimpleArrayInterfaceService->olinkObjectName());
    registry.removeSource(testbed1OlinkStructInterfaceService->olinkObjectName());
    registry.removeSource(testbed1OlinkStructArrayInterfaceService->olinkObjectName());
    
    return 0;
}

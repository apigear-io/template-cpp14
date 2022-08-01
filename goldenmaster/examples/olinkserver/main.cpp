#include <iostream>
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
#include "apigear/olink/olinkhost.h"

using namespace Test;

int main(){
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::PocoImpl::OLinkHost testserver(registry);
    
    auto testbed2ManyParamInterface = std::make_unique<Testbed2::ManyParamInterface>();
    Testbed2::ManyParamInterfaceService testbed2ManyParamInterfaceService(*testbed2ManyParamInterface, registry);
    
    auto testbed2NestedStruct1Interface = std::make_unique<Testbed2::NestedStruct1Interface>();
    Testbed2::NestedStruct1InterfaceService testbed2NestedStruct1InterfaceService(*testbed2NestedStruct1Interface, registry);
    
    auto testbed2NestedStruct2Interface = std::make_unique<Testbed2::NestedStruct2Interface>();
    Testbed2::NestedStruct2InterfaceService testbed2NestedStruct2InterfaceService(*testbed2NestedStruct2Interface, registry);
    
    auto testbed2NestedStruct3Interface = std::make_unique<Testbed2::NestedStruct3Interface>();
    Testbed2::NestedStruct3InterfaceService testbed2NestedStruct3InterfaceService(*testbed2NestedStruct3Interface, registry);
    
    auto tbEnumEnumInterface = std::make_unique<TbEnum::EnumInterface>();
    TbEnum::EnumInterfaceService tbEnumEnumInterfaceService(*tbEnumEnumInterface, registry);
    
    auto tbSame1SameStruct1Interface = std::make_unique<TbSame1::SameStruct1Interface>();
    TbSame1::SameStruct1InterfaceService tbSame1SameStruct1InterfaceService(*tbSame1SameStruct1Interface, registry);
    
    auto tbSame1SameStruct2Interface = std::make_unique<TbSame1::SameStruct2Interface>();
    TbSame1::SameStruct2InterfaceService tbSame1SameStruct2InterfaceService(*tbSame1SameStruct2Interface, registry);
    
    auto tbSame1SameEnum1Interface = std::make_unique<TbSame1::SameEnum1Interface>();
    TbSame1::SameEnum1InterfaceService tbSame1SameEnum1InterfaceService(*tbSame1SameEnum1Interface, registry);
    
    auto tbSame1SameEnum2Interface = std::make_unique<TbSame1::SameEnum2Interface>();
    TbSame1::SameEnum2InterfaceService tbSame1SameEnum2InterfaceService(*tbSame1SameEnum2Interface, registry);
    
    auto tbSame2SameStruct1Interface = std::make_unique<TbSame2::SameStruct1Interface>();
    TbSame2::SameStruct1InterfaceService tbSame2SameStruct1InterfaceService(*tbSame2SameStruct1Interface, registry);
    
    auto tbSame2SameStruct2Interface = std::make_unique<TbSame2::SameStruct2Interface>();
    TbSame2::SameStruct2InterfaceService tbSame2SameStruct2InterfaceService(*tbSame2SameStruct2Interface, registry);
    
    auto tbSame2SameEnum1Interface = std::make_unique<TbSame2::SameEnum1Interface>();
    TbSame2::SameEnum1InterfaceService tbSame2SameEnum1InterfaceService(*tbSame2SameEnum1Interface, registry);
    
    auto tbSame2SameEnum2Interface = std::make_unique<TbSame2::SameEnum2Interface>();
    TbSame2::SameEnum2InterfaceService tbSame2SameEnum2InterfaceService(*tbSame2SameEnum2Interface, registry);
    
    auto tbSimpleSimpleInterface = std::make_unique<TbSimple::SimpleInterface>();
    TbSimple::SimpleInterfaceService tbSimpleSimpleInterfaceService(*tbSimpleSimpleInterface, registry);
    
    auto tbSimpleSimpleArrayInterface = std::make_unique<TbSimple::SimpleArrayInterface>();
    TbSimple::SimpleArrayInterfaceService tbSimpleSimpleArrayInterfaceService(*tbSimpleSimpleArrayInterface, registry);
    
    auto testbed1StructInterface = std::make_unique<Testbed1::StructInterface>();
    Testbed1::StructInterfaceService testbed1StructInterfaceService(*testbed1StructInterface, registry);
    
    auto testbed1StructArrayInterface = std::make_unique<Testbed1::StructArrayInterface>();
    Testbed1::StructArrayInterfaceService testbed1StructArrayInterfaceService(*testbed1StructArrayInterface, registry);

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

    return 0;
}


#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/generated/monitor/manyparaminterface.tracedecorator.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/generated/monitor/nestedstruct1interface.tracedecorator.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/generated/monitor/nestedstruct2interface.tracedecorator.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/generated/monitor/nestedstruct3interface.tracedecorator.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/generated/monitor/enuminterface.tracedecorator.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/generated/monitor/samestruct1interface.tracedecorator.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/generated/monitor/samestruct2interface.tracedecorator.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/generated/monitor/sameenum1interface.tracedecorator.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/generated/monitor/sameenum2interface.tracedecorator.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/generated/monitor/samestruct1interface.tracedecorator.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/generated/monitor/samestruct2interface.tracedecorator.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/generated/monitor/sameenum1interface.tracedecorator.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/generated/monitor/sameenum2interface.tracedecorator.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/generated/monitor/simpleinterface.tracedecorator.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/generated/monitor/simplearrayinterface.tracedecorator.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/generated/monitor/structinterface.tracedecorator.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/generated/monitor/structarrayinterface.tracedecorator.h"
#include "apigear/tracer/tracer.h"

using namespace Test;

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleApp");
    
    auto testbed2ManyParamInterface = std::make_unique<Testbed2::ManyParamInterface>();
    auto testbed2ManyParamInterfaceTraced = Testbed2::ManyParamInterfaceTraceDecorator::connect(*testbed2ManyParamInterface , tracer);
    
    auto testbed2NestedStruct1Interface = std::make_unique<Testbed2::NestedStruct1Interface>();
    auto testbed2NestedStruct1InterfaceTraced = Testbed2::NestedStruct1InterfaceTraceDecorator::connect(*testbed2NestedStruct1Interface , tracer);
    
    auto testbed2NestedStruct2Interface = std::make_unique<Testbed2::NestedStruct2Interface>();
    auto testbed2NestedStruct2InterfaceTraced = Testbed2::NestedStruct2InterfaceTraceDecorator::connect(*testbed2NestedStruct2Interface , tracer);
    
    auto testbed2NestedStruct3Interface = std::make_unique<Testbed2::NestedStruct3Interface>();
    auto testbed2NestedStruct3InterfaceTraced = Testbed2::NestedStruct3InterfaceTraceDecorator::connect(*testbed2NestedStruct3Interface , tracer);
    
    auto tbEnumEnumInterface = std::make_unique<TbEnum::EnumInterface>();
    auto tbEnumEnumInterfaceTraced = TbEnum::EnumInterfaceTraceDecorator::connect(*tbEnumEnumInterface , tracer);
    
    auto tbSame1SameStruct1Interface = std::make_unique<TbSame1::SameStruct1Interface>();
    auto tbSame1SameStruct1InterfaceTraced = TbSame1::SameStruct1InterfaceTraceDecorator::connect(*tbSame1SameStruct1Interface , tracer);
    
    auto tbSame1SameStruct2Interface = std::make_unique<TbSame1::SameStruct2Interface>();
    auto tbSame1SameStruct2InterfaceTraced = TbSame1::SameStruct2InterfaceTraceDecorator::connect(*tbSame1SameStruct2Interface , tracer);
    
    auto tbSame1SameEnum1Interface = std::make_unique<TbSame1::SameEnum1Interface>();
    auto tbSame1SameEnum1InterfaceTraced = TbSame1::SameEnum1InterfaceTraceDecorator::connect(*tbSame1SameEnum1Interface , tracer);
    
    auto tbSame1SameEnum2Interface = std::make_unique<TbSame1::SameEnum2Interface>();
    auto tbSame1SameEnum2InterfaceTraced = TbSame1::SameEnum2InterfaceTraceDecorator::connect(*tbSame1SameEnum2Interface , tracer);
    
    auto tbSame2SameStruct1Interface = std::make_unique<TbSame2::SameStruct1Interface>();
    auto tbSame2SameStruct1InterfaceTraced = TbSame2::SameStruct1InterfaceTraceDecorator::connect(*tbSame2SameStruct1Interface , tracer);
    
    auto tbSame2SameStruct2Interface = std::make_unique<TbSame2::SameStruct2Interface>();
    auto tbSame2SameStruct2InterfaceTraced = TbSame2::SameStruct2InterfaceTraceDecorator::connect(*tbSame2SameStruct2Interface , tracer);
    
    auto tbSame2SameEnum1Interface = std::make_unique<TbSame2::SameEnum1Interface>();
    auto tbSame2SameEnum1InterfaceTraced = TbSame2::SameEnum1InterfaceTraceDecorator::connect(*tbSame2SameEnum1Interface , tracer);
    
    auto tbSame2SameEnum2Interface = std::make_unique<TbSame2::SameEnum2Interface>();
    auto tbSame2SameEnum2InterfaceTraced = TbSame2::SameEnum2InterfaceTraceDecorator::connect(*tbSame2SameEnum2Interface , tracer);
    
    auto tbSimpleSimpleInterface = std::make_unique<TbSimple::SimpleInterface>();
    auto tbSimpleSimpleInterfaceTraced = TbSimple::SimpleInterfaceTraceDecorator::connect(*tbSimpleSimpleInterface , tracer);
    
    auto tbSimpleSimpleArrayInterface = std::make_unique<TbSimple::SimpleArrayInterface>();
    auto tbSimpleSimpleArrayInterfaceTraced = TbSimple::SimpleArrayInterfaceTraceDecorator::connect(*tbSimpleSimpleArrayInterface , tracer);
    
    auto testbed1StructInterface = std::make_unique<Testbed1::StructInterface>();
    auto testbed1StructInterfaceTraced = Testbed1::StructInterfaceTraceDecorator::connect(*testbed1StructInterface , tracer);
    
    auto testbed1StructArrayInterface = std::make_unique<Testbed1::StructArrayInterface>();
    auto testbed1StructArrayInterfaceTraced = Testbed1::StructArrayInterfaceTraceDecorator::connect(*testbed1StructArrayInterface , tracer);

    return 0;
}

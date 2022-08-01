#include <iostream>
#include "testbed2/generated/olink/remotemanyparaminterface.h"
#include "testbed2/generated/monitor/manyparaminterface.tracedecorator.h"
#include "testbed2/generated/olink/remotenestedstruct1interface.h"
#include "testbed2/generated/monitor/nestedstruct1interface.tracedecorator.h"
#include "testbed2/generated/olink/remotenestedstruct2interface.h"
#include "testbed2/generated/monitor/nestedstruct2interface.tracedecorator.h"
#include "testbed2/generated/olink/remotenestedstruct3interface.h"
#include "testbed2/generated/monitor/nestedstruct3interface.tracedecorator.h"
#include "tb_enum/generated/olink/remoteenuminterface.h"
#include "tb_enum/generated/monitor/enuminterface.tracedecorator.h"
#include "tb_same1/generated/olink/remotesamestruct1interface.h"
#include "tb_same1/generated/monitor/samestruct1interface.tracedecorator.h"
#include "tb_same1/generated/olink/remotesamestruct2interface.h"
#include "tb_same1/generated/monitor/samestruct2interface.tracedecorator.h"
#include "tb_same1/generated/olink/remotesameenum1interface.h"
#include "tb_same1/generated/monitor/sameenum1interface.tracedecorator.h"
#include "tb_same1/generated/olink/remotesameenum2interface.h"
#include "tb_same1/generated/monitor/sameenum2interface.tracedecorator.h"
#include "tb_same2/generated/olink/remotesamestruct1interface.h"
#include "tb_same2/generated/monitor/samestruct1interface.tracedecorator.h"
#include "tb_same2/generated/olink/remotesamestruct2interface.h"
#include "tb_same2/generated/monitor/samestruct2interface.tracedecorator.h"
#include "tb_same2/generated/olink/remotesameenum1interface.h"
#include "tb_same2/generated/monitor/sameenum1interface.tracedecorator.h"
#include "tb_same2/generated/olink/remotesameenum2interface.h"
#include "tb_same2/generated/monitor/sameenum2interface.tracedecorator.h"
#include "tb_simple/generated/olink/remotesimpleinterface.h"
#include "tb_simple/generated/monitor/simpleinterface.tracedecorator.h"
#include "tb_simple/generated/olink/remotesimplearrayinterface.h"
#include "tb_simple/generated/monitor/simplearrayinterface.tracedecorator.h"
#include "testbed1/generated/olink/remotestructinterface.h"
#include "testbed1/generated/monitor/structinterface.tracedecorator.h"
#include "testbed1/generated/olink/remotestructarrayinterface.h"
#include "testbed1/generated/monitor/structarrayinterface.tracedecorator.h"
#include "apigear/olink/olinkclient.h"
#include "apigear/tracer/tracer.h"

using namespace Test;

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleOLinkApp");
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::PocoImpl::OLinkClient testClient(registry);
    
    auto remoteTestbed2ManyParamInterface = std::make_unique<Testbed2::RemoteManyParamInterface>(registry, testClient);
    auto testbed2ManyParamInterfaceTraced = Testbed2::ManyParamInterfaceTraceDecorator::connect(*remoteTestbed2ManyParamInterface, tracer);
    
    auto remoteTestbed2NestedStruct1Interface = std::make_unique<Testbed2::RemoteNestedStruct1Interface>(registry, testClient);
    auto testbed2NestedStruct1InterfaceTraced = Testbed2::NestedStruct1InterfaceTraceDecorator::connect(*remoteTestbed2NestedStruct1Interface, tracer);
    
    auto remoteTestbed2NestedStruct2Interface = std::make_unique<Testbed2::RemoteNestedStruct2Interface>(registry, testClient);
    auto testbed2NestedStruct2InterfaceTraced = Testbed2::NestedStruct2InterfaceTraceDecorator::connect(*remoteTestbed2NestedStruct2Interface, tracer);
    
    auto remoteTestbed2NestedStruct3Interface = std::make_unique<Testbed2::RemoteNestedStruct3Interface>(registry, testClient);
    auto testbed2NestedStruct3InterfaceTraced = Testbed2::NestedStruct3InterfaceTraceDecorator::connect(*remoteTestbed2NestedStruct3Interface, tracer);
    
    auto remoteTbEnumEnumInterface = std::make_unique<TbEnum::RemoteEnumInterface>(registry, testClient);
    auto tbEnumEnumInterfaceTraced = TbEnum::EnumInterfaceTraceDecorator::connect(*remoteTbEnumEnumInterface, tracer);
    
    auto remoteTbSame1SameStruct1Interface = std::make_unique<TbSame1::RemoteSameStruct1Interface>(registry, testClient);
    auto tbSame1SameStruct1InterfaceTraced = TbSame1::SameStruct1InterfaceTraceDecorator::connect(*remoteTbSame1SameStruct1Interface, tracer);
    
    auto remoteTbSame1SameStruct2Interface = std::make_unique<TbSame1::RemoteSameStruct2Interface>(registry, testClient);
    auto tbSame1SameStruct2InterfaceTraced = TbSame1::SameStruct2InterfaceTraceDecorator::connect(*remoteTbSame1SameStruct2Interface, tracer);
    
    auto remoteTbSame1SameEnum1Interface = std::make_unique<TbSame1::RemoteSameEnum1Interface>(registry, testClient);
    auto tbSame1SameEnum1InterfaceTraced = TbSame1::SameEnum1InterfaceTraceDecorator::connect(*remoteTbSame1SameEnum1Interface, tracer);
    
    auto remoteTbSame1SameEnum2Interface = std::make_unique<TbSame1::RemoteSameEnum2Interface>(registry, testClient);
    auto tbSame1SameEnum2InterfaceTraced = TbSame1::SameEnum2InterfaceTraceDecorator::connect(*remoteTbSame1SameEnum2Interface, tracer);
    
    auto remoteTbSame2SameStruct1Interface = std::make_unique<TbSame2::RemoteSameStruct1Interface>(registry, testClient);
    auto tbSame2SameStruct1InterfaceTraced = TbSame2::SameStruct1InterfaceTraceDecorator::connect(*remoteTbSame2SameStruct1Interface, tracer);
    
    auto remoteTbSame2SameStruct2Interface = std::make_unique<TbSame2::RemoteSameStruct2Interface>(registry, testClient);
    auto tbSame2SameStruct2InterfaceTraced = TbSame2::SameStruct2InterfaceTraceDecorator::connect(*remoteTbSame2SameStruct2Interface, tracer);
    
    auto remoteTbSame2SameEnum1Interface = std::make_unique<TbSame2::RemoteSameEnum1Interface>(registry, testClient);
    auto tbSame2SameEnum1InterfaceTraced = TbSame2::SameEnum1InterfaceTraceDecorator::connect(*remoteTbSame2SameEnum1Interface, tracer);
    
    auto remoteTbSame2SameEnum2Interface = std::make_unique<TbSame2::RemoteSameEnum2Interface>(registry, testClient);
    auto tbSame2SameEnum2InterfaceTraced = TbSame2::SameEnum2InterfaceTraceDecorator::connect(*remoteTbSame2SameEnum2Interface, tracer);
    
    auto remoteTbSimpleSimpleInterface = std::make_unique<TbSimple::RemoteSimpleInterface>(registry, testClient);
    auto tbSimpleSimpleInterfaceTraced = TbSimple::SimpleInterfaceTraceDecorator::connect(*remoteTbSimpleSimpleInterface, tracer);
    
    auto remoteTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::RemoteSimpleArrayInterface>(registry, testClient);
    auto tbSimpleSimpleArrayInterfaceTraced = TbSimple::SimpleArrayInterfaceTraceDecorator::connect(*remoteTbSimpleSimpleArrayInterface, tracer);
    
    auto remoteTestbed1StructInterface = std::make_unique<Testbed1::RemoteStructInterface>(registry, testClient);
    auto testbed1StructInterfaceTraced = Testbed1::StructInterfaceTraceDecorator::connect(*remoteTestbed1StructInterface, tracer);
    
    auto remoteTestbed1StructArrayInterface = std::make_unique<Testbed1::RemoteStructArrayInterface>(registry, testClient);
    auto testbed1StructArrayInterfaceTraced = Testbed1::StructArrayInterfaceTraceDecorator::connect(*remoteTestbed1StructArrayInterface, tracer);
    
    testClient.connectToHost(Poco::URI("ws://localhost:8000"));

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            keepRunning = false;
            testClient.disconnect();
        }
    } while(keepRunning);

    return 0;
}

"use strict";(self.webpackChunkdocs=self.webpackChunkdocs||[]).push([[536],{8652:(e,n,t)=>{t.d(n,{Z:()=>a});var i=t(7294),o=t(4996);function a(e){let{src:n,caption:t}=e;return i.createElement("figure",{style:{padding:0}},i.createElement("img",{src:(0,o.Z)(n),alt:t}),i.createElement("figcaption",null,`Figure: ${t}`))}},1895:(e,n,t)=>{t.r(n),t.d(n,{assets:()=>k,contentTitle:()=>h,default:()=>b,frontMatter:()=>u,metadata:()=>m,toc:()=>g});var i=t(7462),o=(t(7294),t(3905)),a=t(814),l=t(7784);const r="class IObjectSink {\npublic:\n    virtual std::string olinkObjectName() = 0;\n    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) = 0;\n    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) = 0;\n    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode* node) = 0;\n    virtual void olinkOnRelease() = 0;\n};",s="class  IObjectSource {\npublic:\n    virtual std::string olinkObjectName() = 0;\n    virtual nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) = 0;\n    virtual void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) = 0;\n    virtual void olinkLinked(const std::string& objectId, IRemoteNode* node) = 0;\n    virtual void olinkUnlinked(const std::string& objectId) = 0;\n    virtual nlohmann::json olinkCollectProperties() = 0;\n};\n",c='#include <iostream>\n#include "io_world/generated/olink/helloclient.h"\n#include "apigear/olink/olinkconnection.h"\n#include "apigear/tracer/tracer.h"\n#include "apigear/olink/olinklogadapter.h"\n#include "olink/clientregistry.h"\n#include "olink/clientnode.h"\n#include "apigear/olink/olinkconnection.h"\n#include <iostream>\n\n\nusing namespace HelloWorldExample;\n\nint main() {\n    // Create a global registry.\n    ApiGear::ObjectLink::ClientRegistry registry;\n    // Create a client and make a connection\n    ApiGear::PocoImpl::OlinkConnection client(registry);\n    // Create your client and request linking, which will try to connect with a server side for this object.\n    auto ioWorldHello = std::make_shared<IoWorld::olink::HelloClient>();\n\n    client.connectAndLinkObject(ioWorldHello);\n    client.connectToHost(Poco::URI("ws://localhost:8182"));\n\n    // Or subscribe for signals.\n    ioWorldHello->_getPublisher().subscribeToJustSaid([](auto& /*args*/) { std::cout << "Just said received" << std::endl; });\n    ioWorldHello->_getPublisher().subscribeToLastChanged([](auto& /*args*/) { std::cout << "Last Changed" << std::endl; });\n\n\n    bool keepRunning = true;\n    std::string cmd;\n    do {\n        std::cout << "Enter command:" << std::endl;\n        getline(std::cin, cmd);\n\n        if (cmd == "quit") {\n            keepRunning = false;\n            client.disconnect();\n        }\n    } while (keepRunning);\n    client.disconnectAndUnlink(ioWorldHello->olinkObjectName());\n\n    return 0;\n}\n',p="cmake_minimum_required(VERSION 3.1)\nproject(OLinkClientSimuExample)\n\n# append local binary directory for conan packages to be found\nlist(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})\n\nset(CMAKE_CXX_STANDARD 14)\nset(CMAKE_CXX_STANDARD_REQUIRED ON)\n\nset (SOURCES\n    main.cpp\n)\nadd_executable(OLinkClientSimuExample\n    ${SOURCES}\n)\n\n# ensure maximum compiler support\nif(NOT MSVC)\n  target_compile_options(OLinkClientSimuExample PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)\nelse()\n  target_compile_options(OLinkClientSimuExample PRIVATE /W4 /WX /wd4251)\n  # disable the warning for getenv - needs better cross platform solution\n  target_compile_definitions(OLinkClientSimuExample PRIVATE -D_CRT_SECURE_NO_WARNINGS)\nendif()\n\nfind_package(io_world QUIET COMPONENTS io_world-core io_world-implementation io_world-monitor io_world-olink)\ntarget_link_libraries(OLinkClientSimuExample\n    io_world::io_world-core\n    io_world::io_world-implementation\n    io_world::io_world-monitor\n    io_world::io_world-olink\n)\n\ninstall(TARGETS OLinkClientSimuExample\n        RUNTIME DESTINATION bin COMPONENT Runtime)\n",d='schema: apigear.scenario/1.0\nname: "first scenario"\nversion: "1.0.0"\n#initial properties and setting gunction response\ninterfaces:\n  - name: io.world.Hello #( module io.world and interface Hello combination)\n    properties:\n      last: {content: "Initial"}\n    operations:\n      - name: say\n        actions:\n         - $return: { value: 88  }\n# sequence of changing properties and emitting signals\nsequences:\n  - name: play with hello\n    interval: 2000 # 2 seconds\n    interface: io.world.Hello\n    loops: 3 \n    steps: # step is called every 2 secs according to interval\n      - name: change property\n        actions: \n          - $set: { last: {content: "First Change of Property"} }\n      - name: emit signal\n        actions: \n          - $signal: { justSaid: [ {content: "First Message"} ] }\n      - name: change property AND emit signal\n        actions:\n          - $set: { last: {content: "Second Change of Property"} }\n          - $signal: { justSaid: [ {content: "Other Signal"} ] }\n\n\n';t(8652);const u={sidebar_position:3},h="Olink",m={unversionedId:"features/olink",id:"features/olink",title:"Olink",description:"This feature provides a client and a server adapter for your interfaces for the ObjectLink protocol. It allows you to connect different applications in the same or different technologies (check all of our templates).",source:"@site/docs/features/olink.md",sourceDirName:"features",slug:"/features/olink",permalink:"/template-cpp14/features/olink",draft:!1,editUrl:"https://github.com/apigear-io/template-cpp14/edit/main/docs/features/olink.md",tags:[],version:"current",lastUpdatedBy:"dphan10",lastUpdatedAt:1700746132,formattedLastUpdatedAt:"Nov 23, 2023",sidebarPosition:3,frontMatter:{sidebar_position:3},sidebar:"docsSidebar",previous:{title:"MQTT",permalink:"/template-cpp14/features/mqtt"},next:{title:"Monitor",permalink:"/template-cpp14/features/monitor"}},k={},g=[{value:"Apigear ObjectLink protocol and ObjectLink core library",id:"apigear-objectlink-protocol-and-objectlink-core-library",level:3},{value:"File overview for module",id:"file-overview-for-module",level:2},{value:"cpp apigear - The Network Layer",id:"cpp-apigear---the-network-layer",level:3},{value:"Olink Client Adapter",id:"olink-client-adapter",level:3},{value:"Properties",id:"properties",level:4},{value:"Operations",id:"operations",level:4},{value:"Signals",id:"signals",level:4},{value:"Use <code>HelloClient</code>",id:"use-helloclient",level:4},{value:"Olink Server Adapter",id:"olink-server-adapter",level:3},{value:"Properties",id:"properties-1",level:4},{value:"Operations",id:"operations-1",level:4},{value:"Signals",id:"signals-1",level:4},{value:"Use <code>OLinkHelloAdapter</code>",id:"use-olinkhelloadapter",level:4},{value:"Simulation",id:"simulation",level:2},{value:"Prepare your application",id:"prepare-your-application",level:3},{value:"Prepare the scenario",id:"prepare-the-scenario",level:3},{value:"Run the simulation",id:"run-the-simulation",level:3}],y={toc:g},f="wrapper";function b(e){let{components:n,...t}=e;return(0,o.kt)(f,(0,i.Z)({},y,t,{components:n,mdxType:"MDXLayout"}),(0,o.kt)("h1",{id:"olink"},"Olink"),(0,o.kt)("p",null," This feature provides a ",(0,o.kt)("em",{parentName:"p"},"client")," and a ",(0,o.kt)("em",{parentName:"p"},"server")," adapter for your interfaces for the ",(0,o.kt)("a",{parentName:"p",href:"https://docs.apigear.io/objectlink/"},"ObjectLink")," protocol. It allows you to connect different applications in the same or different technologies (check all of our ",(0,o.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/category/sdk-templates"},"templates"),").",(0,o.kt)("br",null),"\nUse an ",(0,o.kt)("em",{parentName:"p"},"OLink client")," instead of your interface implementation to connect to a remote service, or to a the ",(0,o.kt)("a",{parentName:"p",href:"olink#simulation"},"ApiGear simulation"),".  Use an ",(0,o.kt)("em",{parentName:"p"},"OLink server adapter")," to expose your interface implementation as a remote service.",(0,o.kt)("br",null),"\nBelow you'll find short introduction on ",(0,o.kt)("inlineCode",{parentName:"p"},"ApiGear ObjectLink")," protocol. Before details on client and server, you'll also find piece of information on a network layer implementation for handling ObjectLink in ",(0,o.kt)("inlineCode",{parentName:"p"},"template-cpp"),". "),(0,o.kt)("admonition",{type:"note"},(0,o.kt)("p",{parentName:"admonition"}," The ",(0,o.kt)("inlineCode",{parentName:"p"},"OLink client")," and the ",(0,o.kt)("inlineCode",{parentName:"p"},"OLink server")," objects are ready-to-use as they are, they don't' need any extra implementation.\nIf you want quickly start working with them go to use sections of ",(0,o.kt)("a",{parentName:"p",href:"olink#use-olinkhello"},"client"),", ",(0,o.kt)("a",{parentName:"p",href:"olink#use-olinkhelloadapter"},"server"),".")),(0,o.kt)("h3",{id:"apigear-objectlink-protocol-and-objectlink-core-library"},"Apigear ObjectLink protocol and ObjectLink core library"),(0,o.kt)("p",null,"The ",(0,o.kt)("a",{parentName:"p",href:"https://docs.apigear.io/objectlink/"},"ObjectLink")," protocol is a lightweight protocol for the Objects described with an interface. It allows connecting a client object with a server object, and perform remote operations like: remote property change request (client) or notifications on property changed (server), inform about signal emission (server) and allows requesting a call of a method (client) and giving a response to the outcome (server)."),(0,o.kt)("p",null,"The Olink feature for your interface uses a library ",(0,o.kt)("a",{parentName:"p",href:"https://github.com/apigear-io/objectlink-core-cpp"},"ObjectLink core"),", common for cpp based templates. The provided CMakeLists already contain all the dependencies, so you don't have to add it manually."),(0,o.kt)("p",null,"The library provides an abstraction layer for handling the protocol, independent of the actual network stack. It encodes and decodes the messages and routes them to corresponding objects stored in its registry. The setup is minimal: instantiate the registries (for client and/or server) and pass them to network layer objects in ",(0,o.kt)("a",{parentName:"p",href:"olink#cpp-apigear---the-network-layer"},"cpp apigear library")," "),(0,o.kt)("admonition",{type:"caution"},(0,o.kt)("p",{parentName:"admonition"}," In this library we use STL classes in public interfaces.\nWe assume that this library is built from source (configuration provided by generated CMakeLists).\nOtherwise, it has to be ensured that your build configuration matches the library build configuration.")),(0,o.kt)("h2",{id:"file-overview-for-module"},"File overview for module"),(0,o.kt)("p",null," With an example  API"),(0,o.kt)("details",null,(0,o.kt)("summary",null,"Hello World API (click to expand)"),(0,o.kt)(a.Z,{language:"yaml",showLineNumbers:!0,mdxType:"CodeBlock"},l.Z)),(0,o.kt)("p",null,"the following file structure will be generated. The purpose and content of each file is explained below."),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-bash",metastring:"{7,24}","{7,24}":!0},"\ud83d\udcc2hello-world\n \u2523 \ud83d\udcc2apigear\n \u2503 ...\n \u2523 \ud83d\udcc2cpp_hello_world\n \u2503 \u2523 \ud83d\udcc2apigear\n \u2503 \u2503 \u2523 \ud83d\udcc2mqtt\n \u2503 \u2503 \u2523 \ud83d\udcc2olink\n \u2503 \u2503 \u2503 \u2523 \ud83d\udcc2private\n \u2503 \u2503 \u2503 \u2523 \ud83d\udcdcCMakeLists.txt\n \u2503 \u2503 \u2503 \u2523 \ud83d\udcdcolinkconnection.cpp\n \u2503 \u2503 \u2503 \u2523 \ud83d\udcdcolinkconnection.h\n \u2503 \u2503 \u2503 \u2523 \ud83d\udcdcolinkhost.cpp\n \u2503 \u2503 \u2503 \u2523 \ud83d\udcdcolinkhost.h\n \u2503 \u2503 \u2503 \u2523 ... (helper files)\n \u2503 \u2503 ... \n \u2503 \u2523 \ud83d\udcc2examples\n \u2503 \u2523 \ud83d\udcc2modules\n \u2503 \u2503   \u2517 \ud83d\udcc2io_world_module\n \u2503 \u2503      \u2517 \ud83d\udcc2io_world\n \u2503 \u2503         \u2523 \ud83d\udcc2generated\n \u2503 \u2503         \u2503  \u2523 \ud83d\udcc2api\n \u2503 \u2503         \u2503  \u2523 \ud83d\udcc2core\n \u2503 \u2503         \u2503  \u2523 \ud83d\udcc2mqtt\n \u2503 \u2503         \u2503  \u2523 \ud83d\udcc2olink\n \u2503 \u2503         \u2503  \u2503 \u2523 \ud83d\udcdcCMakeLists.txt\n \u2503 \u2503         \u2503  \u2503 \u2523 \ud83d\udcdchelloclient.cpp\n \u2503 \u2503         \u2503  \u2503 \u2523 \ud83d\udcdchelloclient.h\n \u2503 \u2503         \u2503  \u2503 \u2523 \ud83d\udcdchelloservice.cpp\n \u2503 \u2503         \u2503  \u2503 \u2517 \ud83d\udcdchelloservice.h\n \u2503 \u2523 \ud83d\udcdc Lifecycle for olink client-server implementation.md\n ...\n")),(0,o.kt)("admonition",{type:"note"},(0,o.kt)("p",{parentName:"admonition"},"You may notice an extra document: ",(0,o.kt)("inlineCode",{parentName:"p"},"\ud83d\udcdcLifecycle for olink client-server implementation.md")," which explains life cycle of main objects used when using an olink protocol, in a form of flow diagrams.")),(0,o.kt)("h3",{id:"cpp-apigear---the-network-layer"},"cpp apigear - The Network Layer"),(0,o.kt)("p",null,"When generating the olink feature (or monitor feature) you'll get an additional folder it the top most directory: the ",(0,o.kt)("inlineCode",{parentName:"p"},"\ud83d\udcc2hello-world/cpp_hello_world/apigear"),". The ",(0,o.kt)("inlineCode",{parentName:"p"},"\ud83d\udcc2olink")," subfolder contains objects that implement a network layer (based on ",(0,o.kt)("a",{parentName:"p",href:"https://docs.pocoproject.org/current/Poco.Net.html"},"Poco")," library) for the ObjectLink protocol. Those are:"),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},"OlinkClient - the client, that serves your ",(0,o.kt)("a",{parentName:"li",href:"olink#olink-client-adapter"},"interface client adapters"),".\nThe class is responsible for network connection for ObjectLink client side. It uses the ObjectLink core library for handling messages according to the ObjectLink protocol. Handles linking and unlinking with a remote service for the sink added by the user (the interface OlinkClient Adapters), with regard to the connection state. All the messages dedicated to your object will be delivered to the adapter and proper actions will be performed for the clients that use it, without any of your actions. Also the OlinkClient holds a message queue for messages during disconnected time."),(0,o.kt)("li",{parentName:"ul"},"OlinkHost and a helper class OlinkRemote that you'll find in ",(0,o.kt)("inlineCode",{parentName:"li"},"\ud83d\udcc2private")," subfolder- the server, which hosts your services exposed to network through the ",(0,o.kt)("a",{parentName:"li",href:"olink#olink-server-adapter"},"interface server adapters"),". The class is responsible to set up the server and manage connections requested by clients. It uses ObjectLink core library for handling messages according to the ObjectLink protocol. All incoming messages will be translated to calls and routed to your local object.")),(0,o.kt)("h3",{id:"olink-client-adapter"},"Olink Client Adapter"),(0,o.kt)("p",null,"Files ",(0,o.kt)("inlineCode",{parentName:"p"},"\ud83d\udcdchelloclient.h")," and ",(0,o.kt)("inlineCode",{parentName:"p"},"\ud83d\udcdchelloclient.cpp")," contain the olink client version of the ",(0,o.kt)("inlineCode",{parentName:"p"},"Hello")," interface - an ",(0,o.kt)("inlineCode",{parentName:"p"},"HelloClient")," class.",(0,o.kt)("br",null),"\nIt implements two interfaces: ",(0,o.kt)("inlineCode",{parentName:"p"},"IHello")," and a ",(0,o.kt)("inlineCode",{parentName:"p"},"IObjectSink"),". ",(0,o.kt)("br",null),"\nThe IObjectSink interface comes from ",(0,o.kt)("a",{parentName:"p",href:"https://github.com/apigear-io/objectlink-core-cpp"},"ObjectLink core"),":"),(0,o.kt)("details",null,(0,o.kt)("summary",null,"IObjectSink (click to expand)"),(0,o.kt)(a.Z,{language:"cpp",mdxType:"CodeBlock"},r)),(0,o.kt)("p",null,"and is necessary for handling incoming messages from the server side and is used by a ",(0,o.kt)("inlineCode",{parentName:"p"},"OLinkClient")," (",(0,o.kt)("a",{parentName:"p",href:"olink#cpp-apigear---The-Network-Layer"},"cpp Apigear Olink lib"),"). Apart from setting up and tear down of the ",(0,o.kt)("inlineCode",{parentName:"p"},"OLinkHello")," object, you don't need to perform any additional actions, the object ",(0,o.kt)("inlineCode",{parentName:"p"},"OLinkHello")," will communicate with the server transparently and you should use it as an ",(0,o.kt)("inlineCode",{parentName:"p"},"IHello")," Object only."),(0,o.kt)("h4",{id:"properties"},"Properties"),(0,o.kt)("p",null,"The property getters (here ",(0,o.kt)("inlineCode",{parentName:"p"},"Message last()")," ) return immediately the locally stored last received value from server. ",(0,o.kt)("br",null),"\nThe property setter (here ",(0,o.kt)("inlineCode",{parentName:"p"},"void setLast(const Message& last)")," ) requests setting a value on server side, local value is not changed. ",(0,o.kt)("br",null),"\nYou can subscribe to a property changed (here ",(0,o.kt)("inlineCode",{parentName:"p"},"last")," property ) through the publisher you can get from the ",(0,o.kt)("inlineCode",{parentName:"p"},"HelloClient")," with ",(0,o.kt)("inlineCode",{parentName:"p"},"_getPublisher()"),".\nOr you can subscribe (instead of the above) for as an IHelloSubscriber to receive all changes (and signals).\nWhen the client receives information that server changed the property, a target property (here ",(0,o.kt)("inlineCode",{parentName:"p"},"last"),") is updated locally and a notifies subscribers that property has changed."),(0,o.kt)("admonition",{type:"note"},(0,o.kt)("p",{parentName:"admonition"},"The connected client has its local properties initialized - on a successful linking client with server the client receives a message with current state of properties of the service on server side.")),(0,o.kt)("h4",{id:"operations"},"Operations"),(0,o.kt)("p",null,"The operations have additionally the async version, which is called by the immediate version.",(0,o.kt)("br",null),"\nThe async version sends an invoke operation request to a server.",(0,o.kt)("br",null),"\nSo calling ",(0,o.kt)("inlineCode",{parentName:"p"},"myOlinkHelloInstance.say(myWhen)")," implements execution of ",(0,o.kt)("inlineCode",{parentName:"p"},"sayAsync")," and waits for the result (for non-void type of operations). Have in mind that this is a blocking operation."),(0,o.kt)("h4",{id:"signals"},"Signals"),(0,o.kt)("p",null,"You should not emit any signals from a client.\nYou can connect to any signals offered by your interface (here ",(0,o.kt)("inlineCode",{parentName:"p"},"void justSaid(const Message& msg)")," ), through the publisher. You can either select the signal you're interested in, or subscribe as an IHelloSubscriber to get all the signals and property change notifications.\nWhen a HelloClient client receives the message from server that indicates the signal was emitted it emits a signal (here ",(0,o.kt)("inlineCode",{parentName:"p"},"justSaid"),")."),(0,o.kt)("h4",{id:"use-helloclient"},"Use ",(0,o.kt)("inlineCode",{parentName:"h4"},"HelloClient")),(0,o.kt)("p",null,"As mentioned earlier you need a network layer, here provided by a ",(0,o.kt)("inlineCode",{parentName:"p"},"ApiGear::ObjectLink::OLinkClient")," which also contains the protocol handling ",(0,o.kt)("inlineCode",{parentName:"p"},"ClientNode"),". All you need to do is give it a global ",(0,o.kt)("inlineCode",{parentName:"p"},"ApiGear::ObjectLink::ClientRegistry"),", request connecting to host when it is convenient for you and then add your ",(0,o.kt)("inlineCode",{parentName:"p"},"HelloClient"),"."),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},'    ApiGear::ObjectLink::ClientRegistry registry;\n    ApiGear::ObjectLink::OLinkClient client(registry);\n\n    // Create a global registry.\n    ApiGear::ObjectLink::ClientRegistry registry;\n    // Create a client and make a connection\n    ApiGear::PocoImpl::OlinkConnection client(registry);\n    // Create your client and request linking, which will try to connect with a server side for this object.\n    auto ioWorldHello = std::make_shared<IoWorld::olink::HelloClient>();\n\n    client.connectAndLinkObject(ioWorldHello);    \n    client.connectToHost(Poco::URI("ws://localhost:8182"));\n\n    // You can try out properties\n    auto lastMessage = ioWorldHello->getLast();\n    // Executing the methods\n    ioWorldHello->say(lastMessage, IoWorld::WhenEnum::Soon);\n    IoWorld::Message someMessage("the new content");\n    ioWorldHello->setLast(someMessage);\n    // Or subscribe for signals.\n    ioWorldHello->_getPublisher().subscribeToJustSaid([](auto args) { /*handle the signal*/});\n\n    // remember to unlink your object if you won\'t use it anymore.\n    client.unlinkObjectSource(ioWorldHello->olinkObjectName());\n')),(0,o.kt)("admonition",{type:"caution"},(0,o.kt)("p",{parentName:"admonition"},"ApiGear::ObjectLink::ClientRegistry can have only one object of a certain type. This means that, to have more than one 'OlinkHello' objects you need to put them in different registries. Each Object has an identifier which is created based on the Interface Name, this way client object can be matched with proper server object.")),(0,o.kt)("h3",{id:"olink-server-adapter"},"Olink Server Adapter"),(0,o.kt)("p",null,"Files ",(0,o.kt)("inlineCode",{parentName:"p"},"\ud83d\udcdchelloservice.h")," and ",(0,o.kt)("inlineCode",{parentName:"p"},"\ud83d\udcdchelloservice.h")," contain the olink server adapter for the ",(0,o.kt)("inlineCode",{parentName:"p"},"Hello")," interface - the ",(0,o.kt)("inlineCode",{parentName:"p"},"HelloService")," class.",(0,o.kt)("br",null),"\nIt implements an ",(0,o.kt)("inlineCode",{parentName:"p"},"IObjectSource")," interface (from ",(0,o.kt)("a",{parentName:"p",href:"https://github.com/apigear-io/objectlink-core-cpp"},"ObjectLink core"),"), which wraps your ",(0,o.kt)("inlineCode",{parentName:"p"},"Hello")," and exposes it for remote usage with the ",(0,o.kt)("a",{parentName:"p",href:"https://docs.apigear.io/objectlink/"},"ObjectLink")," protocol. It handles all the network requests, and calls your local object.",(0,o.kt)("br",null),"\nWhen creating the ",(0,o.kt)("inlineCode",{parentName:"p"},"HelloService")," you need to provide the local ",(0,o.kt)("inlineCode",{parentName:"p"},"IHello")," service object, you want to expose to clients."),(0,o.kt)("p",null,"The IObjectSource interface:"),(0,o.kt)("details",null,(0,o.kt)("summary",null,"IObjectSource (click to expand)"),(0,o.kt)(a.Z,{language:"cpp",mdxType:"CodeBlock"},s)),(0,o.kt)("p",null,"After setting up the OlinkHost (cpp Apigear Olink lib) and registering your Interface registered, the client connections and communication with them is handled transparently for you, no additional actions are needed."),(0,o.kt)("admonition",{type:"note"},(0,o.kt)("p",{parentName:"admonition"},"All the received messages from the clients are handled in a thread in which the connection resides, this means that your object may be used from different threads (local and each connection).")),(0,o.kt)("h4",{id:"properties-1"},"Properties"),(0,o.kt)("p",null,"Each time a property changed signal (here ",(0,o.kt)("inlineCode",{parentName:"p"},"void lastChanged(const Message& last)")," ) is emitted, a message is sent to all connected clients with information, which property changed to which value. This may occur either when you change a property directly on your local ",(0,o.kt)("inlineCode",{parentName:"p"},"Hello")," object, or when a change property request message is received by the ",(0,o.kt)("inlineCode",{parentName:"p"},"HelloService"),", which applies the property on your local ",(0,o.kt)("inlineCode",{parentName:"p"},"Hello")," object."),(0,o.kt)("h4",{id:"operations-1"},"Operations"),(0,o.kt)("p",null,"The operations invocation which came from the clients through the network will be performed on your local ",(0,o.kt)("inlineCode",{parentName:"p"},"Hello")," object. The result of the operation (if any) will be returned only to a caller, not all clients. Have in mind that your object may be called from more that one thread."),(0,o.kt)("h4",{id:"signals-1"},"Signals"),(0,o.kt)("p",null,"All the signals emitted by your local ",(0,o.kt)("inlineCode",{parentName:"p"},"Hello")," objects are forwarded to all connected clients with an olink messages."),(0,o.kt)("h4",{id:"use-olinkhelloadapter"},"Use ",(0,o.kt)("inlineCode",{parentName:"h4"},"OLinkHelloAdapter")),(0,o.kt)("p",null,"As mentioned earlier you need a network layer, here provided by a ",(0,o.kt)("inlineCode",{parentName:"p"},"ApiGear::ObjectLink::OLinkHost")," which also contains the protocol handling ",(0,o.kt)("inlineCode",{parentName:"p"},"RemoteNodes"),". The ",(0,o.kt)("inlineCode",{parentName:"p"},"ApiGear::ObjectLink::OLinkRemote")," objects are created automatically per connection. All you need to do is give  a global ",(0,o.kt)("inlineCode",{parentName:"p"},"ApiGear::ObjectLink::RemoteRegistry")," with your ",(0,o.kt)("inlineCode",{parentName:"p"},"OLinkHelloAdapter")," in it to ",(0,o.kt)("inlineCode",{parentName:"p"},"ApiGear::ObjectLink::OLinkHost"),"."),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},'    ApiGear::ObjectLink::RemoteRegistry registry;\n    auto logFunction = [](auto /*level*/, auto /*msg*/){ };\n    ApiGear::PocoImpl::OLinkHost testserver(registry,logFunction);\n\n    auto ioWorldHello = std::make_shared<IoWorld::Hello>();\n    auto ioWorldOlinkHelloService = std::make_shared<IoWorld::olink::HelloService>(ioWorldHello, registry);\n    registry.addSource(ioWorldOlinkHelloService);\n    auto portNumber = 8000;\n    testserver.listen(portNumber);\n\n\n    // use your ioWorldHello as it was Hello implementation, all property changes, and signals will be passed to connected OLink clients.\n    auto lastMessage = ioWorldHello->getLast();\n    ioWorldHello->say(lastMessage, IoWorld::WhenEnum::Soon);\n    IoWorld::Message someMessage("the new content");\n    ioWorldHello->setLast(someMessage); // after this call - if new property is different than current one - all clients will be informed about new value.\n    testIoWorldHello->_getPublisher().publishJustSaid(someMessage);\n\n    // remember to remove from registry if you won\'t use it anymore.\n    registry.removeSource(ioWorldOlinkHelloService->olinkObjectName());\n')),(0,o.kt)("h2",{id:"simulation"},"Simulation"),(0,o.kt)("p",null," The simulation can be used to test, demonstrate or develop applications without the need to have the actual service available.\nThe simulation server is integrated into the ",(0,o.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/category/desktop-studio"},"ApiGear studio")," and the ",(0,o.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/cli/simulate"},"CLI"),"."),(0,o.kt)("p",null," For simulating you will use ",(0,o.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/advanced/simulation/scenario"},"simulation scenarios")," They allow to define sequences of actions. The actions can change the property values of the service or emit signals. The scenarios can be written using a YAML schema."),(0,o.kt)("p",null,"See more on ",(0,o.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/advanced/simulation/intro"},"simulation"),"."),(0,o.kt)("h3",{id:"prepare-your-application"},"Prepare your application"),(0,o.kt)("p",null,"Make sure you are using OlinkClient as your ",(0,o.kt)("inlineCode",{parentName:"p"},"Hello")," object, an instance on ",(0,o.kt)("a",{parentName:"p",href:"olink#olink-client-adapter"},"cpp side")),(0,o.kt)("p",null,"You may try our example, it subscribes for signals and property changes, with a simple logging function. Create new folder under ",(0,o.kt)("inlineCode",{parentName:"p"},"examples")," directory.\nPaste the below ",(0,o.kt)("inlineCode",{parentName:"p"},"main.cpp")," and ",(0,o.kt)("inlineCode",{parentName:"p"},"CMakeLists.txt")," files. Remember to add this directory to main ",(0,o.kt)("inlineCode",{parentName:"p"},"CMakeLists.txt")," (or to extend test_conan.bat/sh in case using conan)."),(0,o.kt)("details",null,(0,o.kt)("summary",null,"main.cpp (click to expand)"),(0,o.kt)(a.Z,{language:"yaml",showLineNumbers:!0,mdxType:"CodeBlock"},c)),(0,o.kt)("details",null,(0,o.kt)("summary",null,"CMAkeLists.txt (click to expand)"),(0,o.kt)(a.Z,{language:"yaml",showLineNumbers:!0,mdxType:"CodeBlock"},p)),(0,o.kt)("admonition",{type:"note"},(0,o.kt)("p",{parentName:"admonition"},"Make sure to configure the client to use the correct IP and port configuration of your simulation server e.g. set ",(0,o.kt)("inlineCode",{parentName:"p"},'client.connectToHost(QUrl("ws://127.0.0.1:8182/ws"));')," and make sure your apigear simulation also uses this port.")),(0,o.kt)("h3",{id:"prepare-the-scenario"},"Prepare the scenario"),(0,o.kt)("p",null,"As a starting point you can check our simulation scenario: "),(0,o.kt)("details",null,(0,o.kt)("summary",null,"Scenario(click to expand)"),(0,o.kt)(a.Z,{language:"yaml",showLineNumbers:!0,mdxType:"CodeBlock"},d)),(0,o.kt)("p",null,"Apart from the header with the scenario name and its version it consists of two parts:"),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},"initialization - for each interface (here, our ui.world.Hello line 6), we're setting initial values of properties(line 8) and the return value of function calls (line 12)"),(0,o.kt)("li",{parentName:"ul"},"sequence of events. You can prepare more than one sequence. For each of them set interval between calling each action (line 16), set how many runs of that sequence you want to execute (line 18) and name the interface the action should be applied to (line 17). In each action you may change many properties, and emit signals.")),(0,o.kt)("h3",{id:"run-the-simulation"},"Run the simulation"),(0,o.kt)("p",null,"Put your scenario file in the ",(0,o.kt)("inlineCode",{parentName:"p"},"\ud83d\udcc2hello-world/apigear"),"  along with other ",(0,o.kt)("inlineCode",{parentName:"p"},".yaml")," files.\nIf you are using the studio, reload your project. Go to ",(0,o.kt)("inlineCode",{parentName:"p"},"settings")," and make sure to set same the port as in your client app (here ",(0,o.kt)("inlineCode",{parentName:"p"},"8182"),").\nClick the ",(0,o.kt)("inlineCode",{parentName:"p"},"play")," button in the application in the ",(0,o.kt)("inlineCode",{parentName:"p"},"simulation")," tab to start the simulation scenario, then start the client application."),(0,o.kt)("p",null,"Instead of the Apigear Studio application can also use its console version, run your scenario with command:"),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-bash"},"apigear simulate run path-from-cli-to-scenario/helloworldtest.scenario.yaml --addr :8182\n")),(0,o.kt)("admonition",{type:"note"},(0,o.kt)("p",{parentName:"admonition"},"We tried some measurements for the OLink performance. You may want to check the ",(0,o.kt)("a",{parentName:"p",href:"https://github.com/apigear-io/performance-checks"},"our tests here"),". We're not providing any data of throughput and latency, as the branch is still in between alpha phase.\nIn general we expect it to be fast as it has small overhead (which may be not sufficient for you).")))}b.isMDXComponent=!0}}]);
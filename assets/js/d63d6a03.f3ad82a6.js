"use strict";(self.webpackChunkdocs=self.webpackChunkdocs||[]).push([[304],{8652:(e,t,a)=>{a.d(t,{Z:()=>i});var r=a(7294),n=a(4996);function i(e){let{src:t,caption:a}=e;return r.createElement("figure",{style:{padding:0}},r.createElement("img",{src:(0,n.Z)(t),alt:a}),r.createElement("figcaption",null,`Figure: ${a}`))}},451:(e,t,a)=>{a.r(t),a.d(t,{assets:()=>d,contentTitle:()=>p,default:()=>f,frontMatter:()=>l,metadata:()=>u,toc:()=>m});var r=a(7462),n=(a(7294),a(3905)),i=a(814),o=a(7784),s=a(8652);const l={},p="Features",u={unversionedId:"features/features",id:"features/features",title:"Features",description:"This guide explains how to use the generated code, what are the available features and  their benefits.",source:"@site/docs/features/features.md",sourceDirName:"features",slug:"/features/",permalink:"/template-cpp14/features/",draft:!1,editUrl:"https://github.com/apigear-io/template-cpp14/edit/main/docs/features/features.md",tags:[],version:"current",lastUpdatedBy:"dphan10",lastUpdatedAt:1700746132,formattedLastUpdatedAt:"Nov 23, 2023",frontMatter:{},sidebar:"docsSidebar",previous:{title:"Quick-Start",permalink:"/template-cpp14/quickstart/"},next:{title:"API",permalink:"/template-cpp14/features/api"}},d={},m=[{value:"Get started",id:"get-started",level:2},{value:"Code generation",id:"code-generation",level:3},{value:"Example API",id:"example-api",level:3},{value:"Features",id:"features-1",level:2},{value:"Core",id:"core",level:3},{value:"Extended",id:"extended",level:3},{value:"Folder structure",id:"folder-structure",level:2}],c={toc:m},h="wrapper";function f(e){let{components:t,...a}=e;return(0,n.kt)(h,(0,r.Z)({},c,a,{components:t,mdxType:"MDXLayout"}),(0,n.kt)("h1",{id:"features"},"Features"),(0,n.kt)("p",null,"This guide explains how to use the generated code, what are the available features and  their benefits."),(0,n.kt)("h2",{id:"get-started"},"Get started"),(0,n.kt)("p",null,"This template generates code for pure c++ projects. In order to successfully compile and use the code, you need to have any c++ compiler installed.\nBasic c++ knowledge is necessary."),(0,n.kt)("h3",{id:"code-generation"},"Code generation"),(0,n.kt)("p",null,"Follow the documentation for the ",(0,n.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/start/first_steps"},"code generation")," in general and ",(0,n.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/cli/generate"},"CLI")," or the ",(0,n.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/category/desktop-studio"},"Studio")," tools.\nOr try first the ",(0,n.kt)("a",{parentName:"p",href:"/template-cpp14/quickstart/"},"quick start guide")," which shows how to prepare api and generate code out of it."),(0,n.kt)("admonition",{type:"tip"},(0,n.kt)("p",{parentName:"admonition"},"For questions regarding this template please go to our ",(0,n.kt)("a",{parentName:"p",href:"https://github.com/orgs/apigear-io/discussions"},"discussions page"),". For feature requests or bug reports please use the ",(0,n.kt)("a",{parentName:"p",href:"https://github.com/apigear-io/template-cpp14/issues"},"issue tracker"),".")),(0,n.kt)("h3",{id:"example-api"},"Example API"),(0,n.kt)("p",null,"The following code snippet contains the ",(0,n.kt)("em",{parentName:"p"},"API")," which is used throughout this guide to demonstrate the generated code and its usage."),(0,n.kt)("details",null,(0,n.kt)("summary",null,"Hello World API (click to expand)"),(0,n.kt)(i.Z,{language:"yaml",showLineNumbers:!0,mdxType:"CodeBlock"},o.Z)),(0,n.kt)("h2",{id:"features-1"},"Features"),(0,n.kt)("h3",{id:"core"},"Core"),(0,n.kt)("p",null,"Features generate a view model for the ",(0,n.kt)("inlineCode",{parentName:"p"},"api"),". This can be used to implement a working ",(0,n.kt)("em",{parentName:"p"},"C++")," service and directly use it in your project."),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/template-cpp14/features/api"},"api")," - generates compilable base abstract interfaces for your 'api'', a basic implementation for data types and subscriber/publisher abstract classes that describe the notification system for users of your interfaces."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/template-cpp14/features/stubs"},"stubs")," - adds a basic stubs for the ",(0,n.kt)("inlineCode",{parentName:"li"},"api"),", you'll get classes that can actually be instantiated with a ready to use publishers, this is a starting point for your implementation."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/template-cpp14/features/conan"},"conan")," - a build and packaging support for your project. ")),(0,n.kt)("h3",{id:"extended"},"Extended"),(0,n.kt)("p",null,"Features can be used in combination with ",(0,n.kt)("inlineCode",{parentName:"p"},"api")," and add more functionality on top, like the simulation (see ",(0,n.kt)("a",{parentName:"p",href:"/template-cpp14/features/olink#simulation"},"olink"),")"),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/template-cpp14/features/olink"},"olink")," - provides a client and server adapters for each interface, that can be connected to any of the other technology templates with support for ",(0,n.kt)("a",{parentName:"li",href:"https://docs.apigear.io/objectlink/"},"ObjectLink"),". Use this feature to connect with ApiGear simulation tools."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/template-cpp14/features/monitor"},"monitor")," - generates a middle ware layer which logs all API events to the ",(0,n.kt)("a",{parentName:"li",href:"https://docs.apigear.io/docs/category/command-line"},"CLI")," or the ",(0,n.kt)("a",{parentName:"li",href:"https://docs.apigear.io/docs/category/desktop-studio"},"Studio")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/template-cpp14/features/mqtt"},"MQTT")," experimental - provides minimal working adapters for MQTT client and service side for each interfaces. Check also MQTT in other technology templates that supports it."),(0,n.kt)("li",{parentName:"ul"},"examples and examples_olink feature - generates:",(0,n.kt)("ul",{parentName:"li"},(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("inlineCode",{parentName:"li"},"olinkserver")," shows use of your interfaces as an olink services."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("inlineCode",{parentName:"li"},"olinkclient")," shows use of your interfaces as an olink clients."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("inlineCode",{parentName:"li"},"mqttserver")," shows use of your interfaces with mqtt adapted for your services."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("inlineCode",{parentName:"li"},"mqttclient")," shows use of your interfaces as a mqtt adapted for your services users."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("inlineCode",{parentName:"li"},"app")," simple example with stubs."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("inlineCode",{parentName:"li"},"appthreadsafe")," simple example with stubs wrapped with thread safe decorator. See ",(0,n.kt)("a",{parentName:"li",href:"/template-cpp14/features/stubs#core"},"thread safe decorator from core features"))))),(0,n.kt)(s.Z,{caption:"Overview of features for user application, including receiving data from network: Bottom floor shows possible inputs for your API, you can either obtain data from the network with OLink or MQTT or use local (thread safe if necessary) implementation.",src:"/img/features/featuresApp.png",mdxType:"Figure"}),(0,n.kt)("admonition",{type:"note"},(0,n.kt)("p",{parentName:"admonition"},"Theoretically you can use Thread Safe Decorator with other features that implements API: OLinkClient and MQTT Client, but they, already provide thread safety on at least same level as the Thread Safe Decorator.")),(0,n.kt)(s.Z,{caption:"Overview of features for user application, including publishing data through network: Topmost floor shows your options for using your local implementation (bottom floor): you can use it in your local app and/or use method of sharing the data with clients in the network. Consider then using thread safe version of your implementation.",src:"/img/features/featuresServer.png",mdxType:"Figure"}),(0,n.kt)("p",null,"There are also an ",(0,n.kt)("em",{parentName:"p"},"internal")," features:"),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("inlineCode",{parentName:"li"},"apigear"),", which is generated for the ",(0,n.kt)("em",{parentName:"li"},"extended")," features and is explained with them."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("inlineCode",{parentName:"li"},"core"),", which is generated for the stubs and the ",(0,n.kt)("em",{parentName:"li"},"extended")," features. For the explanation see ",(0,n.kt)("a",{parentName:"li",href:"/template-cpp14/features/stubs#core"},"core documentation"))),(0,n.kt)("p",null,"Each feature can be selected using the solution file or via command line tool."),(0,n.kt)("admonition",{type:"note"},(0,n.kt)("p",{parentName:"admonition"},(0,n.kt)("em",{parentName:"p"},"Features are case sensitive, make sure to always ",(0,n.kt)("strong",{parentName:"em"},"use lower-case.")," "))),(0,n.kt)("admonition",{type:"tip"},(0,n.kt)("p",{parentName:"admonition"},"The ",(0,n.kt)("em",{parentName:"p"},"meta")," feature ",(0,n.kt)("inlineCode",{parentName:"p"},"all")," enables all specified features of the template. If you want to see the full extent of the generated code ",(0,n.kt)("inlineCode",{parentName:"p"},"all")," is easiest solution.\nPlease note, ",(0,n.kt)("inlineCode",{parentName:"p"},"all")," is part of the code generator and not explicitly used within templates.")),(0,n.kt)("h2",{id:"folder-structure"},"Folder structure"),(0,n.kt)("p",null,"This graph shows the full folder structure which is generated for ",(0,n.kt)("inlineCode",{parentName:"p"},"all")," features enabled, but skips the ",(0,n.kt)("a",{parentName:"p",href:"/template-cpp14/features/conan"},"conan")," files. Generated features are encapsulated in separate folders for each module or for the common features like ",(0,n.kt)("inlineCode",{parentName:"p"},"examples")," and the internal helper feature ",(0,n.kt)("inlineCode",{parentName:"p"},"apigear"),", a level above, in the ",(0,n.kt)("inlineCode",{parentName:"p"},"generation target")," level, here ",(0,n.kt)("inlineCode",{parentName:"p"},"cpp_hello_world"),". For more details visit the documentation for each feature. "),(0,n.kt)("pre",null,(0,n.kt)("code",{parentName:"pre",className:"language-bash"},"\ud83d\udcc2hello-world\n \u2523 \ud83d\udcc2apigear\n \u2503 \u2523 \ud83d\udcdchelloworld.solution.yaml\n \u2503 \u2517 \ud83d\udcdchelloworld.module.yaml\n \u2523 \ud83d\udcc2cpp_hello_world\n \u2503 \u2523 \ud83d\udcc2apigear\n \u2503 \u2523 \ud83d\udcc2examples\n \u2503 \u2523 \ud83d\udcc2modules\n \u2503 \u2503   \u2517 \ud83d\udcc2io_world_module\n \u2503 \u2503      \u2517 \ud83d\udcc2io_world\n \u2503 \u2503         \u2523 \ud83d\udcc2generated\n \u2503 \u2503         \u2503  \u2523 \ud83d\udcc2api\n \u2503 \u2503         \u2503  \u2523 \ud83d\udcc2core\n \u2503 \u2503         \u2503  \u2523 \ud83d\udcc2mqtt\n \u2503 \u2503         \u2503  \u2517 \ud83d\udcc2olink\n \u2503 \u2503         \u2503 \ud83d\udcc2implementation\n \u2503           \u2517 \ud83d\udcdcCMakeLists.txt\n \u2503 \u2517 \ud83d\udcdcCMakeLists.txt\n")))}f.isMDXComponent=!0}}]);
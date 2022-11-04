{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $class := printf "%sService" .Interface.Name  }}
{{- $interface := .Interface.Name  }}

#include "{{snake .Module.Name}}/generated/api/datastructs.api.h"
#include "{{snake .Module.Name}}/generated/olink/{{lower (camel .Interface.Name)}}service.h"
#include "{{snake .Module.Name}}/generated/core/{{snake .Module.Name}}.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include <iostream>


using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }};
using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }}::olink;

namespace 
{
const std::string interfaceId = "{{lower1 .Module.Name}}.{{$interface}}";
}

{{$class}}::{{$class}}(std::shared_ptr<I{{$interface}}> {{$interface}}, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_{{$interface}}({{$interface}})
    , m_registry(registry)
{
    m_{{$interface}}->_getPublisher().subscribeToAllChanges(*this);
}

{{$class}}::~{{$class}}()
{
    m_{{$interface}}->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string {{$class}}::olinkObjectName() {
    return interfaceId;
}

nlohmann::json {{$class}}::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
{{- range .Interface.Operations}}
{{- $operation := . }}
    if(memberMethod == "{{$operation.Name}}") {
{{- range $idx, $elem := $operation.Params }}
{{- $param := . }}
        const {{cppType "" $param}}& {{$param}} = fcnArgs.at({{ $idx}});      
{{- end }}
    {{- if ( eq (cppType "" $operation.Return) "void") }}
        m_{{$interface}}->{{lower1 $operation.Name}}({{ cppVars $operation.Params }});
        return nlohmann::json{};
    {{- else }}
        {{cppType "" $operation.Return}} result = m_{{$interface}}->{{lower1 $operation.Name}}({{ cppVars $operation.Params }});
        return result;
    {{- end}}
    }
{{- else }}
    // no operations to invoke {{- /* we generate anyway for consistency */}}
    (void) fcnArgs;
{{- end }}
    return nlohmann::json();
}

void {{$class}}::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
{{- range .Interface.Properties}}
{{- $property := . }}
    if(memberProperty == "{{$property}}") {
        {{cppType "" $property}} {{$property}} = value.get<{{cppType "" $property}}>();
        m_{{$interface}}->set{{Camel $property.Name}}({{$property}});
    }
{{- else }}
    // no properties to set {{- /* we generate anyway for consistency */}}
    (void) value;
{{- end }} 
}

void {{$class}}::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void {{$class}}::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json {{$class}}::olinkCollectProperties()
{
    return nlohmann::json::object({
{{- range $idx, $elem := .Interface.Properties}}
{{- $property := . }}
{{- if $idx }},{{- end }}
        { "{{$property.Name}}", m_{{$interface}}->get{{Camel $property.Name}}() }
{{- end }}
    });
}

{{- range .Interface.Signals}}
{{- $signal := . }}
void {{$class}}::on{{Camel $signal.Name}}({{cppParams "" $signal.Params}})
{
    const nlohmann::json args = { {{ cppVars $signal.Params}} };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{$signal.Name}}");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
{{- end }}

{{- range .Interface.Properties}}
{{- $property := . }}
void {{$class}}::on{{Camel $property.Name}}Changed({{cppReturn "" $property}} {{$property.Name}})
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{$property.Name}}");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, {{$property}});
        }
    }
}
{{- end }}


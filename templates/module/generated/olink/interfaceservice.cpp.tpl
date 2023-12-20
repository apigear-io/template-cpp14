{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $class := printf "%sService" .Interface.Name  }}
{{ $interfaceNameOriginal := .Interface.Name  }}
{{ $interfaceName := Camel .Interface.Name  }}
{{- $interfaceClass := printf "I%s" $interfaceName -}}


#include "{{snake .Module.Name}}/generated/api/datastructs.api.h"
#include "{{snake .Module.Name}}/generated/olink/{{lower (camel .Interface.Name)}}service.h"
#include "{{snake .Module.Name}}/generated/core/{{snake .Module.Name}}.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "olink/core/olinkcontent.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }};
using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }}::olink;

namespace 
{
const std::string interfaceId = "{{.Module.Name}}.{{$interfaceNameOriginal}}";
}

{{$class}}::{{$class}}(std::shared_ptr<{{$interfaceClass}}> {{$interfaceNameOriginal}}, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_{{$interfaceNameOriginal}}({{$interfaceNameOriginal}})
    , m_registry(registry)
{
    m_{{$interfaceNameOriginal}}->_getPublisher().subscribeToAllChanges(*this);
}

{{$class}}::~{{$class}}()
{
    m_{{$interfaceNameOriginal}}->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string {{$class}}::olinkObjectName() {
    return interfaceId;
}

ApiGear::ObjectLink::OLinkContent {{$class}}::olinkInvoke(const std::string& methodId, const ApiGear::ObjectLink::OLinkContent& fcnArgs) {
{{- if len .Interface.Operations }}
{{- $paramsUsed := false}}
{{- range .Interface.Operations }}
{{- $operation := . }}
{{- if len $operation.Params }}{{ $paramsUsed = true }}{{- break }}{{- end }}
{{- end }}
{{- if not $paramsUsed}}
    (void) fcnArgs;
{{- end }}
{{- end }}
    AG_LOG_DEBUG("{{$class}} invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    ApiGear::ObjectLink::OLinContentStreamReader argumentsReader(fcnArgs);
{{- range .Interface.Operations}}
{{- $operation := . }}
    if(memberMethod == "{{$operation.Name}}") {
{{- range $idx, $elem := $operation.Params }}
{{- $param := . }}
        {{cppType "" $param}} {{$param}}{};
        argumentsReader.read({{$param}});
{{- end }}
    {{- if .Return.IsVoid }}
        m_{{$interfaceNameOriginal}}->{{lower1 $operation.Name}}({{ cppVars $operation.Params }});
        return {};
    {{- else }}
        return ApiGear::ObjectLink::invokeReturnValue(m_{{$interfaceNameOriginal}}->{{lower1 $operation.Name}}({{ cppVars $operation.Params }}));
    {{- end}}
    }
{{- else }}
    // no operations to invoke {{- /* we generate anyway for consistency */}}
    (void) fcnArgs;
    (void) memberMethod;
{{- end }}
    return {};
}

void {{$class}}::olinkSetProperty(const std::string& propertyId, const ApiGear::ObjectLink::OLinkContent& value) {
    AG_LOG_DEBUG("{{$class}} set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
{{- range .Interface.Properties}}
{{- $property := . }}
    if(memberProperty == "{{$property}}") {
        {{cppType "" $property}} value_{{$property}}{};
        ApiGear::ObjectLink::readValue(value, value_{{$property}});
        m_{{$interfaceNameOriginal}}->set{{Camel $property.Name}}(value_{{$property}});
    }
{{- else }}
    // no properties to set {{- /* we generate anyway for consistency */}}
    (void) value;
    (void) memberProperty;
{{- end }} 
}

void {{$class}}::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("{{$class}} linked " + objectId);
}

void {{$class}}::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("{{$class}} unlinked " + objectId);
}

ApiGear::ObjectLink::OLinkContent {{$class}}::olinkCollectProperties()
{
    return ApiGear::ObjectLink::argumentsToContent(
{{- range $idx, $elem := .Interface.Properties}}
{{- $property := . }}
{{- if $idx }},{{- end }}
        ApiGear::ObjectLink::toInitialProperty(std::string("{{$property.Name}}"), m_{{$interfaceNameOriginal}}->get{{Camel $property.Name}}())
{{- end }} );
}

{{- range .Interface.Signals}}
{{- $signal := . }}
void {{$class}}::on{{Camel $signal.Name}}({{cppParams "" $signal.Params}})
{
    auto args = ApiGear::ObjectLink::argumentsToContent({{ cppVars $signal.Params}});
    static const auto signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{$signal.Name}}");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
{{- end }}

{{- range .Interface.Properties}}
{{- $property := . }}
void {{$class}}::on{{Camel $property.Name}}Changed({{cppParam "" $property}})
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{$property.Name}}");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, ApiGear::ObjectLink::propertyToContent({{$property}}));
        }
    }
}
{{- end }}


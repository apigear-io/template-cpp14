{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $class := Camel .Interface.Name  }}
{{- $interfaceClass := printf "I%s" $class }}
{{- $interfaceNameOriginal := .Interface.Name  }}
{{- $sub_class := printf "I%sSubscriber" $class }}
{{- $pub_class := printf "I%sPublisher" $class }}
#pragma once
#include "{{snake .Module.Name}}/generated/api/{{snake .Module.Name}}.h"
#include "{{snake .Module.Name}}/generated/api/common.h"
#include "{{snake .Module.Name}}/generated/core/{{lower (camel .Interface.Name)}}.data.h"
#include <memory>

namespace {{ Camel .System.Name }} {
namespace {{ Camel .Module.Name }} {

/**
* The {{$interfaceNameOriginal}} implementation.
{{- if .Interface.Description }}
*{{.Interface.Description}}
{{- end }}
*/
class {{ SNAKE .System.Name  }}_{{ SNAKE .Module.Name  }}_EXPORT {{$class}} : public {{$interfaceClass}}
{
public:
    explicit {{$class}}();
    ~{{$class}}();
public:
{{- range .Interface.Properties}}
{{- $property := . }}
    {{- if $property.Description }}
    /**
    * {{$property.Name}} {{$property.Description}}
    */
{{- end }}
    void set{{Camel $property.Name}}({{ cppParam "" $property}}) override;
    {{cppReturn "" $property}} get{{Camel $property.Name}}() const override;
    {{/*  */ -}}    
{{- end }}

{{- range .Interface.Operations}}
{{- $operation := . }}
{{- if $operation.Description }}
    /**
    * {{$operation.Description}}
    */
{{- end }}
    {{cppType "" $operation.Return}} {{lower1 $operation.Name}}({{cppParams "" $operation.Params}}) override;
    std::future<{{cppType "" $operation.Return}}> {{lower1 $operation.Name}}Async({{cppParams "" $operation.Params}}) override;
        {{/*  */ -}} 
{{- end }}
    /**
    * Access to a publisher, use it to subscribe for {{$interfaceNameOriginal}} changes and signal emission.
    * @return The publisher for {{$interfaceNameOriginal}}.
    */
    {{$pub_class}}& _getPublisher() const override;
private:
    /** The publisher for the {{$interfaceNameOriginal}}. */
    std::unique_ptr<{{$pub_class}}> m_publisher;
    /** The helper structure to store all the properties for {{$interfaceNameOriginal}}. */
    {{$class}}Data m_data;
};
} // namespace {{ Camel .Module.Name }}
} // namespace {{ Camel .System.Name }}

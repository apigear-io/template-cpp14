cmake_minimum_required(VERSION 3.23.2)
project({{lower1 (camel .System.Name)}})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# this target is a dummy for subprojects to add their dependencies
if(BUILD_TESTING)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

endif(BUILD_TESTING)

# checks are workaround until generator support feature check properly
{{- if .Features.apigear }}
find_package(apigear QUIET)
if(NOT apigear_FOUND)
  # pull apigear as dependency
  message(STATUS "apigear NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(apigear
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/apigear"
  )
  FetchContent_MakeAvailable(apigear)
endif()

find_package(poco QUIET)
if(NOT poco_FOUND)
    # "poco:shared": False,
    set(ENABLE_DATA_MYSQL OFF CACHE BOOL "" FORCE)
    # "openssl:shared": False,
    set(ENABLE_ACTIVERECORD OFF CACHE BOOL "" FORCE)
    set(ENABLE_ACTIVERECORD_COMPILER OFF CACHE BOOL "" FORCE)
    set(ENABLE_APACHECONNECTOR OFF CACHE BOOL "" FORCE)
    set(ENABLE_CPPPARSER OFF CACHE BOOL "" FORCE)
    set(ENABLE_CRYPTO OFF CACHE BOOL "" FORCE)
    set(ENABLE_DATA OFF CACHE BOOL "" FORCE)
    set(ENABLE_DATA_ODBC OFF CACHE BOOL "" FORCE)
    set(ENABLE_DATA_POSTGRESQL OFF CACHE BOOL "" FORCE)
    set(ENABLE_DATA_SQLITE OFF CACHE BOOL "" FORCE)
    set(ENABLE_ENCODINGS OFF CACHE BOOL "" FORCE)
    set(ENABLE_JSON OFF CACHE BOOL "" FORCE)
    set(ENABLE_JWT OFF CACHE BOOL "" FORCE)
    set(ENABLE_MONGODB OFF CACHE BOOL "" FORCE)
    set(ENABLE_NET ON CACHE BOOL "" FORCE)
    set(ENABLE_NETSSL OFF CACHE BOOL "" FORCE)
    set(ENABLE_PAGECOMPILER  OFF CACHE BOOL "" FORCE)
    set(ENABLE_PAGECOMPILER_FILE2PAGE  OFF CACHE BOOL "" FORCE)
    set(ENABLE_PDF OFF CACHE BOOL "" FORCE)
    set(ENABLE_POCODOC OFF CACHE BOOL "" FORCE)
    set(ENABLE_REDIS OFF CACHE BOOL "" FORCE)
    set(ENABLE_SEVENZIP OFF CACHE BOOL "" FORCE)
    set(ENABLE_UTIL ON CACHE BOOL "" FORCE)
    set(ENABLE_XML OFF CACHE BOOL "" FORCE)
    set(ENABLE_ZIP OFF CACHE BOOL "" FORCE)
    include(FetchContent)
    FetchContent_Declare(
        Poco
        GIT_REPOSITORY https://github.com/pocoproject/poco.git
        GIT_TAG poco-1.11.6-release
        )
    FetchContent_MakeAvailable(Poco)
endif()
include(${CMAKE_CURRENT_BINARY_DIR}/_deps/poco-build/Poco/PocoConfig.cmake)

{{- end }}

{{- range .System.Modules }}
{{- $module_id := snake .Name}}
find_package({{$module_id}} QUIET)
if(NOT {{$module_id}}_FOUND)
  # pull {{$module_id}} as dependency
  message(STATUS "{{$module_id}} NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare({{$module_id}}
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/{{$module_id}}_module/{{$module_id}}"
  )
  FetchContent_MakeAvailable({{$module_id}})
endif()
{{- end }}

{{- if .Features.examples }}
add_subdirectory(examples/app)
add_subdirectory(examples/appthreadsafe)
{{- end }}
{{- if .Features.examples_olink }}
add_subdirectory(examples/olinkserver)
add_subdirectory(examples/olinkclient)
{{- end }}

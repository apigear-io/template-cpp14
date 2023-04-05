cmake_minimum_required(VERSION 3.23.2)
project(test)

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
find_package(testbed2 QUIET)
if(NOT testbed2_FOUND)
  # pull testbed2 as dependency
  message(STATUS "testbed2 NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(testbed2
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/testbed2_module/testbed2"
  )
  FetchContent_MakeAvailable(testbed2)
endif()
find_package(tb_enum QUIET)
if(NOT tb_enum_FOUND)
  # pull tb_enum as dependency
  message(STATUS "tb_enum NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(tb_enum
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/tb_enum_module/tb_enum"
  )
  FetchContent_MakeAvailable(tb_enum)
endif()
find_package(tb_same1 QUIET)
if(NOT tb_same1_FOUND)
  # pull tb_same1 as dependency
  message(STATUS "tb_same1 NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(tb_same1
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/tb_same1_module/tb_same1"
  )
  FetchContent_MakeAvailable(tb_same1)
endif()
find_package(tb_same2 QUIET)
if(NOT tb_same2_FOUND)
  # pull tb_same2 as dependency
  message(STATUS "tb_same2 NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(tb_same2
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/tb_same2_module/tb_same2"
  )
  FetchContent_MakeAvailable(tb_same2)
endif()
find_package(tb_simple QUIET)
if(NOT tb_simple_FOUND)
  # pull tb_simple as dependency
  message(STATUS "tb_simple NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(tb_simple
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/tb_simple_module/tb_simple"
  )
  FetchContent_MakeAvailable(tb_simple)
endif()
find_package(testbed1 QUIET)
if(NOT testbed1_FOUND)
  # pull testbed1 as dependency
  message(STATUS "testbed1 NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(testbed1
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/testbed1_module/testbed1"
  )
  FetchContent_MakeAvailable(testbed1)
endif()
add_subdirectory(examples/app)
add_subdirectory(examples/appthreadsafe)
add_subdirectory(examples/olinkserver)
add_subdirectory(examples/olinkclient)

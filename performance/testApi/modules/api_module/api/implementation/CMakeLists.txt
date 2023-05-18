set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES_CORE_IMPL
    testapi.cpp
)
add_library(api-implementation SHARED ${SOURCES_CORE_IMPL})
add_library(api::api-implementation ALIAS api-implementation)
target_include_directories(api-implementation
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../modules>
    $<INSTALL_INTERFACE:include/api>
)
target_link_libraries(api-implementation PUBLIC api::api-api api::api-core Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(api-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(api-implementation PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
if (NOT Catch2_Found)
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.8
    GIT_SHALLOW    TRUE
    FIND_PACKAGE_ARGS)
FetchContent_MakeAvailable(Catch2)
endif()
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/api.test.cpp
    testapi.test.cpp
)
add_executable(test_api
    ${SOURCES_TEST}
)
target_link_libraries(test_api api::api-implementation Catch2::Catch2)
target_include_directories(test_api PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


add_test(test_api test_api)
add_dependencies(check test_api)
endif(BUILD_TESTING)

install(TARGETS api-implementation
        EXPORT ApiImplementationTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/api   COMPONENT Development)
# install includes
FILE(GLOB Api_INCLUDES *.h)
install(FILES ${Api_INCLUDES}
        DESTINATION include/api)

export(EXPORT ApiImplementationTargets
  NAMESPACE api::
)

install(EXPORT ApiImplementationTargets
  FILE ApiImplementationTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE api::
)

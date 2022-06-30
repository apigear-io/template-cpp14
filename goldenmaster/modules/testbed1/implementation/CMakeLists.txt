set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES_CORE_IMPL
    testbed1_structinterface.cpp
    testbed1_structarrayinterface.cpp
)
add_library(testbed1-implementation STATIC ${SOURCES_CORE_IMPL})
add_library(testbed1::testbed1-implementation ALIAS testbed1-implementation)
target_include_directories(testbed1-implementation
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/testbed1>
)
target_link_libraries(testbed1-implementation PUBLIC testbed1::testbed1-api testbed1::testbed1-core)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(testbed1-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(testbed1-implementation PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
find_package(Catch2 REQUIRED)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/testbed1.test.cpp
    structinterface.test.cpp
    structarrayinterface.test.cpp
)
add_executable(test_testbed1 EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_testbed1 testbed1::testbed1-implementation Catch2::Catch2)
target_include_directories(test_testbed1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


add_test(test_testbed1 test_testbed1)
add_dependencies(check test_testbed1)
endif(BUILD_TESTING)

install(TARGETS testbed1-implementation
        EXPORT Testbed1ImplementationTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/testbed1   COMPONENT Development)
# install includes
FILE(GLOB Testbed1_INCLUDES *.h)
install(FILES ${Testbed1_INCLUDES}
        DESTINATION include/testbed1)

export(EXPORT Testbed1ImplementationTargets
  NAMESPACE testbed1::
)

install(EXPORT Testbed1ImplementationTargets
  FILE Testbed1ImplementationTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE testbed1::
)
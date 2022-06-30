set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES_CORE_IMPL
    testbed2_manyparaminterface.cpp
    testbed2_nestedstruct1interface.cpp
    testbed2_nestedstruct2interface.cpp
    testbed2_nestedstruct3interface.cpp
)
add_library(testbed2-implementation STATIC ${SOURCES_CORE_IMPL})
add_library(testbed2::testbed2-implementation ALIAS testbed2-implementation)
target_include_directories(testbed2-implementation
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/testbed2>
)
target_link_libraries(testbed2-implementation PUBLIC testbed2::testbed2-api testbed2::testbed2-core)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(testbed2-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(testbed2-implementation PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
find_package(Catch2 REQUIRED)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/testbed2.test.cpp
    manyparaminterface.test.cpp
    nestedstruct1interface.test.cpp
    nestedstruct2interface.test.cpp
    nestedstruct3interface.test.cpp
)
add_executable(test_testbed2 EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_testbed2 testbed2::testbed2-implementation Catch2::Catch2)
target_include_directories(test_testbed2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


add_test(test_testbed2 test_testbed2)
add_dependencies(check test_testbed2)
endif(BUILD_TESTING)

install(TARGETS testbed2-implementation
        EXPORT Testbed2ImplementationTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/testbed2   COMPONENT Development)
# install includes
FILE(GLOB Testbed2_INCLUDES *.h)
install(FILES ${Testbed2_INCLUDES}
        DESTINATION include/testbed2)

export(EXPORT Testbed2ImplementationTargets
  NAMESPACE testbed2::
)

install(EXPORT Testbed2ImplementationTargets
  FILE Testbed2ImplementationTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE testbed2::
)
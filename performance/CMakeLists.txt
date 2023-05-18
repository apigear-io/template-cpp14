cmake_minimum_required(VERSION 3.1)
project(performace_tests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(JSON_BuildTests OFF)

find_package(api COMPONENTS olink-performance-helper)


if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

add_subdirectory(testApi)

add_executable(server_for_tests "tests_single_object/server_for_tests.cpp")
add_executable(test_client_set_int_property "tests_single_object/test_client_set_int_property.cpp" )
add_executable(test_client_set_string_property "tests_single_object/test_client_set_string_property.cpp" )


target_link_libraries(server_for_tests  api::api-olink api::api-implementation)
target_link_libraries(test_client_set_int_property api::api-olink)
target_link_libraries(test_client_set_string_property api::api-olink)


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

add_executable(single_server_for_tests "tests_single_object/server_for_tests.cpp")
add_executable(test_single_client_set_int_property "tests_single_object/test_client_set_int_property.cpp" )
add_executable(test_single_client_set_string_property "tests_single_object/test_client_set_string_property.cpp" )
add_executable(test_clients_set_int "tests_many_objects/test_client_set_int.cpp" )
add_executable(test_clients_set_float "tests_many_objects/test_client_set_float.cpp" )
add_executable(test_clients_set_string "tests_many_objects/test_client_set_string.cpp" )
add_executable(servers_for_tests "tests_many_objects/server_for_tests.cpp" "tests_many_objects/prepare_test_services.cpp" )


target_link_libraries(single_server_for_tests  api::api-olink api::api-implementation)
target_link_libraries(test_single_client_set_int_property api::api-olink)
target_link_libraries(test_single_client_set_string_property api::api-olink)
target_link_libraries(test_clients_set_int api::api-olink)
target_link_libraries(test_clients_set_float api::api-olink)
target_link_libraries(test_clients_set_string api::api-olink)
target_link_libraries(servers_for_tests api::api-olink  api::api-implementation)


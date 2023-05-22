cmake_minimum_required(VERSION 3.1)
project(MQTTClient)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(MQTTClient
    ${SOURCES}
)

find_package(apigear QUIET COMPONENTS utilities)
find_package(testbed2 QUIET COMPONENTS testbed2-core testbed2-mqtt)
find_package(tb_enum QUIET COMPONENTS tb_enum-core tb_enum-mqtt)
find_package(tb_same1 QUIET COMPONENTS tb_same1-core tb_same1-mqtt)
find_package(tb_same2 QUIET COMPONENTS tb_same2-core tb_same2-mqtt)
find_package(tb_simple QUIET COMPONENTS tb_simple-core tb_simple-mqtt)
find_package(testbed1 QUIET COMPONENTS testbed1-core testbed1-mqtt)
target_link_libraries(MQTTClient
    apigear::utilities
    testbed2::testbed2-core
    testbed2::testbed2-mqtt
    tb_enum::tb_enum-core
    tb_enum::tb_enum-mqtt
    tb_same1::tb_same1-core
    tb_same1::tb_same1-mqtt
    tb_same2::tb_same2-core
    tb_same2::tb_same2-mqtt
    tb_simple::tb_simple-core
    tb_simple::tb_simple-mqtt
    testbed1::testbed1-core
    testbed1::testbed1-mqtt
)

install(TARGETS MQTTClient
        RUNTIME DESTINATION bin COMPONENT Runtime)
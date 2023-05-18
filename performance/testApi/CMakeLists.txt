cmake_minimum_required(VERSION 3.1)
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
find_package(api QUIET)
if(NOT api_FOUND)
  # pull api as dependency
  message(STATUS "api NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(api
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/api_module/api"
  )
  FetchContent_MakeAvailable(api)
endif()

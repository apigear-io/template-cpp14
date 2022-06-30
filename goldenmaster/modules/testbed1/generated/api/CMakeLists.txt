set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES
    testbed1_datastructs.api.cpp
)
add_library(testbed1-api STATIC ${SOURCES})
add_library(testbed1::testbed1-api ALIAS testbed1-api)
target_include_directories(testbed1-api
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/testbed1>
)
target_link_libraries(testbed1-api PUBLIC Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(testbed1-api PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(testbed1-api PRIVATE /W4 /WX /wd4251)
endif()

# install binary files
install(TARGETS testbed1-api
        EXPORT Testbed1ApiTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/testbed1   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/testbed1/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Testbed1ApiTargets
  NAMESPACE testbed1::
)

install(EXPORT Testbed1ApiTargets
  FILE Testbed1ApiTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE testbed1::
)
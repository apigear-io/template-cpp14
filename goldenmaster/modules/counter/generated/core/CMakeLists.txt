set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)
set (SOURCES_CORE_SUPPORT
    counter.json.adapter.cpp
    counter.publisher.cpp
    counter.threadsafedecorator.cpp
)
add_library(counter-core SHARED ${SOURCES_CORE_SUPPORT})
add_library(counter::counter-core ALIAS counter-core)
target_include_directories(counter-core
    PUBLIC
    $<BUILD_INTERFACE:${MODULES_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(counter-core PUBLIC counter::counter-api nlohmann_json::nlohmann_json)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(counter-core PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(counter-core PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS counter-core
        EXPORT CounterCoreTargets)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/counter/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT CounterCoreTargets
  NAMESPACE counter::
)

install(EXPORT CounterCoreTargets
  FILE CounterCoreTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE counter::
)

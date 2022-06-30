set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-olink)
set (SOURCES_OLINK
    testbed2_manyparaminterfaceadapter.cpp
    testbed2_manyparaminterfaceinterface.cpp
    testbed2_nestedstruct1interfaceadapter.cpp
    testbed2_nestedstruct1interfaceinterface.cpp
    testbed2_nestedstruct2interfaceadapter.cpp
    testbed2_nestedstruct2interfaceinterface.cpp
    testbed2_nestedstruct3interfaceadapter.cpp
    testbed2_nestedstruct3interfaceinterface.cpp
)
add_library(testbed2-olink SHARED ${SOURCES_OLINK})
add_library(testbed2::testbed2-olink ALIAS testbed2-olink)
target_include_directories(testbed2-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/testbed2>
)
target_link_libraries(testbed2-olink 
    testbed2::testbed2-core
    apigear::poco-olink
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(testbed2-olink PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(testbed2-olink PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS testbed2-olink
        EXPORT Testbed2OLinkTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/testbed2   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/testbed2/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Testbed2OLinkTargets
  NAMESPACE testbed2::
)

install(EXPORT Testbed2OLinkTargets
  FILE Testbed2OLinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE testbed2::
)
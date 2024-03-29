#include <memory>
#include "catch2/catch.hpp"
#include "testbed2/implementation/nestedstruct2interface.h"

using namespace Test::Testbed2;
TEST_CASE("Testing NestedStruct2Interface", "[NestedStruct2Interface]"){
    std::unique_ptr<INestedStruct2Interface> testNestedStruct2Interface = std::make_unique<NestedStruct2Interface>();
    // setup your test
    SECTION("Test operation func1") {
        // Do implement test here
        testNestedStruct2Interface->func1(NestedStruct1());
    }
    SECTION("Test operation func2") {
        // Do implement test here
        testNestedStruct2Interface->func2(NestedStruct1(), NestedStruct2());
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testNestedStruct2Interface->setProp1(NestedStruct1());
        REQUIRE( testNestedStruct2Interface->getProp1() == NestedStruct1() );
    }
    SECTION("Test property prop2") {
        // Do implement test here
        testNestedStruct2Interface->setProp2(NestedStruct2());
        REQUIRE( testNestedStruct2Interface->getProp2() == NestedStruct2() );
    }
}

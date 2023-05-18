#include <memory>
#include "catch2/catch.hpp"
#include "api/implementation/testapi.h"

using namespace Test::Api;
TEST_CASE("Testing TestApi", "[TestApi]"){
    std::unique_ptr<ITestApi> testTestApi = std::make_unique<TestApi>();
    // setup your test
    SECTION("Test operation funcInt") {
        // Do implement test here
        testTestApi->funcInt(0);
    }
    SECTION("Test operation funcFloat") {
        // Do implement test here
        testTestApi->funcFloat(0.0f);
    }
    SECTION("Test operation funcString") {
        // Do implement test here
        testTestApi->funcString(std::string());
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testTestApi->setPropInt(0);
        REQUIRE( testTestApi->getPropInt() == 0 );
    }
    SECTION("Test property propFloat") {
        // Do implement test here
        testTestApi->setPropFloat(0.0f);
        REQUIRE( testTestApi->getPropFloat() == Approx( 0.0f ) );
    }
    SECTION("Test property propString") {
        // Do implement test here
        testTestApi->setPropString(std::string());
        REQUIRE( testTestApi->getPropString() == std::string() );
    }
}

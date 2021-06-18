#include "catch.hpp"
#include "lib.hpp"
#include <string>

TEST_CASE("Nothing") { 
    std::string battlefield_test[9] = {
        "", "", "", 
        "", "", "", 
        "", "", "",
    };
    REQUIRE(fn_test(battlefield_test) == true); }
    
TEST_CASE("Win line") { 
    std::string battlefield_test[9] = {
        "X", "X", "X", 
        "", "", "", 
        "", "", "",
    };
    REQUIRE(fn_test(battlefield_test) == false); }
    
TEST_CASE("No win") {
    std::string battlefield_test[9] = {
        "X", "X", "O", 
        "", "", "", 
        "", "", "",
    };
    REQUIRE(fn_test(battlefield_test) == true); }
    
TEST_CASE("Win line 2") {
    std::string battlefield_test[9] = {
        "X", "", "", 
        "O", "O", "O", 
        "X", "X", "O",
    };
    REQUIRE(fn_test(battlefield_test) == false); }

TEST_CASE("No diagonal") {
    std::string battlefield_test[9] = {
        "X", "X", "O", 
        "", "O", "", 
        "O", "", "",
    };
    REQUIRE(fn_test(battlefield_test) == false); }

TEST_CASE("Win stolb") {
    std::string battlefield_test[9] = {
        "X", "O", "X", 
        "", "O", "X", 
        "", "O", "",
    };
    REQUIRE(fn_test(battlefield_test) == false); }

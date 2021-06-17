#include "catch.hpp"
#include "lib.hpp"

TEST_CASE("Something works") { REQUIRE(not_random() == not_random()); }
TEST_CASE("1") { REQUIRE(check_battlefield(0, 1, 1) == false); }
TEST_CASE("2") { REQUIRE(check_battlefield(0, 1, 0) == false); }
TEST_CASE("3") { REQUIRE(check_battlefield(0, 0, 1) == false); }
TEST_CASE("4") { REQUIRE(check_battlefield(1, 1, 1) == true); }
TEST_CASE("5") { REQUIRE(check_battlefield(4, 4, 4) == true); }
TEST_CASE("6") { REQUIRE(check_battlefield(5, 5, 0) == false); }
TEST_CASE("7") { REQUIRE(check_battlefield(5, 5, 5) == true); }
TEST_CASE("8") { REQUIRE(check_battlefield(50, 5, 1) == false); }
TEST_CASE("9") { REQUIRE(check_battlefield(8, 3, 1) == false); }
TEST_CASE("10") { REQUIRE(check_battlefield(0, 0, 9) == false); }
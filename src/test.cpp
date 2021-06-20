#include "catch.hpp"
#include "lib.cpp"
#include <string>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>

TEST_CASE("Nothing") { 
    std::string battlefield[9] = {
        "", "", "", 
        "", "", "", 
        "", "", "",
    };
    bool game_run = true;
    nana::button button_all[9];
    fn(battlefield, game_run, button_all);
    REQUIRE(game_run == true); }

TEST_CASE("Win line") { 
    std::string battlefield[9] = {
        "X", "X", "X", 
        "", "", "", 
        "", "", "",
    };
    bool game_run = true;
    nana::button button_all[9];
    fn(battlefield, game_run, button_all);
    REQUIRE(game_run == false); }
    
TEST_CASE("No win") {
    std::string battlefield[9] = {
        "X", "X", "O", 
        "", "", "", 
        "", "", "",
    };
    bool game_run = true;
    nana::button button_all[9];
    fn(battlefield, game_run, button_all);
    REQUIRE(game_run == true); }
    
TEST_CASE("Win line 2") {
    std::string battlefield[9] = {
        "X", "", "", 
        "O", "O", "O", 
        "X", "X", "O",
    };
    bool game_run = true;
    nana::button button_all[9];
    fn(battlefield, game_run, button_all);
    REQUIRE(game_run == false); }

TEST_CASE("No diagonal") {
    std::string battlefield[9] = {
        "X", "X", "O", 
        "", "O", "", 
        "O", "", "",
    };
    bool game_run = true;
    nana::button button_all[9];
    fn(battlefield, game_run, button_all);
    REQUIRE(game_run == false); }

TEST_CASE("Win stolb") {
    std::string battlefield[9] = {
        "X", "O", "X", 
        "", "O", "X", 
        "", "O", "",
    };
    bool game_run = true;
    nana::button button_all[9];
    fn(battlefield, game_run, button_all);
    REQUIRE(game_run == false); }

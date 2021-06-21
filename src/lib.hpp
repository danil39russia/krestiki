#include <string>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>

extern void fn(std::string (&battlefield)[9], bool &game_run, nana::button (&button_all)[9]);
extern void clear(nana::button (&button_all)[9]);
extern void btn_click(std::string (&battlefield)[9], int num, std::string &btn_txt, nana::button (&button_all)[9], bool &player_turn, bool &game_run);
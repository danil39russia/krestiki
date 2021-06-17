#include "nana/gui/widgets/picture.hpp"
#include "nana/paint/image.hpp"
#include <fmt/core.h>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <string>
//Подключили библиотеки



int main() {
    using namespace nana;
    
    //указываем размер окна
    form fm(nana::rectangle(400, 100, 320, 390));

    //хранит в себе значения полей
    std::string battlefield[9] = {
        "", "", "", "", "", "", "", "", "",
    };
    /*
    Переменные, где

    pvp_mod - режим игры
    player_turn - ход игрока?
    game_run - статус игры
    btn_txt - показывает, что ставить следующим
    */
    bool pvp_mod = false;
    bool player_turn = true;
    bool game_run = true;
    std::string btn_txt = "X";

    //инициализация кнопок
    button button_1{fm};
    button button_2{fm};
    button button_3{fm};
    button button_4{fm};
    button button_5{fm};
    button button_6{fm};
    button button_7{fm};
    button button_8{fm};
    button button_9{fm};

    //настраиваем цвет кнопки
    button_1.bgcolor(color_rgb(0xFFFFFF));

    //настраиваем шрифт кнопки
    button_1.typeface(nana::paint::font("", 40, true));

    //обработка нажатий кнопки
    button_1.events().click([&] {
        /*
        Проверяет, продолжается ли игра и пустая ли клетка
        Ставит крестик или нолик в зависимости от хода
        */
        if (battlefield[0] == "" & game_run == true) {
            battlefield[0] = btn_txt;
            button_1.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        /*
        Проверка всех условий выигрыша.
        Если есть выигрышная комбинация, то меняет цвет кнопок и завершает игру
        */
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    button_2.bgcolor(color_rgb(0xFFFFFF));
    button_2.typeface(nana::paint::font("", 40, true));
    button_2.events().click([&] {
        if (battlefield[1] == "" & game_run == true) {
            battlefield[1] = btn_txt;
            button_2.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    button_3.bgcolor(color_rgb(0xFFFFFF));
    button_3.typeface(nana::paint::font("", 40, true));
    button_3.events().click([&] {
        if (battlefield[2] == "" & game_run == true) {
            battlefield[2] = btn_txt;
            button_3.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    button_4.bgcolor(color_rgb(0xFFFFFF));
    button_4.typeface(nana::paint::font("", 40, true));
    button_4.events().click([&] {
        if (battlefield[3] == "" & game_run == true) {
            battlefield[3] = btn_txt;
            button_4.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    button_5.bgcolor(color_rgb(0xFFFFFF));
    button_5.typeface(nana::paint::font("", 40, true));
    button_5.events().click([&] {
        if (battlefield[4] == "" & game_run == true) {
            battlefield[4] = btn_txt;
            button_5.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    button_6.bgcolor(color_rgb(0xFFFFFF));
    button_6.typeface(nana::paint::font("", 40, true));
    button_6.events().click([&] {
        if (battlefield[5] == "" & game_run == true) {
            battlefield[5] = btn_txt;
            button_6.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    button_7.bgcolor(color_rgb(0xFFFFFF));
    button_7.typeface(nana::paint::font("", 40, true));
    button_7.events().click([&] {
        if (battlefield[6] == "" & game_run == true) {
            battlefield[6] = btn_txt;
            button_7.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    button_8.bgcolor(color_rgb(0xFFFFFF));
    button_8.typeface(nana::paint::font("", 40, true));
    button_8.events().click([&] {
        if (battlefield[7] == "" & game_run == true) {
            battlefield[7] = btn_txt;
            button_8.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    button_9.bgcolor(color_rgb(0xFFFFFF));
    button_9.typeface(nana::paint::font("", 40, true));
    button_9.events().click([&] {
        if (battlefield[8] == "" & game_run == true) {
            battlefield[8] = btn_txt;
            button_9.caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_2.bgcolor(color_rgb(0xDC143C));
            button_3.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_4.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_7.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_4.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_2.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_8.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_6.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_1.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_9.bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_3.bgcolor(color_rgb(0xDC143C));
            button_5.bgcolor(color_rgb(0xDC143C));
            button_7.bgcolor(color_rgb(0xDC143C));
        }
    });

    //кнопка рестарта
    button button_restart{fm};
    button_restart.bgcolor(color_rgb(0x696969));
    button_restart.typeface(nana::paint::font("", 15, true));
    button_restart.caption("Рестарт");
    button_restart.events().click([&] {
        //тут все кнопки очищаются, игра перезапускается
        for (int i = 0; i < 9; i++) {
            battlefield[i] = "";
        };
        button_1.caption("");
        button_2.caption("");
        button_3.caption("");
        button_4.caption("");
        button_5.caption("");
        button_6.caption("");
        button_7.caption("");
        button_8.caption("");
        button_9.caption("");
        player_turn = true;
        button_1.bgcolor(color_rgb(0xFFFFFF));
        button_2.bgcolor(color_rgb(0xFFFFFF));
        button_3.bgcolor(color_rgb(0xFFFFFF));
        button_4.bgcolor(color_rgb(0xFFFFFF));
        button_5.bgcolor(color_rgb(0xFFFFFF));
        button_6.bgcolor(color_rgb(0xFFFFFF));
        button_7.bgcolor(color_rgb(0xFFFFFF));
        button_8.bgcolor(color_rgb(0xFFFFFF));
        button_9.bgcolor(color_rgb(0xFFFFFF));
        game_run = true;
    });

    //кнопка смены режима игры
    button change_mod{fm};
    change_mod.bgcolor(color_rgb(0x696969));
    change_mod.typeface(nana::paint::font("", 15, true));
    change_mod.caption("vs PC");
    change_mod.events().click([&] {
        if (!pvp_mod) {
            change_mod.caption("PvP");
            pvp_mod = true;
        } else {
            change_mod.caption("vs PC");
            pvp_mod = false;
            player_turn = true;
        }
        for (int i = 0; i < 9; i++) {
            battlefield[i] = "";
        };
        button_1.caption("");
        button_2.caption("");
        button_3.caption("");
        button_4.caption("");
        button_5.caption("");
        button_6.caption("");
        button_7.caption("");
        button_8.caption("");
        button_9.caption("");
        button_1.bgcolor(color_rgb(0xFFFFFF));
        button_2.bgcolor(color_rgb(0xFFFFFF));
        button_3.bgcolor(color_rgb(0xFFFFFF));
        button_4.bgcolor(color_rgb(0xFFFFFF));
        button_5.bgcolor(color_rgb(0xFFFFFF));
        button_6.bgcolor(color_rgb(0xFFFFFF));
        button_7.bgcolor(color_rgb(0xFFFFFF));
        button_8.bgcolor(color_rgb(0xFFFFFF));
        button_9.bgcolor(color_rgb(0xFFFFFF));
        game_run = true;
    });

    //кнопка выхода
    button button_exit{fm, "Quit"};
    button_exit.bgcolor(color_rgb(0xDC143C));
    button_exit.typeface(nana::paint::font("", 15, true));
    button_exit.events().click([&fm] { fm.close(); });

    button_7.caption(battlefield[0]);
    button_8.caption(battlefield[1]);
    button_9.caption(battlefield[2]);

    //Настройка расположений кнопок
    fm.div("vert <>"
           "<weight=5%>\n"
           "<<weight=5%>weight=25% text size=20 < button_line1><weight=5%>>"
           "<>\n"
           "<<weight=5%>weight=25%<button_line2><weight=5%>>"
           "<>\n"
           "<<weight=5%>weight=25%<button_line3><weight=5%>>"
           "<>\n"
           "<weight=5%>\n"
           "<<weight=10%>weight=10%<button_line4><weight=10%>>"
           "<>\n"
           "<weight=5%>");

    //определяем, какая кнопка в какой строке
    fm["button_line1"] << button_1 << button_2 << button_3;
    fm["button_line2"] << button_4 << button_5 << button_6;
    fm["button_line3"] << button_7 << button_8 << button_9;
    fm["button_line4"] << button_restart << button_exit; //<< change_mod;
    fm.collocate();

    // Show the form
    fm.show();

    // Start to event loop process, it blocks until the form is closed.
    exec();
}

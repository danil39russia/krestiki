#include "nana/gui/widgets/picture.hpp"
#include "nana/paint/image.hpp"
#include <fmt/core.h>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <string>
//Подключили библиотеки


void fn(std::string (&battlefield)[9], bool &game_run, nana::button (&button_all)[9]){
    using namespace nana;

    if ((battlefield[0] == battlefield[1]) & (battlefield[1] == battlefield[2]) & battlefield[2] != "") {
            game_run = false;
            button_all[0].bgcolor(color_rgb(0xDC143C));
            button_all[1].bgcolor(color_rgb(0xDC143C));
            button_all[2].bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[3] == battlefield[4]) & (battlefield[4] == battlefield[5]) & battlefield[5] != "") {
            game_run = false;
            button_all[3].bgcolor(color_rgb(0xDC143C));
            button_all[4].bgcolor(color_rgb(0xDC143C));
            button_all[5].bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[6] == battlefield[7]) & (battlefield[7] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_all[6].bgcolor(color_rgb(0xDC143C));
            button_all[7].bgcolor(color_rgb(0xDC143C));
            button_all[8].bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[3]) & (battlefield[3] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_all[0].bgcolor(color_rgb(0xDC143C));
            button_all[3].bgcolor(color_rgb(0xDC143C));
            button_all[7].bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[1] == battlefield[4]) & (battlefield[4] == battlefield[7]) & battlefield[7] != "") {
            game_run = false;
            button_all[1].bgcolor(color_rgb(0xDC143C));
            button_all[4].bgcolor(color_rgb(0xDC143C));
            button_all[7].bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[5]) & (battlefield[5] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_all[2].bgcolor(color_rgb(0xDC143C));
            button_all[5].bgcolor(color_rgb(0xDC143C));
            button_all[8].bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[0] == battlefield[4]) & (battlefield[4] == battlefield[8]) & battlefield[8] != "") {
            game_run = false;
            button_all[0].bgcolor(color_rgb(0xDC143C));
            button_all[4].bgcolor(color_rgb(0xDC143C));
            button_all[8].bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) & (battlefield[4] == battlefield[6]) & battlefield[6] != "") {
            game_run = false;
            button_all[2].bgcolor(color_rgb(0xDC143C));
            button_all[4].bgcolor(color_rgb(0xDC143C));
            button_all[6].bgcolor(color_rgb(0xDC143C));
        }
}

void clear(nana::button (&button_all)[9]){
    using namespace nana;

    button_all[0].caption("");
    button_all[1].caption("");
    button_all[2].caption("");
    button_all[3].caption("");
    button_all[4].caption("");
    button_all[5].caption("");
    button_all[6].caption("");
    button_all[7].caption("");
    button_all[8].caption("");
    button_all[0].bgcolor(color_rgb(0xFFFFFF));
    button_all[1].bgcolor(color_rgb(0xFFFFFF));
    button_all[2].bgcolor(color_rgb(0xFFFFFF));
    button_all[3].bgcolor(color_rgb(0xFFFFFF));
    button_all[4].bgcolor(color_rgb(0xFFFFFF));
    button_all[5].bgcolor(color_rgb(0xFFFFFF));
    button_all[6].bgcolor(color_rgb(0xFFFFFF));
    button_all[7].bgcolor(color_rgb(0xFFFFFF));
    button_all[8].bgcolor(color_rgb(0xFFFFFF));
}


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
    button button_all[9] = {
    button{fm},
    button{fm},
    button{fm},
    button{fm},
    button{fm},
    button{fm},
    button{fm},
    button{fm},
    button{fm}
    };

    //button button_all[1]{fm};
    //настраиваем цвет кнопки
    button_all[0].bgcolor(color_rgb(0xFFFFFF));

    //настраиваем шрифт кнопки
    button_all[0].typeface(nana::paint::font("", 40, true));

    //обработка нажатий кнопки
    button_all[0].events().click([&] {
        /*
        Проверяет, продолжается ли игра и пустая ли клетка
        Ставит крестик или нолик в зависимости от хода
        */
        if (battlefield[0] == "" & game_run == true) {
            battlefield[0] = btn_txt;
            button_all[0].caption(btn_txt);
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
        fn(battlefield, game_run, button_all);
    });

    button_all[1].bgcolor(color_rgb(0xFFFFFF));
    button_all[1].typeface(nana::paint::font("", 40, true));
    button_all[1].events().click([&] {
        if (battlefield[1] == "" & game_run == true) {
            battlefield[1] = btn_txt;
            button_all[1].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        fn(battlefield, game_run, button_all);
    });

    button_all[2].bgcolor(color_rgb(0xFFFFFF));
    button_all[2].typeface(nana::paint::font("", 40, true));
    button_all[2].events().click([&] {
        if (battlefield[2] == "" & game_run == true) {
            battlefield[2] = btn_txt;
            button_all[2].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        fn(battlefield, game_run, button_all);
    });

    button_all[3].bgcolor(color_rgb(0xFFFFFF));
    button_all[3].typeface(nana::paint::font("", 40, true));
    button_all[3].events().click([&] {
        if (battlefield[3] == "" & game_run == true) {
            battlefield[3] = btn_txt;
            button_all[3].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        fn(battlefield, game_run, button_all);
    });

    button_all[4].bgcolor(color_rgb(0xFFFFFF));
    button_all[4].typeface(nana::paint::font("", 40, true));
    button_all[4].events().click([&] {
        if (battlefield[4] == "" & game_run == true) {
            battlefield[4] = btn_txt;
            button_all[4].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        fn(battlefield, game_run, button_all);
    });

    button_all[5].bgcolor(color_rgb(0xFFFFFF));
    button_all[5].typeface(nana::paint::font("", 40, true));
    button_all[5].events().click([&] {
        if (battlefield[5] == "" & game_run == true) {
            battlefield[5] = btn_txt;
            button_all[5].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        fn(battlefield, game_run, button_all);
    });

    button_all[6].bgcolor(color_rgb(0xFFFFFF));
    button_all[6].typeface(nana::paint::font("", 40, true));
    button_all[6].events().click([&] {
        if (battlefield[6] == "" & game_run == true) {
            battlefield[6] = btn_txt;
            button_all[6].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        fn(battlefield, game_run, button_all);
    });

    button_all[7].bgcolor(color_rgb(0xFFFFFF));
    button_all[7].typeface(nana::paint::font("", 40, true));
    button_all[7].events().click([&] {
        if (battlefield[7] == "" & game_run == true) {
            battlefield[7] = btn_txt;
            button_all[7].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        fn(battlefield, game_run, button_all);
    });

    button_all[8].bgcolor(color_rgb(0xFFFFFF));
    button_all[8].typeface(nana::paint::font("", 40, true));
    button_all[8].events().click([&] {
        if (battlefield[8] == "" & game_run == true) {
            battlefield[8] = btn_txt;
            button_all[8].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
        }
        fn(battlefield, game_run, button_all);
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
        clear(button_all);
        player_turn = true;
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
        clear(button_all);
        game_run = true;
    });

    //кнопка выхода
    button button_exit{fm, "Quit"};
    button_exit.bgcolor(color_rgb(0xDC143C));
    button_exit.typeface(nana::paint::font("", 15, true));
    button_exit.events().click([&fm] { fm.close(); });

    button_all[6].caption(battlefield[0]);
    button_all[7].caption(battlefield[1]);
    button_all[8].caption(battlefield[2]);

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
    fm["button_line1"] << button_all[0] << button_all[1] << button_all[2];
    fm["button_line2"] << button_all[3] << button_all[4] << button_all[5];
    fm["button_line3"] << button_all[6] << button_all[7] << button_all[8];
    fm["button_line4"] << button_restart << button_exit; //<< change_mod;
    fm.collocate();

    // Show the form
    fm.show();

    // Start to event loop process, it blocks until the form is closed.
    exec();
}

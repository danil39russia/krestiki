#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <string>
#include "lib.cpp"
//Подключили библиотеки

/** \brief "Тело" игры
 *
 * Создание окна и вывод в него всех кнопок
 *
 * @param pvp_mod - переменная отвечает на вопрос "Включен PVP мод?"
 * @param player_turn - переменная отвечает на вопрос "Сейчас ходит игрок?"
 * @param game_run - переменная указывает, идет ли еще игра
 * @param btn_txt - содержит в себе знак, который поставится при следующем ходе
 * @param button_all - содержит в себе все кнопки
 * @param battlefield - содержит в себе значения полей
 */

int main() {
    ///используем пространство имен nana
    using namespace nana;
    
    ///указываем размер окна
    form fm(nana::rectangle(400, 100, 320, 390));

    ///объявляем переменные
    std::string battlefield[9] = {
        "", "", "", "", "", "", "", "", "",
    };

    bool pvp_mod = false;
    bool player_turn = true;
    bool game_run = true;
    std::string btn_txt = "X";

    /// создаем кнопки
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

    ///настраиваем цвет кнопки
    button_all[0].bgcolor(color_rgb(0xFFFFFF));

    ///настраиваем шрифт кнопки
    button_all[0].typeface(nana::paint::font("", 40, true));

    ///настраиваем цвет и шрифт кнопок
    for (int i = 0; i < 9; i++) {
        button_all[i].bgcolor(color_rgb(0xFFFFFF));
        button_all[i].typeface(nana::paint::font("", 40, true));
    }
    

    ///обработка нажатий кнопки
    button_all[0].events().click([&] {

    /**
    * Проверяет, продолжается ли игра и пустая ли клетка
    * Ставит крестик или нолик в зависимости от хода
    */
        btn_click(battlefield, 0, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });

    
    button_all[1].events().click([&] {
        btn_click(battlefield, 1, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });


    button_all[2].events().click([&] {
        btn_click(battlefield, 2, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });


    button_all[3].events().click([&] {
        btn_click(battlefield, 3, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });


    button_all[4].events().click([&] {
        btn_click(battlefield, 4, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });


    button_all[5].events().click([&] {
        btn_click(battlefield, 5, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });


    button_all[6].events().click([&] {
        btn_click(battlefield, 6, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });


    button_all[7].events().click([&] {
        btn_click(battlefield, 7, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });


    button_all[8].events().click([&] {
        btn_click(battlefield, 8, btn_txt, button_all, player_turn, game_run);
        fn(battlefield, game_run, button_all);
    });

    ///кнопка рестарта
    button button_restart{fm};
    button_restart.bgcolor(color_rgb(0x696969));
    button_restart.typeface(nana::paint::font("", 15, true));
    button_restart.caption("Рестарт");
    button_restart.events().click([&] {
    ///тут все кнопки очищаются, игра перезапускается
        for (int i = 0; i < 9; i++) {
            battlefield[i] = "";
        };
        clear(button_all);
        player_turn = true;
        game_run = true;
    });

    ///кнопка смены режима игры
    button change_mod{fm};
    change_mod.bgcolor(color_rgb(0x696969));
    change_mod.typeface(nana::paint::font("", 15, true));
    change_mod.caption("vs PC");
    change_mod.events().click([&] {
    ///если выключен pvp мод, то включаем его
        if (!pvp_mod) {
            change_mod.caption("PvP");
            pvp_mod = true;
        ///если был включен pvp, то включаем режим против пк
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

    ///кнопка выхода
    button button_exit{fm, "Quit"};
    button_exit.bgcolor(color_rgb(0xDC143C));
    button_exit.typeface(nana::paint::font("", 15, true));
    button_exit.events().click([&fm] { fm.close(); });

    ///Настройка расположений кнопок
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

    ///определяем, какая кнопка в какой строке
    fm["button_line1"] << button_all[0] << button_all[1] << button_all[2];
    fm["button_line2"] << button_all[3] << button_all[4] << button_all[5];
    fm["button_line3"] << button_all[6] << button_all[7] << button_all[8];
    fm["button_line4"] << button_restart << button_exit; //<< change_mod;
    fm.collocate();

    /// Show the form
    fm.show();

    /// Start to event loop process, it blocks until the form is closed.
    exec();
}

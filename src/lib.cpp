#pragma once
#include <string>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include "lib.hpp"

/** \brief Функция, проверяющая возможную выигрышную комбинацию
 * 
 * Если конмбинация выигрышная, то заканчивает игру и подсвечитвает выигрыш красным
 * 
 * @param battlefield - принимает на вход значения поля
 * @param game_run - принимает на вход значение статуса игры
 * @param button_all - принимает на вход значения поля
*/
void fn(std::string (&battlefield)[9], bool &game_run, nana::button (&button_all)[9]){
    ///использование пространства имен "nana"
    using namespace nana;
    ///проверка первой строки
    if ((battlefield[0] == battlefield[1]) && (battlefield[1] == battlefield[2]) && battlefield[2] != "") {
            ///заверишить игру
            game_run = false;
            ///перекрасить выигрушную комбинацию в красный цвет
            button_all[0].bgcolor(color_rgb(0xDC143C));
            button_all[1].bgcolor(color_rgb(0xDC143C));
            button_all[2].bgcolor(color_rgb(0xDC143C));
        }
        ///проверка второй строки
        else if((battlefield[3] == battlefield[4]) && (battlefield[4] == battlefield[5]) && battlefield[5] != "") {
            game_run = false;
            button_all[3].bgcolor(color_rgb(0xDC143C));
            button_all[4].bgcolor(color_rgb(0xDC143C));
            button_all[5].bgcolor(color_rgb(0xDC143C));
        }
        ///проверка третьей строки
        else if((battlefield[6] == battlefield[7]) && (battlefield[7] == battlefield[8]) && battlefield[8] != "") {
            game_run = false;
            button_all[6].bgcolor(color_rgb(0xDC143C));
            button_all[7].bgcolor(color_rgb(0xDC143C));
            button_all[8].bgcolor(color_rgb(0xDC143C));
        }
        ///проверка первого столбца
        else if((battlefield[0] == battlefield[3]) && (battlefield[3] == battlefield[6]) && battlefield[6] != "") {
            game_run = false;
            button_all[0].bgcolor(color_rgb(0xDC143C));
            button_all[3].bgcolor(color_rgb(0xDC143C));
            button_all[6].bgcolor(color_rgb(0xDC143C));
        }
        ///проверка второго столбца
        else if((battlefield[1] == battlefield[4]) && (battlefield[4] == battlefield[7]) && battlefield[7] != "") {
            game_run = false;
            button_all[1].bgcolor(color_rgb(0xDC143C));
            button_all[4].bgcolor(color_rgb(0xDC143C));
            button_all[7].bgcolor(color_rgb(0xDC143C));
        }
        ///проверка третьего столбца
        else if((battlefield[2] == battlefield[5]) && (battlefield[5] == battlefield[8]) && battlefield[8] != "") {
            game_run = false;
            button_all[2].bgcolor(color_rgb(0xDC143C));
            button_all[5].bgcolor(color_rgb(0xDC143C));
            button_all[8].bgcolor(color_rgb(0xDC143C));
        }
        ///проверка диагоналей
        else if((battlefield[0] == battlefield[4]) && (battlefield[4] == battlefield[8]) && battlefield[8] != "") {
            game_run = false;
            button_all[0].bgcolor(color_rgb(0xDC143C));
            button_all[4].bgcolor(color_rgb(0xDC143C));
            button_all[8].bgcolor(color_rgb(0xDC143C));
        }
        else if((battlefield[2] == battlefield[4]) && (battlefield[4] == battlefield[6]) && battlefield[6] != "") {
            game_run = false;
            button_all[2].bgcolor(color_rgb(0xDC143C));
            button_all[4].bgcolor(color_rgb(0xDC143C));
            button_all[6].bgcolor(color_rgb(0xDC143C));
        }
}

/** Функция отчиски
 *
 * задает всем кнопкам пустой текст и возвращает фон не дефолтный
 * "стирает все кнопки и перезапускает игру"
 */
void clear(nana::button (&button_all)[9]){
    using namespace nana;
    ///отчистка текста кнопок
    for (int i = 0; i < 9; i++){
        button_all[i].caption("");
    }
    
    ///отчистка цвета кнопок
    for (int i = 0; i < 9; i++){
            button_all[i].bgcolor(color_rgb(0xFFFFFF));
        }
}

/** Функция отработки нажатия кнопки
 *
 * при нажатии кнопки проверяет, может ли быть сделан ход
 * если ход можно сделать, что меняет текст кнопки и передает ход
 */
void btn_click(std::string (&battlefield)[9], int num, std::string &btn_txt, nana::button (&button_all)[9], bool &player_turn, bool &game_run){
    if (battlefield[num] == "" && game_run == true) {
            battlefield[num] = btn_txt;
            button_all[num].caption(btn_txt);
            if (btn_txt == "X")
                btn_txt = "O";
            else
                btn_txt = "X";
            player_turn = false;
            }
}
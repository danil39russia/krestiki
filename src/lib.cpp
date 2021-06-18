//#include <nana/gui.hpp>
//#include <nana/gui/widgets/button.hpp>
//#include <nana/gui/widgets/label.hpp>
//#include <string>



#include "lib.hpp"
#include <string>


int fn_test(std::string (&battlefield_test)[9]){
    if ((battlefield_test[0] == battlefield_test[1]) && (battlefield_test[1] == battlefield_test[2]) && battlefield_test[2] != "") {
            return false;
        }
        else if((battlefield_test[3] == battlefield_test[4]) && (battlefield_test[4] == battlefield_test[5]) && battlefield_test[5] != "") {
            return false;
        }
        else if((battlefield_test[6] == battlefield_test[7]) && (battlefield_test[7] == battlefield_test[8]) && battlefield_test[8] != "") {
            return false;
        }
        else if((battlefield_test[0] == battlefield_test[3]) && (battlefield_test[3] == battlefield_test[6]) && battlefield_test[6] != "") {
            return false;
        }
        else if((battlefield_test[1] == battlefield_test[4]) && (battlefield_test[4] == battlefield_test[7]) && battlefield_test[7] != "") {
            return false;
        }
        else if((battlefield_test[2] == battlefield_test[5]) && (battlefield_test[5] == battlefield_test[8]) && battlefield_test[8] != "") {
            return false;
        }
        else if((battlefield_test[0] == battlefield_test[4]) && (battlefield_test[4] == battlefield_test[8]) && battlefield_test[8] != "") {
            return false;
        }
        else if((battlefield_test[2] == battlefield_test[4]) && (battlefield_test[4] == battlefield_test[6]) && battlefield_test[6] != "") {
            return false;
        }
        else {
            return true;
        }
}


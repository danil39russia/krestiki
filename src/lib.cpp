#include "lib.hpp"
#include <string>


int not_random() { return 3; }

int check_battlefield(int a, int b, int c){
    if ((a == b)&(b==c)) {
        return true;
    }
    else{
        return false;
    }
}
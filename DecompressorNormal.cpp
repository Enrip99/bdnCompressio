#include <iostream>
#include <string.h>
#include "LectorBits.h"

int main(){
    LectorBits lector("sortida.bdn");
    char llegit;
    while (llegit = lector.llegeixBit(), llegit != -1){
        if (llegit) std::cout << "a";
        else std::cout << "b";
    }
    std::cout << std::endl;
}
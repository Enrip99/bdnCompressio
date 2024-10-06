#include <iostream>
#include <string>
#include "LectorBits.hpp"

int main(){
    LectorBits lector("sortida.bdn");
    char llegit;
    while (llegit = lector.llegeixBit(), llegit != -1){
        if (llegit) std::cout << "1";
        else std::cout << "0";
    }
    std::cout << std::endl;
}
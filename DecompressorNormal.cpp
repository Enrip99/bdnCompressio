#include <iostream>
#include <string.h>
#include "LectorBits.h"

int main(){
    LectorBits lector("sortida.bdn");
    unsigned char llegit;
    while (llegit = lector.llegeixBit() != -1){
        std::cout << llegit;
    }
    std::cout << std::endl;
}
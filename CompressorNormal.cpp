#include <iostream>
#include <string>
#include "EscriptorBits.h"

int main(int argc, char *argv[]){
    
    /*
    if (argc != 3){
        std::cout << "Us: " << argv[0] << " <input> <output>" << std::endl;
        return 1;
    }
    */
    EscriptorBits escriptor("sortida.bdn");

    std::string input;
    while (std::cin >> input){
        for (int i = 0; i < input.length(); ++i){
            escriptor.escriuBit(input[i] != '0');
        }
    }
    escriptor.acabaEscriure();
    
    return 0;
}
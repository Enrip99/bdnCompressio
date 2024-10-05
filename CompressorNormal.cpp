#include <iostream>
#include <string>
#include <stdio.h>
#include "EscriptorBits.hpp"

#define midaBuffer 4096
#define bytesDiferents 256

int main(int argc, char *argv[]){
    
    /*
    if (argc != 3){
        std::cout << "Us: " << argv[0] << " <input> <output>" << std::endl;
        return 1;
    }
    */
    unsigned long long int llistatOcurrencies[bytesDiferents] = {0};

    FILE * entrada;
    entrada = fopen(argv[1], "r");
    __uint8_t bufferLectura[midaBuffer];
    int bytesLlegits;
    while ((!std::feof(entrada)) && (bytesLlegits = fread(bufferLectura, sizeof(__uint8_t), midaBuffer, entrada))){
        for (int i = 0; i < bytesLlegits; ++i){
            ++llistatOcurrencies[bufferLectura[i]];
        }
    }

    for (int i = 0; i < bytesDiferents; ++i){
        if (llistatOcurrencies[i]) std::cout << (char) i << " - " << llistatOcurrencies[i] << std::endl;
        
    }


   /*
    EscriptorBits escriptor("sortida.bdn");

    std::string input;
    while (std::cin >> input){
        for (int i = 0; i < input.length(); ++i){
            escriptor.escriuBit(input[i] != '0');
        }
    }
    escriptor.acabaEscriure();
    */
    
    return 0;
}
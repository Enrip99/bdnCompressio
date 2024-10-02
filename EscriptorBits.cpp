#include "EscriptorBits.h"

EscriptorBits::EscriptorBits(std::string fitxer){
    byteActual = 0;
    comptadorBit = 0;
    sortida.open(fitxer , std::ios::out | std::ios::trunc | std::ios::binary);
};

void EscriptorBits::escriuBit(bool bit){
    byteActual <<= 1;
    if (bit) ++byteActual;
    ++comptadorBit;
    if (!(comptadorBit % numBits)){
        sortida << byteActual;
    }
    
};

void EscriptorBits::acabaEscriure(){
    if (comptadorBit % numBits){
        while (comptadorBit % numBits){
            byteActual <<= 1;
            ++comptadorBit;
        }
        sortida << byteActual;
    }
    sortida.close();

};
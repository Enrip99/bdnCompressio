#include "EscriptorBits.h"

EscriptorBits::EscriptorBits(std::string fitxer){
    comptadorBit = 0;
    sortida.open(fitxer , std::ios::out | std::ios::trunc | std::ios::binary);
    llistaEscriure[0] = (__uint8_t) (numBits >> 8);
    llistaEscriure[1] = (__uint8_t) (numBits & 0x00FF);
};

void EscriptorBits::escriuBit(bool bit){
    llistaEscriure[comptadorBit/8 + bytesPadding] |= (__uint8_t) bit << (7 - (comptadorBit%8));
    ++comptadorBit;
    if (comptadorBit == numBits ){
        sortida.write(reinterpret_cast<char*>(llistaEscriure), midaArray);
        comptadorBit = 0;
        for (int i = bytesPadding; i < midaArray; ++i) llistaEscriure[i] = 0;
    }    
};

void EscriptorBits::acabaEscriure(){

    /*

    if (comptadorBit % numBits){
        while (comptadorBit % numBits){
            byteActual <<= 1;
            ++comptadorBit;
        }
        sortida << byteActual;
    }
    */
    sortida.close();

};
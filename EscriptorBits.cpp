#include "EscriptorBits.h"

EscriptorBits::EscriptorBits(std::string fitxer){
    llistaEscriure.reset();
    comptadorBit = numBits;
    sortida.open(fitxer , std::ios::out | std::ios::trunc | std::ios::binary);
};

void EscriptorBits::escriuBit(bool bit){
    llistaEscriure[--comptadorBit] = bit;
    if (!comptadorBit){
        unsigned int tempNumBits = numBits;
        sortida.write(reinterpret_cast<char*>(&tempNumBits), sizeof(tempNumBits));

        comptadorBit = numBits;
        llistaEscriure.reset();
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
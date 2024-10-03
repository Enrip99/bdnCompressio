#include "LectorBits.h"
#include <iostream>

LectorBits::LectorBits(std::string fitxer){
    comptadorBit = 0;
    entrada.open(fitxer, std::ios::in | std::ios::binary);
    entrada.read(reinterpret_cast<char*>(llistaLectura), midaArray);
    limitBloc = (llistaLectura[0] << 8) | (llistaLectura[1]);

    for (int i = 0; i < midaArray; ++i) std::cout << llistaLectura[i];

};

signed char LectorBits::llegeixBit(){
    if (comptadorBit == limitBloc){
        if (comptadorBit == numBits){
            comptadorBit = 0;
            entrada.read(reinterpret_cast<char*>(llistaLectura), midaArray);
            limitBloc = (llistaLectura[0] << 8) | (llistaLectura[1]);
            if (limitBloc == 0){
                entrada.close();
                return -1;
            }
        }
        else{
            entrada.close();
            return -1;
        }
    }

    signed char resultat = ((llistaLectura[comptadorBit/8 + bytesPadding]) >> (7 - (comptadorBit%8))) & 0x01;
    ++comptadorBit;
    return resultat;
};
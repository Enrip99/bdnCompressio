#ifndef LECTORBITS_H
#define LECTORBITS_H

#include <fstream>
#include <string.h>
#include "DimensionsIO.h"

class LectorBits{
    private:
        __uint8_t llistaLectura[midaArray];
        __uint16_t comptadorBit;
        __uint16_t limitBloc;
        std::ifstream entrada;

    public:
        //Constructora, entrada és un nom de fitxer
        LectorBits(std::string fitxer);

        //Llegeix bit del fitxer
        //Retorna 1 si el proper bit és true
        //Retorna 0 si el proper bit és false
        //Retorna -1 si EOF
        signed char llegeixBit();
};

#endif
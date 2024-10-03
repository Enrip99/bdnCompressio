#ifndef ESCRIPTORBITS_H
#define ESCRIPTORBITS_H

#include <stdio.h>
#include <string>
#include "DimensionsIO.hpp"

class EscriptorBits{
    private:
        __uint8_t llistaEscriure[midaArray];
        __uint16_t comptadorBit;
        FILE * sortida;

    public:
        //Constructora, sortida és un nom de fitxer
        EscriptorBits(std::string fitxer);

        //Escriu el bit al fitxer
        void escriuBit(bool bit);

        //Acaba d'omplir el fitxer abans de tancar
        void acabaEscriure();
};

#endif
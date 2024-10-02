#ifndef ESCRIPTORBITS_H
#define ESCRIPTORBITS_H

#include <fstream>
#include <string.h>
#include <iostream>

class EscriptorBits{
    private:
        __uint8_t byteActual;
        const int numBits = sizeof(byteActual) * __CHAR_BIT__;
        unsigned char comptadorBit;
        std::ofstream sortida;

    public :
        //Constructora, sortida és un nom de fitxer
        EscriptorBits(std::string sortida);

        //Escriu el bit al fitxer
        void escriuBit(bool bit);

        //Acaba d'omplir el fitxer abans de tancar
        void acabaEscriure();
};

#endif
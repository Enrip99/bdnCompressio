#ifndef ESCRIPTORBITS_H
#define ESCRIPTORBITS_H

#include <fstream>
#include <string.h>
#include <iostream>

//#define numBytes 4094
#define numBytes 3
#define numBits ( numBytes * 8 )
#define bytesPadding 2
#define midaArray ( numBytes + bytesPadding )

class EscriptorBits{
    private:
        __uint8_t llistaEscriure[midaArray];
        __uint16_t comptadorBit;
        std::ofstream sortida;

    public:
        //Constructora, sortida és un nom de fitxer
        EscriptorBits(std::string fitxer);

        //Escriu el bit al fitxer
        void escriuBit(bool bit);

        //Acaba d'omplir el fitxer abans de tancar
        void acabaEscriure();
};

#endif
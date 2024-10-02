#ifndef ESCRIPTORBITS_H
#define ESCRIPTORBITS_H

#include <fstream>
#include <string.h>
#include <iostream>
#include <bitset>

//#define numBits 32768
#define numBits 20

class EscriptorBits{
    private:
        std::bitset<numBits> llistaEscriure;
        unsigned int comptadorBit;
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
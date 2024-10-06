#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include "EscriptorBits.hpp"
#include "DimensionsIO.hpp"
#include "BinTree.hpp"

#define midaBuffer 4096

int main(int argc, char *argv[]){
    /*
    if (argc != 3){
        std::cout << "Us: " << argv[0] << " <input> <output>" << std::endl;
        return 1;
    }
    */

    unsigned long long int llistatOcurrencies[bytesDiferents] = {0};

    FILE * entrada = fopen(argv[1], "r");
    __uint8_t bufferLectura[midaBuffer];
    int bytesLlegits;

    std::multimap<unsigned long long int, BinTree<__uint8_t> > insercions;
    std::multimap<unsigned long long int, BinTree<__uint8_t> >::iterator iterador;
    unsigned long long int tempOcurrencia;
    BinTree<__uint8_t> tempArbre;

    //EscriptorBits escriptor(argv[2]);
    //EscriptorBits escriptor("sortida2.bdn");

    while ((!std::feof(entrada)) && (bytesLlegits = fread(bufferLectura, sizeof(__uint8_t), midaBuffer, entrada))){
        for (int i = 0; i < bytesLlegits; ++i){
            ++llistatOcurrencies[bufferLectura[i]];
        }
    }

    //Construir arbre

    for (unsigned int i = 0; i < bytesDiferents; ++i){
        if (llistatOcurrencies[i]){
            insercions.insert({
                llistatOcurrencies[i],
                BinTree<__uint8_t>((__uint8_t)(i & 0xFF))
            });
        }
    }

    iterador = insercions.begin();
    while (insercions.size() > 1){
        tempOcurrencia = iterador -> first;
        tempArbre = iterador -> second;
        iterador = insercions.erase(iterador);
        insercions.insert({
            tempOcurrencia + iterador -> first,
            BinTree<__uint8_t>(0, tempArbre, iterador -> second)
            });
        iterador = insercions.erase(iterador);
    }

    

    /*
    for (const auto& e : insercions){
        std::cout << e.first << " " << e.second.value() << std::endl;
    }
    */


    //Escriure Arbre
        // recorda que no cal escriure res de les freqüències



    //Llegir un altre cop el fitxer i comprimir-ho
    /*
    std::fseek(entrada, 0, SEEK_SET);
    std::clearerr(entrada);
    while ((!std::feof(entrada)) && (bytesLlegits = fread(bufferLectura, sizeof(__uint8_t), midaBuffer, entrada))){
        for (int i = 0; i < bytesLlegits; ++i){
            //write bits
        }
    }
    escriptor.acabaEscriure();
    std::fclose(entrada);
    */
    
    return 0;
}
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stdio.h>
#include "EscriptorBits.hpp"
#include "DimensionsIO.hpp"
#include "BinTree.hpp"

#define estructuraParella std::pair<__uint8_t, unsigned long long int>
#define estructuraArbre BinTree < estructuraParella >
#define estructuraCache std::map<__uint8_t, std::vector<bool> >


int main(int argc, char *argv[]){
    
    if (argc != 3){
        std::cout << "Us: " << argv[0] << " <input> <output>" << std::endl;
        exit(1);
    }

    estructuraArbre arbreAdaptatiu (estructuraParella {0,0});
    //Arbre sobre el qual crearem la codificació de Huffman adaptativa.
    //first: byte que codifica en cas de ser una fulla no NYT.
    //second: nombre d'iteracions del node. 0 per NYT.
    //S'inicia amb el node NYT.

    estructuraCache cacheArbre;
    //Mapa amb els bits que corresponen a cada byte per poder comprimir sense recòrrer l'arbre.

    std::vector<bool> cacheNYT;
    //bits que corresponen a NTY. S'emmagatzema fora del map.

    std::map<uint_least8_t, std::vector<bool>>::iterator posicio;
    //Iterador per trobarun byte a la caché de l'arbre.

    std::vector <bool> cacheByteActual;
    //Camí al node de l'ultim byte que hem llegit.

    FILE * entrada = fopen(argv[1], "r");
    __uint8_t bufferLectura[midaBuffer];
    int bytesLlegits;
    //Obrim fitxer a llegir, primer argument de la linia de comanda.
    //Variables per assistir a la lectura a baix nivell.

    EscriptorBits escriptor(argv[2]);
    //Objecte per escriure el fixter comprimit a disc.


    //Procès principal
    //
    //Llegim el fitxer d'entrada sencer

    estructuraArbre arbreTemporal, fullaIncrementar;
    bool nouNode;

    while ((!std::feof(entrada)) && (bytesLlegits = fread(bufferLectura, sizeof(__uint8_t), midaBuffer, entrada))){
        for (int i = 0; i < bytesLlegits; ++i){

            //Mirem si hem enregistrat ja aquest byte abans 

            posicio = cacheArbre.find(bufferLectura[i]);

            arbreTemporal = estructuraArbre(arbreAdaptatiu);

            if (posicio == cacheArbre.end()){

                //Si no el coneixem, escrivim a la sortida el camí a NYT seguit del byte nou a codificar.

                for (int j = 0; j < cacheNYT.size(); ++j) escriptor.escriuBit(cacheNYT[j]);
                escriptor.escriuBit(bufferLectura[i] & 0b10000000);
                escriptor.escriuBit(bufferLectura[i] & 0b01000000);
                escriptor.escriuBit(bufferLectura[i] & 0b00100000);
                escriptor.escriuBit(bufferLectura[i] & 0b00010000);
                escriptor.escriuBit(bufferLectura[i] & 0b00001000);
                escriptor.escriuBit(bufferLectura[i] & 0b00000100);
                escriptor.escriuBit(bufferLectura[i] & 0b00000010);
                escriptor.escriuBit(bufferLectura[i] & 0b00000001);

                cacheByteActual = cacheNYT;
                cacheByteActual.push_back(1);

                //Obtenim el node a manipular

                for (int j = 0; j < cacheNYT.size(); ++j){
                    if (cacheNYT[j]) arbreTemporal = arbreTemporal.right();
                    else arbreTemporal = arbreTemporal.left();
                }

                nouNode = true;

            }
            else{

                //Si ja el coneixíem, escrivim a la sortida el camí al seu node.

                cacheByteActual = posicio->second;

                for (int j = 0; j < cacheByteActual.size(); ++j){
                    escriptor.escriuBit(cacheByteActual[j]);

                    //Obtenim el node a manipular

                    if (cacheByteActual[j]) arbreTemporal = arbreTemporal.right();
                    else arbreTemporal = arbreTemporal.left();
                }

                nouNode = false;

            }

            //Aqui fem el processament de veritat

            fullaIncrementar = estructuraArbre();

            if (nouNode){
                arbreTemporal.addChildren(
                   estructuraArbre (estructuraParella {0,0}),
                   estructuraArbre (estructuraParella {bufferLectura[i],0})
                );
                fullaIncrementar = arbreTemporal.right();
            }
            else {
                // Swap líder bloc

                //if (nou p == germà de NYT){
                //  fullaIncrementar = arbreTemporal;
                //  arbreTemporal = arbreTemporal.parent();
                //}
            }

            while(! arbreTemporal.empty()){
                //Incrementa(arbreTemporal);
            }

            if (! fullaIncrementar.empty()){
                //Incrementa(fullaIncrementar);
            }
        }
    }

    std::fclose(entrada);
    
    return 0;

}

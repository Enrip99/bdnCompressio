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

void rebalancejaArbre(estructuraArbre & arbre, std::vector<bool> & ultimModificat, std::vector<bool> & cacheNYT, estructuraCache cacheArbre){
    std::queue<estructuraArbre> cua;
    bool modificat = false;
    estructuraArbre nodeModificat(arbre);
    for (int i = 0; i < ultimModificat.size(); ++i){
        if (ultimModificat[i]) arbre = arbre.right();
        else arbre = arbre.left();
    }
    cua.push(arbre);
    while(! cua.empty()){
        if (cua.front().right().equals(nodeModificat) ){
            // reiterar per pare????
        }
        else if (cua.front().right().value().second < nodeModificat.value().second){
            // swap; què fer desrpés???
        }
        else if (cua.front().left().equals(nodeModificat) ){
            // reiterar per pare????
        }
        else if (cua.front().left().value().second < nodeModificat.value().second){
            // swap; què fer desrpés???
        }
    }
}


void addByteToTree(__uint8_t nouByte, estructuraArbre & arbre, std::vector<bool> & cacheNYT, estructuraCache cacheArbre){
    estructuraArbre arbreAux(arbre);

    //Trobem el node arbre indicat per cacheNYT.

    for (int i = 0; i < cacheNYT.size(); ++i){
        if (cacheNYT[i]) arbreAux = arbreAux.right();
        else arbreAux = arbreAux.left();
    }

    //Actualitzem el seu valor i afegim com a fills un "nou" NYT i el byte que acabem de trobar.

    arbreAux.setValue(estructuraParella {0,1});
    arbreAux.addChildren(
        estructuraArbre (estructuraParella {0,0}),
        estructuraArbre (estructuraParella {nouByte,1})
    );

    //Actualitzem les caches.

    cacheArbre[nouByte] = cacheNYT;
    cacheNYT.push_back(0);
    cacheArbre[nouByte].push_back(1);
}


void increaseByteOccurrence(estructuraArbre & arbre, std::vector<bool> & camiNode){
    estructuraParella parellaTemp;

    //Trobem el node arbre indicat per camiNode.

    for (int i = 0; i < camiNode.size(); ++i){
        if (camiNode[i]) arbre = arbre.right();
        else arbre = arbre.left();
    }

    //Incrementem en 1 el seu valor.
        
    parellaTemp = arbre.value();
    ++parellaTemp.second;
    arbre.setValue(parellaTemp);
}


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

    //FILE * entrada = fopen(argv[1], "r");
    __uint8_t bufferLectura[midaBuffer];
    int bytesLlegits;
    //Obrim fitxer a llegir, primer argument de la linia de comanda.
    //Variables per assistir a la lectura a baix nivell.

    EscriptorBits escriptor(argv[2]);
    //Objecte per escriure el fixter comprimit a disc.


    BinTree<int> un (0, BinTree<int>(1), BinTree<int>(2));
    BinTree<int> dos (5, BinTree<int>(6), BinTree<int>(7));

    BinTree<int> tres = un.left();
    BinTree<int> quatre = dos.left();

    std::cout << dos.value() << " - ";
    //std::cout << tres.value() << " - ";

    tres.swap(quatre);

    std::cout << dos.left().value() << " - ";
    //std::cout << tres.value() << std::endl;



    fflush(stdout);


    //Procès principal
    //
    //Llegim el fitxer d'entrada sencer
/*
    while ((!std::feof(entrada)) && (bytesLlegits = fread(bufferLectura, sizeof(__uint8_t), midaBuffer, entrada))){
        for (int i = 0; i < bytesLlegits; ++i){

            //Mirem si hem enregistrat ja aquest byte abans 

            posicio = cacheArbre.find(bufferLectura[i]);

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

                //Tot seguit, l'afegim a l'arbre penjant d'on era NYT, amb una freqüència de 1.

                addByteToTree(bufferLectura[i], arbreAdaptatiu, cacheNYT, cacheArbre);
            }
            else{

                //Si ja el coneixíem, escrivim a la sortida el camí al seu node.

                cacheByteActual = posicio->second;
                for (int j = 0; j < cacheByteActual.size(); ++j) escriptor.escriuBit(cacheByteActual[j]);

                //Tot seguit, augmentem la seva freqüència en 1, 

                increaseByteOccurrence(arbreAdaptatiu, posicio->second);
            }

            //Independenment de si és nou o no, mirem si cal reordenar l'arbre.

            rebalancejaArbre(arbreAdaptatiu, cacheByteActual, cacheNYT, cacheArbre);
        }
    }
*/
    //std::fclose(entrada);
    
    return 0;

}

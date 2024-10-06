#include <iostream>
#include <string>
#include "LectorBits.hpp"
#include "DimensionsIO.hpp"
#include "BinTree.hpp"

void errorLectura(){
    perror("Error en llegir el fitxer.");
    exit(1);
}

void llegeixArbre(BinTree<__uint8_t>& arbre, LectorBits & lector){
    signed char llegit = lector.llegeixBit();
    if (llegit == 0){
        BinTree<__uint8_t> l;
        llegeixArbre(l, lector);
        BinTree<__uint8_t> r;
        llegeixArbre(r, lector);
        arbre = BinTree<__uint8_t>(0, l, r);
    }
    else if (llegit == 1){
        __uint8_t properByte = 0x00;
        for (int i = 7; i >= 0; --i){
            llegit = lector.llegeixBit();
            if (llegit == -1) errorLectura();
            properByte |= (llegit << i);
        }
        arbre = BinTree<__uint8_t>(properByte);
    }
    else errorLectura();
}

void write_bintree_int(const BinTree<__uint8_t> &a)
{
        if (not a.empty()) {
                int x = a.value();
                write_bintree_int(a.left());
                std::cout << " " << x;
                write_bintree_int(a.right());
  }
}



int main(int argc, char *argv[]){

    if (argc != 3){
        std::cout << "Us: " << argv[0] << " <input> <output>" << std::endl;
        return 1;
    }

    LectorBits lector(argv[1]);
    char llegit;
    BinTree<__uint8_t> arbreHuffman, arbreRecorrer;



    //construir arbre

    llegeixArbre(arbreHuffman, lector);


    arbreRecorrer = BinTree<__uint8_t> (arbreHuffman);
    //write_bintree_int(arbreRecorrer);
    while(llegit = lector.llegeixBit(), llegit != -1){
        if (llegit == 0){
            //esquerra
            arbreRecorrer = arbreRecorrer.left();
        }
        else{
            //dreta
            arbreRecorrer = arbreRecorrer.right();
        }
        if (arbreRecorrer.left().empty()){
            std::cout << arbreRecorrer.value();
            arbreRecorrer = BinTree<__uint8_t> (arbreHuffman);
        }
    }



}
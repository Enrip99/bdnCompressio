#include <iostream>
#include <fstream>
#include <string.h>

std::ofstream out("sortida.bdn");
__uint8_t byteActual = 0;
const int numBits = sizeof(byteActual) * __CHAR_BIT__;
unsigned char comptadorBit = 0;

void escriuBit(bool bit){
    byteActual <<= 1;
    if (bit) ++byteActual;
    ++comptadorBit;
    if (!(comptadorBit % numBits)){
        out << byteActual;
    }
}

void acabaEscriure(){
    if (comptadorBit % numBits){
        while (comptadorBit % numBits){
            byteActual <<= 1;
            ++comptadorBit;
        }
        out << byteActual;
    }
    out.close();
}

int main(){

    std::string input;
    while (std::cin >> input){
        for (int i = 0; i < input.length(); ++i){
            escriuBit(input[i] != '0');
        }
    }
    acabaEscriure();
    
    return 0;
}
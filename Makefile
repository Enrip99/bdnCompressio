CC=g++
CXXFLAGS=-std=c++11

all: compress_normal descompress_normal

compress_normal: CompressorNormal.o EscriptorBits.o EscriptorBits.hpp DimensionsIO.hpp BinTree.hpp
	$(CC) -o CompressorNormal CompressorNormal.o EscriptorBits.o

descompress_normal: DescompressorNormal.o LectorBits.o LectorBits.hpp DimensionsIO.hpp BinTree.hpp
	$(CC) -o DescompressorNormal DescompressorNormal.o LectorBits.o

clean: 
	rm -f *.o CompressorNormal DescompressorNormal

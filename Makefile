CC=g++
CXXFLAGS=-std=c++11

all: compress_normal decompress_normal

compress_normal: CompressorNormal.o EscriptorBits.o EscriptorBits.hpp DimensionsIO.hpp BinTree.hpp
	$(CC) -o CompressorNormal CompressorNormal.o EscriptorBits.o

decompress_normal: DecompressorNormal.o LectorBits.o LectorBits.hpp DimensionsIO.hpp BinTree.hpp
	$(CC) -o DecompressorNormal DecompressorNormal.o LectorBits.o

clean: 
	rm -f *.o CompressorNormal DecompressorNormal

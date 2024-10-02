CC=g++
CXXFLAGS=-std=c++11

all: compress_normal

compress_normal: CompressorNormal.o EscriptorBits.o EscriptorBits.h
	$(CC) -o CompressorNormal CompressorNormal.o EscriptorBits.o

clean: 
	rm -f *.o CompressorNormal

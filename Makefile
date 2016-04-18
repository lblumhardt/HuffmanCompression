# A simple makefile for CSE 100 PA2

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: compress uncompress

compress: HCNode.o HCTree.o

uncompress: HCNode.o HCTree.o

HCTree.o: HCNode.hpp HCTree.hpp

HCNode.o: HCNode.hpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

cpress:
	g++ -g -o compress HCNode.cpp compress.cpp

upress:
	g++ -g -o uncompress HCNode.cpp uncompress.cpp

clean:
	rm -f compress uncompress *.o core*


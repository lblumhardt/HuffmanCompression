# A simple makefile for CSE 100 PA2

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: compress uncompress

HCTree.o: HCNode.hpp HCTree.hpp

HCNode.o: HCNode.hpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

compress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o
	g++ -g -o compress compress.cpp BitOutputStream.cpp BitInputStream.cpp HCNode.cpp	

uncompress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o 
	g++ -g -o uncompress uncompress.cpp BitOutputStream.cpp BitInputStream.cpp HCNode.cpp	

clean:
	rm -f compress uncompress *.o core*


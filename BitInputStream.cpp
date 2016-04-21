#include "BitInputStream.hpp"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

BitInputStream::BitInputStream(istream & is) : in(is) {
    buf = 0;
    first = 1;
    nbits = 8;
}



void BitInputStream::fill() {
  buf = in.get();
  //in.read((char*)&buf, sizeof(buf));
  if(first == 1) {
    buf = in.get();
    first = 0;
  }
  cout << "\n \n \n";
  cout << "we calling fill again and our buffer is " << std::bitset<8>(buf) << " \n";
  cout << "\n \n \n";
  nbits = 0;
}

int BitInputStream::readBit() {
  if(nbits == 8) {
    fill();
  }
  
 /* if(buf == EOF) {
    cout << "this is the EOF line in BitInputStream and shouldnt be printed \n";
    return -1;
  }*/
  unsigned char mask = 1;
  mask = mask << (7-nbits);
  
  mask = mask & buf;
  nbits++;
  if(mask == 0) {
    cout << "bit being returned is 0 \n";
    return 0;
  }
  else {
    cout << "bit being returned is 1 \n";
    return 1;
  } 
 
/*
 
  unsigned char mask = buf >> (7-nbits);
  mask = mask & 1;  


  nbits++;
  return (int)mask; */
}

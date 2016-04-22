/* Lucas Blumhardt A12020745
 * This class reads the contents of a file using an istream and 1 byte buffer
 * */
#include "BitInputStream.hpp"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

BitInputStream::BitInputStream(istream & is) : in(is) {
    buf = 0;
    nbits = 8;
}



void BitInputStream::fill() {
  buf = in.get();
  nbits = 0;
}

int BitInputStream::readBit() {
  if(nbits == 8) {
    fill();
  }
  
  //uses a mask to extract the nbits'th bit
  unsigned char mask = 1;
  mask = mask << (7-nbits); 
  mask = mask & buf;
  nbits++;
  if(mask == 0) {
    return 0;
  }
  else {
    return 1;
  } 
}

#include "BitInputStream.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

void BitInputStream::fill() {
  buf = in.get();
  nbits = 0;
}

int BitInputStream::readBit() {
  if(nbits == 8) {
    fill();
  }
  
  unsigned char mask = buf >> (7-nbits);
  mask = mask & 1;  


  nbits++;
  return (int)mask;
}

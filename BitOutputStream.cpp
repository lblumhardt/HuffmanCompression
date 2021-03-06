/* Lucas Blumhardt A12020745
 * This class fills a 1 byte buffer bit by bit until the buffer is full, then
 * writes it to the ostream 
 * */
#include "BitOutputStream.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

/* send the buffer to the output stream and clear it */
void BitOutputStream::flush() {
  out.put(buf);
  out.flush();
  buf = nbits = 0;
}

/* Write the least significant bit of the argument to te bit buffer, and 
 * increment the bit buffer index. But flush the buffer first if full
 * */
void BitOutputStream::writeBit(int i) {
  //is the bit buffer full? then flush it
  if(nbits == 8) {
    flush();
  }
  
  //if the int is 1, we must put the bit 1 into the buffer
  unsigned char mask = 1;
  if(i == 1) {
    mask = mask << (7 - nbits);
    buf = buf | mask;
  } 
  //if the int is 0, we must put the bit 0 into the buffer
  if(i == 0) {
    mask = mask << (7 - nbits);
    mask = ~mask;
    buf = buf & mask;
  } 
  nbits++; 
}

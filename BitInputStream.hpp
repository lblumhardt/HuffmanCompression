#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP

#include <iostream>

using namespace std;

class BitInputStream {
private:
  char buf;
  int nbits;        //how many bits have been read from the buffer
  istream& in;
public:

  /* Initialize a BitInputStream that will use the given istream for input
 * */
  BitInputStream(istream & is) : in(is) {
    buf = 0;
    nbits = 8;
  }

  /* Fill the buffer from the input */
  void fill();
  
  /* Read the next bit from the bit buffer. Fill the buffer form the input
 * stream first if needed.
 * Return 1 if the bit read is 1, 0 if bit read is 0
 * */
  int readBit();
};

#endif

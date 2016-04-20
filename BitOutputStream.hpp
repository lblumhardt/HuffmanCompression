#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP

#include <iostream>

using namespace std;

class BitOutputStream {
private:
  char buf;
  int nbits;
  ostream& out;
public:

  /* Initialize a BitOutputStream that will use the given ostream for output
 * */
  BitOutputStream(ostream & os) : out(os), buf(0), nbits(0) {
    //clear buffer and bit counter
  }

  /* Send the buffer to the output and clear it */
  void flush();
  
  /* Write the least significant bit of the argument to the bit buffer,
 * and increment the bit buffer index. But flush the buffer first, if it's full
 * */
  void writeBit(int i);
};

#endif

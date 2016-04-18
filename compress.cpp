/* Lucas Blumhardt A12020745
 * compress program. Creates a huffman tree from the input file and encodes
 * the data into an output file along with a header which consists of the
 * characters' frequencies in the input file.
 * */
#include "HCTree.cpp"
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
  
  //checks valid number of command args
  if(argc != 3) {
    cout << "Incorrect number of command line arguments passed. Should be 2 \n";
    return -1;
  } 
  
  std::ifstream input(argv[1], std::ifstream::in);
 
  std::ifstream input2(argv[1], std::ifstream::in);
  unsigned char nextChar;
  int nextByte;
  
  //Increments the frequency of each ASCII char as it is encountered in the 
  //input file
  std::vector<int> vec(256,0);
  
  if(input.peek()!= EOF) {
   
    while((nextByte = input.get()) != EOF) {
      cout << "we entered? \n";
      nextChar = (unsigned char)nextByte;
      vec[nextByte] = vec[nextByte] + 1;
    } 
  }
  
  
  input.close();
  
  //build the Huffman Tree with frequency vector
  HCTree t;
  t.build(vec);
  
  std::ofstream out(argv[2], std::ofstream::out);
  //std::ifstream input2 (argv[1], std::ifstream::in);
  
  //write the header so file can be decoded
  for(int i=0; i < vec.size(); i++) {
    out << vec[i] << "\n"; 
    cout << "should get 256 o deez \n";
  }
  
  //encodes each symbol and writes to the output  
  while((nextByte = input2.get()) != EOF) {
    nextChar = (unsigned char)nextByte;
    t.encode(nextChar, out);
  }
 
  out.close();
  input2.close();
  return 1;
}

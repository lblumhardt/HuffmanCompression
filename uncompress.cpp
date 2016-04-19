/* Lucas Blumhardt A12020745
 * uncompress program. Creates a huffman tree from the input file's header
 * and decodes the string of ASCII 1s and 0s in the file
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

  HCTree t;

  std::ifstream input(argv[1], std::ifstream::in);
  std::ofstream output(argv[2], std::ofstream::out); 
  vector<int> freqs(256,0);
  int temp;
  //converting the header into a vector to build a huffman tree with
  for(int i=0; i < freqs.size(); i++) {
    input >> temp;
    freqs[i] = temp;  
    //cout << temp << "\n";
  }
  
  t.build(freqs);
  int nextByte;
  unsigned char nextChar;
  int decodedInt;
   
  while((nextByte = input.peek()) != EOF) {
    decodedInt = t.decode(input);
    
    //corner case the file is meant to be empty
    if(decodedInt == -1) {
      break;
    }
    if(decodedInt != -1) {
      nextChar = (unsigned char)decodedInt;
      output << nextChar;
    }
  }
  
  input.close();
  output.close();
}

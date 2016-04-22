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
  int numOfBits = 0;
  HCTree t;

  std::ifstream input(argv[1], ios::binary);
  std::ofstream output(argv[2], std::ofstream::out); 
  BitInputStream bitin(input); 
  vector<int> freqs(256,0);
  int temp;
  if(input.peek() == EOF) {
    input.close();
    output.close();
    return 1;
  }
  //converting the header into a vector to build a huffman tree with
  for(int i=0; i < freqs.size(); i++) {
    input.read((char*)&temp, 3*sizeof(char));
    //input >> temp; 
    freqs[i] = temp;
    numOfBits = numOfBits + temp; 
  }
  
  //everything above works p good
  t.build(freqs);
  unsigned char nextChar;
  int decodedInt;
  int currentNumOfBits = 0;
  while(/*input.peek() != EOF*/ true) {
    decodedInt = t.decode(bitin);
    //cout << "decode returned this int " << decodedInt << "\n"; 
    currentNumOfBits++;
    //corner case the file is meant to be empty
    if(decodedInt == -1) {
      break;
    }
    if(decodedInt != -1) {
      nextChar = (unsigned char)decodedInt;
      output << nextChar;
    }
    if(currentNumOfBits == numOfBits) {
      break;
    }
  }
  //output << (unsigned char)t.decode(bitin); 
  input.close();
  output.close();
}

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
  
  std::ifstream input(argv[1], ios::binary);
 
  std::ifstream input2(argv[1], ios::binary);
  unsigned char nextChar;
  int nextByte;
  bool emptyFile = true; 
  bool onlyOneChar = true;
  //Increments the frequency of each ASCII char as it is encountered in the 
  //input file
  std::vector<int> vec(256,0);
  
  unsigned char firstChar = (unsigned char)input.peek();
  if(input.peek()!= EOF) {
    emptyFile = false;
    while((nextByte = input.get()) != EOF) {
      //cout << "we entered? \n";
      nextChar = (unsigned char)nextByte;
      if(firstChar != nextChar) {
        //cout << "there is more than 1 type of char in herer \n";
        onlyOneChar = false;
      }
      vec[nextByte] = vec[nextByte] + 1;
    } 
  }
 
  input.close();
  std::ofstream out(argv[2], std::ofstream::out); 
  if(emptyFile == true) {
    input2.close();
    out.close();
    return 1;
  }

  if(onlyOneChar == true) {
  
  }
  //build the Huffman Tree with frequency vector
  HCTree t;
  t.build(vec);

  //std::ofstream out(argv[2], std::ofstream::out);
    
  //write the header so file can be decoded
  for(int i=0; i < vec.size(); i++) {
    //out << vec[i] << "\n"; 
    //cout << "should get 256 o deez \n";
    out.write((char*)&vec[i],3*sizeof(char));
  }

//this part of the code is for the ASCII encoding. not binary  
/*  //encodes each symbol and writes to the output  
  while((nextByte = input2.get()) != EOF) {
    nextChar = (unsigned char)nextByte;
    t.encode(nextChar, out);
  }
*/

  BitOutputStream bitout(out);
  while((nextByte = input2.get()) != EOF) {
    nextChar = (unsigned char)nextByte;
    //cout << "encoding " << nextChar << "\n";
    t.encode(nextChar, bitout);
  } 
  bitout.flush();
  out.close();
  input2.close();
  return 1;
}

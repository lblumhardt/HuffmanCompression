#include "HCTree.cpp"
#include <vector>
#include <iostream>

int main() {

  cout << "titays \n";

  //testing build for HCTree
/*  std::vector<int> v(256);
  v.push_back(1);
  v.push_back(0);
  v.push_back(10);
  HCTree t;
  t.build(v);
  
  //Testing node comparator?
  
  
  HCNode n3(1, 10, 0, 0, 0);
  HCNode n4(1, 99, 0, 0, 0);
  
  HCNode n5(3, 'x', 0, 0, 0);

  bool b1 = n3 < n4;
  bool b2 = n4 < n3;
  bool b3 = n4 < n5;

  cout << "newline is less than c " << b1 << "\n";
  cout << "c is less than newline " << b2 << "\n";
  cout << "is 'b' less than 'x'? " << b3 << "\n";
*/
  //testing decode;
/*  std::ifstream ifs ("testFile.txt", std::ifstream::in);
  unsigned char nextChar;
  int nextByte;
  std::vector<int> vec(256,0);
  while((nextByte = ifs.get()) != EOF) {
    nextChar = (unsigned char)nextByte;
    vec[nextByte] = vec[nextByte] + 1;
    cout << nextChar;
    
  }*/
//  ifs.close();
//  HCTree actual;
//  actual.build(vec);
  
 // std::ofstream out("encodedTestFile.txt", std::ofstream::out);
//  std::ifstream ifs2 ("testFile.txt", std::ifstream::in);
 // while((nextByte = ifs2.get()) != EOF) {
   // nextChar = (unsigned char)nextByte;
  //  actual.encode(nextChar, out);
 // }
//  out.close();
 
 // ifs2.close();
  
  //testing decode
  //std::ifstream ifs3("encodedTestFile.txt", std::ifstream::in);
  //std::ofstream out3("decodedTestFile.txt", std::ofstream::out); 
  
 // while((nextByte = ifs3.peek()) != EOF) {
    //nextChar = (unsigned char)actual.decode(ifs3);
    //cout << nextChar;
    //out3 << nextChar;
  // }
  
  int theint = -1;
  unsigned char mellow = (unsigned char)theint;
  theint = (int)mellow;
  cout << mellow << "\n";
  cout << theint << "\n";
//  ifs.close();
  return 1;
}

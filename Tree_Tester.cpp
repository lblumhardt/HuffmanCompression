#include "HCTree.cpp"
#include <vector>
#include <iostream>

int main() {
  cout << "titays \n";

  //testing build for HCTree
  std::vector<int> v(256);
  v.push_back(1);
  v.push_back(0);
  v.push_back(10);
  HCTree t;
  t.build(v);
  
  //Testing node comparator?
  
  
  HCNode n3(10, 'a', 0, 0, 0);
  HCNode n4(3, 'b', 0, 0, 0);
  
  HCNode n5(3, 'x', 0, 0, 0);

  bool b1 = n3 < n4;
  bool b2 = n4 < n3;
  bool b3 = n4 < n5;

  cout << "n3 is less than n4 " << b1 << "\n";
  cout << "n4 is less than n3 " << b2 << "\n";
  cout << "is 'b' less than 'x'? " << b3 << "\n";




  return 1;
}

#include "HCTree.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


HCTree::~HCTree() {
  cout << "destructor \n";
}

void HCTree::build(const vector<int>& freqs) {
  cout << "fruck \n";
  
  //loop through freqs and makes HCNode pointers to put into leaves 
  vector<int>::const_iterator it = freqs.begin(); 
  std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> pq;
  for(int i = 0; i < freqs.size(); i++) { 
    if(freqs[i] != 0) {
      cout << "im making a node " << freqs[i] << "\n";
      HCNode* temp = new HCNode(freqs[i], i, 0, 0, 0);
      leaves[i] = temp;
      
      //puts the node into a min heap
      pq.push(temp);
    }
  }
 
  while(pq.size() > 1) {
  
  }    
    
   
  
}


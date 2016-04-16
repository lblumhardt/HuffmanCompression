#include "HCTree.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


HCTree::~HCTree() {
  cout << "destructor \n";
}

void HCTree::build(const vector<int>& freqs) {
  cout << "entering build \n";
  
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
 
  //combines the two least frequent nodes at a time until a huffman tree is built 
  int frequencySum = 0;
  while(pq.size() > 1) {
    HCNode* smallest = pq.top();
    pq.pop();
    HCNode* second = pq.top();
    pq.pop();
    frequencySum = smallest->count + second->count;
    HCNode* parent = new HCNode(frequencySum, smallest->symbol, smallest, second, 0);
    smallest->p = parent;
    second->p = parent;
    pq.push(parent); 
  }    
    
  //right here pq should hold the pointer to the top node of huffman tree 
  
}

void HCTree::encode(byte symbol, ofstream& out) const {

  HCNode* curr = leaves[symbol];
  
}

int HCTree::decode(ifstream& in) const {
  
  unsigned char nextChar;
  int next;
  in.open("testerFile.txt");
  while((next = in.get()) != EOF) {
    nextChar = (unsigned char)next;
    cout << next;
    cout << nextChar;
  }
  return 1;
}

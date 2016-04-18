#include "HCTree.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


HCTree::~HCTree() {
  deleteAll(root);
}

void HCTree::build(const vector<int>& freqs) {
  
  
  //loop through freqs and makes HCNode pointers to put into leaves 
  vector<int>::const_iterator it = freqs.begin(); 
  std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> pq;
  for(int i = 0; i < freqs.size(); i++) { 
    if(freqs[i] != 0) {
        
      HCNode* temp = new HCNode(freqs[i], i, 0, 0, 0);
      leaves[i] = temp;
      
      //puts the node into a min heap
      pq.push(temp);
    }
  }
 
  //combines the two least frequent nodes at a time until a huffman tree is built 
  int frequencySum = 0;
  if(pq.size() == 1) {
    HCNode* curr = pq.top();
    HCNode* newRoot = new HCNode(curr->count, curr->symbol, curr, 0, 0);
    curr->p = newRoot;
    cout << "made single node of frequency " << curr->count << "\n";
    root = newRoot;
    return;   
  }
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
  if(pq.size() == 0) {
    HCNode* empty = new HCNode(0, -1, 0, 0, 0);
    root = empty;
    return;
  }  
  //right here pq should hold the pointer to the top node of huffman tree 
  root = pq.top(); 
   
}

void HCTree::encode(byte symbol, ofstream& out) const {
  
  if(!out.is_open()) {
    cout << "The input file wasn't properly opened. \n";
    return;
  } 
  vector<unsigned char> code;
  HCNode* curr = leaves[symbol];
  while(curr->p != 0) {
    //is this going to be backwards? perhaps. lets test
    if (curr->p->c0 == curr){
      //its 0
      //out << '0';
      code.push_back('0');
    }
    else {
      //its 1
      //out << '1';
      code.push_back('1');
    } 
    curr = curr->p;
  }
  while(!code.empty()) {
    out << code.back();
    code.pop_back();
  }
  
}


/* decode method. Takes the input from the ifstream and traverses the Huffman
 * Tree according to the bits (actually ASCII 1s and 0s) to determine what 
 * symbol this binary string represents
 * */
int HCTree::decode(ifstream& in) const {
  
  unsigned char nextChar;
  int next;
 
  //checking if file was opened correctly
  if(!in.is_open()) {
    cout << "The input file wasn't properly opened. \n";
    return -1;
  }

  //descends the huffman tree
  HCNode* curr = root; 
  if(root->symbol == -1) {
    return -1;
  }
  if(curr->c0 == 0 && curr->c1 == 0) {
    return -1;
  }  

  //double check this while condition. i think it works bc tree is full
  while(in.peek() != EOF && curr->c0 != 0) {
    next = in.get();
    nextChar = (unsigned char)next;
    if(nextChar == '1') {
      curr = curr->c1;
    }
    if(nextChar == '0') {
      curr = curr->c0;
    }
    if(curr->c1 == 0) {
      break;
    } 
    //cout << nextChar;
  }
  return (unsigned char)curr->symbol;
}


void HCTree::deleteAll(HCNode* curr) {
  if(curr == 0) {
    return;
  }
  deleteAll(curr->c1);
  deleteAll(curr->c0);
  delete curr;
}


/* Lucas Blumhardt A12020745
 * Class that can construct a Huffman Code tree from a vector of ints (frequencies)
 * This class encodes and decodes messages by traversing it's tree, the root of
 * which is a member variable
 * */
#include "HCTree.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

//tree deletes nodes recursively
HCTree::~HCTree() {
  deleteAll(root);
}

/* build
 * this method only works if freqs is a vector of size 256 where each index
 * corresponds to the ASCII char of that value.
 * */
void HCTree::build(const vector<int>& freqs) {
  
  //loop through freqs and makes HCNode pointers to put into leaves 
  vector<int>::const_iterator it = freqs.begin(); 
  std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> pq;
  for(int i = 0; i < freqs.size(); i++) { 
    if(freqs[i] != 0) {  
      HCNode* temp = new HCNode(freqs[i], i, 0, 0, 0);
      leaves[i] = temp;
      //organize node into a min heap
      pq.push(temp);
    }
  }
 
  //corner case where file being encoded consists of only one char
  if(pq.size() == 1) {
    HCNode* curr = pq.top();
    HCNode* newRoot = new HCNode(curr->count, curr->symbol, curr, 0, 0);
    curr->p = newRoot;
    root = newRoot;
    return;   
  }
 
  //combines two smallest nodes into a tree, the pushes that tree's root back
  //into the heap
  //Smaller of the two nodes becomes the 0 child
  //Smaller of the two nodes has its symbol implanted into the parent node
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
    //cout << parent->symbol << " is the parent of 0 child " << smallest->symbol << " and 1 child " << second->symbol << "\n";
    pq.push(parent); 
  }    
  
  //coner case where file being encoded is empty. the -1 count. In later methods
  //it is convenient that the root lacks both a parent and children
  if(pq.size() == 0) {
    HCNode* empty = new HCNode(0, -1, 0, 0, 0); 
    root = empty;
    return;
  }  
  //right here pq should hold the pointer to the top node of huffman tree 
  root = pq.top();  
}

/* encodes the byte passed by finding it in the leaves vector and traversing
 * up the Huffman Tree and recording the 0 and 1 children
 * */
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
      code.push_back('0');
    }
    else {
      //its 1
      code.push_back('1');
    } 
    curr = curr->p;
  }
  while(!code.empty()) {
    out << code.back();
    code.pop_back();
  }
  
}

/* encodes the byte passed by finding it in the leaves vector and traversing
 * up the Huffman Tree and recording the 0 and 1 children
 * */
void HCTree::encode(byte symbol, BitOutputStream& out) const {
  vector<int> code;
  HCNode* curr = leaves[symbol];
  while(curr->p != 0) {
    
    if (curr->p->c0 == curr){
      //its 0 
      code.push_back(0);
    }
    else {
      //its 1
      code.push_back(1);
    } 
    curr = curr->p;
  }

  int temp;
  while(!code.empty()) {
    temp = code.back();
    out.writeBit(temp);
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
    //cout << "The input file wasn't properly opened. \n";
    return -1;
  }

  //descends the huffman tree
  HCNode* curr = root; 
  
/*
  if(root->symbol == -1) {
    return -1;
*/  //corner case where file is empty
  if(curr->c0 == 0 && curr->c1 == 0) {
    return -1;
  }  

  //reads byte by byte until a leaf node is reached
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
  }
  return (unsigned char)curr->symbol;
}

/** Return symbol coded in the next sequence of bits from the stream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
int HCTree::decode(BitInputStream& in) const {
  
  HCNode* curr = root;
  if(curr->c0 == 0 && curr->c1 == 0) {
    return -1;
  }
  
  int bit;

  //read bit by bit until we have found an encoded char!
  while(true) {
    bit = in.readBit();
    if(bit == 1) {
      curr = curr->c1;
    }
    if(bit == 0) {
      curr = curr->c0;
    }
    if(bit == -1) {
      return -1;
    } 
        
    if(curr->c1 == 0) {
      break;
    }
  }
  //at this point curr may not be a leaf
  unsigned char currentSym = curr->symbol;
  if(leaves[currentSym] != curr) {
    return -1;
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


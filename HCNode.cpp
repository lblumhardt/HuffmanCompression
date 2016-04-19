/* Lucas Blumhardt A12020745
 * Node of the Huffman Tree. Overload the < comparator so that when placed
 * in a priority queue the data structure will behave as a min heap
 * */
#include "HCNode.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

bool HCNode::operator<(const HCNode& other) {
  if(count != other.count) {  
    return count > other.count;
  }

  return symbol < other.symbol;
}


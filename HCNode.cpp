#include "HCNode.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>



bool HCNode::operator<(const HCNode& other) {
  if(count != other.count) { 
    cout << count << "\n";
    return count > other.count;
  }

  return symbol < other.symbol;
}




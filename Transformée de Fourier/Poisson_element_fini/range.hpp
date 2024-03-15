#include<iostream>
#include <valarray>

using namespace std;

// cas ou le pas vaut 1
std::slice range (size_t first, size_t last) {
return std::slice (first, last-first, 1); 
}

// sinon

std::slice range (size_t first, size_t step, size_t last) {
  return std::slice (first, (last-first)/step, step);
}
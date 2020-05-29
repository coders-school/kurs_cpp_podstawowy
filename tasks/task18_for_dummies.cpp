#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int foo(std::vector<int> first, std::vector<int> second) {
  return std::accumulate(begin(first),
    std::transform(begin(first), end(first), begin(second), begin(first),        
      std::multiplies<int>()), 
    0);
}

int main() {
  std::vector<int> vec {10, 20, 3, 8, 21, 30};
  std::vector<int> vec2 {8, 15, 30, 21, 33, 30};
  std::cout << foo(vec, vec2);

  return 0;
}

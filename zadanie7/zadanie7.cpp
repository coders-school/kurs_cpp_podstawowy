#include <iostream>
#include <vector>

int max(const std::vector<int>& vec) {
  int max {0};
  for (const int element : vec) {
    if (element > max)
      max = element;
  }
  
  return max;
}

// int main() {
//   std::vector<int> vec{4,3,2,5,6,7,9,1,0};
//   std::cout << max(vec) << '\n';

//   return 0;
// }

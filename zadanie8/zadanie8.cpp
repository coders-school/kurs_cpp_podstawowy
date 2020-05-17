#include <iostream>
#include <vector>

std::vector<int> foo(int count, int sequence) {
  std::vector<int> vec(count);
  for (size_t i = 0 ; i < count ; ++i) {
    vec[i] = sequence * (i + 1);
  }

  return vec;
}

// int main() {
//   for (const int element : foo(10, 5))
//     std::cout << element << " | ";

//   return 0;
// }

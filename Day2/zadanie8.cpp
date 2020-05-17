#include <iostream>
#include <vector>

int foo(std::vector<int> first, std::vector<int> second) {
  size_t result {0};
  for (size_t i = 0 ; i < first.size() ; ++i) {
    result += first[i] * second[i];
  }

  return result;
}

int main() {
  std::vector<int> vec {10, 20, 3, 8, 21, 30};
  std::vector<int> vec2 {8, 15, 30, 21, 33, 30};
  std::cout << foo(vec, vec2);

  return 0;
}

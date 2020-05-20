#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> foo(int first, int second, int third, int fourth, int fifth) {
  std::vector<int> result {first, second, third, fourth, fifth};
  std::sort(begin(result), end(result));
  return result;
}

int main() {
  auto vec = foo(10, 20, 3, 8, 21);
  for (const auto& el : vec)
    std::cout << el <<  " ";

  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

int GetMax(std::vector<int> first, std::vector<int> second) {
  std::sort(begin(first), end(first));
  std::sort(begin(second), end(second));
  return first.back() > second.back() ? first.back() : second.back();
}

int main() {
  std::vector<int> vec {10, 20, 3, 8, 21, 30};
  std::vector<int> vec2 {8, 15, 30, 21, 33, 30, 25};
  std::cout << GetMax(vec, vec2);

  return 0;
}

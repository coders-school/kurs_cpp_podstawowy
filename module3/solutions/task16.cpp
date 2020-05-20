#include <algorithm>
#include <iostream>
#include <vector>

void foo(const std::vector<int>& vec, int number) {
  int equal {0};
  int greater {0};
  int lower {0};
  for (size_t i = 0 ; i < vec.size() ; ++i) {
    if (vec[i] > number)
      ++greater;
    else if (vec[i] < number)
      ++lower;
    else
      ++equal;
  }
  std::cout << "Greater: " << greater << '\n';
  std::cout << "Lower: " << lower << '\n';
  std::cout << "Equal: " << equal << '\n';
}

int main() {
  std::vector<int> vec {10, 20, 3, 8, 21, 30};
  foo(vec, 10);

  return 0;
}

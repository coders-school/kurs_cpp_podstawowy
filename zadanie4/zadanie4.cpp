#include <iostream>
#include <vector>

int AddEvenNumbers(const std::vector<int>& vec) {
  int sum {0};
  for (const int element : vec) {
    if (!(element % 2))
      sum += element;
  }

  return sum;
}

// int main() {
//   std::vector<int> vec{1, 2, 3, 4, 5};
//   std::cout << AddEvenNumbers(vec) << "\n";

//   return 0;
// }

#include <algorithm>
#include <iostream>
#include <vector>

void MultiplyOddNumber2(int& number) {
    if (number % 2) {
    number *= number;
  }
}

void MultiplyOddNumber(int& number) {
  number = number % 2 ? number * number : number;
}

std::vector<int> multiplyOddNumbers(std::vector<int> vec) {
  std::for_each(begin(vec), end(vec), MultiplyOddNumber);
  return vec;
}

// int main() {
//   std::vector<int> vec{4,3,2,5,6,7,9,1,0};
//   vec = multiplyOddNumbers(vec);
//   for (const int element : vec)
//     std::cout << element << " | ";

//   return 0;
// }

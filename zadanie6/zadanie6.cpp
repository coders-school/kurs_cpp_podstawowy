#include <iostream>

// Euklides algorithm
int NWD(int lhs, int rhs) {
  if (lhs < rhs)
    std::swap(lhs, rhs);

  int result {0};
  while (result = lhs % rhs) {
    lhs = rhs;
    rhs = result;
  }

  return rhs;
}

int NWW(int lhs, int rhs) {
  return lhs * rhs / NWD(lhs, rhs);
}

// int main() {
//   std::cout << "NWW(255, 15) = " << NWW(44, 123) << "\n";
//   std::cout << "NWD(255, 15) = " << NWD(44, 123) << "\n";

//   return 0;
// }

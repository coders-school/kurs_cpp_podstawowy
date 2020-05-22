#include <iostream>
#include "nwdNww.hpp"

int main() {
  std::cout << "NWW(255, 15) = " << NWW(255, 15) << "\n";
  std::cout << "NWD(255, 15) = " << NWD(255, 15) << "\n";


  std::cout << "NWW(255, 15) = " << NWW(
    0.5 * (std::numeric_limits<int>::max() - 1),
    std::numeric_limits<int>::max() - 1) << "\n";
  

  return 0;
}

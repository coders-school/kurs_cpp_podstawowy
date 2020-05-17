#include <iostream>
#include <vector>

void foo(const::string& str) {
  str = "Other string";
}

int main() {
  std::string str("Some string");
  foo(str);

  return 0;
}

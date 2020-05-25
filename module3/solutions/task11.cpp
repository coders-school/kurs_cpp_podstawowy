#include <iostream>
#include <vector>

void foo(const::string& str) {
  str = "Other string";
}

int main() {
  std::string str("Some string");
  foo(str);
  // pass by ref to show that it modifies?
  // scope??
  return 0;
}

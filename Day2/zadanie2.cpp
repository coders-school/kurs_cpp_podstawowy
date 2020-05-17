#include <iostream>

void foo(int* ptr) {
  *ptr = 10;
}

void bar(int* ptr) {
  *ptr = 20;
}

int main() {
  int number = 5;
  std::cout << number << '\n';
  foo(&number);
  std::cout << number << '\n';
  bar(&number); 
  std::cout << number << '\n';

  return 0;
}

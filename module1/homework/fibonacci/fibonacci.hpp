#pragma once
#include <cstddef>

int fibonacci_iterative(int sequence) {
    int a = 0;
    int b = 1;
    int temp;
    for (std::size_t i = 0; i < sequence; ++i) {
      temp = b;
      b = a + b;
      a = temp;
    }
    return a;
}

int fibonacci_recursive(int sequence) {
  if (sequence == 0) return 0;
  if (sequence == 1) return 1;

  return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}

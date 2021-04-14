#include <iostream>
#include "fibonacci.hpp"

int main() {
    std::cout << fibonacci_iterative(19) << "\n";
    std::cout << fibonacci_recursive(19) << "\n";

    return 0;
}

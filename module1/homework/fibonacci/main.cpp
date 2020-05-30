#include <iostream>
#include "fibonacci.hpp"

int main() {
    int nElements = 0;
//    std::cout << fibonacci_iterative(10) << "\n";
//    std::cout << fibonacci_recursive(10) << "\n";
    std::cout << "How many Fibonacci sequence do You want to know?" << "\n";
    std::cin >> nElements;

    for (int iter = 0 ; iter <= nElements; iter++) {
        long long fi = fibonacci_iterative(iter);
        long long fr = fibonacci_recursive(iter);
        std::cout << "fibonacci n = " << iter << " iterative(n) = " <<  fi << " recursive(n) = " << fr << ((fi==fr)?" OK ":" BAD ") << "\n";

    }

    return 0;
}

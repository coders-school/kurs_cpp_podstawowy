#include <iostream>

// Write your function here
void fun(int = 10, std::string = "Hello") {
}

int main() {
    std::cout << "max (1, 2, 3): " << max(1, 2, 3) << "\n";
    std::cout << "max (2, 3, 1): " << max(2, 3, 1) << "\n";

    return 0;
}

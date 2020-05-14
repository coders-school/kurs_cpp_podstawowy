#include <iostream>

// Write missing function here

int multiply(int left, int right)
{
    return left * right;
}

int main()
{
    std::cout << "4 * 5: " << multiply(4, 5) << "\n";
    std::cout << "10 * 5: " << multiply(10, 5) << "\n";
    std::cout << "-5 * 5: " << multiply(-5, 5) << "\n";

    return 0;
}

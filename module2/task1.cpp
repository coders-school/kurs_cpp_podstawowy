#include <iostream>
#include <string>
#include <vector>

// Implement printVec to print the content of a given vector on screen.
// Each string in a new line.

void printVector(const std::vector<std::string> &vector) {
    for (auto &el : vector) {
        std::cout << el << "\n";
    }
}

int main() {
    std::vector<std::string> vec{
        "Hello Coders School!",
        "Welcome to the best C++ course ever",
        "Man, this is crazy :)"};
    printVector(vec);
    return 0;
}

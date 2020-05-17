#include <iostream>
#include <vector>

void printVec(const std::vector<int>& vec) {
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6};
    printVec(vec);
}

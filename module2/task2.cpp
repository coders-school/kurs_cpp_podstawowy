#include <iostream>
#include <vector>
#include <algorithm>

// Implement concatenateVector.
// It should take 2 vectors and return one which has alternately elements from the first and the other one.
std::vector<int> concatenateVector(const std::vector<int> & vec1, const std::vector<int> & vec2) {
    std::vector<int> vec;

    size_t i = 0;
    for(; i < std::min(vec1.size(), vec2.size()); ++i) {
        vec.push_back(vec1[i]);
        vec.push_back(vec2[i]);
    }
    while(i < vec1.size()) {
        vec.push_back(vec1[i]);
        ++i;
    }
    while(i < vec2.size()) {
        vec.push_back(vec2[i]);
        ++i;
    }

    return vec;
}

int main() {
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {11, 12, 13, 14, 15, 16, 17};

    auto vec = concatenateVector(vec1, vec2);
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    std::cout << '\n';
    return 0;
}

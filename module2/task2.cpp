#include <iostream>
#include <vector>

// Implement concatenateVector.
// It should take 2 vectors and return one which has alternately elements from the first and the other one.
std::vector<int> concatenateVector(const std::vector<int>& firstVector, const std::vector<int>& secondVector) {
    std::vector<int> resultVector(firstVector.size() + secondVector.size());

    size_t it;
    for (it = 0; it < std::min(firstVector.size(), secondVector.size()); ++it) {
        resultVector.push_back(firstVector[it]);
        resultVector.push_back(secondVector[it]);
    }
    while (it < firstVector.size()) {
        resultVector.push_back(firstVector[it++]);
    }
    while (it < secondVector.size()) {
        resultVector.push_back(secondVector[it++]);
    }

    return resultVector;
}

int main() {
    std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> vec2{11, 12, 13, 14, 15};

    auto vec = concatenateVector(vec1, vec2);
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    return 0;
}

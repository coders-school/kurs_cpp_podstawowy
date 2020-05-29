#include "vectorFunctions.hpp"


std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result_vector;
    result_vector.reserve(count);
    for (int i = 0; i < count; i++) {
        std::shared_ptr<int> number = std::make_shared<int>(i);
        result_vector.push_back(number);
    }
    return result_vector;
}

void print(const std::vector<std::shared_ptr<int>> vec) {
    for (const std::shared_ptr<int> elem : vec) {
        std::cout << "num: " << *elem << "\n";
    }
}

void add10(std::vector<std::shared_ptr<int>> vec) {
    for (const std::shared_ptr<int> elem : vec) {
        *elem += 10;
    }
}

void sub10(int* const ptr) {
    
}

void sub10(std::vector<std::shared_ptr<int>>& ptr) { 

}
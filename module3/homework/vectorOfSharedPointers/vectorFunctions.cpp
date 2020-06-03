#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result_vector;
    result_vector.reserve(count);
    for (size_t i = 0; i < count; i++) {
        result_vector.push_back(std::make_shared<int>(i));
    }
    return result_vector;
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    for (const std::shared_ptr<int>& ptr : vec) {
        std::cout << *ptr << "\t";
    }
    std::cout << '\n';
}

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const std::shared_ptr<int>& ptr : vec) {
        if (ptr) {
            *ptr += 10;
        }
    }
}

void sub10(int* const ptr) {
    if (ptr) {
        *ptr -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const std::shared_ptr<int>& ptr : vec) {
        if (ptr) {
            sub10(ptr.get());
        }
    }
}

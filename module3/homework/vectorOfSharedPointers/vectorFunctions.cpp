#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result;

    for (int i = 0; i <= count; i++) {
        result.emplace_back(std::make_shared<int>(i));
    }

    return result;
}
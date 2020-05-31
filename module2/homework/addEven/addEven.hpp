#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int result = 0;
    for (const auto& it: numbers) {
        if (it % 2 == 0) {
            result += it;
        }
    }
    return result;
}

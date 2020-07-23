#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    // TODO: Your implementation goes here
    int result = 0;

    for (const auto& value : numbers) {
        if (value % 2 == 0) {
            result += value;
        }
    }

    // Below return is only to make this function compile now
    return result;
}

#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    auto sum = 0;

    for (auto& number : numbers) {
	if (number % 2 == 0) sum += number;
    }
    return sum;
}

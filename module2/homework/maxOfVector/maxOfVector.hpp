#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    auto max_number =  - std::numeric_limits<int>::max(); // the smallest number

    for (auto& el : vec) {
	if (el > max_number) max_number = el;
    }

    return max_number; 
}

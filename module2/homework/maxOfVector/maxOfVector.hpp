#pragma once
#include <vector>
#include <limits>
#include <algorithm>

int maxOfVector(const std::vector<int>& vec) {
    return *(std::max_element(std::begin(vec), std::end(vec)));
}

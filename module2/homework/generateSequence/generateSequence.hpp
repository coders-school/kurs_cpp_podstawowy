#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {

    std::vector<int> vec;

    if (count < 0)
    {
        return vec;
    }

    vec.reserve(count);

    for (size_t i = 0; i < count; i++)
    {
        vec.push_back(step + step * i);
    }

    return vec;
}

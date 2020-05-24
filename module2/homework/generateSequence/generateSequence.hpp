#pragma once
#include <vector>
#include <algorithm>

std::vector<int> generateSequence(int count, int step)
{
    if (count < 0)
        return {};
    std::vector<int> v(count);
    std::generate(v.begin(), v.end(), [n = 0, step]() mutable { return n += step; });
    return v;
}

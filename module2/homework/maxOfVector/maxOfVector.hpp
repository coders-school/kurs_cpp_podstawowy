#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << '\n';
    }

    return {};
}

#pragma once
#include <vector>

int addEven(const std::vector<int> &numbers)
{
    auto result = 0;
    for (const auto &num : numbers)
    {
        if (num % 2 == 0)
        {
            result = result + num;
        }
    }
    return result;
}

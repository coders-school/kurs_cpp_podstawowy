#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step)
{
    if (count > 0)
    {
        std::vector<int> sequence(count);
        int val2add = step;
        for (auto& i : sequence)
        {
            i = val2add;
            val2add += step;
        }

        return sequence;
    }

    return {};
}

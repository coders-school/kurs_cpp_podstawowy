#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step)
{
    if (count > 0)
    {
        std::vector<int> sequence(count);
        sequence[0] = step;
        for (int i = 1; i < count; ++i)
        {
            sequence[i] = sequence[i - 1] + step;
        }

        return sequence;
    }

    return {};
}

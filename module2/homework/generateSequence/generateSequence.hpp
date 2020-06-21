#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step)
{
    // TODO: Implement me :)
    if (count < 0)
    {
        std::vector<int> sequence{};
        return sequence;
    }

    if (count != 0)
    {
        std::vector<int> sequence(count);
        sequence[0] = step;
        for (auto i = 0; i < count; i++)
        {
            sequence[i + 1] = sequence[i] + step;
        }

        return sequence;
    }
    else
    {
        std::vector<int> sequence{};
        return sequence;
    }
}

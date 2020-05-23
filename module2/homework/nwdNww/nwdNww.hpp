#pragma once
#include <algorithm>
#include <cstdlib>

int NWD(int lhs, int rhs)
{
    int higher = std::max(std::abs(lhs), std::abs(rhs));
    int lower = std::min(std::abs(lhs), std::abs(rhs));
    int remainder = 0;
    while (lower)
    {
        remainder = higher % lower;
        higher = lower;
        lower = remainder;
    }

    return higher;
}

int NWW(int lhs, int rhs)
{
    int nwd = NWD(lhs, rhs);
    if (nwd)
    {
        return std::abs(lhs * rhs) / nwd;
    }

    return 0;
}

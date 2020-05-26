#pragma once
#include <algorithm>
#include <cstdlib>

int NWD(int lhs, int rhs)
{
    lhs = std::abs(lhs);
    rhs = std::abs(rhs);
    int higher = std::max(lhs, rhs);
    int lower = std::min(lhs, rhs);
    int remainder = 0;
    while (lower != 0)
    {
        remainder = higher % lower;
        higher = lower;
        lower = remainder;
    }

    return higher;
}

int NWW(int lhs, int rhs)
{
    // The behavior is undefined if lhs, rhs, or the least common multiple of lhs and rhs is not representable as a value of type 'int'.
    int nwd = NWD(lhs, rhs);
    if (nwd != 0)
    {
        lhs = std::abs(lhs);
        rhs = std::abs(rhs);
        return lhs / nwd * rhs;
    }

    return 0;
}

#pragma once
#include <cmath>

int NWD(int lhs, int rhs)
{
    if (lhs == rhs)
        return abs(lhs);
    else if (lhs == 1 or rhs == 1)
        return 1;
    else if (lhs == 0)
        return abs(rhs);
    else if (rhs == 0)
        return abs(lhs);
    return abs(lhs) > abs(rhs) ? NWD(abs(lhs) - abs(rhs), abs(rhs)) : NWD(abs(rhs) - abs(lhs), abs(lhs));
}

int NWW(int lhs, int rhs)
{
    if (lhs == 0 or rhs == 0)
        return 0;
    return abs(lhs * rhs) / NWD(lhs, rhs);
}

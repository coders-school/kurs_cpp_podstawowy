#pragma once
#include <cstdlib>

int NWD(int lhs, int rhs) 
{
    int factor = 0;
    while (rhs != 0)
    {
        factor = rhs;
        rhs = lhs % rhs;
        lhs = factor;
    }

    return abs(lhs);
}

int NWW(int lhs, int rhs) 
{
    if (!lhs || !rhs)
    {
        return 0;
    }
    return abs((lhs * rhs) / NWD(lhs, rhs));
}

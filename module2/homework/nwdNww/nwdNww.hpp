#include <cstdlib>
#pragma once

int NWD(int lhs, int rhs)
{
    // TODO: Implement me :)
    while (lhs != rhs)
    {
        if (rhs > lhs)
        {
            rhs -= lhs;
        }
        else
        {
            lhs -= rhs;
        }
    }
    return std::abs(rhs);
}

int NWW(int lhs, int rhs)
{
    // TODO: Implement me :)
    if (lhs < 0 || rhs < 0)
    {
        return 0;
    }
    return std::abs((lhs * rhs) / NWD(lhs, rhs));
}

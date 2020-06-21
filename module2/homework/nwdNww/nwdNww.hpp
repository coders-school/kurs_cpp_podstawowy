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
    return rhs;
}


int NWW(int lhs, int rhs)
{
    // TODO: Implement me :)
    int NWW = (lhs*rhs)*NWD(lhs,rhs);
    return NWW;
}

#pragma once

int NWD(int lhs, int rhs) 
{
    if (rhs != 0)
        return NWD(rhs, lhs % rhs);
    else
        return std::abs(lhs);
    
}

int NWW(int lhs, int rhs) 
{
    int res = 0;
    if (lhs != 0 && rhs != 0)
        res = (lhs * rhs) / (NWD(lhs, rhs));
    return std::abs(res);
}

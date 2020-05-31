#pragma once

int NWD(int lhs, int rhs) { 

    if (lhs < 0) lhs *= -1;
    if (rhs < 0) rhs *= -1;

    if (lhs == 0) return rhs;
    if (rhs == 0) return lhs;

    while(lhs != rhs)
    {
        if(lhs < rhs) rhs-=lhs;
        else lhs-=rhs;
    }
    return lhs;
}

int NWW(int lhs, int rhs) {

    if (lhs < 0) lhs *= -1;
    if (rhs < 0) rhs *= -1;

    if(lhs==rhs && lhs == 0) return 0;
    return (lhs * rhs / NWD(lhs, rhs)) ;
}

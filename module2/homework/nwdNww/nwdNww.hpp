#pragma once

int NWD(int lhs, int rhs) {
    unsigned int t;
    while (rhs)
    {
        t = rhs ;
        rhs = lhs % rhs;
        lhs = t;
    }
    return lhs;
}
int NWW(int lhs, int rhs) {
if (lhs==0 || rhs==0) {return 0;}
long long mul=lhs*rhs;
   unsigned int t;
    while (rhs)
    {
        t = rhs ;
        rhs = lhs % rhs;
        lhs = t;
    }
    return mul/lhs;
}
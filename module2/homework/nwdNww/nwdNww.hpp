#pragma once
#include <cmath>

int NWD(int lhs, int rhs) {
    int mod;

    if(lhs < 0) {
        lhs = -lhs;
    }
    if(rhs < 0) {
        rhs = -rhs;
    }

    while(rhs) {
        mod = lhs % rhs;
        lhs = rhs;
        rhs = mod;
    }
    return lhs;
}

int NWW(int lhs, int rhs) {
    int nwd = NWD(lhs, rhs);
    if(!nwd) {
        return 0;
    }

    return abs(lhs * rhs) / nwd;
}

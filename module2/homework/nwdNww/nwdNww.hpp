#pragma once
#include <cstdlib>

int NWD(int lhs, int rhs) {
    int max_divider =0;
    for(int i = 1; (i <= abs(lhs) || i <= abs(rhs)); ++i){
        if(lhs%i == 0 & rhs%i == 0)
            max_divider = i;
    }
    return max_divider;
}

int NWW(int lhs, int rhs) {
    if (NWD(lhs, rhs)!= 0)
        return abs(lhs*rhs)/NWD(lhs, rhs);
    else 
        return abs(lhs*rhs); 
}

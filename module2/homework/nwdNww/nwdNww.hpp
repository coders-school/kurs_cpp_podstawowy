#pragma once
#include <cmath>

int NWD(int lhs, int rhs) {
    if(lhs == 0){
        return rhs;
    }
    else if(rhs == 0){
        return lhs;
    }

    int temp;
    while(rhs != 0){
        temp = std::abs(rhs);
        rhs = std::abs(lhs) % temp;
        lhs = temp;
    }

    return lhs;
}

int NWW(int lhs, int rhs) {
    if(lhs == 0 || rhs == 0){
        return 0;
    }
    
    lhs = std::abs(lhs);
    rhs = std::abs(rhs);
    return  lhs/NWD(lhs, rhs) * rhs;
}

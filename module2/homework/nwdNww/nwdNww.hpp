#pragma once
#include <cmath>

int NWD(int lhs, int rhs) {
    int buff;
    if(lhs == 0)
        return rhs;
    else if(rhs == 0)
        return lhs;    
    while(true){
        if(lhs%rhs == 0){
            return std::abs(rhs);
        }
        buff = lhs%rhs;
        lhs = rhs;
        rhs = buff;
    }
}

int NWW(int lhs, int rhs) {
    if((lhs == 0)||(rhs == 0))
        return 0;
    int i = 1;
    while(true){
        if((lhs*i)%rhs == 0)
            return std::abs(lhs*i);
        else
            i++;
    }
}

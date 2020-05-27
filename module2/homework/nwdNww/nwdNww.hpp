#pragma once
#include <algorithm>
#include <stdlib.h>
#include <vector>


int NWD(int lhs, int rhs) {
    int first = std::max(abs(lhs), abs(rhs));
    int second = std::min(abs(lhs), abs(rhs));
    while(second > 0){
        int tmp = first % second;
        first = second;
        second = tmp;
    }
    return first;
}

int NWW(int lhs, int rhs) {
    if(lhs == 0 && rhs == 0){
        return 0;
    }
    return abs (lhs * rhs) / NWD(lhs, rhs); 
}

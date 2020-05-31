#pragma once
#include <cmath>

int NWD(int lhs, int rhs) {

    int temp;
    while(rhs != 0)
    {
        temp = rhs;
        rhs = lhs%rhs;
        lhs = temp;
    }
    
    return abs(lhs);
    
}

int NWW(int lhs, int rhs) {
    
    if(lhs != 0 && rhs !=0)
    {
   
    int temp = lhs/NWD(lhs, rhs)*rhs;

    return abs(temp);
    }
    return 0;
}

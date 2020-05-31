#pragma once

int NWD(int lhs, int rhs){
    int temp = 0;
    while(rhs != 0){
        temp = rhs;
        rhs = lhs % rhs;
        lhs = temp;
    }
    return abs(lhs);   
}

int NWW(int lhs, int rhs){
    if(lhs == 0 && rhs == 0){
        return 0;
    }
    int nwd = NWD(lhs, rhs);
    return abs(lhs / nwd * rhs);
}

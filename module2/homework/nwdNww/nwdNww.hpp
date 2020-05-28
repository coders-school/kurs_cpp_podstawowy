#pragma once

int NWD(int lhs, int rhs) {
    if(lhs == 0) return rhs;
    if(rhs == 0) return lhs;
    lhs = abs(lhs);
    rhs = abs(rhs);
    while(lhs!=rhs){
        if(lhs>rhs){
            lhs-=rhs;
        }else{
            rhs-=lhs;
        }
    }
    return lhs;
}

int NWW(int lhs, int rhs) {
    lhs = abs(lhs);
    rhs = abs(rhs);
    if(lhs == rhs && rhs == 0) return 0;
    return lhs*rhs/NWD(lhs,rhs);
}
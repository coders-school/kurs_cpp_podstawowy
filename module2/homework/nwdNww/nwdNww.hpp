#pragma once
#include <vector>
#include <algorithm>

int NWD(int lhs, int rhs) {
     if (lhs < 0)
      lhs = lhs * (-1);
    if (rhs < 0)
      rhs = rhs * (-1);
      
    int sec;
     while(rhs!=0){
       sec = rhs;
       rhs = lhs%rhs;
       lhs = sec;
     }
    return lhs;
}

int NWW(int lhs, int rhs) {
    return lhs/NWD(lhs, rhs)*rhs;
}

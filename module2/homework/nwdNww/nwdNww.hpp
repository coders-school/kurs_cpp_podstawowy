#pragma once

int NWD(int lhs, int rhs) {
    int sub=0;
    do {
        (lhs<rhs) ? sub=rhs-lhs : sub=lhs-rhs;
        (lhs>=sub && lhs>=rhs) ? lhs=sub : rhs=sub;    
    }
    while (lhs-rhs!=0);
    return lhs;
}

int NWW(int lhs, int rhs) {
if (lhs==0 || rhs==0) {return 0;}
long long mul=lhs*rhs;
int sub=0;
    do {
        (lhs<rhs) ? sub=rhs-lhs : sub=lhs-rhs;
        (lhs>=sub && lhs>=rhs) ? lhs=sub : rhs=sub;    
    }
    while (lhs-rhs!=0);
    return (mul/lhs);
}
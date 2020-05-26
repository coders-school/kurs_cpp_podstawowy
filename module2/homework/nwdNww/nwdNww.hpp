#pragma once

void ABS_Num( int & lhs, int& rhs)
{
    lhs = abs(lhs);
    rhs = abs(rhs);
}
int NWD(int lhs, int rhs) { 
    ABS_Num(lhs,rhs);
    if (lhs == 0) return rhs;
    if (rhs == 0) return lhs;
    
    while(lhs != rhs)
    {
        if(lhs < rhs) rhs-=lhs;
        else lhs-=rhs;
    }
    return lhs;
}
 
int NWW(int lhs, int rhs) {
    ABS_Num(lhs,rhs);
    if(lhs==rhs and lhs == 0) return 0;
    return (lhs / NWD(lhs, rhs)) * rhs;
}   



#pragma once
#include<cmath>

int NWD(int lhs, int rhs){
    
   int reszta = {};

   while( rhs != 0)
   {
       reszta = lhs % rhs;
       lhs = rhs;
       rhs = reszta;
   } 
   return abs(lhs);

}

int NWW(int lhs, int rhs){
    
    if(NWD(lhs, rhs) == 0)
    {
    return 0;
    }

    else
    {
    return abs((lhs*rhs) / NWD(lhs, rhs));
    }
    
}

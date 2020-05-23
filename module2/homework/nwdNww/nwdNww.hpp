#pragma once

int NWD(int lhs, int rhs) {
    if(lhs==0 && rhs==0)
        return 0;
   
    lhs=abs(lhs);
    rhs=abs(rhs);

    int nwd;
    if(lhs==0 || lhs==rhs)
        return rhs;
    if(rhs==0)
        return lhs;

    while(lhs!=rhs)
    {
        if(lhs>rhs)
            lhs-=rhs;
        else
            rhs-=lhs;               
    }
    return lhs;
}

int NWW(int lhs, int rhs) {

    if(lhs==0 && rhs==0)
        return 0;
    
    lhs=abs(lhs);
    rhs=abs(rhs); 

    return (lhs*rhs)/NWD(lhs,rhs);

}

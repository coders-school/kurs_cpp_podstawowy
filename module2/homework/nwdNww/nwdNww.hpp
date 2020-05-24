#pragma once

int NWD(int lhs, int rhs) {
    int dividend, divider, result = 1;
    
    if(rhs == 0 || lhs == 0)
    {
        if(rhs == 0 && lhs != 0) return lhs;
        else if(rhs != 0 && lhs == 0) return rhs;
        else return 0;
    }

    if(rhs < 0) rhs = abs(rhs);
    if(lhs < 0) lhs = abs(lhs);

    if(rhs > lhs)
    {
        dividend = rhs;
        divider = lhs;
    }
    else
    {
        dividend = lhs;
        divider = rhs;
    }
    
    for(int i = divider; i >= 1; i--)
    {
        if(dividend%i == 0 && divider%i == 0)
        {
            result = i;
            break;
        }
    }

    return result;
}

int NWW(int lhs, int rhs) {
    int dividend, divider, result = 1;

    if(rhs == 0 || lhs == 0) return 0;

    if(rhs < 0) rhs = abs(rhs);
    if(lhs < 0) lhs = abs(lhs);

    if(rhs > lhs)
    {
        dividend = rhs;
        divider = lhs;
    }
    else
    {
        dividend = lhs;
        divider = rhs;
    }

    for(int i = dividend; ; i++)
    {
        if(i % dividend  == 0 && i % divider == 0)
        {
            result = i;
            break;
        }
    }

    return result;
}

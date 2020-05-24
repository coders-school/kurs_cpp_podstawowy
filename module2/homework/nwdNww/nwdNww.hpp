#pragma once

int NWD(int lhs, int rhs) {
    int dividend, divider, result = 1;
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
    // TODO: Implement me :)
    return -1;
}

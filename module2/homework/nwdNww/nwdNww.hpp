#pragma once

int NWD(int lhs, int rhs) {

    if (lhs == 0)
    {
        return rhs;
    }

    if (rhs == 0)
    {
        return lhs;
    }

    int bufor;
    
    if (rhs>lhs)
    {
        int pom = lhs;
        lhs = rhs;
        rhs = pom;
    }

    while (rhs!=0)
    {
        bufor = lhs % rhs;
        lhs = rhs;
        rhs = bufor;
    }

    if (lhs < 0)
    {
        lhs = -lhs;
    }

    return lhs;
}

int NWW(int lhs, int rhs) {

    if(lhs == 0 || rhs == 0)
    {
        return 0;
    }
    auto nww = (lhs / NWD(lhs, rhs) * rhs);

    if(nww < 0)
    {
        nww = -nww;
    }

    return nww;
}

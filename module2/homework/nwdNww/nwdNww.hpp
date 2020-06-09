#pragma once
#include <cmath>

/**
 * Zoptymalizowany algorytm Euklidesa
 * From: http://www.algorytm.edu.pl/algorytmy-maturalne/algorytm-eulkidesa.html
 * (I did it 20 years ago.. I promise.)
 */
int NWD(int lhs, int rhs) 
{
    int buf;

    while(rhs)
    {
        buf = rhs;
        rhs = lhs % rhs;
        lhs = buf;
    }
    return std::abs(lhs);
}

/**
 * From: http://www.algorytm.edu.pl/algorytmy-maturalne/nww.html
 */
int NWW(int lhs, int rhs) 
{
    int nww = 0;
    int buf = NWD(lhs, rhs);

    if(buf) 
    {
        nww =  std::abs(lhs / buf * rhs);
    } 
    return nww;
}

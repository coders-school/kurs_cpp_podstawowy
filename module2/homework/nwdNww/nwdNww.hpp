#pragma once
#include <cstdlib>

int NWD(int lhs, int rhs) {
    /*
       Based on fact that NWD(a, b) = NWD(b, a mod b)
    */

    int modulo = 0;

    while (rhs != 0) {
	modulo = lhs % rhs;
	lhs = rhs;
	rhs = modulo;
    }

    return std::abs(lhs);
}

int NWW(int lhs, int rhs) {
    int nwd = NWD(lhs, rhs);

    if (nwd == 0) return 0;
    return std::abs((lhs * rhs) / NWD(lhs, rhs));
}

#pragma once
#include <cstdlib>

int NWD(int lhs, int rhs) {
    if (rhs == 0) {
        return lhs;
    }

    int remainder = 0;
    while ((remainder = lhs % rhs) != 0) {
        lhs = rhs;
        rhs = remainder;
    }
    return std::abs(rhs);
}

int NWD_recursive(int lhs, int rhs) {
    if (rhs == 0) {
        return lhs;
    }

    return std::abs(NWD(rhs, lhs % rhs));
}

int NWW(int lhs, int rhs) {
    int nwd = NWD(lhs, rhs);

    if (nwd == 0) {
        return 0;
    }
    return std::abs(lhs / nwd * rhs);
}

#pragma once

int NWD(int lhs, int rhs) {
    if(lhs == 0) {
        return rhs;
    }
    if(rhs == 0) {
        return lhs;
    }
    if(lhs < 0) {
        lhs *= -1;
    }
    if(rhs < 0) {
        rhs *= -1;
    }
    while(rhs != lhs) {
        if(rhs > lhs) {
            rhs -= lhs;
        } else {
            lhs -= rhs;
        }
    }
    return lhs;
}

int NWW(int lhs, int rhs) {
    if(lhs == 0 || rhs == 0) {
        return 0;
    }
    return std::abs(lhs * rhs / NWD(lhs, rhs));
}

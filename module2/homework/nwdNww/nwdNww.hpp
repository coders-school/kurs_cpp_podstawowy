#pragma once

int NWD(int lhs, int rhs) {
    if (lhs == 0) {
        return std::abs(rhs); 
    }
    return std::abs(NWD(rhs % lhs, lhs)); 
}

int NWW(int lhs, int rhs) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    }
    return std::abs((lhs * rhs) / NWD(lhs, rhs));
}

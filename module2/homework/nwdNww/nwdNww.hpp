#pragma once

int NWD(int lhs, int rhs) {
    if (rhs == 0) {
        return lhs;
    }

    while (lhs % rhs != 0) {
        int rest = lhs % rhs;
        lhs = rhs;
        rhs = rest;
    }

    return std::abs(rhs);
}

int NWW(int lhs, int rhs) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    }

    return static_cast<long long>(std::abs(lhs)) * std::abs(rhs) / NWD(lhs, rhs);
}

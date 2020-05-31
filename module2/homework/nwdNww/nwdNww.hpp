#pragma once

int NWD(int lhs, int rhs) {
    int divider;
    lhs = abs(lhs);
    rhs = abs(rhs);
    while (rhs != 0) {
        divider = rhs;
        rhs = lhs % rhs;
        lhs = divider;
    }
    return lhs;
}

int NWW(int lhs, int rhs) {
    int nwd = NWD(lhs, rhs);
    return nwd == 0 ? 0 : abs(lhs / NWD(lhs, rhs) * rhs);
}

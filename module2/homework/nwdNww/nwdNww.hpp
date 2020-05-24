#pragma once

int NWD(int lhs, int rhs) {
    int nwd;
    int remainder;

    if (lhs == 0) {
        return rhs;
    } else if (rhs == 0) {
        return lhs;
    }

    do {
        remainder = lhs % rhs;

        if (remainder == 0) {
            nwd = rhs;
        } else {
            lhs = rhs;
            rhs = remainder;
        }

    } while (remainder != 0);

    if (nwd < 0) {
        nwd = -nwd;
    }

    return nwd;
}

int NWW(int lhs, int rhs) {
    
    if ((lhs == 0) or (rhs == 0)) {
        return 0;
    }

    auto nww = (lhs / NWD(lhs, rhs)) * rhs;

    if (nww < 0) {
        nww = -nww;
    }

    return nww;
}

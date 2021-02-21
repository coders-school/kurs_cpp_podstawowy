#pragma once

int NWD(int lhs, int rhs) {
    while (lhs != rhs){
        if (lhs > rhs){
            lhs -= rhs;
        }
        else {
            rhs -= lhs;
        }
    }
    return rhs;
}

int NWW(int lhs, int rhs) {
    return (lhs * rhs) / NWD(lhs, rhs);
}

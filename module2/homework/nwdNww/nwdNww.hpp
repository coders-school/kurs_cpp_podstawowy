#pragma once

int NWD(int lhs, int rhs) {
    int temp;
    while (rhs != 0){
        temp = lhs % rhs;
        lhs = rhs;
        rhs = temp;
    }
    return abs(lhs);
}

int NWW(int lhs, int rhs) {
    if (NWD(lhs, rhs) == 0){
        return 0;
    }
    return abs((lhs * rhs) / NWD(lhs, rhs));
}

#pragma once

int NWD(int lhs, int rhs) {
    int temp;
    while (rhs)
    {
        temp = rhs;
        rhs = lhs % rhs;
        lhs = temp; 
    }
    return abs(lhs);
}

int NWW(int lhs, int rhs) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    }
    return abs(lhs * rhs) / NWD(lhs, rhs);
}

#pragma once

int NWD(int lhs, int rhs) {
    if (rhs == 0) {
        return lhs;
    }
    if (lhs == 0) {
        return rhs;
    }
    if (abs(lhs) == abs(rhs)) {
        return abs(lhs);
    }
    int modulo = lhs > rhs ? abs(lhs % rhs) : abs(rhs % lhs);
    int higher = lhs > rhs ? abs(rhs) : abs(lhs);
    int divided = higher;
    while (modulo != 0) {
        higher = modulo;
        modulo = divided % modulo;
        divided = higher;
    }

    return divided;
}

int NWW(int lhs, int rhs) {
    if (lhs == 0 || rhs ==0) {
        return 0;
    }
    if (abs(lhs) == abs(rhs)) {
        return abs(lhs);
    }
    long long result = abs(lhs * rhs) / (NWD(lhs, rhs));
    return result;
}

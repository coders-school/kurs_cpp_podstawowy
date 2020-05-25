#pragma once

int NWD(int lhs, int rhs) {
    if (rhs == 0) {
        return lhs;
    }
    if (lhs == 0) {
        return rhs;
    }
    if (lhs == rhs) {
        return lhs;
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
    return -1;
}

int NWW(int lhs, int rhs) {
    // TODO: Implement me :)
    return -1;
}

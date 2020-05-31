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
    // TODO: Implement me :)
    return -1;
}

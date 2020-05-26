#pragma once

int NWD(int lhs, int rhs) {
    int sub=0;
    do {
        (lhs<rhs) ? sub=rhs-lhs : sub=lhs-rhs;
        (lhs>=sub && lhs>=rhs) ? lhs=sub : rhs=sub;    
    }
    while (lhs-rhs!=0);
    return lhs;
}

//int NWW(int lhs, int rhs) {
    // TODO: Implement me :)
 //   return -1;
//}

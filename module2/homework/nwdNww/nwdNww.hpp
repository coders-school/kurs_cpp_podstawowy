#pragma once

int NWD(int lhs, int rhs) {
   if (rhs != 0){
        return NWD (rhs, lhs%rhs);
   }
    return std::abs(lhs); 
}

int NWW(int lhs, int rhs) {
    if (lhs==0 || rhs==0){
        return 0;
    }
    return (static_cast<uint32_t>(lhs) * static_cast<uint32_t>(rhs)) / NWD(lhs,rhs);
}

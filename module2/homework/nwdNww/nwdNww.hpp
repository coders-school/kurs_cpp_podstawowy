#pragma once

#include <algorithm>

int NWD(int lhs, int rhs) {
    int& divident = lhs;
    int& divisor = rhs;
    
    if(divident < 0 || divisor < 0) {
        divident = std::abs(divident);
        divisor = std::abs(divisor);
    }

    if (divident == 0 || divisor == 0) {
        return std::max(divident, divisor);
    }

    if(divisor > divident) {
        std::swap(divident, divisor);
    }
        
    int remainder{};
    do {
        remainder = divident % divisor;
        if(remainder != 0) {
            divident = divisor;
            divisor = remainder;
        }
    } while(remainder != 0);

    return divisor;
}

int NWW(int lhs, int rhs) {
    if (lhs < 0 || rhs < 0) {
        lhs = std::abs(lhs);
        rhs = std::abs(rhs);
    }
    
    int NwdValue = NWD(lhs,rhs);
    if (!NwdValue) {
        return 0;
    }
    
    return lhs / NwdValue * rhs;
}

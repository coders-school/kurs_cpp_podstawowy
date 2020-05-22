#pragma once
#include <limits>

int NWD(int lhs, int rhs) {
    if(lhs * rhs == 0) {
        return lhs + rhs;
        // if one of them is 0, return bigger of them
    }
    int nwd = std::abs(lhs);
    lhs = std::abs(lhs);
    rhs = std::abs(rhs);
    while(lhs != rhs) {
        nwd = abs(lhs - rhs);
        lhs > rhs ? lhs = nwd : rhs = nwd;
    }
    return nwd; 
}

int NWW(int lhs, int rhs) {
    // Function should return int,
    // so inputing to large values can result 
    // in int overflow.
    // Testing their product must be performed on int types
    // two times bigger
    if(lhs == 0 || rhs == 0) {
        return 0;
    }
    int64_t product = std::abs
        ( static_cast<int64_t>(lhs) * static_cast<int64_t>(rhs) ) 
            / NWD(lhs, rhs) ;

    if(product > std::numeric_limits<int>::max()) {
        return 0;
    }
    return static_cast<int>(product);
}

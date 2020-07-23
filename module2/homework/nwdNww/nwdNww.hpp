#pragma once
#include <map>


std::map<int, int> getPrimals(int value) {
    std::map<int, int> result; 

    int divider = 2;
    while (value > 1 || value < -1) {
        if (value % divider == 0) {
            if (result.find(divider) != result.end()) {
                ++result[divider];
            }
            else {
                result[divider] = 1;               
            }
            value /= divider;
        }
        else {
            ++divider;
        }
    }
    return result;
}


int NWW(int lhs, int rhs) {
    std::map<int,int> lprim { getPrimals(lhs) };
    std::map<int,int> rprim { getPrimals(rhs) };
    int result = 1;

    for (const auto& [key, value] : lprim) {
        if (auto rprimIterator = rprim.find(key); rprimIterator != rprim.end()) {
            for (size_t i = 0; i < std::max(value, rprim[value]); ++i) {
                result *= key;
            }       
            rprim.erase(rprimIterator);
        } 
        else {
            for (size_t i = 0; i < value; ++i) {
                result *= key;
            }
        }
    }
    for (const auto& [key, value] : rprim) {
        for (size_t i = 0; i < value; ++i) {
            result *= key;
        }
    }

    return result;
}


int NWD(int lhs, int rhs) { 
    return -1;
    //return (lhs * rhs / NWD(lhs, rhs)) ;
}

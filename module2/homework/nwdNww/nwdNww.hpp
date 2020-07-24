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

void ShowPrimals (const std::map<int,int>& map) {
    for (auto const& [key, value] : map) {
        std::cout << "[" << key << ", " << value << "] \n";
    }
    std::cout << "\n";
}


int NWW(int lhs, int rhs) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    }

    std::map<int,int> lprim { getPrimals(lhs) };
    std::map<int,int> rprim { getPrimals(rhs) };
    int result = 1;

    // ShowPrimals(lprim);    
    // ShowPrimals(rprim);

    for (const auto& [key, value] : lprim) {
        if (auto rprimIterator = rprim.find(key); rprimIterator != rprim.end()) {
            for (size_t i = 0; i < std::max(value, rprim[key]); ++i) {
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
    if (lhs == 0) {
        return rhs;
    }
    if (rhs == 0) {
        return lhs;
    }

    while (lhs % rhs != 0) {
        int change = lhs % rhs;
        lhs = rhs;
        rhs = change;
    }
    return (rhs < 0)? -rhs : rhs;
}

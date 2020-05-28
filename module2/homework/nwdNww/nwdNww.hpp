#pragma once
#include <algorithm>

int NWD(int lhs, int rhs){
    	while(rhs)
		std::swap(lhs %= rhs, rhs);
	return std::abs(lhs);
}

int NWW(int lhs, int rhs) {
    if (NWD(lhs, rhs)==0) {return 0;}
    return std::abs((lhs*rhs)/NWD(lhs, rhs));
}

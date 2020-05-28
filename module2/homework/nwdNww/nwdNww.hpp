#pragma once

int NWD(int lhs, int rhs)  {

    int result = 0;

    lhs = std::abs(lhs);
    rhs = std::abs(rhs);

	if(rhs > lhs) {
        std::swap(lhs,rhs);
	}

	while(rhs) {
        result = rhs;
		rhs = lhs % rhs;
		lhs = result;
    }
	return lhs;
}

int NWW(int lhs, int rhs) {

    if(lhs == 0 || rhs == 0) {
        return 0;
    }

    lhs = std::abs(lhs);
    rhs = std::abs(rhs);

    for(int i = 1; i < (lhs * rhs); i++) {
        if((i % lhs == 0)&&(i % rhs == 0)) {
            return i;
        }
    }
    return lhs * rhs;
}

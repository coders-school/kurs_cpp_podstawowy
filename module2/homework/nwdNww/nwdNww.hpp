#pragma once

int NWD(int lhs, int rhs) {
    
    if (lhs == 0 && rhs == 0) 

        return 0;

    lhs = std::abs(lhs);
    rhs = std::abs(rhs);
    

    if (rhs != 0) {

        return NWD ( rhs, lhs % rhs);

    }
    
    return lhs;
}

int NWW(int lhs, int rhs) {
    
    if (lhs == 0 && rhs == 0) 

        return 0;

    lhs = std::abs(lhs);
    rhs = std::abs(rhs);        


    return (lhs / NWD(lhs, rhs)) * rhs;

}

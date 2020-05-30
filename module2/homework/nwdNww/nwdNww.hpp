#pragma once

int NWD(int lhs, int rhs) {
    if ((lhs > 0) && (rhs > 0))
        while (true)
        {
            while(lhs >= rhs){
                if(lhs == rhs) return rhs;
                lhs -= rhs;
            }
            int number = lhs;
            lhs = rhs;
            rhs = number;
        }
    
    return 0;
}

int NWW(int lhs, int rhs) {
      if ((lhs > 0) && (rhs > 0))
        return lhs * rhs / NWD(lhs, rhs);
    
    return 0;
}

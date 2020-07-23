#pragma once

int NWD(int lhs, int rhs) {
	int pom;

  	while(rhs != 0) {
    	pom = rhs;
    	rhs = lhs % rhs;
    	lhs = pom;  
  	}
    return lhs;
}


int NWW(int lhs, int rhs) {
    // TODO: Implement me :)
    return -1;
}

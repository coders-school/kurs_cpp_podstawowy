#pragma once


/**
 * Zoptymalizowany algorytm Euklidesa
 * From: http://www.algorytm.edu.pl/algorytmy-maturalne/algorytm-eulkidesa.html
 * (I did it 20 years ago.. I promise.)
 */
int NWD(int lhs, int rhs) {
    int buf;
    
	if(lhs < 0){
        lhs *= -1U;
    }
	if(rhs < 0){
        rhs *= -1U;
    }
    while(rhs != 0)
    {
		buf = rhs;
		rhs = lhs % rhs;
		lhs = buf;	
	}	
    return lhs;
}

/**
 * From: http://www.algorytm.edu.pl/algorytmy-maturalne/nww.html
 */ 
int NWW(int lhs, int rhs) {
	int buf;
	
    if(lhs < 0){
        lhs *= -1U;
    }
	if(rhs < 0){
        rhs *= -1U;
    }

    buf = NWD(lhs, rhs);
    if(buf){
        return lhs / buf * rhs;
    }else{
        return 0;
    }
}

#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    	int a=0;
	int b=1;
	int c=0;
	for (size_t i = 0 ; i < sequence ; i++) {
	

		if (i < 2){
		
			c = 1;
		} else {
		
			a=b;
			b=c;
			c=a+b;
		}
		
	
	}  

	
	return c;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here

    	int solution = 0;

	if (sequence < 1){
	
		solution = 0;
	} else {
		solution = sequence < 3 ? 1 : (fibonacci_recursive(sequence-1)+fibonacci_recursive(sequence-2)); 
	}
	    
    return solution;
}

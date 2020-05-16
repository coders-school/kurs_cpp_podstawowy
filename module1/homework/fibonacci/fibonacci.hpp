#pragma once

int fibonacci_iterative(int sequence) {

        if(sequence==0) return 0;

        if(sequence==1) return 1;
	int fib=0;
        int fib_prev = 1;
	int fib_prev_prev = 0;

	for (int i=2; i<=sequence; i++)
	{
		fib = fib_prev + fib_prev_prev;
		fib_prev_prev = fib_prev;
		fib_prev = fib;

	}

    	return fib;
}

int fibonacci_recursive(int sequence) {
	
   	if(sequence==0) return 0; 

	if(sequence<3&&sequence>0)
		return 1;
	
	return fibonacci_recursive(sequence-2)+fibonacci_recursive(sequence-1); 
	
}

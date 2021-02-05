#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    int total = 0, first = 0, second = 1;
    if (sequence == 0)
	    return 0;
    else if (sequence == 1)
	    return 1;
    else{
    	for (int i = 0; i<sequence-1; i++){
		total = first + second;
		first = second;
		second = total;
	}
}
	return total;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    if (sequence == 0)
	    return 0;
    else if (sequence == 1)
	    return 1;
    else
	    return fibonacci_recursive(sequence -2) + fibonacci_recursive(sequence - 1);
    return 0;
}

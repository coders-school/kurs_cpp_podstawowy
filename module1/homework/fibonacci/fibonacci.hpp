#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
	int secondValue = 0;
	int firstValue = 1;
	int result = 1;
	if(sequence == 0)
	{
		return sequence;
	}
	if(sequence == 1)
	{
		return sequence;
	}
	for(int i = 2; i < sequence; i++)
	{
		secondValue = firstValue;
		firstValue = result;
		result = firstValue + secondValue; 
	}
    return result;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    return 0;
}

#pragma once

int fibonacci_iterative(int sequence) {

   	if (sequence < 1)
		return 0;

	if (sequence == 1)
		return 1;


	int first = 0, second = 1;
	int result = 0;

	for(int k = 2; k <= sequence; ++k)
	{
		result = first + second;
		first = second;
		second = result;
	}

	return result;

}

int fibonacci_recursive(int sequence) {
    if (sequence==0)
    {
        return 0;
    }
    if (sequence==1)
    {
        return 1;
    }
    return (fibonacci_recursive(sequence-1)+fibonacci_recursive(sequence-2));
    
}

#pragma once

int fibonacci_iterative(int sequence) {

    int fibi[47];

    switch (sequence)
    {
        case 0: {
            return 0;
        }
        case 1:
        case 2: {
            return 1;
        }
        default: {
            fibi[1] = 1;
            fibi[2] = 1;

            for (int i = 3; i <= sequence; i++)
            {
                fibi[i] = fibi[i-1] + fibi[i-2];    
            }
            return fibi[sequence];
        }
    }
    return 0;
}

int fibonacci_recursive(int sequence) {
    if ((sequence == 0) || (sequence == 1)) {
        return sequence;
    } else {
        return fibonacci_recursive(sequence-2) + fibonacci_recursive(sequence-1);
    }
    return 0;
}

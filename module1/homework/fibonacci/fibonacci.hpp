#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence <= 1) {
        return sequence;
    }
    else {
        int current = 1, one_before = 1, two_before = 0;
        for (int i = 2; i <= sequence; ++i)
            {
                current = one_before + two_before;
                two_before = one_before;
                one_before = current;
            }
        return current;
    }
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    return 0;
}

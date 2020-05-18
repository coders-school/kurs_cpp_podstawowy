#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence <= 0) {
        return 0;
    } else if (sequence <= 2) {
        return 1;
    }

    int result  = 1;
    int lastNum = 0;
    for (int i = 2; i <= sequence; i++) {
        int temp = result + lastNum;
        lastNum  = result;
        result   = temp;
    }

    return result;
}

int fibonacci_recursive(int sequence) {
    if (sequence <= 0) {
        return 0;
    } else if (sequence <= 2) {
        return 1;
    }

    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}

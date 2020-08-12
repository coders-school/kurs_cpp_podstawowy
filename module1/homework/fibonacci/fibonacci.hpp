#pragma once

int fibonacci_iterative(int sequence) {
    int num = 0;
    int num2 = 1;
    int result = 0;

    for (int i = 0; i < sequence; i++) {
        if (i <= 0) {
            return 0;
        } else if (i < 2) {
            return 1;
        } else {
            num = num2;
            num2 = result;
            result = num + num2;
        }
    }

    return result;
}

int fibonacci_recursive(int sequence) {
    if (sequence <= 0) {
        return 0;
    } else if (sequence < 2) {
        return 1;
    }

    return fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1);
}

#pragma once

int fibonacci_iterative(int sequence) {

    int first = 1;
    int second = 1;
    int result;

    if (sequence <=3){
        return 1;
    }
    
    for (int i = 3; i <= sequence; i++) {
        result=first+second;
        second=first;
        first=result;
    }
    return result;
}

int fibonacci_recursive(int sequence) {

    int first = 1;
    int second = 1;
    int result;

    if (sequence <=3){
        return 1;
    }

    for (int i = 3; i <= sequence; i++) {
        result=first+second;
        second=first;
        first=result;
        std::cout << "To jest " << i << " wynik w ciagu: " << result << std::endl;
    }

    return 0;
}


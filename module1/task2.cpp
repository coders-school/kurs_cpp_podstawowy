#include <iostream>

// Write your function here
int max(int arg1, int arg2, int arg3)
{
    int max;
    
    if (arg1 > arg2 && arg1 > arg3){
        max = arg1;
    } else if (arg2 > arg1 && arg2 > arg3){
        max = arg2;
    } else {
        max = arg3;
    }

    return max;
}

int main()
{
    std::cout << "max (1, 2, 3): " << max(1, 2, 3) << "\n";
    std::cout << "max (2, 3, 1): " << max(2, 3, 1) << "\n";
    std::cout << "max (3, 2, 1): " << max(3, 2, 1) << "\n";

    return 0;
}

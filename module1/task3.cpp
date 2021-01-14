#include <iostream>

// Write your function here
void printString(std::string arg1, int arg2)
{
    int i = 0;

    do
    {
        std::cout << arg1 << "\n";
        i++;

    } while (i != arg2);
}

int main()
{
    printString("Hello", 5);
    std::cout << "\n";

    printString("AbC", 2);
    std::cout << "\n";

    printString("HiHi ", 6);
    std::cout << "\n";

    return 0;
}

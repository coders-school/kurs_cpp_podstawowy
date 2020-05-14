#include <iostream>
#include <string>

// Write your function here
void printString(std::string napis, int powt)
{
    int i = 1;
    while(i <= powt)
    {
        std::cout << napis << "\n";
        i++;
    } 
}

int main() {
    printString("Hello", 5);
    std::cout << "\n";

    printString("AbC", 2);
    std::cout << "\n";

    printString("HiHi ", 6);
    std::cout << "\n";

    return 0;
}

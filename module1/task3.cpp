#include <iostream>

// Write your function here
void printString(std::string word, int number){
    for(int i=0;i<number;i++){
        std::cout<<word<<'\t';
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

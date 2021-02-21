#include <iostream>
#include <map>
#include <string>

void Print(const std::map<size_t, std::string>&map){
    for (const auto& [index, title] : map){
        std::cout << index << " | " << title << "\n";        
    }
}

int main(){
    std::map<size_t, std::string> discs {
        {1, "LOTR: The Folloship ..."},
        {2, "LOTR: The Two Towers"},
        {3, "LOTR: The Return ..."}
    };

    Print(discs);
    std::cout << "\nAfter adding new element\n";
    discs[4] = "Harry Potter";
    Print(discs);
    std::cout << "\nAfter modification of an elemen\n";
    discs[4] = "Harry Potter and the Philosopher's Stone";
    Print(discs);

    return 0;
}
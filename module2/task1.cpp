#include <iostream>
#include <vector>
#include <string>

void printVector(std::vector<std::string>& text){
    for (const auto i : text){
        std::cout << i << "\n";
    }
}

int main() {
    std::vector<std::string> vec {
        "Hello Coders School!",
        "Welcome to the best C++ course ever",
        "Man, this is crazy :)"
    };
    printVector(vec);
    return 0;
}

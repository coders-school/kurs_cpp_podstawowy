#include <iostream>
#include <string>
#include <ostream>
#include "validation.hpp"
#include <vector>

int main() {
    std::string password = "Morela92#";
    std::string repeatedPassword = "Morela92#";
    std::cout << "Set new password: ";
    //std::cin >> password;
    std::cout << "Repeat password: ";
    //std::cin >> repeatedPassword;
    auto result = checkPassword(password, repeatedPassword);
    std::cout << getErrorMessage(result) << "\n";
    return 0;
}

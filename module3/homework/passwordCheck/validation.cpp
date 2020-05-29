#include "validation.hpp"
#include <iostream>

std::string getErrorMessage(ErrorCode code)
{
    switch (code)
    {
    case ErrorCode::Ok:
        return "Password correct";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password too short (must have at least 9 characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password should contain at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password should contain at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password should contain at least one big letter";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords do not match";
    default:
        return "Unknown error :(";
    }
}

bool doPasswordsMatch(std::string password1, std::string password2) {
    return password1 == password2;
}

int main() {
    for(int i = 0; i <=5; i++) {
        std::cout << getErrorMessage(static_cast<ErrorCode>(i)) << "\n";
    }

    std::cout << doPasswordsMatch("ziemniaki", "balonik") << "\n";
    std::cout << doPasswordsMatch("japko", "japko") << "\n";
    std::cout << doPasswordsMatch("żółĆ4", "żółĆ4") << "\n";
    std::cout << doPasswordsMatch("kot", "Kot") << "\n";
    
    return 0;
}
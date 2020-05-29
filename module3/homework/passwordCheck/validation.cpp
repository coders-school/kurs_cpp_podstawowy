#include "validation.hpp"
#include <iostream>


std::string getErrorMessage(ErrorCode code)
{
    switch (code)
    {
    case ErrorCode::Ok:
        return "OK";
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

bool doesPasswordsMatch(std::string password1, std::string password2) {
    return password1 == password2;
}

ErrorCode checkPasswordRules(std::string password) {
    if(password.size() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if(std::none_of(password.begin(), password.end(), isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if(std::all_of(password.begin(), password.end(), isalnum)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if(std::none_of(password.begin(), password.end(), isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string password1, std::string password2) {
    if(!doesPasswordsMatch(password1, password2)) {
        return ErrorCode::PasswordsDoesNotMatch;
    } else {
        return checkPasswordRules(password1);
    }
}

// int main() {
//     for(int i = 0; i <=6; i++) {
//         std::cout << getErrorMessage(static_cast<ErrorCode>(i)) << "\n";
//     }

//     std::cout << doesPasswordsMatch("ziemniaki", "balonik") << "\n";
//     std::cout << doesPasswordsMatch("japko", "japko") << "\n";
//     std::cout << doesPasswordsMatch("żółĆ4", "żółĆ4") << "\n";
//     std::cout << doesPasswordsMatch("kot", "Kot") << "\n";

//     // std::string pass = "pies";
//     std::cout << "pies \t\t\t" << getErrorMessage(checkPasswordRules("pies")) << "\n";
//     std::cout << "pumpernikiel\t\t" << getErrorMessage(checkPasswordRules("pumpernikiel")) << "\n";
//     std::cout << "pumpernikiel9\t\t" << getErrorMessage(checkPasswordRules("pumpernikiel9")) << "\n";
//     std::cout << "pumpernikiel9$\t\t" << getErrorMessage(checkPasswordRules("pumpernikiel9$")) << "\n";
//     std::cout << "pumPernikiel9$\t\t" << getErrorMessage(checkPasswordRules("pumPernikiel9$")) << "\n";

//     std::cout << getErrorMessage(checkPassword("radom", "morda")) << "\n";
//     std::cout << getErrorMessage(checkPassword("uatwehasuo", "tródnehasuo")) << "\n";
//     std::cout << getErrorMessage(checkPassword("kratownica", "kratownica")) << "\n";
//     std::cout << getErrorMessage(checkPassword("kratownica9", "kratownica9")) << "\n";
//     std::cout << getErrorMessage(checkPassword("pumpernikiel9$", "pumpernikiel9$")) << "\n";
//     std::cout << getErrorMessage(checkPassword("pumPernikiel9$", "pumPernikiel9$")) << "\n";

//     return 0;
// }
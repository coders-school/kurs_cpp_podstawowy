#include "validation.hpp"

#include <algorithm>
#include <iostream>

bool doesPasswordsMatch(std::string password, std::string repetedPassword) {
    return password == repetedPassword;
}

std::string getErrorMessage(ErrorCode code) {
    switch(static_cast<int>(code)) {
        case 0: return "OK";
        case 1: return "Password is too short";
        case 2: return "Password need to contain at least one digit";
        case 3: return "Password need to contain at least one special character (like: [#],[%],[,],[$],[/]";
        case 4: return "Password need to contain at least one uppercase letter";
        case 5: return "Passwords do not match";
        default: return "I do not know that kind of error. I am sorry...";
    }
}

ErrorCode checkPasswordRules(std::string password) {
    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string password, std::string repetedPassword) {
    if(!doesPasswordsMatch(password, repetedPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    } else {
        return checkPasswordRules(password);
    }
}
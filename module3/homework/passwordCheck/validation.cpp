#include "validation.hpp"

#include <algorithm>
#include <iostream>

bool doesPasswordsMatch(const std::string& password, const std::string& repetedPassword) {
    return password == repetedPassword;
}

std::string getErrorMessage(ErrorCode code) {
    switch(code) {
        case ErrorCode::Ok: 
            return "OK";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters: 
            return "Password is too short";
        case ErrorCode::PasswordNeedsAtLeastOneNumber: 
            return "Password need to contain at least one digit";
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter: 
            return "Password need to contain at least one special character (like: [#],[%],[,],[$],[/]";
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter: 
            return "Password need to contain at least one uppercase letter";
        case ErrorCode::PasswordsDoesNotMatch: 
            return "Passwords do not match";
        default: 
            return "I do not know that kind of error. I am sorry...";
    }
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    } else if (std::none_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    } else if (std::all_of(password.begin(), password.end(), ::isalnum)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }else if (std::none_of(password.begin(), password.end(), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    } else {
        return ErrorCode::Ok;
    }
}

ErrorCode checkPassword(const std::string& password, const std::string& repetedPassword) {
    if(!doesPasswordsMatch(password, repetedPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    } else {
        return checkPasswordRules(password);
    }
}

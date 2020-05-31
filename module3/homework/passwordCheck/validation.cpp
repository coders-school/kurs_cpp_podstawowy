#include "validation.hpp"
#include <string>

std::string getErrorMessage(ErrorCode errorNumber) {
    switch (errorNumber) {
        case ErrorCode::Ok: {
            return "OK";
        }
        case ErrorCode::PasswordNeedsAtLeastNineCharacters: {
            return "Password needs at least nine characters";
        }
        case ErrorCode::PasswordNeedsAtLeastOneNumber: {
            return "Password needs at least one number";
        }
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter: {
            return "Password needs at least one special character";
        }
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter: {
            return "Password needs at least one uppercase letter";
        }
        case ErrorCode::PasswordsDoesNotMatch: {
            return "Passwords does not match";
        }
        default: {
            return "Unknown error";
        }
    }
}

//code below is only for building

bool doesPasswordsMatch(const std::string&, const std::string&) {
    return false;
}

ErrorCode checkPasswordRules(const std::string&) {
    return ErrorCode::PasswordsDoesNotMatch;
}

ErrorCode checkPassword(const std::string&, const std::string&) {
    return ErrorCode::PasswordsDoesNotMatch;
}
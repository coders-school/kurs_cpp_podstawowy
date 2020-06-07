#include "validation.hpp"

#include <string>

std::string getErrorMessage(ErrorCode error) {
    switch (error) {
    case ErrorCode::Ok:
        return "Ok";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Error, Password need at least 9 characters!";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Error, Password need at least 1 number!";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Error, Password need at least one special character!";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Error, Password need at least uppercase letter!";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Error, password does not match!";
    default:
        return "Undefined Error!";
    }
}

bool doesPasswordsMatch(const std::string input, const std::string password) {
    return input == password;
}
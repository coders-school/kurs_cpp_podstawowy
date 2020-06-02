#include "validation.hpp"

std::string getErrorMessage(ErrorCode errorToDecode) {
    switch (errorToDecode) {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords does not match";
    default:
        return "Unknown error";
    }
}

bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword) {
    return true;
}

ErrorCode checkPasswordRules(const std::string& password) {
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword) {
    return ErrorCode::Ok;
}

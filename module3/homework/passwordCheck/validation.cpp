#include "validation.hpp"

std::string getErrorMessage(ErrorCode errorToDecode) {
    switch (errorToDecode) {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password Needs At Least Nine Characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password Needs At Least One Number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password Needs At Least One Special Character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password Needs At Least One Uppercase Letter";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords Does Not Match";
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

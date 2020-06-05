#include "validation.hpp"

#include <algorithm>
#include <iostream>

bool doesPasswordsMatch(const std::string& password, const std::string& repetedPassword) {
    return password == repetedPassword;
}

std::string getErrorMessage(ErrorCode code) {
    switch (code) {
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
        return "OK";
    }
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    if (std::none_of(password.begin(), password.end(), ::isdigit))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    if (std::all_of(password.begin(), password.end(), ::isalnum))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    if (std::none_of(password.begin(), password.end(), ::isupper))
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& repetedPassword) {
    if (!doesPasswordsMatch(password, repetedPassword))
        return ErrorCode::PasswordsDoesNotMatch;

    return checkPasswordRules(password);
}

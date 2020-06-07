#include "validation.hpp"
#include <algorithm>

bool doesPasswordsMatch(const std::string &password, const std::string &repeatedPassword) {
    if (password.compare(repeatedPassword)) {
        return false;
    }
    return true;
}

ErrorCode checkPasswordRules(const std::string &password) {
    if (password.length() < minPasswordLength) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::any_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::any_of(password.begin(), password.end(), ::isalnum)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::any_of(password.begin(), password.end(), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string &password, const std::string &repeatedPassword) {
    if (!doesPasswordsMatch(password, repeatedPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(password);
}

std::string getErrorMessage(const ErrorCode &errorCode) {

    switch (errorCode) {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one upper case letter";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords does not match";
    default:
        return "Error message unknown";
    }
}

#include "validation.hpp"

#include <algorithm>
#include <cctype>

namespace {
unsigned const minimumPasswordLength = 9;
};

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

bool doesPasswordsMatch(const std::string& basePassword, const std::string& repeatedPassword) {
    return basePassword == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < minimumPasswordLength) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (!std::any_of(std::begin(password), std::end(password),
                     [](unsigned char c) { return std::isdigit(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if (!std::any_of(std::begin(password), std::end(password),
                     [](unsigned char c) { return std::isprint(c) && !std::isalnum(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (!std::any_of(std::begin(password), std::end(password),
                     [](unsigned char c) { return std::isupper(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& basePassword, const std::string& repeatedPassword) {
    if (!doesPasswordsMatch(basePassword, repeatedPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(basePassword);
}

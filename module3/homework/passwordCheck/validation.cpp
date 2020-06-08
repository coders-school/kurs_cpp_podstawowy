#include "validation.hpp"

#include <algorithm>
#include <iostream>

std::string getErrorMessage(ErrorCode error) {
    switch (error) {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Error, password does not match!";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Error, Password need at least 9 characters!";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Error, Password need at least 1 number!";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Error, Password need at least one special character!";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Error, Password need at least uppercase letter!";
    default:
        return "Undefined Error!";
    }
}

bool doesPasswordsMatch(const std::string& input, const std::string& password) {
    return input == password;
}

ErrorCode checkPasswordRules(const std::string& password) {
    constexpr int minPasswordSize = 9;
    if (password.size() < minPasswordSize) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::none_of(password.cbegin(), password.cend(), [](char i){ return isdigit(i); })) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::none_of(password.cbegin(), password.cend(), [](char i){ return ispunct(i); })) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::none_of(password.cbegin(), password.cend(), [](char i){ return isupper(i); })) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& input, const std::string& password) {
    if (!doesPasswordsMatch(input, password)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(input);
}

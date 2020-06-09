#include "validation.hpp"

#include <time.h>

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>

std::string getErrorMessage(const ErrorCode err) {
    switch (err) {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Passwrod needs at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one Uppercase letter";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Password does not match";
    default:
        return "Error";
    }
}

bool doesPasswordsMatch(const std::string& password1, const std::string& password2) {
    return password1 == password2;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.size() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (any_of(password.begin(), password.end(), isdigit) == false) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (any_of(password.begin(), password.end(), std::not1(std::ptr_fun(::isalnum))) == false) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (any_of(password.begin(), password.end(), isupper) == false) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password1, const std::string& password2) {
    if (doesPasswordsMatch(password1, password2)) {
        return checkPasswordRules(password1);
    }
    return ErrorCode::PasswordsDoesNotMatch;
}
#include "validation.hpp"

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <string>

std::string getErrorMessage(const ErrorCode& code) {
    switch (code) {
    case ErrorCode::Ok:
        return "OK";
        break;

    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "PasswordNeedsAtLeastNineCharacters";
        break;

    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "PasswordNeedsAtLeastOneNumber";
        break;

    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "PasswordNeedsAtLeastOneSpecialCharacter";
        break;

    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "PasswordNeedsAtLeastOneUppercaseLetter";
        break;

    case ErrorCode::PasswordsDoesNotMatch:
        return "PasswordsDoesNotMatch";
        break;

    default:
        return "Unknow behavior";
    }
}

bool doesPasswordsMatch(const std::string& pass1, const std::string& pass2) {
    return pass1 == pass2;
}

ErrorCode checkPasswordRules(const std::string& pass) {
    constexpr int PASSWORD_LENGTH = 9;

    if (pass.length() < PASSWORD_LENGTH)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    else if (std::none_of(pass.begin(), pass.end(), [](char c) { return isdigit(c); }))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    else if (std::none_of(pass.begin(), pass.end(), [](char c) { return !isalnum(c); }))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    else if (std::none_of(pass.begin(), pass.end(), [](char c) { return isupper(c); }))
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    else {
        return ErrorCode::Ok;
    }
}

ErrorCode checkPassword(const std::string& pass1, const std::string& pass2) {
    if (!doesPasswordsMatch(pass1, pass2))
        return ErrorCode::PasswordsDoesNotMatch;
    else {
        return checkPasswordRules(pass1);
    }
}

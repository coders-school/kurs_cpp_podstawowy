#pragma once

#include <algorithm>
#include <iostream>
#include <string>

enum class ErrorCode {

    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch,
};

std::string getErrorMessage(const ErrorCode code);
bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword);

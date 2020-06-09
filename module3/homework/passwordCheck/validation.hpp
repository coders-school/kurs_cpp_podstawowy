#pragma once

#include <string>

enum ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(const ErrorCode err);
bool doesPasswordsMatch(const std::string& password1, const std::string& password2);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& password1, const std::string& password2);
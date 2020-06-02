#include <string>

#pragma once

enum class ErrorCode {
    Ok,
    PasswordsDoesNotMatch,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordNeedsAtLeastOneSpecialCharacters,
};

std::string getErrorMessage(const ErrorCode&);
bool doesPasswordsMatch(const std::string&, const std::string&);
ErrorCode checkPasswordRules(const std::string&);
ErrorCode checkPassword(const std::string&, const std::string&);

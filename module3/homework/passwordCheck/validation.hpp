#pragma once
#include <string>

const int minPasswordLength = 9;
enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

bool doesPasswordsMatch(const std::string&, const std::string&);
ErrorCode checkPasswordRules(const std::string&);
ErrorCode checkPassword(const std::string&, const std::string&);
std::string getErrorMessage(const ErrorCode&);

#pragma once
#include <string>

enum ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordDoesNotMatch
};

std::string getErrorMessage(const ErrorCode);
bool doesPasswordMatch(const std::string&, const std::string&);
ErrorCode checkPasswordRules(const std::string&);
ErrorCode checkPassword(const std::string&, const std::string&);

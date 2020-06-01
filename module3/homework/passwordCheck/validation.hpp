#include <string>

#pragma once

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacters,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PassswordsDoesNotMatch,
};

std::string getErrorMessage(const ErrorCode& errorCode);
bool doesPasswordsMatch(const std::string& firstPwd, const std::string& secondPwd);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& firstPwr, const std::string& secondPwd);


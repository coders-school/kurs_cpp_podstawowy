#pragma once

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharackters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharackter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch,
};

std::string getErrorMessage(const ErrorCode);
bool doesPasswordsMatch(const std::string&, const std::string&);
ErrorCode checkPasswordRules(const std::string&);
ErrorCode checkPassword(const std::string&, const std::string&);
#pragma once

#include <algorithm>
#include <cctype>
#include <string>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode code);
bool doesPasswordsMatch(const std::string & password1, const std::string & password2);
ErrorCode checkPasswordRules(const std::string & password);
ErrorCode checkPassword(const std::string & password1, const std::string & password2);
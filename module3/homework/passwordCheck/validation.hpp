#pragma once
#include <string>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch,
};


std::string getErrorMessage(const ErrorCode error);
bool doesPasswordsMatch(const std::string& password, const std::string& passwordRetyped);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& password, const std::string& passwordRetyped);

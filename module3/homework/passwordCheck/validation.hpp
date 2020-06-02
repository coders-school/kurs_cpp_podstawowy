#pragma once

#include <string>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(const ErrorCode errorCode);

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword);

ErrorCode checkPasswordRules(const std::string& password);

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword);

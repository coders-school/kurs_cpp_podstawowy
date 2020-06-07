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

std::string getErrorMessage(ErrorCode error);
bool doesPasswordsMatch(const std::string input, const std::string password);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& input, const std::string& password);

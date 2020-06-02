#pragma once
#include <iostream>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode error);
bool doesPasswordsMatch(const std::string& passwordA, const std::string& passwordB);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& passwordA, const std::string& passwordB);

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

bool doesPasswordsMatch(std::string password, std::string repetedPassword);
std::string getErrorMessage(ErrorCode error);
ErrorCode checkPasswordRules(std::string password);
ErrorCode checkPassword(std::string password, std::string repetedPassword);

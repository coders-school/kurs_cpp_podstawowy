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

constexpr auto passwordMinimumLength = 9;

std::string getErrorMessage(ErrorCode);

bool doesPasswordsMatch(std::string, std::string);

ErrorCode checkPasswordRules(std::string);

ErrorCode checkPassword(std::string, std::string);


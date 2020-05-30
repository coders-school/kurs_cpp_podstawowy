#pragma once
#include <string>

enum class ErrorCode {
    Ok = 100,
    PasswordNeedsAtLeastNineCharacters = 101,
    PasswordNeedsAtLeastOneNumber = 102,
    PasswordNeedsAtLeastOneSpecialCharacter = 103, 
    PasswordNeedsAtLeastOneUppercaseLetter = 104,
    PasswordsDoesNotMatch = 105
};

std::string getErrorMessage(ErrorCode);

bool doesPasswordsMatch(std::string, std::string);

ErrorCode checkPasswordRules(std::string);

ErrorCode checkPassword(std::string, std::string);

#pragma once
#include <string>

enum class ErrorCode{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PassworIncludeForbiddenCharacter,
    PasswordsDoesNotMatch
};

std::string  getErrorMessage(ErrorCode err);
bool doesPasswordsMatch(const std::string& first_password, const std::string& second_password);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& first_password, const std::string& second_password);

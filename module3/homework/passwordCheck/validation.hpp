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
bool doesPasswordsMatch(std::string first_password, std::string second_password);
ErrorCode checkPasswordRules(std::string password);
ErrorCode checkPassword(std::string first_password, std::string second_password);

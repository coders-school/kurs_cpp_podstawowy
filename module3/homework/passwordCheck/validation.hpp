#pragma once
#include <string>

enum class ErrorCode{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode code);

bool doesPasswordsMatch(const std::string& first_pass, const std::string& second_pass);

ErrorCode checkPasswordRules(const std::string& password);

ErrorCode checkPassword(const std::string& first_pass, const std::string& second_pass);








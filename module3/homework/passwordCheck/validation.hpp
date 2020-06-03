#pragma once

#include <string>

enum class ErrorCode
{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

// This line below indicates which characters are allowed and which are not
const std::string specialCharacters = " !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
constexpr int minPasswordLength = 9;

std::string getErrorMessage(ErrorCode errorCode);
bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword);


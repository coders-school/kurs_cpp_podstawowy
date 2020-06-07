#pragma once

#include<string>

const int minPassLength = 9;
enum class ErrorCode {
    Ok, 
    PasswordNeedsAtLeastNineCharacters, 
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};
std::string getErrorMessage(const ErrorCode& errCode);
bool doesPasswordsMatch(const std::string& firstPass, const std::string& secondPass);
ErrorCode checkPasswordRules(const std::string& firstPass);
ErrorCode checkPassword(const std::string& firstPass, const std::string& secondPass);
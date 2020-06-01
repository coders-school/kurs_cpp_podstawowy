#pragma once
#include <iostream>
#include <algorithm>
#include <array>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode codeToShow);

bool doesPasswordsMatch(const std::string& firstPwd, const std::string& secondPwd);

ErrorCode checkPasswordRules(const std::string& password);

ErrorCode checkPassword(const std::string& firstPwd, const std::string& secondPwd);


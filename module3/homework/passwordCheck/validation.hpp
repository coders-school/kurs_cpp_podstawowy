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

constexpr int errorCodeFirstElementValue = static_cast<int>(ErrorCode::Ok);
constexpr int errorCodeLastElementValue = static_cast<int>(ErrorCode::PasswordsDoesNotMatch);

std::string getErrorMessage(const ErrorCode& input);
bool doesPasswordsMatch(const std::string& input1, const std::string& input2);
ErrorCode checkPasswordRules(const std::string& input);
ErrorCode checkPassword(const std::string& actualPassword, const std::string& correctPassword);

#include "validation.hpp"

#include <algorithm>
#include <cctype>
#include <functional>
#include <map>

namespace {
const std::map<ErrorCode, std::function<int(int)>> conditionMap = {
    {ErrorCode::PasswordNeedsAtLeastOneNumber, isalnum},
    {ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter, isupper},
    {ErrorCode::PasswordNeedsAtLeastOneSpecialCharacters, ispunct},
};
}

std::string getErrorMessage(const ErrorCode& errorCode) {
    switch (errorCode) {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords does not Match, please double check them.";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password too short (minimum 9 characters).";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter.";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacters:
        return "Password needs at least one special charater.";
    default:
        return "Error message unknown";
    }
}

bool doesPasswordsMatch(const std::string& firstPwd, const std::string& secondPwd) {
    return firstPwd == secondPwd;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    for (const auto& condition : conditionMap) {
        if (!std::any_of(password.begin(), password.end(), condition.second)) {
            return condition.first;
        }
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& firstPwd, const std::string& secondPwd) {
    if (!doesPasswordsMatch(firstPwd, secondPwd)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(firstPwd);
}

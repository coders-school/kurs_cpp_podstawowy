#include "validation.hpp"

#include <algorithm>
#include <cctype>
#include <regex>
#include <string>

std::string getErrorMessage(ErrorCode code) {
    std::string result;

    switch (code) {
    case ErrorCode::Ok:
        result = "OK";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        result = "Password requires at least 9 characters";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        result = "Password requires at least one number";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        result = "Password requires at least special character";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        result = "Password requires at least one uppercase letter";
        break;
    case ErrorCode::PasswordsDoesNotMatch:
        result = "Password does not match";
        break;
    default:
        result = "Unknown error";
        break;
    }

    return result;
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    int minPasswordLength = 9;
    std::regex specialPattern("[^\\w\\*]");

    if (password.length() < minPasswordLength)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    if (std::none_of(password.begin(), password.end(), ::isdigit))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    if (std::none_of(password.begin(), password.end(), ::isupper))
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    if (std::none_of(password.begin(), password.end(), ::isalpha))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    if (!std::regex_match(password, specialPattern))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword) {
    if (doesPasswordsMatch(firstPassword, secondPassword))
        return checkPasswordRules(firstPassword);
    else
        return ErrorCode::PasswordsDoesNotMatch;
}

#include "validation.hpp"

#include <iostream>

std::string getErrorMessage(ErrorCode code)
{
    switch (code)
    {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password too short (must have at least 9 characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password should contain at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password should contain at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password should contain at least one big letter";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords do not match";
    default:
        return "Unknown error";
    }
}

bool doesPasswordsMatch(const std::string & password1, const std::string & password2)
{
    return password1 == password2;
}

ErrorCode checkPasswordRules(const std::string & password)
{
    if (password.size() < 9)
    {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::none_of(password.begin(), password.end(), isdigit))
    {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::all_of(password.begin(), password.end(), isalnum))
    {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::none_of(password.begin(), password.end(), isupper))
    {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string & password1, const std::string & password2)
{
    if (!doesPasswordsMatch(password1, password2))
    {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(password1);
}
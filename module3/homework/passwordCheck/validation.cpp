#include "validation.hpp"

#include <algorithm>


std::string getErrorMessage(const ErrorCode &errCode)
{
    switch (errCode)
    {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords does not match - check them";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password Needs at least 9 characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Min one sing must be numbr";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Min one sing must be a special character.";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Min one sing must be uppercase letter";

    default:
        return "Something is bad";
    }
}
bool doesPasswordsMatch(const std::string &firstPass, const std::string &secondPass)
{
    return firstPass == secondPass;
}
ErrorCode checkPassword(const std::string &firstPass, const std::string &secondPass)
{
    if (!doesPasswordsMatch(firstPass, secondPass))
    {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(firstPass);
}

ErrorCode checkPasswordRules(const std::string &firstPass)
{
    if (firstPass.length() < minPassLength)
    {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::none_of(firstPass.begin(), firstPass.end(), ::isdigit))
    {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::none_of(firstPass.begin(), firstPass.end(), ::isalnum))
    {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::none_of(firstPass.begin(), firstPass.end(), ::isupper))
    {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

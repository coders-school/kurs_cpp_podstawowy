#include "validation.hpp"

#include <algorithm>
#include <string>

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

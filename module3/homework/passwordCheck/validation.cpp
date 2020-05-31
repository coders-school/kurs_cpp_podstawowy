#include "validation.hpp"

std::string getErrorMessage(ErrorCode errorCode)
{
    switch (errorCode)
    {
    case ErrorCode::Ok:
        return "Password is correct";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special characters";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
        break;
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords does not match";
        break;
    default:
        return std::string();
        break;
    }
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword)
{
    return false;
}

ErrorCode checkPasswordRules(const std::string& password)
{
    return ErrorCode();
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword)
{
    return ErrorCode();
}

#include "validation.hpp"
#include <string>
#include <algorithm>

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

bool passwordHasNineCharacters(const std::string& password)
{
    return password.length() >= 9;
}

bool passwordHasNumber(const std::string& password)
{
    return std::any_of(password.begin(), password.end(), ::isdigit);
}

bool passwordHasSpecialCharacter(const std::string& password)
{
    for (size_t i = 0, count = password.length(); i < count; i++)
    {
        if ((password[i] >= 48 && password[i] <= 57) ||
            (password[i] >= 65 && password[i] <= 90) ||
            (password[i] >= 97 && password[i] <= 122))
        {
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool passwordHasUppercase(const std::string& password)
{
    return std::any_of(password.begin(), password.end(), ::isupper);
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword)
{
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password)
{
    if (!passwordHasNineCharacters(password)) 
    {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (!passwordHasNumber(password)) 
    {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if (!passwordHasSpecialCharacter(password)) 
    {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (!passwordHasUppercase(password)) 
    {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword)
{
    if (!doesPasswordsMatch(password, repeatedPassword)) 
    {
        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(password);
}

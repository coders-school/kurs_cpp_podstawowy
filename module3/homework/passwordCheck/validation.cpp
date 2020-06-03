#include "validation.hpp"

#include <algorithm>

std::string getErrorMessage(ErrorCode errorCode)
{
    switch (errorCode)
    {
        case ErrorCode::Ok:
            return "OK";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Password needs at least nine characters.";
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Password needs at least one number.";
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Password needs at least one special character.";
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Password needs at least one uppercase letter.";
        case ErrorCode::PasswordsDoesNotMatch:
            return "Password does not match.";
        default:
            return "Error Code undefined.";
    }
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword)
{
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password)
{
    if (password.size() < minPasswordLength)
    {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (!std::any_of(password.begin(), password.end(), ::isdigit))
    {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    bool passContainsSpecialChar =
        std::any_of(specialCharacters.begin(),
                    specialCharacters.end(),
                    [password](char ch) {
                        return std::any_of(password.begin(),
                                           password.end(),
                                           [ch](char c) { return ch == c; });
                    });
    if (!passContainsSpecialChar)
    {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (!std::any_of(password.begin(), password.end(), ::isupper))
    {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword)
{
    if (doesPasswordsMatch(password, repeatedPassword))
    {
        return checkPasswordRules(password);
    }
    
    return ErrorCode::PasswordsDoesNotMatch;
}


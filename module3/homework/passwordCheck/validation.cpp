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

bool doesPasswordsMatch(std::string password, std::string repeatedPassword)
{
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(std::string password)
{
    if (password.size() <= 9)
    {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    bool foundNumber = false;
    for (const auto& ch : password)
    {
        if (ch >= '0' && ch <= '9')
        {
            foundNumber = true;
        }
    }
    if (!foundNumber)
    {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    // https://www.ipvoid.com/password-special-characters/
    // https://owasp.org/www-community/password-special-characters
    std::string specialCharacters = " !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
    bool passContainsSpecialChar = std::any_of(specialCharacters.begin(),
                                                specialCharacters.end(),
                                                [password](char ch){ return std::any_of(password.begin(),
                                                                                        password.end(),
                                                                                        [ch](char c){ return ch == c; }); });
    if (!passContainsSpecialChar)
    {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    bool passContainsUpperChar = std::any_of(password.begin(), password.end(), ::isupper);
    if (!passContainsUpperChar)
    {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string password, std::string repeatedPassword)
{
    if (doesPasswordsMatch(password, repeatedPassword))
    {
        return checkPasswordRules(password);
    }
    return ErrorCode::PasswordsDoesNotMatch;
}

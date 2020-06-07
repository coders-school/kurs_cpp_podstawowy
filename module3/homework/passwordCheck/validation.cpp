#include "validation.hpp"
#include <string>
#include <algorithm>

std::map<ErrorCode, const char*> ErrorMap
{
    {ErrorCode::Ok, "OK"},
    {ErrorCode::PasswordNeedsAtLeastNineCharacters, "Password needs at least nine characters"},
    {ErrorCode::PasswordNeedsAtLeastOneNumber, "Password needs at least one number"},
    {ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter, "Password needs at least one special characters"},
    {ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter, "Password needs at least one uppercase letter"},
    {ErrorCode::PasswordsDoesNotMatch, "Passwords do not match"}   
};

std::string getErrorMessage(ErrorCode errorCode)
{
    return ErrorMap[errorCode];
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
    return std::any_of(password.begin(), password.end(), ::ispunct);
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

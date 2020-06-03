#include "validation.hpp"
#include <algorithm>
#include <cctype>

std::string getErrorMessage(ErrorCode error)
{
    switch(error)
    {
        case ErrorCode::Ok:
            return "Your password is correct.\n";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters: 
            return "Your password needs at least nine characters.\n";
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Your password needs at least one number.\n";
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Your password needs at least one special character.\n";
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Your password needs at least one upper case letter.\n";
        case ErrorCode::PasswordsDoesNotMatch:
            return "Passwords do not match.\n"; 
        default:
            return "Your password is incorrect.\n";
    }
}

bool doesPasswordsMatch(const std::string& firstPass, const std::string& secondPass)
{
    return firstPass == secondPass;
}

ErrorCode checkPasswordRules(const std::string& password)
{
    if(password.size() < 9)
    {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    else if (!std::any_of(password.begin(), password.end(), [](char letter){ return isdigit(letter); }))
    {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    else if (!std::any_of(password.begin(), password.end(), [](char letter){ return ispunct(letter); }))
    {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    else if (!std::any_of(password.begin(), password.end(), [](char letter){ return isupper(letter); }))
    {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& firstPass, const std::string& secondPass)
{
    if (doesPasswordsMatch(firstPass, secondPass))
    {
        return checkPasswordRules(firstPass);
    }
    
    return ErrorCode::PasswordsDoesNotMatch;
}

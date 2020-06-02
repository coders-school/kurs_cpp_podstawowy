#include <iostream>
#include <array>
#include <algorithm>

#include "validation.hpp"

std::string getErrorMessage(ErrorCode errorType){
    switch(errorType){
        case ErrorCode::Ok:
            return "OK";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Your password need at least nine characters. \n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Your password need at least one number. \n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Your password need at least one special character. \n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return  "Your password need at least one uppercase letter. \n";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Passwords does not match. \n";
            break;
        default:
            return "Unknown error \n";
    }
}

bool doesPasswordsMatch(const std::string& first, const std::string& second)
{
    return first == second;
}

ErrorCode checkPasswordRules(const std::string& password)
{
    //checking if size in at least 9
    if(password.size() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    if (!std::any_of(password.begin(), password.end(), isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if (std::none_of(password.begin(), password.end(), [](char sign) { return isprint(sign) && !isalnum(sign); })) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (!std::any_of(password.begin(), password.end(), isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& first,const std::string& second)
{
    if(!doesPasswordsMatch(first, second))
    {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(first);
}



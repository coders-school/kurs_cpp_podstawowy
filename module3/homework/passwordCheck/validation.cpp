#include <cstring>
#include <algorithm>


#include "validation.hpp"

const int8_t minPasswordLen = 9;
std::string getErrorMessage(ErrorCode code)
{
    switch(code)
    {
        case ErrorCode::Ok : {return "The given password is OK.";}
        case ErrorCode::PasswordNeedsAtLeastNineCharacters : 
                    {return "ERROR. Password needs at least nine characters.";}
        case ErrorCode::PasswordNeedsAtLeastOneNumber : 
                    {return "ERROR. Password needs at least one number.";}
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter : 
                    {return "ERROR. Password needs at least one special character.";}
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter : 
                    {return "ERROR. Password needs at least one uppercase letter.";}
        case ErrorCode::PasswordsDoesNotMatch: 
                    {return "ERROR. Password does not match.";}
    }
}

bool doesPasswordMatch(std::string password, std::string repeated_password)
{
    if(password != repeated_password) return false;
    return true;
}

ErrorCode checkPasswordRules(std::string const password)
{
    if(password.length() < minPasswordLen) return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    if(std::find_if(password.begin(), 
        password.end(), isdigit) == password.end())
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    if(std::find_if(password.begin(), 
        password.end(), isupper) == password.end())
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    bool passwordContainsSpecialCharacter = false;
    std::string const listOfTheSpecialCharacters = "!@#$%^&*";
    for(const char& ch : listOfTheSpecialCharacters)
    {
        if(std::any_of(password.begin(), password.end(),
                [ch](const char& l){return l == ch;}))
                {
                    passwordContainsSpecialCharacter = true;
                    break;
                }
    }

    if(!passwordContainsSpecialCharacter) 
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string const password,
                    std::string const repeated_password)
{
    if(!doesPasswordMatch(password,repeated_password))
        return ErrorCode::PasswordsDoesNotMatch;

    return checkPasswordRules(password,repeated_password);
}
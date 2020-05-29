#include "validation.hpp"
#include <iostream>

std::string getErrorMessage(ErrorCode type){
    auto code = static_cast<int>(type);
    switch(code){
        case 123:
            return "Your password is ok. \n";
            break;
        case 9:
            return "Your password need at least nine characters. \n";
            break;
        case 1:
            return "Your password need at least one number. \n";
            break;
        case 2:
            return "Your password need at least one special character. \n";
            break;
        case 3:
            return  "Your password need at least one uppercase letter. \n";
            break;
        default:
            return "idk what's going on dude \n";
            break;
    }
}

bool doesPasswordsMatch(std::string first, std::string second)
{
    return (first == second);
}

ErrorCode checkPasswordRules(std::string password)
{
    //checking if size in at least 9
    if(password.size() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    //checking if string has at least one number, one special character and uppercase letter
    //default to false
    bool hasNumber = false;
    bool hasSpecialCharacter = false;
    bool hasUppercaseLetter = false;

    //everything in one loop, so the efficiency if better
    for(size_t i= 0; i < password.size(); i++)
    {
        //checking if it has at least one number
        if( (static_cast<int>(password[i]) > 47 && static_cast<int>(password[i]) < 58 ) ) {
            hasNumber = true; //bool to true if char on i-index is a number
        }
        //if not it is still set to false

        //checking if it has special character
        if( (static_cast<int>(password[i]) > 32 && static_cast<int>(password[i]) < 48 ) ||
            (static_cast<int>(password[i]) > 57 && static_cast<int>(password[i]) < 65 ) ) {
            hasSpecialCharacter = true; //bool to true if char on i-index is a special character
        }

        if( (static_cast<int>(password[i]) > 64 && static_cast<int>(password[i]) < 91 ) ) {
            hasUppercaseLetter = true; //bool to true if char on i-index is a number
        }
    }
    if(!hasNumber)
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    if(!hasSpecialCharacter)
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    if(!hasUppercaseLetter)
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string first, std::string second)
{
    if(!doesPasswordsMatch(first, second))
    {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(first);
}


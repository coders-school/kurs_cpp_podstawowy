#include "validation.hpp"
#include <string>

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
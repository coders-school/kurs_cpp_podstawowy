#include "validation.hpp"
#include <iostream>

std::string getErrorMessage(ErrorCode code){
    switch(code){
        case Ok:{
            return "Password OK";
            break;
        }
        case PasswordNeedsAtLeastNineCharacters:{
            return "Password needs at least nine characters.";
            break;
        }
        case PasswordNeedsAtLeastOneNumber:{
            return "Password needs at least one number.";
            break;
        }
        case PasswordNeedsAtLeastOneSpecialCharacter:{
            return "Password neads at leastone special character.";
            break;
        }
        case PasswordNeedsAtLeastOneUppercaseLetter:{
            return "Passwors needs at least one uppercase letter.";
            break;
        }
        case PasswordsDoesNotMatch:{
            return "Passwords does not match.";
            break;
        }
    }
    return "test";
}

bool doesPasswordsMatch(std::string password1, std::string password2){
    
    return 0;
}

ErrorCode checkPasswordRules(std::string password){
    
    return Ok;
}

ErrorCode checkPassword(std::string password1, std::string password2){
    
    return Ok;
}

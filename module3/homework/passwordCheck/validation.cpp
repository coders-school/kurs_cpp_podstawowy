#include "validation.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>

std::string getErrorMessage(ErrorCode code){
    switch(code){
        case Ok:{
            return "OK";
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
    if (password1 == password2){
        return true;
    } else {
        return false;
    }
}

ErrorCode checkPasswordRules(std::string password){
   // bool ifNumber = false;
   // bool ifSpecialCharacter = false;
   // bool ifUppercaseLetter = false
    if (password.size() < 9){
        return PasswordNeedsAtLeastNineCharacters;
    } else if (!std::any_of(password.begin(), password.end(), [](char i){return std::isdigit(i);})) {
        return PasswordNeedsAtLeastOneNumber;
    } else if (!std::any_of(password.begin(), password.end(), [](char i){return std::ispunct(i);})) {
        return PasswordNeedsAtLeastOneSpecialCharacter;
    } else if (!std::any_of(password.begin(), password.end(), [](char i){return std::isupper(i);})) {
        return PasswordNeedsAtLeastOneUppercaseLetter;    
    } else
    return Ok;
}

ErrorCode checkPassword(std::string password1, std::string password2){
    if (doesPasswordsMatch(password1, password2) == false){
        return PasswordsDoesNotMatch;
    } else {
        return checkPasswordRules(password1);   
    }
}

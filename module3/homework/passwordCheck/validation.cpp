#include "validation.hpp"
#include <iostream>


std::string getErrorMessage(ErrorCode err){
    switch(err){
        case ErrorCode::Ok:
            return "OK";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Your password needs at least nine characeters";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Your password needs at least one special character";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Your password needs at least one uppercase letter";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Password does not match";
            break;
        default:
            return "Unknown error";
            break;
    }
}
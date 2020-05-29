#include "validation.hpp"
#include <iostream>
#include <ctime>


std::string getErrorMessage(ErrorCode err){
    switch(err){
        case ErrorCode::Ok:
            return "OK";
            break;
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

bool doesPasswordsMatch(std::string first_password, std::string second_password){
    if(first_password == second_password){
        return true;
    }
    return false;
}

ErrorCode checkPasswordRules(std::string password){
    std::srand(std::time(nullptr));
    return static_cast<ErrorCode>(std::rand() % static_cast<int>(ErrorCode::PasswordsDoesNotMatch));
}
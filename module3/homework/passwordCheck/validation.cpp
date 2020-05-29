#include "validation.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>

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
    /*
    TODO:
    -Modify and add new test cases to check if function is working properly
    */
    
    // Exercise 4
    // std::srand(std::time(nullptr));
    // return static_cast<ErrorCode>(std::rand() % static_cast<int>(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter));
    if(password.size() < 9){
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if(!std::any_of(password.begin(), password.end(), ispunct)){
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if(!std::any_of(password.begin(), password.end(), isupper)){
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    
    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string first_password, std::string second_password){
    if(!doesPasswordsMatch(first_password, second_password)){
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(first_password);
}
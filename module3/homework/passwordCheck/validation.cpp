#include "validation.hpp"
#include <algorithm>
#include <iostream>

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
        case ErrorCode::PassworIncludeForbiddenCharacter:
            return "Your password include forbidden character";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Password does not match";
            break;
        default:
            return "Unknown error";
            break;
    }
}

bool doesPasswordsMatch(const std::string& first_password, const std::string& second_password){
    return first_password == second_password;
}

ErrorCode checkPasswordRules(const std::string& password){
    if(password.size() < 9){
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if(!std::any_of(password.begin(), password.end(), ispunct)){
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if(!std::any_of(password.begin(), password.end(), isupper)){
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    if(!std::any_of(password.begin(), password.end(), isdigit)){
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if(!std::none_of(password.begin(), password.end(), isspace)){
        return ErrorCode::PassworIncludeForbiddenCharacter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& repeated_password){
    if(!doesPasswordsMatch(password, repeated_password)){
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(password);
}

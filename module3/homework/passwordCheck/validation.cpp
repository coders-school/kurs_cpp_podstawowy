#include "validation.hpp"

std::string getErrorMessage(const ErrorCode error){
    switch (error){
    case Ok:
        return "Ok";
    case PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
    case PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
    case PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
    case PasswordDoesNotMatch:
        return "Password does not match";        
    }
    return "Unknown error";
}

bool doesPasswordMatch(const std::string& lhs, const std::string& rhs){
    return lhs == rhs;
}

ErrorCode checkPasswordRules(const std::string& str){
    return Ok;
}

ErrorCode checkPassword(const std::string& lhs, const std::string& rhs){
    if(!doesPasswordMatch(lhs, rhs)){
        return PasswordDoesNotMatch;
    }
    return checkPasswordRules(lhs);
}

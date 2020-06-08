#include "validation.hpp"
#include <algorithm>

std::string getErrorMessage(const ErrorCode error){
    switch (error){
    case Ok:
        return "OK";
    case PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
    case PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
    case PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
    case PasswordsDoesNotMatch:
        return "Password does not match";        
    }
    return "Unknown error";
}

bool doesPasswordsMatch(const std::string& lhs, const std::string& rhs){
    return lhs == rhs;
}

ErrorCode checkPasswordRules(const std::string& str){
    if(str.length() < MinPasswordLength){
        return PasswordNeedsAtLeastNineCharacters;
    }
    else if(std::none_of(str.begin(), str.end(), ::isdigit)){
        return PasswordNeedsAtLeastOneNumber;
    }
    else if(std::all_of(str.begin(), str.end(), ::isalnum)){
        return PasswordNeedsAtLeastOneSpecialCharacter;
    }
    else if(std::none_of(str.begin(),str.end(), ::isupper)){
        return PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return Ok;
}

ErrorCode checkPassword(const std::string& lhs, const std::string& rhs){
    if(!doesPasswordsMatch(lhs, rhs)){
        return PasswordsDoesNotMatch;
    }
    return checkPasswordRules(lhs);
}

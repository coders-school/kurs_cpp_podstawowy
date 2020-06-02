#include "validation.hpp"

std::string getErrorMessage(const ErrorCode code){
switch (code)
{
case ErrorCode::Ok :
    return "OK";
    break;
case ErrorCode::PasswordNeedsAtLeastNineCharacters :
    return "Password is too short, needs at least 9 characters";
    break;
case ErrorCode::PasswordNeedsAtLeastOneNumber : 
    return "Password needs at least one number";
    break;
case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter :
    return "Password needs at least one special character";
    break;
case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter :
    return "Password needs at least one uppercase letter";
    break;
case ErrorCode::PasswordsDoesNotMatch :
    return "Passwords doesnt match";
    break;
default:
    return "unknown error, better contact the service";
    break;
}
}

bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword){
    return firstPassword == secondPassword;
}

ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword){
    if(bool code = doesPasswordsMatch(firstPassword, secondPassword);!code){
        return ErrorCode::PasswordsDoesNotMatch;
    }else{
        return checkPasswordRules(firstPassword);
    }
}
ErrorCode checkPasswordRules(const std::string& password){
    if(password.length() < 9){
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }if(std::none_of(password.begin(), password.end(), ::isdigit)){
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }if(std::all_of(password.begin(),password.end(), ::isalnum)){
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }if(std::none_of(password.begin(),password.end(), ::isupper)){
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

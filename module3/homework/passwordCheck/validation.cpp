#include "validation.hpp"

std::string getErrorMessage(ErrorCode error){
    switch(error){
        case ErrorCode::Ok:
            return "OK";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "PasswordNeedsAtLeastNineCharacters";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "PasswordNeedsAtLeastOneNumber";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "PasswordNeedsAtLeastOneSpecialCharacter";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "PasswordNeedsAtLeastOneUppercaseLetter";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "PasswordsDoesNotMatch";
            break;
        default:
            return "Error code not know";
    }
}

bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword){
    return (firstPassword == secondPassword);
}

ErrorCode checkPasswordRules(const std::string& password){
    srand( time( NULL ) ); 
    return ErrorCode(std::rand()%5);
}

ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword){
    if(!doesPasswordsMatch(firstPassword, secondPassword))
        return ErrorCode::PasswordsDoesNotMatch;
    else
        return checkPasswordRules(firstPassword);    
}

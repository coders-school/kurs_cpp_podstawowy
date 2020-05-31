#include "validation.hpp"

ErrorCode checkPassword(const std::string& password,const std::string& repeatedPassword) {
    if(!doesPasswordsMatch(password, repeatedPassword))
        return ErrorCode::PasswordsDoesNotMatch;

    
}

bool doesPasswordsMatch(const std::string& password,const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    
}



std::string getErrorMessage(ErrorCode result) {
    
    switch(result)
    {
        case ErrorCode::Ok:
            return "Ok";
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
            return "UndefinedError";
    }
}
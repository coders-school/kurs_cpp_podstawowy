#include "validation.hpp"
#include <regex>

ErrorCode checkPassword(const std::string& password,const std::string& repeatedPassword) {
    if(!doesPasswordsMatch(password, repeatedPassword))
        return ErrorCode::PasswordsDoesNotMatch;
    
    return checkPasswordRules(password);  
}

bool doesPasswordsMatch(const std::string& password,const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    std::regex upperCaseChar("[A-Z]");
    std::regex specialChar("[$&+,:;=?@#|'<>.^*()%!]");
    std::regex oneNumber("[0-9]");

    if(password.length() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    if(!std::regex_search(password,  upperCaseChar))
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    if(!std::regex_search(password, specialChar))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    if(!std::regex_search(password, oneNumber))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    return Ok;

}


std::string getErrorMessage(ErrorCode result) {
    
    switch(result)
    {
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
            return "UndefinedError";
    }
}
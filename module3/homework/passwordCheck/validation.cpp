#include "validation.hpp"

std::string getErrorMessage(ErrorCode error){
    switch(error){
        case ErrorCode::Ok:
            return "OK";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Password needs at least nine characters";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Password needs at least one number";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Password needs at least one special character";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Password needs at least one uppercase letter";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Passwords does not match";
            break;
        default:
            return "Unknown error code";
    }
}

bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword){
    return (firstPassword == secondPassword);
}

ErrorCode checkPasswordRules(const std::string& password){
    if(password.size() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    else if(!(std::any_of(password.begin(), password.end(), [](auto element){return std::isdigit(element);})))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    else if(!(std::any_of(password.begin(), password.end(), [](auto element){return std::ispunct(element);})))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    else if(!(std::any_of(password.begin(), password.end(), [](auto element){return std::isupper(element);})))
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    else
        return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword){
    if(!doesPasswordsMatch(firstPassword, secondPassword))
        return ErrorCode::PasswordsDoesNotMatch;
    else
        return checkPasswordRules(firstPassword);    
}

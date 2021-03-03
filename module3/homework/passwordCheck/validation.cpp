#include "validation.hpp"
// TODO: Put implementations here
std::string getErrorMessage(ErrorCode error){
    switch(error){
        case ErrorCode::Ok:
            return "OK";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Password needs at least nine characters.\n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Password needs at least one number.\n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Password needs at least one special character.\n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Password needs at least one uppercase letter.\n";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Password does not match.\n";
            break;
    }
}

bool doesPasswordsMatch(const std::string password, const std::string repeatedPassword){
    if (password == repeatedPassword)
        return true;
    else
        return false;
}

ErrorCode checkPasswordRules(const std::string password){
    if(password.length() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    
    bool hasNumber = false;
    for(int i = 0; i < password.length(); i++){
        if(isdigit(password[i]))
            hasNumber = true;
    }
    if(!hasNumber)
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    std::string normalCharacter = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    size_t specialCharacter = password.find_first_not_of(normalCharacter);
    bool hasSpecialCharacter = false;
    if(specialCharacter != std::string::npos)
        hasSpecialCharacter = true;
    if(!hasSpecialCharacter)
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    bool hasUppercaseLetter = false;
    for(int i = 0; i < password.length(); i++){
        if(isupper(password[i]))
            hasUppercaseLetter = true;
    }
    if(!hasUppercaseLetter)
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    else
        return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string password, const std::string repeatedPassword){
    if(doesPasswordsMatch(password, repeatedPassword))
        return checkPasswordRules(password);
    else
        return ErrorCode::PasswordsDoesNotMatch;
}

#include "validation.hpp"

std::string getErrorMessage(ErrorCode error){
    switch(error){
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
            return "Error code not know";
    }
}

bool doesPasswordsMatch(std::string firstPassword, std::string secondPassword){
    return (firstPassword == secondPassword);
}
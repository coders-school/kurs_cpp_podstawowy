#include "validation.hpp"

std::string getErrorMessage(ErrorCode err){
    static const std::map < ErrorCode, std::string > labels = {
        {Ok,"OK"},
        {PasswordNeedsAtLeastNineCharacters,"PasswordNeedsAtLeastNineCharacters"},
        {PasswordNeedsAtLeastOneNumber,"PasswordNeedsAtLeastOneNumber"},
        {PasswordNeedsAtLeastOneSpecialCharacter,"PasswordNeedsAtLeastOneSpecialCharacter"},
        {PasswordNeedsAtLeastOneUppercaseLetter,"PasswordNeedsAtLeastOneUppercaseLetter"},
        {PasswordsDoesNotMatch,"PasswordsDoesNotMatch"}
    };
    return labels.find(err)->second;
}

bool doesPasswordsMatch(std::string passwd1,std::string passwd2){
    if(passwd1.compare(passwd2)==0)
        return true;
    else return false;
}

ErrorCode checkPasswordRules(std::string passwd){
    return static_cast<ErrorCode>(rand()%4);
}
ErrorCode checkPassword(std::string passwd1,std::string passwd2){
    if(!doesPasswordsMatch(passwd1,passwd2))
        return PasswordsDoesNotMatch;
    else 
        return checkPasswordRules(passwd1);
}


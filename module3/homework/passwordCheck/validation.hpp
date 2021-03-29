#ifndef validation_H_
#define validation_H_

#include <string>

enum class ErrorCode
{
    Ok ,
    PasswordNeedsAtLeastNineCharacters ,
    PasswordNeedsAtLeastOneNumber ,
    PasswordNeedsAtLeastOneSpecialCharacter ,
    PasswordNeedsAtLeastOneUppercaseLetter ,
    PasswordsDoesNotMatch 
};
std::string getErrorMessage(ErrorCode msg);
bool doesPasswordsMatch(std::string password1, std::string password2);
ErrorCode checkPasswordRules(const std::string pass);
ErrorCode checkPassword(std::string password1, std::string password2);
//
#endif 
#ifndef PASSWORDCHECKO_VALIDATION_H
#define PASSWORDCHECKO_VALIDATION_H

#include <iostream>

enum class ErrorCode
{
    Ok = 123,
    PasswordNeedsAtLeastNineCharacters = 9,
    PasswordNeedsAtLeastOneNumber = 1,
    PasswordNeedsAtLeastOneSpecialCharacter = 2,
    PasswordNeedsAtLeastOneUppercaseLetter = 3,
    PasswordsDoesNotMatch = 0,
};

//Functions
void getErrorMessage(ErrorCode type);
bool doesPasswordsMatch(std::string first, std::string second);
ErrorCode checkPasswordRules(std::string password);
ErrorCode checkPassword(std::string first, std::string second);

#endif //PASSWORDCHECKO_VALIDATION_H


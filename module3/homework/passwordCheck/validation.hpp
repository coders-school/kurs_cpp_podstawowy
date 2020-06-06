#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

enum ErrorCode
{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode error){
    return "Ok";
}

bool doesPasswordsMatch(std::string input,std::string password){
    return false;
}

std::string checkPasswordRules(const std::string& password){
   srand (time(NULL));
   int random = rand() % 6;
   return getErrorMessage(ErrorCode(random));
}

std::string checkPassword(std::string input,std::string password){
    if (!doesPasswordsMatch(input,password)) {
        return getErrorMessage(ErrorCode::PasswordsDoesNotMatch);
    }
    return checkPasswordRules(input);
}


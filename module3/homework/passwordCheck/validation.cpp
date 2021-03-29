#include "validation.hpp"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <experimental/random>
#include <algorithm>
#include <cctype>
#include <string>
#include <stdio.h>
// TODO: Put implementations here

std::string getErrorMessage(ErrorCode msg)
{
    switch (msg)
    {
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
    }
    return "OK";
}
bool doesPasswordsMatch(std::string password1, std::string password2)
{
    if (password1 == password2)
    {   
        return true;
    }
    return false;
}

ErrorCode checkPasswordRules(const std::string pass)
{
    if(pass.length() < 0)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    
    //PasswordNeedsAtLeastOneNumber
    if(!std::any_of(pass.begin(), pass.end(), ::isdigit))
    {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    //PasswordNeedsAtLeastOneSpecialCharacter
    // std::string normalChar = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    // size_t special = pass.find_first_not_of(normalChar);
    // bool flagaSpecial = false;
    // if (special != std::string::npos)
    //     flagaSpecial = true;
    // if (flagaSpecial)
    //     return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    std::string normalCharacter = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    size_t specialCharacter = pass.find_first_not_of(normalCharacter);
    bool hasSpecialCharacter = false;
    if(specialCharacter != std::string::npos)
        hasSpecialCharacter = true;
    if(!hasSpecialCharacter)
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    //PasswordNeedsAtLeastOneUppercaseLetter
    bool containUppercase = false;
    int i = 0;
    while (pass[i])
    {
        if (isupper(pass[i]))
        {
            containUppercase = true;
        }
        i++;
    }
    if (!containUppercase)
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    
    return ErrorCode::Ok;

    //PasswordsDoesNotMatch

}
ErrorCode checkPassword(std::string password1, std::string password2)
{
      if (doesPasswordsMatch(password1, password2))
      {
            return checkPasswordRules(password1);
      }
   return ErrorCode::PasswordsDoesNotMatch;
}
#include "validation.hpp"
#include <string>
#include <iostream>
#include <algorithm>

bool czy_zawiera_cyfre(char znak)
{
    int cyfra = (int)znak;
    return (cyfra >= 48) && (cyfra <= 57);
}

bool czy_zawiera_znak_specjalny(char znak)
{
    int cyfra = (int)znak;
    return ((cyfra >= 0) && (cyfra <= 47)
        || (cyfra >= 58) && (cyfra <= 64)
        || (cyfra >= 91) && (cyfra <= 96)
        || (cyfra >= 0) && (cyfra <= 47)
        || (cyfra >= 123) && (cyfra <= 255));
}

bool czy_zawiera_wielka_litere(char znak)
{
    int cyfra = (int)znak;
    return (cyfra >= 65) && (cyfra <= 90);
}

ErrorCode checkPasswordRules(std::string password)
{
    if (password.size() < 9) 
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    if (!std::any_of(password.begin(), password.end(), czy_zawiera_cyfre))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    if (!std::any_of(password.begin(), password.end(), czy_zawiera_znak_specjalny))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    
    if (!std::any_of(password.begin(), password.end(), czy_zawiera_wielka_litere))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    return ErrorCode::Ok;
}



ErrorCode checkPassword(std::string password, std::string repeatedPassword)
{
    if (doesPasswordsMatch(password, repeatedPassword))
        return checkPasswordRules(password);
    else 
        return ErrorCode::PasswordsDoesNotMatch;
   
}

bool doesPasswordsMatch(std::string password, std::string repeatedPassword)
{
    return (password == repeatedPassword);
}

std::string getErrorMessage(ErrorCode result)
{
        switch(result)
        {
        case ErrorCode::Ok:
            return "OK";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Your password need at least nine characters. \n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Your password need at least one number. \n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Your password need at least one special character. \n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return  "Your password need at least one uppercase letter. \n";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Passwords does not match. \n";
            break;
        default:
            return "Error \n";
        }
}   
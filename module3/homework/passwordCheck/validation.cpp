#include <iostream>
#include <array>

#include "validation.h"

std::string getErrorMessage(ErrorCode errorType){
    switch(errorType){
        case ErrorCode::Ok:
            return "Your password is ok. \n";
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
            return "Unknown error \n";
    }
}

bool doesPasswordsMatch(std::string& first, std::string& second)
{
    return first == second;
}

ErrorCode checkPasswordRules(std::string& password)
{
    //checking if size in at least 9
    if(password.size() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    //checking if string has at least one number, one special character and uppercase letter
    //default to false
    bool hasNumber = false;
    bool hasSpecialCharacter = false;
    bool hasUppercaseLetter = false;

    //everything in one loop, so the efficiency if better
    for(size_t i= 0; i < password.size(); i++)
    {
        //checking if it has at least one number
        //add "!hasNumber" statement so it doesn't need to check if it's true
        if( !hasNumber && password[i] >= '0' && password[i] <= '9' ){
            hasNumber = true; //bool to true if char on i-index is a number
        }
        //if not it is still set to false

        //checking if it has special character
        if( !hasSpecialCharacter && ( password[i] > ' ' && password[i] < '0' ) ||
                (password[i] > '9' && password[i] < 'A' ) ) {
            hasSpecialCharacter = true; //bool to true if char on i-index is a special character
        }

        //hasSpecialCharacter = (std::any_of(password.begin(), password.end(), [](char c){return c == '!' || c == '@';}));
        // ^this gonna work but i don't know how to check every special character, i think it's bad to write out all symbols

        if( !hasUppercaseLetter && password[i] > 'A' && password[i] < 'Z' ) {
            hasUppercaseLetter = true; //bool to true if char on i-index is a number
        }
    }
    if(!hasNumber)
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    if(!hasSpecialCharacter)
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    if(!hasUppercaseLetter)
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string& first, std::string& second)
{
    if(!doesPasswordsMatch(first, second))
    {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(first);
}

int main() {
    std::string password;
    std::string repeatedPassword;
    std::cout << "Set new password: ";
    std::cin >> password;
    std::cout << "Repeat password: ";
    std::cin >> repeatedPassword;
    auto result = checkPassword(password, repeatedPassword);
    std::cout << getErrorMessage(result) << '\n';

    return 0;
}

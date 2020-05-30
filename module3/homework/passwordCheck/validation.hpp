#include<string>

enum class ErrorCode 
{
    Ok = 0,
    PasswordNeedsAtLeastNineCharacters = 1,
    PasswordNeedsAtLeastOneNumber = 2,
    PasswordNeedsAtLeastOneSpecialCharacter = 3,
    PasswordNeedsAtLeastOneUppercaseLetter = 4,
    PasswordsDoesNotMatch = 5
};


std::string getErrorMessage(ErrorCode code);
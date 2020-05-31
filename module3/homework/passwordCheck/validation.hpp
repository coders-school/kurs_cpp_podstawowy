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

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword);
std::string getErrorMessage(ErrorCode code);
ErrorCode checkPasswordRules(std::string& password);

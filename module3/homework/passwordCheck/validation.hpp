#include <string>

enum class ErrorCode
{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

//Functions
std::string getErrorMessage(ErrorCode errorType);
bool doesPasswordsMatch(std::string& first, std::string& second);
ErrorCode checkPasswordRules(std::string& password);
ErrorCode checkPassword(std::string& first, std::string& second);


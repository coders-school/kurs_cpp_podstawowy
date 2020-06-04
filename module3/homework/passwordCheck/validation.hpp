#include <string>

enum class ErrorCode {

Ok,
PasswordNeedsAtLeastNineCharacters,
PasswordNeedsAtLeastOneNumber,
PasswordNeedsAtLeastOneSpecialCharacter,
PasswordNeedsAtLeastOneUppercaseLetter,
PasswordsDoesNotMatch

};


std::string getErrorMessage(ErrorCode e);

bool doesPasswordsMatch(const std::string& pass, const std::string& repPass);

ErrorCode checkPasswordRules(const std::string& pass);

ErrorCode checkPassword(const std::string& pass, const std::string& repPass);

ErrorCode checkPasswordRules(const std::string& pass, const std::string& repPass);


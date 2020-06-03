#pragma once
#include <string>

enum class ErrorCode {
Ok,
PasswordNeedsAtLeastNineCharacters,
PasswordNeedsAtLeastOneNumber,
PasswordNeedsAtLeastOneSpecialCharacter,
PasswordNeedsAtLeastOneUppercaseLetter,
PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode code);
bool doesPasswordsMatch(std::string const & pass1, std::string const & pass2);
ErrorCode checkPasswordRules(std::string const & pass);
ErrorCode checkPassword(std::string const & pass1, std::string const & pass2);

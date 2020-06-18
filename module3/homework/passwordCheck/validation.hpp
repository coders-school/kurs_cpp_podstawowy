// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard
#pragma once
#include <string>
#include <map>

enum ErrorCode {
Ok,
PasswordNeedsAtLeastNineCharacters,
PasswordNeedsAtLeastOneNumber,
PasswordNeedsAtLeastOneSpecialCharacter,
PasswordNeedsAtLeastOneUppercaseLetter,
PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode);
bool doesPasswordsMatch(std::string passwd1,std::string passwd2);
ErrorCode checkPasswordRules(std::string passwd);
ErrorCode checkPassword(std::string passwd1,std::string passwd2);


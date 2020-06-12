#include "validation.hpp"

#include <iostream>
#include <algorithm>
#include <string>

std::string getErrorMessage(const ErrorCode error){
switch(error){
   case ErrorCode::Ok:
      return "OK";
   case ErrorCode::PasswordNeedsAtLeastNineCharacters:
      return "Too short password(needs at least 9 character )";
   case ErrorCode::PasswordNeedsAtLeastOneNumber:
      return "Password needs at least one number";
   case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
      return "Password needs at least one special character";
   case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
      return "Password needs at least one uppercase letter";
   case ErrorCode::PasswordsDoesNotMatch:
      return "Passwords doesn't match";
   default:
      return "undefined error";
   }
}

bool doesPasswordsMatch(const std::string& first, const std::string& second){
   return first == second;
}

ErrorCode checkPasswordRules(const std::string& password){
   
   
   size_t const minimumPasswordLength = 9;
   
   if(password.size() < minimumPasswordLength) {
      return ErrorCode::PasswordNeedsAtLeastNineCharacters;
   }
   
   if (std::none_of(password.begin(), password.end(), ::isdigit)) {
      return ErrorCode::PasswordNeedsAtLeastOneNumber;
   }

   if (std::all_of(password.begin(), password.end(), ::isalnum)) {
      return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
   }

   if (std::none_of(password.begin(), password.end(), ::isupper)) {
      return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
      }
   return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& first, const std::string& second){
   if(!doesPasswordsMatch(first, second)) {
      return ErrorCode::PasswordsDoesNotMatch;
   }

   return checkPasswordRules(first);
}


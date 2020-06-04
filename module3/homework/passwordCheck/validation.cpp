#include "validation.hpp"
#include <algorithm>
#include <numeric>

std::string getErrorMessage(ErrorCode error){
    switch(static_cast<int>(error)){
      case static_cast<int>(ErrorCode::Ok):
         return "OK";
      case static_cast<int>(ErrorCode::PasswordNeedsAtLeastNineCharacters):
         return "Error! Password need at least 9 characters !";
      case static_cast<int>(ErrorCode::PasswordNeedsAtLeastOneNumber):
         return "Error! Password need at least 1 number !";
      case static_cast<int>(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter):
         return "Error! Password need at least 1 special char !";
      case static_cast<int>(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter):
         return "Error! Password need at least 1 Uppercase Letter !";
      case static_cast<int>(ErrorCode::PasswordsDoesNotMatch):
         return "Password does not match !!!";
      default: 
         return "Unknown Error !";
    }
}

bool doesPasswordsMatch(const std::string& first, const std::string& second){

    return first == second;
}

ErrorCode checkPasswordRules(const std::string& password){

    if(password.size() < 9){
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if(std::none_of(password.begin(), password.end(), isdigit)){
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if(std::none_of(password.begin(), password.end(), [](int letter){return (isalpha(letter) == 0) && (isdigit(letter) == 0);})){
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if(std::none_of(password.begin(), password.end(), isupper)){
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& first, const std::string& second){

    if(doesPasswordsMatch(first, second)){
        return checkPasswordRules(first);
    }

    return ErrorCode::PasswordsDoesNotMatch;
}

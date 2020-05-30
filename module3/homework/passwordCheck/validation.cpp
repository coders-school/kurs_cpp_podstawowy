#include "validation.hpp"
// TODO: Put implementations here


std::string getErrorMessage(ErrorCode error){
    switch(static_cast<int>(error)){
      case 0:
         return "OK";
         break;
      case 1:
         return "Wrong ! Password need at least 9 characters !";
         break;
      case 2:
         return "Wrong ! Password need at least 1 number !";
         break;
      case 3:
         return "Wrong ! Password need at least 1 special char !";
         break;
      case 4:
         return "Wrong ! Password need at least 1 Uppercase Letter !";
         break;
      case 5:
         return "Password does not match !!!";
         break;
    }

return "";
}

bool doesPasswordsMatch(std::string first, std::string second){

    return first == second ? true : false;
}

ErrorCode checkPasswordRules(std::string password){

    if(password.size() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    if(std::none_of(password.begin(), password.end(), isdigit)){
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if (std::none_of(password.begin(), password.end(), [](int letter){  return (isalpha(letter) == 0) && (isdigit(letter) == 0); })){
         return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (std::none_of(password.begin(), password.end(), isupper)){
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string first, std::string second){

    if(doesPasswordsMatch(first, second)){
        return checkPasswordRules(first);
    }
    else{
        return ErrorCode::PasswordsDoesNotMatch;
    }
}



#include <iostream>

enum class ErrorCode {
  OK,
  PASSWORD_DOESNT_MATCH,
  PASSWORD_NEED_AT_LEAST_NINE_CHARACTER,
  PASSWORD_NEED_AT_LEAST_ONE_NUMBER,
  PASSWORD_NEED_AT_LEAST_ONE_SPECIAL_CHARACTER,
  PASSWORD_NEED_AT_LEAST_ONE_UPPER_LETTER
};

ErrorCode CheckPassword(const std::string& str) {
  return ErrorCode::OK;
}

int main() {
  std::string password;
  ErrorCode response = ErrorCode::PASSWORD_DOESNT_MATCH;

  while (response != ErrorCode::OK) {
    std::cout << "Provide Password: ";
    std::cin >> password;
    response = CheckPassword(password);
    switch (response) {
    case ErrorCode::OK: {
        std::cout << "Provide Again password: ";
        std::string password2;
        std::cin >> password2;
        if (password2 == password)
          std::cout << "OK!\n";
        else {
          response = ErrorCode::PASSWORD_DOESNT_MATCH;;
          std::cout << "ErrorCode::PASSWORD_DOESNT_MATCH\n";
        }
        break;
      }
    case ErrorCode::PASSWORD_DOESNT_MATCH:
      std::cout << "PASSWORD_DOESNT_MATCH\n";
      break;
    case ErrorCode::PASSWORD_NEED_AT_LEAST_NINE_CHARACTER:
      std::cout << "PASSWORD_NEED_AT_LEAST_NINE_CHARACTER\n";
      break;
    case ErrorCode::PASSWORD_NEED_AT_LEAST_ONE_NUMBER:
      std::cout << "PASSWORD_NEED_AT_LEAST_ONE_NUMBER\n";
      break;
    case ErrorCode::PASSWORD_NEED_AT_LEAST_ONE_SPECIAL_CHARACTER:
      std::cout << "PASSWORD_NEED_AT_LEAST_ONE_SPECIAL_CHARACTER\n";
      break;
    case ErrorCode::PASSWORD_NEED_AT_LEAST_ONE_UPPER_LETTER:
      std::cout << "PASSWORD_NEED_AT_LEAST_ONE_UPPER_LETTER\n";
      break;
    }
  }

  return 0;
}

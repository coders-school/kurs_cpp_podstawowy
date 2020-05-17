#include <algorithm>
#include <iostream>
#include <string>

void Tolower(char& characer) {
  characer = tolower(characer);
}

std::string FormatString(std::string str) {
    std::for_each(std::begin(str), std::end(str), Tolower);
    // In futre You will learn std::transform and can make this
    // std::transform(std::begin(str), std::end(str), std::begin(str), tolower);

    std::string str_whithout_whitespaces {};
    const char whitespaces[] = "\t\n ";
    for (char character : str) {
      if (std::find(std::begin(whitespaces), std::end(whitespaces), character) 
        == std::end(whitespaces)) {
          str_whithout_whitespaces += character;
        }
    }

  return str_whithout_whitespaces;
}

// int main() {
//   std::string str("AlA ma \tKotA \na KoT \nma aLe");
//   std::cout << "Before format string: " << str << '\n';
//   str = FormatString(str);
//   std::cout << "After format string: " << str << '\n';

//   return 0;
// }

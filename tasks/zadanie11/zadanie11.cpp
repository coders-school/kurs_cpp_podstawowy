#include <algorithm>
#include <iostream>
#include <string>

std::string RemoveVovel(const std::string& str) {
  const char vovels[] = "aeiouy";
  std::string str_without_vovels;

  for (char character : str) {
    if (std::find(std::begin(vovels), std::end(vovels), character) == std::end(vovels))
      str_without_vovels += character;
  }

  return str_without_vovels;
}

// int main() {
//   std::string str("ala ma kota a kot ma ale");
//   str = RemoveVovel(str);
//   std::cout << "After delete vovels: " << str;

//   return 0;
// }

#include <algorithm>
#include <iostream>
#include <string>

size_t CountVovel2(const std::string& str) {
  size_t counter {0};
  const char vovels[] = "aeiouy";
  size_t pos = str.find_first_of(vovels);
  while (pos != std::string::npos) {
    pos = str.find_first_of(vovels, ++pos);
    ++counter;
  }

  return counter;
}

size_t CountVovel(const std::string& str) {
  size_t counter {0};
  const char vovels[] = "aeiouy";
  size_t pos = 0;
  while (true) {
    pos = str.find_first_of(vovels, pos);
    if (pos != std::string::npos)
      ++counter;
    else
      break;
    ++pos;
  }

  return counter;
}

// int main() {
//   std::string str("ala ma kota a kot ma ale");
//   std::cout << "vowels: " << CountVovel(str) << "\n";
//   std::cout << "vowels: " << CountVovel2(str) << "\n";

//   return 0;
// }

#include <iostream>
#include <vector>

// First option
bool isPrime(size_t number) {
  if (number < 2) 
    return false;
  if (number < 4)
    return true;

  int divider {2};
  while (number >= divider * 2) {
    if (number % divider == 0)
      return false;
    ++divider;
  }

  return true;
}

// Second much better option
// We need to check only if number is divide by 2, 3, 5
// or 11, 17, 23 ect.. (prviouse number + 6)
// Whats more we only need to check sqrt(number) numbers.
bool isPrime2(size_t number) {
  if (number < 4) 
    return number > 1;
  if (number % 2 == 0 || number % 3 == 0)
    return false;

  int divider {5};
  while (number >= divider * divider) {
    if (number % divider == 0)
      return false;
    divider+=6;
  }

  return true;
}

// int main() {
//   std::vector<int> not_prime_num {4, 6, 8, 10, 12, 14, 144, 148, 125, 100, 225, 81, 1270, 432, 111};
//   for (int element : not_prime_num) {
//     std::cout << element << " isPrime? " << std::boolalpha << isPrime(element) << "\n";
//   }

//   std::vector<int> prime_num {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
//   for (int element : prime_num) {
//     std::cout << element << " isPrime? " << std::boolalpha << isPrime(element) << "\n";
//   }

//   std::cout << "\n" << std::string(40, '_') << "\n";
  
//   for (int element : not_prime_num) {
//     std::cout << element << " isPrime? " << std::boolalpha << isPrime2(element) << "\n";
//   }
//   for (int element : prime_num) {
//     std::cout << element << " isPrime? " << std::boolalpha << isPrime2(element) << "\n";
//   }

//   return 0;
// }

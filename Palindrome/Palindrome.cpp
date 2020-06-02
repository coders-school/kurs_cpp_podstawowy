#include <iostream>

bool isPalindrome(const std::string &text){
    bool result = true;
    for (long unsigned int i = 0;i< text.length() / 2;i++){
        if (text[i] != text[text.length() - i - 1]) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
    std::cout << isPalindrome("Ala ma kota") << "\n";
    std::cout << isPalindrome("ala") << "\n"; 
    std::cout << isPalindrome("kajak") << "\n";
    std::cout << isPalindrome("neveroddoreven") << "\n";
    std::cout << isPalindrome("abacada") << "\n";
}

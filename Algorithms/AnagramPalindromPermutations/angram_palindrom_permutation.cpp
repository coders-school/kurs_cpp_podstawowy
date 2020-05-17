#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"

void TransformToLower(std::string& str) {
    std::transform(begin(str), end(str), begin(str), tolower);
}

void RemoweWhitespaces(std::string& str) {
    const char whitespaces[] = " \t\n\r";
    str.erase(std::remove_if(begin(str), end(str), 
        [&whitespaces](const char c) {
            return std::find(std::begin(whitespaces), std::end(whitespaces), c) != std::end(whitespaces);
        }), str.end()
    );
}

bool isPalindrome(std::string str) {
    TransformToLower(str);
    RemoweWhitespaces(str);
    return std::equal(begin(str), std::next(std::begin(str), str.size() / 2), rbegin(str));
}

bool isAnagram(std::string lhs, std::string rhs) {
    TransformToLower(lhs);
    RemoweWhitespaces(lhs);
    TransformToLower(rhs);
    RemoweWhitespaces(rhs);
    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());
    return lhs == rhs; 
}

void GetPermutationHelper(std::string str, size_t first, size_t last, std::vector<std::string>& res) {
    if (first == last) {
        res.push_back(str);
        return;
    }
        
    for (size_t i = first ; i <= last ; ++i) {
        // swap letter
        std::swap(str[first], str[i]);
        GetPermutationHelper(str, first + 1, last, res);
        // back to previous position
        std::swap(str[first], str[i]);
    }
}

std::vector<std::string> GetPermutation(const std::string& str) { 
    std::vector<std::string> res;
    GetPermutationHelper(str, 0 , str.size() - 1, res);
    return res;
}

TEST(Test, IsPalindrome) {
    EXPECT_TRUE(isPalindrome("a"));
    EXPECT_TRUE(isPalindrome("aa"));
    EXPECT_TRUE(isPalindrome("aaa"));
    EXPECT_TRUE(isPalindrome("Abcdefghijklmnoonmlkjihgfedcba"));
    EXPECT_TRUE(isPalindrome("Abcdefghijklmnonmlkjihgfedcba"));
    EXPECT_TRUE(isPalindrome("Abcd ef ghi jklMn\toON\tmlkJih g f E d C\n\nba"));

    EXPECT_FALSE(isPalindrome("abb"));
    EXPECT_FALSE(isPalindrome("abbaa"));
    EXPECT_FALSE(isPalindrome("abab"));
}

TEST(Test, isAnagram) {
    EXPECT_TRUE(isAnagram("abcdefgh", "hgfedcba"));
    EXPECT_TRUE(isAnagram("Ala ma kota", "kota Ala MA"));
    EXPECT_TRUE(isAnagram("Ala miala kota", "miala akla toa"));

    EXPECT_FALSE(isAnagram("abb", "bbb"));
    EXPECT_FALSE(isAnagram("abba", "aaab"));
    EXPECT_FALSE(isAnagram("Ala kota ma", "ala kot ma"));
}

TEST(Test, ShouldGetPermutaton) {
    std::vector<std::string> expect{
        "Kura", "Kuar", "Krua", "Krau", "Karu", "Kaur", "uKra", "uKar",
        "urKa", "uraK", "uarK", "uaKr", "ruKa", "ruaK", "rKua", "rKau",
        "raKu", "rauK", "aurK", "auKr", "aruK", "arKu", "aKru", "aKur"
    };
    EXPECT_EQ(expect, GetPermutation("Kura"));

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

#include "gtest/gtest.h"

// First implmementation using only pointer
void reverse_helpers(char* begin, char* end)
{
    char tmp {};
    while (begin < end)
    {
        tmp = *begin;
        *begin++ = *end;
        *end-- = tmp;
    }
}

void reverse(char* sentence)
{
    char* begin = sentence;
    char* end = sentence;

    while (*end != '\0')
    {
        end++;
        if (*end == ' ' || *end == '\0')
        {
            reverse_helpers(begin, end - 1);
            begin = end + 1;
        }
    }

    reverse_helpers(sentence, end - 1);
}

// Second implmementation using string and vector
std::string reverseStr(char* sentence)
{
    std::stringstream ss(sentence);
    std::vector<std::string> words;
    for (std::string word ; ss >> word ; )
    {
        words.push_back(word);
    }
    std::reverse(words.begin(), words.end());

    std::string tmp {};
    for (const std::string& word : words)
    {
        tmp += word + " ";
    }
    tmp.pop_back();
    return tmp;
}

TEST(Test, ShoudlReverseSentence) {
    std::string str("This is intresting and valuable sentence!");
    std::string expected("sentence! valuable and intresting is This");
    EXPECT_EQ(expected, reverseStr(str.data()));

    reverse(str.data());
    EXPECT_EQ(expected, str);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
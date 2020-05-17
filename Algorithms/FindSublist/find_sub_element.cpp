#include <algorithm>
#include <array>
#include <list>
#include <numeric>
#include <vector>

#include "gtest/gtest.h"

int FindSusequence(std::list<int> input, std::list<int> sequence) {
    size_t i = 0;
    for (auto it_input = input.begin() ; it_input != input.end() ; ++it_input) {
        if (i++ > input.size() - sequence.size())
            break;

        auto it_seq = sequence.begin();
        for (; it_seq != sequence.end() ; ++it_seq, ++it_input) {
            if (*it_seq != *it_input)
                break;
        }
        if (it_seq == sequence.end())
            return std::distance(input.begin(), it_input) - sequence.size();
    }
    return -1;
}

std::vector<size_t> findAllSubsequence(const std::string& input, const std::string& sequence) {
    std::vector<size_t> pos;
    for (size_t i = 0 ; i <= input.size() - sequence.size() ; i++) {
        size_t j = 0;
        for (; j < sequence.size() ; ++i, ++j) {
            if (input[i] != sequence[j])
                break;
        }
        if (j == sequence.size())
            pos.push_back(i - j);
    }
    return pos;
}

constexpr const int kCharactersNum = 255;

std::array<int, kCharactersNum> PrepareBadChar(const std::string& str) {  
    std::array<int, kCharactersNum> badChar;
    std::fill(begin(badChar), end(badChar), -1);
    for (int i = 0 ; i < str.size() ; ++i) 
        badChar[(int) str[i]] = i;  
    return badChar;
}  

std::vector<int> FindAllSusequenceMoore(const std::string& input, const std::string& sequence) {  
    std::vector<int> result;
    const auto badChar = PrepareBadChar(sequence);
    int shift {};
    while (shift <= (input.size() - sequence.size())) {
        int index = sequence.size() - 1;  

        // Move index if pattern match
        while(index >= 0 && sequence[index] == input[shift + index])  
            --index;

        // If pattern match index will be -1
        if (index == -1) {
            result.push_back(shift); 
            shift += (shift + sequence.size() < input.size()) 
                ? sequence.size() - badChar[input[shift + sequence.size()]]
                : 1;  
        } else {
            shift += std::max(1, index - badChar[input[shift + index]]);  
        }  
    }
    return result;
}  

TEST(Test, ShouldFindFirstSubsequence) {
    std::list<int> list1 {1,2,3,4,5,6,7,8,9,10,11,12,13};
    std::list<int> list2 {11,12,13};
    EXPECT_EQ(FindSusequence(list1, list2), 10);
}

TEST(Test, ShouldFindAllSubsequence) {
    std::string first {"nigdy nie mow nigdy, bo czasami mozesz nie miec racji i wtedy nie"};
    std::vector<size_t> expected {6, 39, 62};
    EXPECT_EQ(expected, findAllSubsequence(first, "nie"));
}

TEST(Test, ShouldFindAllSubsequenceMoore) {
    std::string first {"nigdy nie mow nigdy, bo czasami mozesz nie miec racji i wtedy nie"};
    std::vector<int> expected {6, 39, 62};
    EXPECT_EQ(expected, FindAllSusequenceMoore(first, "nie"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <iostream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

std::vector<std::string> PrintAllCombination(const std::string& str) { 
    int sequences = 1 << str.size();
    std::vector<std::string> result(sequences);

    for (int i = 0 ; i < sequences ; ++i) {
        for (size_t j = 0 ; j < str.size() ; ++j) {
            if (i & (1 << j)) {
                result[i] += str[j];
            }
        }
    }
    return result;
}

TEST(Test, PrintAllCombination) {
    std::vector<std::string> expected {
        "", "K", "r", "Kr", "o", "Ko", "ro", "Kro", "w", "Kw",
         "rw", "Krw", "ow", "Kow", "row", "Krow", "a", "Ka", 
         "ra", "Kra", "oa", "Koa", "roa", "Kroa", "wa", "Kwa", 
         "rwa", "Krwa", "owa", "Kowa", "rowa", "Krowa"
    };
    EXPECT_EQ(expected, PrintAllCombination("Krowa"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
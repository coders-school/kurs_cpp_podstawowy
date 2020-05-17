#include <iostream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

std::string binaryToDec(const std::string& str) {
    int value = 0;
    size_t shift = str.size() - 1;
    for (char el : str) {
        value += (el - 48) << shift--;
    }
    return std::to_string(value);
}

std::string DecToBinary(const std::string& str) {
    if (str == "0")
        return str;
    std::string ret;
    int value = std::stoi(str);
    while (value > 0) {
        ret.insert(0, 1, (value % 2) + 48);
        value /= 2;
    }
    return ret; 
}

TEST(Test, ShoudlConvertBinaryToDec) {
    EXPECT_EQ("0", binaryToDec("0"));
    EXPECT_EQ("1", binaryToDec("1"));
    EXPECT_EQ("3", binaryToDec("11"));
    EXPECT_EQ("2", binaryToDec("10"));
    EXPECT_EQ("2020", binaryToDec("11111100100"));
}

TEST(Test, ShoudlConvertDecToBinary) {
    EXPECT_EQ("0", DecToBinary("0"));
    EXPECT_EQ("1", DecToBinary("1"));
    EXPECT_EQ("11", DecToBinary("3"));
    EXPECT_EQ("10", DecToBinary("2"));
    EXPECT_EQ("11111100100", DecToBinary("2020"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <array>
#include <utility>

#include "gtest/gtest.h"
#include "zadanie13.cc"

class Zadanie13 :public ::testing::TestWithParam<std::pair<std::array<int, 20>, bool>> {
};

TEST_P(Zadanie13, ShouldChechisPrime) {
  for (const int num : GetParam().first)
    EXPECT_EQ(isPrime(num), GetParam().second);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie13Test,
  Zadanie13,
  ::testing::Values(
    std::make_pair(std::array<int, 20>{4, 6, 8, 10, 12, 14, 144, 148, 125, 100, 225, 81, 1270, 432, 111, 16, 18, 20, 21, 50}, false),
    std::make_pair(std::array<int, 20>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461}, true)
  )
);

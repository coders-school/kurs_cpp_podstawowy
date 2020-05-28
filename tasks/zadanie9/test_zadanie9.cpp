#include <vector>

#include "gtest/gtest.h"
#include "zadanie9.cc"

struct Params {
  std::vector<int> input;
  std::vector<int> expected_result;
};

class Zadanie9 :public ::testing::TestWithParam<Params> {
};

TEST_P(Zadanie9, ShouldMultiplyOddNumbers) {
  const Params& test_data = GetParam();
  EXPECT_EQ(multiplyOddNumbers(test_data.input), 
            test_data.expected_result);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie9Test,
  Zadanie9,
  ::testing::Values(
    Params{std::vector<int>{2,4,6,8,10}, std::vector<int>{2,4,6,8,10}},
    Params{std::vector<int>{1,2,3,4,5}, std::vector<int>{1,2,9,4,25}},
    Params{std::vector<int>{1,0,1,3}, std::vector<int>{1,0,1,9}},
    Params{std::vector<int>{2,2,2,4}, std::vector<int>{2,2,2,4}},
    Params{std::vector<int>{3,7,9}, std::vector<int>{9,49,81}}
  )
);

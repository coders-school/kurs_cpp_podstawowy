#include <vector>

#include "gtest/gtest.h"
#include "zadanie8.cc"

struct Paramss {
  int count;
  int sequence;
  std::vector<int> expected_result;
};

class Zadanie8 : public ::testing::TestWithParam<Paramss> {
};

TEST_P(Zadanie8, ShouldCreateVector) {
  const Paramss& test_data = GetParam();
  EXPECT_EQ(foo(test_data.count, test_data.sequence), test_data.expected_result);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie8Test,
  Zadanie8,
  ::testing::Values(
    Paramss{10, 5, std::vector<int>{5,10,15,20,25,30,35,40,45,50}},
    Paramss{0, 0, std::vector<int>{}},
    Paramss{5, 2, std::vector<int>{2,4,6,8,10}},
    Paramss{8, 5, std::vector<int>{5,10,15,20,25,30,35,40}},
    Paramss{3, -4, std::vector<int>{-4,-8,-12}}
  )
);

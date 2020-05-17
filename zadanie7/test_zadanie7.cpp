#include <array>
#include <vector>

#include "gtest/gtest.h"
#include "zadanie7.cc"

class Zadanie7 :public ::testing::TestWithParam<std::tuple<std::array<int, 9>, int>> {
};

TEST_P(Zadanie7, ShouldFindMax) {
  auto vec = std::get<0>(GetParam());
  auto expected_result = std::get<1>(GetParam());
  EXPECT_EQ(max(std::vector<int>(vec.begin(), vec.end())), expected_result);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie7Test,
  Zadanie7,
  ::testing::Values(
    std::make_tuple(std::array<int, 9>{4,3,2,5,6,7,9,1,0}, 9),
    std::make_tuple(std::array<int, 9>{0,0,0,-1,0,0,0,0,0}, 0),
    std::make_tuple(std::array<int, 9>{1,1,1,1,1,2,1,1,1}, 2),
    std::make_tuple(std::array<int, 9>{-1,-1,-1,-1,-2,-1,0,-1,-2}, 0),
    std::make_tuple(std::array<int, 9>{22, 88, 10, 0, 5, 6, 7, 8, 9}, 88),
    std::make_tuple(std::array<int, 9>{-1,0,1,-2,-4,-6,-7,-8,-8}, 1)
  )
);

#include <array>
#include <vector>

#include "gtest/gtest.h"
#include "zadanie4.cc"

class Zadanie4 :public ::testing::TestWithParam<std::tuple<std::array<int, 5>, int>> {
};

TEST_P(Zadanie4, ShouldAddEvenNumbers) {
  std::array<int, 5> vec = std::get<0>(GetParam());
  int expected_result = std::get<1>(GetParam());
  EXPECT_EQ(AddEvenNumbers(std::vector<int>(vec.begin(), vec.end())), expected_result);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie4Test,
  Zadanie4,
  ::testing::Values(
    std::make_tuple(std::array<int, 5>{1, 2, 3, 4, 5}, 6),
    std::make_tuple(std::array<int, 5>{2, 4, 6, 8, 10}, 30),
    std::make_tuple(std::array<int, 5>{1, 1, 1, 1, 1}, 0),
    std::make_tuple(std::array<int, 5>{0, 0, 0, 0, 0}, 0),
    std::make_tuple(std::array<int, 5>{21, 20, 18, 16, 19}, 54)
  )
);

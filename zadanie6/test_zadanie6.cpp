#include <vector>

#include "gtest/gtest.h"
#include "zadanie6.cc"

class Zadanie6 :public ::testing::TestWithParam<std::tuple<int, int, int>> {
};

TEST_P(Zadanie6, ShouldCalculateNWD) {
  int first = std::get<0>(GetParam());
  int second = std::get<1>(GetParam());
  int expected_result = std::get<2>(GetParam());
  EXPECT_EQ(NWD(first, second), expected_result);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie6Test,
  Zadanie6,
  ::testing::Values(
    std::make_tuple(44, 123, 1),
    std::make_tuple(891, 33, 33),
    std::make_tuple(0, 0, 0),
    std::make_tuple(1, 0, 1),
    std::make_tuple(23122, 322, 2),
    std::make_tuple(4345, 25, 5),
    std::make_tuple(65464, 344324, 4)
  )
);

class Zadanie6_v2 :public ::testing::TestWithParam<std::tuple<int, int, int>> {
};

TEST_P(Zadanie6_v2, ShouldCalculateNWW) {
  int first = std::get<0>(GetParam());
  int second = std::get<1>(GetParam());
  int expected_result = std::get<2>(GetParam());
  EXPECT_EQ(NWW(first, second), expected_result);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie6Test_v2,
  Zadanie6_v2,
  ::testing::Values(
    std::make_tuple(24, 36, 72),
    std::make_tuple(50, 17, 850),
    std::make_tuple(50, 30, 150),
    std::make_tuple(1, 1, 1),
    std::make_tuple(23122, 322, 3722642),
    std::make_tuple(28, 14, 28),
    std::make_tuple(105, 25, 525)
  )
);
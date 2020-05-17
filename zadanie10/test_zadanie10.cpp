#include <utility>
#include <string>

#include "gtest/gtest.h"
#include "zadanie10.cc"

class Zadanie10 :public ::testing::TestWithParam<std::pair<std::string, size_t>> {
};

TEST_P(Zadanie10, ShouldCountVovel) {
  EXPECT_EQ(CountVovel(GetParam().first), GetParam().second);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie10Test,
  Zadanie10,
  ::testing::Values(
    std::make_pair("ala ma kota a kot ma ale", 10),
    std::make_pair("zcb nm klj hgfd srp", 0),
    std::make_pair("aeiouy", 6),
    std::make_pair("bbbaccccedddddifffffo ggu  hhhy", 6),
    std::make_pair("zzzzzzzzzzzzzzzzzzzzzzzzzzz", 0),
    std::make_pair("a a a a a a a a a a a", 11),
    std::make_pair("x y z x y z x y z", 3)
  )
);

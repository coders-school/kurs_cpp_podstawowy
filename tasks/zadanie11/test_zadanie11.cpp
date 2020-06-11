#include <utility>
#include <string>

#include "gtest/gtest.h"
#include "zadanie11.cc"

class Zadanie11 :public ::testing::TestWithParam<std::pair<std::string, std::string>> {
};

TEST_P(Zadanie11, ShouldRemoveVovel) {
  EXPECT_EQ(RemoveVovel(GetParam().first), GetParam().second);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie11Test,
  Zadanie11,
  ::testing::Values(
    std::make_pair("ala ma kota a kot ma ale", "l m kt  kt m l"),
    std::make_pair("zcb nm klj hgfd srp", "zcb nm klj hgfd srp"),
    std::make_pair("aeiouy", ""),
    std::make_pair("bbbaccccedddddifffffo ggu  hhhy", "bbbccccdddddfffff gg  hhh"),
    std::make_pair("zzzzzzzzzzzzzzzzzzzzzzzzzzz", "zzzzzzzzzzzzzzzzzzzzzzzzzzz"),
    std::make_pair("a a a a a a a a a a a", "          "),
    std::make_pair("x y z x y z x y z", "x  z x  z x  z")
  )
);

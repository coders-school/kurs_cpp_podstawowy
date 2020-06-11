#include <utility>
#include <string>

#include "gtest/gtest.h"
#include "zadanie12.cc"

class Zadanie12 :public ::testing::TestWithParam<std::pair<std::string, std::string>> {
};

TEST_P(Zadanie12, ShouldFormatString) {
  EXPECT_EQ(FormatString(GetParam().first), GetParam().second);
}

INSTANTIATE_TEST_CASE_P(
  Zadanie12Test,
  Zadanie12,
  ::testing::Values(
    std::make_pair("ala ma kota a kot ma ale", "alamakotaakotmaale"),
    std::make_pair("AlA ma \tKotA \na KoT \nma aLe", "alamakotaakotmaale"),
    std::make_pair("aeiouy", "aeiouy"),
    std::make_pair("bbbaccccedddddifffffo ggu  hhhy", "bbbaccccedddddifffffogguhhhy"),
    std::make_pair("zzzz\nzz\tzz\nzz\tzz\nzzz\tzz\nzz\tzzz\nzzz\tzz", "zzzzzzzzzzzzzzzzzzzzzzzzzzz"),
    std::make_pair("A a A a A a A a A a a", "aaaaaaaaaaa"),
    std::make_pair("x\ty\nz X\ty Z\nX y\tz", "xyzxyzxyz")
  )
);

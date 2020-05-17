#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "MockClasses.h"
#include "Player.h"
#include "Test_values.h"
#include "TimeServiceLocator.h"

template <typename FUN>
void NextDays(size_t days, FUN fun) {
    for (size_t i = 0 ; i < days ; ++i) {
        fun();
    }
}

TEST(PlayerTest, ShouldPayCrewEveryDay) {
    auto timeMock_ = std::make_unique<TimeMock>();
    TimeServiceLocator::Provide(timeMock_.get());
    auto player = std::make_unique<Player>(kPlayerMoney);
    EXPECT_EQ(player->GetMoney(), kPlayerMoney);
    NextDays(10, [&player](){ player->PayCrew(kCrew); });
    EXPECT_EQ(player->GetMoney(), kPlayerMoney - (kCrew * 10));
}

TEST(PlayerTest, ShouldBankruptWhenCantPayCrew) {
    auto timeMock_ = std::make_unique<TimeMock>();
    TimeServiceLocator::Provide(timeMock_.get());
    auto player = std::make_unique<Player>(kPlayerMoney);
    EXPECT_EQ(player->GetMoney(), kPlayerMoney);
    NextDays(26, [&player](){ player->PayCrew(kCrew); });
    EXPECT_EQ(player->GetMoney(), SIZE_MAX);
}
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "Fruit.h"
#include "MockClasses.h"
#include "Player.h"
#include "Test_values.h"

template <typename FUN>
void NextDays(size_t days, FUN fun) {
    for (size_t i = 0 ; i < days ; ++i) {
        fun();
    }
}

TEST(CargoTest, ShouldChangePriceWhenProductSpoil) {
    auto timeMock = std::make_unique<TimeMock>();
    auto fruit = std::make_unique<Fruit>(kFruitAmount, 
            kFruitName, kFruitBasePrice, kFruitExpiryTime,
            kFruitTimeElapsed, timeMock.get());
    EXPECT_EQ(fruit->GetPrice(), 50);
    NextDays(8, [&fruit](){ fruit->NextDay(); });
    EXPECT_EQ(fruit->GetPrice(), 10);
    NextDays(2, [&fruit](){ fruit->NextDay(); });
    EXPECT_EQ(fruit->GetPrice(), 0);
}

TEST(PlayerTest, ShouldPayCrewEveryDay) {
    auto timeMock = std::make_unique<TimeMock>();
    auto player = std::make_unique<Player>(
        kPlayerMoney, timeMock.get());
    EXPECT_EQ(player->GetMoney(), kPlayerMoney);
    NextDays(10, [&player](){ player->PayCrew(50); });
    EXPECT_EQ(player->GetMoney(), kPlayerMoney - (50 * 10));
}

TEST(PlayerTest, ShouldBankruptWhenCantPayCrew) {
    auto timeMock = std::make_unique<TimeMock>();
    auto player = std::make_unique<Player>(
        kPlayerMoney, timeMock.get());
    EXPECT_EQ(player->GetMoney(), kPlayerMoney);
    NextDays(21, [&player](){ player->PayCrew(50); });
    EXPECT_EQ(player->GetMoney(), SIZE_MAX);
}
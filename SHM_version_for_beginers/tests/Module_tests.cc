#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "Alcohol.h"
#include "Fruit.h"
#include "GTime.h"
#include "Island.h"
#include "Item.h"
#include "MockClasses.h"
#include "Player.h"
#include "Store.h"
#include "Test_values.h"

using testing::_;
using testing::AtLeast;
using testing::AtMost;
using testing::MockFunction;
using testing::Return;

constexpr size_t kX1 = 0;
constexpr size_t kY1 = 10;
constexpr size_t kX2 = 10;
constexpr size_t kY2 = 20;
constexpr size_t kX3 = 40;
constexpr size_t kY3 = 50;
 
class GameTests : public testing::Test {
public:
    void SetUp() override {
        time_ = std::make_unique<Time>();
        player_ = std::make_unique<Player>(kPlayerMoney, time_.get());
    }

    std::vector<Island> PrepareMapForTest() {
        std::vector<Island> vec;
        vec.reserve(3);
        vec.push_back(Island(kX1, kY1, time_.get()));
        vec.push_back(Island(kX2, kY2, time_.get()));
        vec.push_back(Island(kX3, kY3, time_.get()));
        return vec;
    }

    std::vector<std::unique_ptr<Cargo>> prepareCargoForTest() {
        std::vector<std::unique_ptr<Cargo>> cargo;
        cargo.push_back(std::make_unique<Alcohol>(kAlcoholAmount, 
            kAlcoholName, kAlcoholBasePrice, kAlcoholPercentage));
        cargo.push_back(std::make_unique<FruitMock>(kFruitAmount, 
            kFruitName, kFruitBasePrice, kFruitExpiryTime,
            kFruitTimeElapsed, time_.get()));
        cargo.push_back(std::make_unique<Item>(kItemAmount, 
            kItemlName, kItemBasePrice, Item::Rarity::legendary));
        return cargo;
    }

    std::unique_ptr<Time> time_;
    std::unique_ptr<Player> player_;
};

TEST_F(GameTests, PlayerShouldPayCrewWhileTravel) {
    EXPECT_EQ(player_->GetMoney(), kPlayerMoney);
    ++*time_;
    EXPECT_EQ(player_->GetMoney(), kPlayerMoney - kCrew);
}

TEST_F(GameTests, ObserversShouldBeNotified) {
    auto fruit = std::make_unique<FruitMock>(kFruitAmount, 
        kFruitName, kFruitBasePrice, kFruitExpiryTime,
        kFruitTimeElapsed, time_.get());
    auto* fruit_ptr = fruit.get();
    EXPECT_CALL(*fruit_ptr, GetAmount());
    player_->PurchaseCargo(std::move(fruit), 200);
    ASSERT_EQ(player_->GetCargo(0), fruit_ptr);

    auto islands = PrepareMapForTest();
    auto cargo1 = prepareCargoForTest();
    auto cargo2 = prepareCargoForTest();
    auto cargo3 = prepareCargoForTest();
    auto* fruit_ptr1 = static_cast<FruitMock*>(cargo1[1].get());
    auto* fruit_ptr2 = static_cast<FruitMock*>(cargo2[1].get());
    auto* fruit_ptr3 = static_cast<FruitMock*>(cargo3[1].get());
    islands[0].GetStore()->SetCargo(std::move(cargo1));
    islands[1].GetStore()->SetCargo(std::move(cargo2));
    islands[2].GetStore()->SetCargo(std::move(cargo3));

    EXPECT_CALL(*fruit_ptr, NextDay());
    EXPECT_CALL(*fruit_ptr1, NextDay());
    EXPECT_CALL(*fruit_ptr2, NextDay());
    EXPECT_CALL(*fruit_ptr3, NextDay());
    ++*time_;
}

TEST_F(GameTests, ShouldStopNotifyRemovedObsers) {
    auto fruit = std::make_unique<FruitMock>(kFruitAmount, 
        kFruitName, kFruitBasePrice, kFruitExpiryTime,
        kFruitTimeElapsed, time_.get());
    auto* fruit_ptr = fruit.get();
    EXPECT_CALL(*fruit_ptr, GetAmount());
    player_->PurchaseCargo(std::move(fruit), 200);
    ASSERT_EQ(player_->GetCargo(0), fruit_ptr);
    
    auto islands = PrepareMapForTest();
    auto cargo1 = prepareCargoForTest();
    auto cargo2 = prepareCargoForTest();
    auto cargo3 = prepareCargoForTest();
    auto* fruit_ptr1 = static_cast<FruitMock*>(cargo1[1].get());
    auto* fruit_ptr2 = static_cast<FruitMock*>(cargo2[1].get());
    auto* fruit_ptr3 = static_cast<FruitMock*>(cargo3[1].get());
    islands[0].GetStore()->SetCargo(std::move(cargo1));
    islands[1].GetStore()->SetCargo(std::move(cargo2));
    islands[2].GetStore()->SetCargo(std::move(cargo3));

    EXPECT_CALL(*fruit_ptr, NextDay());
    EXPECT_CALL(*fruit_ptr1, NextDay());
    EXPECT_CALL(*fruit_ptr2, NextDay());
    EXPECT_CALL(*fruit_ptr3, NextDay());
    ++*time_;

    time_->RemoveObserver(fruit_ptr1);
    time_->RemoveObserver(fruit_ptr2);
    time_->RemoveObserver(fruit_ptr3);
    EXPECT_CALL(*fruit_ptr, NextDay());
    EXPECT_CALL(*fruit_ptr1, NextDay()).Times(0);
    EXPECT_CALL(*fruit_ptr2, NextDay()).Times(0);
    EXPECT_CALL(*fruit_ptr3, NextDay()).Times(0);
    ++*time_;
}

TEST_F(GameTests, ShouldCallNextDayWhenTimeIncrement) {
    auto fruit = std::make_unique<FruitMock>(kFruitAmount, 
        kFruitName, kFruitBasePrice, kFruitExpiryTime,
        kFruitTimeElapsed, time_.get());
    auto* fruit_ptr = fruit.get();
    EXPECT_CALL(*fruit_ptr, GetAmount());
    player_->PurchaseCargo(std::move(fruit), 200);
    ASSERT_EQ(player_->GetCargo(0), fruit_ptr);

    EXPECT_CALL(*fruit_ptr, NextDay());
    ++*time_;
}

TEST_F(GameTests, ShouldReturnDistanceBeetweenIsland) {
    auto islands = PrepareMapForTest();
    auto* first_island = &islands[0];
    auto* second_island = &islands[1];
    auto map = std::make_unique<Map>(time_.get());
    map->SetIslandForTesting(std::move(islands));
    map->Travel(first_island);
    ASSERT_EQ(map->GetCurrentPosition(), first_island);
    ASSERT_EQ(map->GetDistanceToIsland(second_island), 14);
}
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "GTime.h"
#include "Island.h"
#include "MockClasses.h"
#include "Player.h"
#include "Store.h"
#include "Test_values.h"
#include "TimeServiceLocator.h"

using testing::_;
using testing::MockFunction;

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
        TimeServiceLocator::Provide(time_.get());
        player_ = std::make_unique<Player>(kPlayerMoney);
    }

    std::vector<Island> PrepareMapForTest() {
        std::vector<Island> vec;
        vec.reserve(3);
        vec.push_back(Island(kX1, kY1));
        vec.push_back(Island(kX2, kY2));
        vec.push_back(Island(kX3, kY3));
        return vec;
    }

    std::unique_ptr<Time> time_;
    std::unique_ptr<Player> player_;
};

TEST_F(GameTests, PlayerShouldPayCrewWhileTravel) {
    EXPECT_EQ(player_->GetMoney(), kPlayerMoney);
    ++*time_;
    EXPECT_EQ(player_->GetMoney(), kPlayerMoney - kCrew);
}

TEST_F(GameTests, ShouldLoadCargoToAnotherShipWhenPreviousIsFull) {
    auto ship = std::make_unique<Ship>(
        kCapacity, kCrew, kSpeed, kId + 1, kShipPrice, kName, nullptr);
    auto ship2 = std::make_unique<Ship>(
        kCapacity, kCrew, kSpeed, kId + 2, kShipPrice, kName, nullptr);
    auto ship_ptr = ship.get();
    auto ship_ptr2 = ship2.get();
    player_->BuyShip(std::move(ship), 0);
    player_->BuyShip(std::move(ship2), 0);

    auto cargo = std::make_unique<Cargo>(kJewelleryName, kJewelleryAmount);
    player_->PurchaseCargo(cargo.get(), 0, 300);

    ASSERT_EQ(ship_ptr->GetCargo(kJewelleryName), cargo.get());
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 0);
    ASSERT_EQ(ship_ptr2->GetCargo(kJewelleryName), cargo.get());
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 0);
}  

TEST_F(GameTests, ShouldReturnDistanceBeetweenIsland) {
    auto islands = PrepareMapForTest();
    auto* first_island = &islands[0];
    auto* second_island = &islands[1];
    auto map = std::make_unique<Map>();
    map->SetIslandForTesting(std::move(islands));
    map->Travel(first_island);
    ASSERT_EQ(map->GetCurrentPosition(), first_island);
    ASSERT_EQ(map->GetDistanceToIsland(second_island), 14);
}
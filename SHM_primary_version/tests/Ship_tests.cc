#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "Cargo.h"
#include "GTime.h"
#include "MockClasses.h"
#include "Ship.h"
#include "Test_values.h"
#include "TimeServiceLocator.h"

class ShipTest : public testing::Test {
public:
    void SetUp() override {
        time_ = std::make_unique<Time>();
        TimeServiceLocator::Provide(time_.get());
        player_ = std::make_unique<Player>(kPlayerMoney);
    }

    std::unique_ptr<Time> time_;
    std::unique_ptr<Player> player_;
};

TEST_F(ShipTest, ShouldRemoveCargoWhenAmountIsZero) {
    auto ship = std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kId, kShipPrice, kName, nullptr);
    auto item = std::make_unique<Cargo>(kItemName, kItemBasePrice);
    ship->Load(item.get(), kItemAmount);
    ASSERT_EQ(ship->GetCargo(kItemName), item.get());

    ASSERT_EQ(ship->TryUnload(item.get(), kItemAmount), kItemAmount);
    ASSERT_EQ(ship->GetCargo(kItemName), nullptr);
}

TEST_F(ShipTest, ShouldAccumulateCargoWhenTheSame) {
    auto ship = std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kId, kShipPrice, kName, nullptr);
    auto item = std::make_unique<Cargo>(kItemName, kItemBasePrice);
    ship->Load(item.get(), kItemAmount);
    ASSERT_EQ(ship->GetCargo(kItemName), item.get());
    ASSERT_EQ(ship->GetAvailableCapacity(), kItemAmount);

    ship->Load(item.get(), kItemAmount);
    ASSERT_EQ(ship->GetCargo(kItemName), item.get());
    ASSERT_EQ(ship->GetAvailableCapacity(), 0);
}

TEST_F(ShipTest, ShouldLoadAndUnloadDiffrentCargo) {
    const size_t ship_capacity = (3 * kCapacity);
    auto ship = std::make_unique<Ship>(
		ship_capacity, kCrew, kSpeed, kId, kShipPrice, kName, nullptr);

    // Load
    auto item = std::make_unique<Cargo>(kItemName, kItemBasePrice);
    ship->Load(item.get(), kItemAmount);
    ASSERT_EQ(ship->GetCargo(kItemName), item.get());
    ASSERT_EQ(ship->GetAvailableCapacity(), ship_capacity - kItemAmount);

    auto alcohol = std::make_unique<Cargo>(kAlcoholName, kAlcoholBasePrice);
    ship->Load(alcohol.get(), kAlcoholAmount);
    ASSERT_EQ(ship->GetCargo(kAlcoholName), alcohol.get());
    ASSERT_EQ(ship->GetAvailableCapacity(), ship_capacity - (kItemAmount + kAlcoholAmount));

    auto fruit = std::make_unique<Cargo>(kFruitName, kFruitBasePrice);
    ship->Load(fruit.get(), kFruitAmount);
    ASSERT_EQ(ship->GetCargo(kFruitName), fruit.get());
    ASSERT_EQ(ship->GetAvailableCapacity(), 
        ship_capacity - (kItemAmount + kAlcoholAmount + kFruitAmount));

    // UNLOAD
    ASSERT_EQ(ship->TryUnload(item.get(), kItemAmount), kItemAmount);
    ASSERT_EQ(ship->GetAvailableCapacity(), ship_capacity - (kAlcoholAmount + kFruitAmount));
    ASSERT_EQ(ship->TryUnload(alcohol.get(), kAlcoholAmount), kAlcoholAmount);
    ASSERT_EQ(ship->GetAvailableCapacity(), ship_capacity - kFruitAmount);
    ASSERT_EQ(ship->TryUnload(fruit.get(), kFruitAmount), kFruitAmount);
    
    // SHIP SHOULD BE EMPTY
    ASSERT_EQ(ship->GetAvailableCapacity(), ship_capacity);
}

TEST_F(ShipTest, ShouldLoadCargoToAnotherShipWhenPreviousIsFull) {
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

TEST_F(ShipTest, ShouldRemoveCargoFromFewShips) {
    auto ship = std::make_unique<Ship>(
        kCapacity, kCrew, kSpeed, kId + 1, kShipPrice, kName, nullptr);
    auto ship2 = std::make_unique<Ship>(
        kCapacity, kCrew, kSpeed, kId + 2, kShipPrice, kName, nullptr);
    auto ship_ptr = ship.get();
    auto ship_ptr2 = ship2.get();
    player_->BuyShip(std::move(ship), 0);
    player_->BuyShip(std::move(ship2), 0);
    EXPECT_EQ(player_->GetAvailableSpace(), 3 * kCapacity);

    auto cargo = std::make_unique<Cargo>(kJewelleryName, kJewelleryAmount);
    player_->PurchaseCargo(cargo.get(), 0, 300);
    EXPECT_EQ(player_->GetAvailableSpace(), 0);
    player_->SellCargo(cargo.get(), 0, 250);
    EXPECT_EQ(player_->GetAvailableSpace(), 250);

    ASSERT_EQ(ship_ptr->GetCargo(kJewelleryName), nullptr);
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), kCapacity);
    ASSERT_EQ(ship_ptr2->GetCargo(kJewelleryName), cargo.get());
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 50);
} 

TEST_F(ShipTest, ShouldLoadAndUnloadDiffrentCargoOnFewShip) {
    auto shippp = player_->GetShip(14);
    player_->SellShip(shippp, 0);
    auto ship = std::make_unique<Ship>(
        kCapacity, kCrew, kSpeed, kId + 1, kShipPrice, kName, nullptr);
    auto ship2 = std::make_unique<Ship>(
        kCapacity, kCrew, kSpeed, kId + 2, kShipPrice, kName, nullptr);
    auto ship_ptr = ship.get();
    auto ship_ptr2 = ship2.get();
    player_->BuyShip(std::move(ship), 0);
    player_->BuyShip(std::move(ship2), 0);
    EXPECT_EQ(player_->GetAvailableSpace(), 2 * kCapacity);

    // Load
    auto item = std::make_unique<Cargo>(kItemName, kItemBasePrice);
    player_->PurchaseCargo(item.get(), 0, kItemAmount);
    ASSERT_EQ(ship_ptr->GetCargo(kItemName), item.get());
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), kCapacity - kItemAmount);
    ASSERT_EQ(ship_ptr2->GetCargo(kItemName), nullptr);
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 100);

    auto alcohol = std::make_unique<Cargo>(kAlcoholName, kAlcoholBasePrice);
    player_->PurchaseCargo(alcohol.get(), 0, kAlcoholAmount);
    ASSERT_EQ(ship_ptr->GetCargo(kAlcoholName), alcohol.get());
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 0);
    ASSERT_EQ(ship_ptr2->GetCargo(kAlcoholName), alcohol.get());
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 50);

    auto fruit = std::make_unique<Cargo>(kFruitName, kFruitBasePrice);
    player_->PurchaseCargo(fruit.get(), 0, 50);
    ASSERT_EQ(ship_ptr->GetCargo(kFruitName), nullptr);
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 0);
    ASSERT_EQ(ship_ptr2->GetCargo(kFruitName), fruit.get());
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 0);

    // UNLOAD
    player_->SellCargo(item.get(), 0, 50);
    ASSERT_EQ(ship_ptr->GetCargo(kItemName), nullptr);
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 50);
    ASSERT_EQ(ship_ptr2->GetCargo(kItemName), nullptr);
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 0);

    player_->SellCargo(alcohol.get(), 0, 50);
    ASSERT_EQ(ship_ptr->GetCargo(kAlcoholName), nullptr);
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 100);
    ASSERT_EQ(ship_ptr2->GetCargo(kAlcoholName), alcohol.get());
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 0);
    
    player_->SellCargo(fruit.get(), 0, 50);
    ASSERT_EQ(ship_ptr->GetCargo(kFruitName), nullptr);
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 100);
    ASSERT_EQ(ship_ptr2->GetCargo(kFruitName), nullptr);
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 50);

    player_->SellCargo(alcohol.get(), 0, 50);
    ASSERT_EQ(ship_ptr->GetCargo(kAlcoholName), nullptr);
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 100);
    ASSERT_EQ(ship_ptr2->GetCargo(kAlcoholName), nullptr);
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 100);

    // SHIP SHOULD BE EMPTY
    ASSERT_EQ(player_->GetAvailableSpace(), 2 * kCapacity);
}

TEST_F(ShipTest, ShouldReplaceRemovedCargoWithNewestCargo) {
    player_->SellShip(player_->GetShip(15), 0);
    auto ship = std::make_unique<Ship>(
        kCapacity, kCrew, kSpeed, kId + 1, kShipPrice, kName, nullptr);
    auto ship2 = std::make_unique<Ship>(
        kCapacity, kCrew, kSpeed, kId + 2, kShipPrice, kName, nullptr);
    auto ship_ptr = ship.get();
    auto ship_ptr2 = ship2.get();
    player_->BuyShip(std::move(ship), 0);
    player_->BuyShip(std::move(ship2), 0);
    EXPECT_EQ(player_->GetAvailableSpace(), 2 * kCapacity);

    auto alcohol = std::make_unique<Cargo>(kAlcoholName, kAlcoholBasePrice);
    player_->PurchaseCargo(alcohol.get(), 0, 150);
    ASSERT_EQ(ship_ptr->GetCargo(kAlcoholName), alcohol.get());
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 0);
    ASSERT_EQ(ship_ptr2->GetCargo(kAlcoholName), alcohol.get());
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 50);

    player_->SellCargo(alcohol.get(), 0, 50);
    ASSERT_EQ(ship_ptr->GetCargo(kAlcoholName), alcohol.get());
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 50);
    ASSERT_EQ(ship_ptr2->GetCargo(kAlcoholName), alcohol.get());
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 50);

    auto item = std::make_unique<Cargo>(kItemName, kItemBasePrice);
    player_->PurchaseCargo(item.get(), 0, kItemAmount);
    ASSERT_EQ(ship_ptr->GetCargo(kItemName), item.get());
    ASSERT_EQ(ship_ptr->GetAvailableCapacity(), 0);
    ASSERT_EQ(ship_ptr2->GetCargo(kItemName), nullptr);
    ASSERT_EQ(ship_ptr2->GetAvailableCapacity(), 50);
}
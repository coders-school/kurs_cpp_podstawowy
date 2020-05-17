#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "Alcohol.h"
#include "Fruit.h"
#include "GTime.h"
#include "Item.h"
#include "MockClasses.h"
#include "Ship.h"
#include "Test_values.h"
#include "TimeServiceLocator.h"

TEST(ShipTest, ShouldRemoveCargoWhenAmountIsZero) {
    auto timeMock_ = std::make_unique<TimeMock>();
    TimeServiceLocator::Provide(timeMock_.get());
    auto ship = std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kName, kId, nullptr);
    auto item = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice, Item::Rarity::legendary);
    auto* item_ptr = item.get();
    ship->Load(std::move(item));
    ASSERT_EQ(ship->GetCargo(0), item_ptr);

    *item_ptr -= kItemAmount;
    ship->Unload(item_ptr);
    ASSERT_EQ(ship->GetCargo(0), nullptr);
}

TEST(ShipTest, ShouldAccumulateCargoWhenTheSame) {
    auto timeMock_ = std::make_unique<TimeMock>();
    TimeServiceLocator::Provide(timeMock_.get());
    auto ship = std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kName, kId, nullptr);
    auto item = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice, Item::Rarity::legendary);
    auto* item_ptr = item.get();
    ship->Load(std::move(item));
    ASSERT_EQ(ship->GetCargo(0), item_ptr);

    auto item2 = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice, Item::Rarity::legendary);
    auto* item_ptr2 = item2.get();
    ship->Load(std::move(item2));
    ASSERT_EQ(ship->GetCargo(0), item_ptr);
    ASSERT_EQ(ship->GetCargo(1), nullptr);
}

TEST(ShipTest, ShouldLoadAndUnloadDiffrentCargo) {
    auto timeMock_ = std::make_unique<TimeMock>();
    TimeServiceLocator::Provide(timeMock_.get());
    auto ship = std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kName, kId, nullptr);
    
    // LOAD
    auto item = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice, Item::Rarity::legendary);
    auto* item_ptr = item.get();
    ship->Load(std::move(item));
    ASSERT_EQ(ship->GetCargo(0), item_ptr);
    auto alcohol = std::make_unique<Alcohol>(kAlcoholAmount, 
            kAlcoholName, kAlcoholBasePrice, kAlcoholPercentage);
    auto* alcohol_ptr = alcohol.get();
    ship->Load(std::move(alcohol));
    ASSERT_EQ(ship->GetCargo(1), alcohol_ptr);
    auto fruit = std::make_unique<Fruit>(kFruitAmount, 
            kFruitName, kFruitBasePrice, kFruitExpiryTime,
            kFruitTimeElapsed);
    auto* fruit_ptr = fruit.get();
    ship->Load(std::move(fruit));
    ASSERT_EQ(ship->GetCargo(2), fruit_ptr);

    // UNLOAD
    *item_ptr -= kItemAmount;
    *alcohol_ptr -= kAlcoholAmount;
    ship->Unload(item_ptr);
    ship->Unload(alcohol_ptr);
    ship->Unload(fruit_ptr);
    
    // STOCK SHOULD BE EMPTY
    ASSERT_EQ(ship->GetCargo(0), nullptr);
}

TEST(ShipTest, ShouldAddAnotherCargoWhenDiffrent) {
    auto timeMock_ = std::make_unique<TimeMock>();
    TimeServiceLocator::Provide(timeMock_.get());
    auto ship = std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kName, kId, nullptr);
    auto item = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice, Item::Rarity::legendary);
    auto* item_ptr = item.get();
    ship->Load(std::move(item));
    ASSERT_EQ(ship->GetCargo(0), item_ptr);

    // Diffrent rarity
    auto item2 = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice, Item::Rarity::epic);
    auto* item_ptr2 = item2.get();
    ship->Load(std::move(item2));
    ASSERT_EQ(ship->GetCargo(1), item_ptr2);

    // Diffrent base price
    auto item3 = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice + 2, Item::Rarity::epic);
    auto* item_ptr3 = item3.get();
    ship->Load(std::move(item3));
    ASSERT_EQ(ship->GetCargo(2), item_ptr3);
}
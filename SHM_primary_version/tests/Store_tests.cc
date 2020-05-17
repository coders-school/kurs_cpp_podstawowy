#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "Cargo.h"
#include "CargoTypes.h"
#include "CargoTypeServiceLocator.h"
#include "GTime.h"
#include "MockClasses.h"
#include "Player.h"
#include "Store.h"
#include "Test_values.h"
#include "TimeServiceLocator.h"

using testing::_;
using testing::MockFunction;

class TestSuit : public testing::Test {
public:
    TestSuit():
            timeMock_(std::make_unique<TimeMock>()),
            cargoTypes_(std::make_unique<CargoTypes>()) {
        TimeServiceLocator::Provide(timeMock_.get());
        CargoTypeServiceLocator::Provide(cargoTypes_.get());
        EXPECT_CALL(*timeMock_, AddObserver(_)).Times(1);
        playerMock_ = std::make_unique<PlayerMock>(kPlayerMoney);
        EXPECT_CALL(*timeMock_, AddObserver(_)).Times(1);
        store_ = std::make_unique<Store>();
    }

    void TearDown() override {
        // Check if Player and Store unregister thier observer
        EXPECT_CALL(*timeMock_, RemoveObserver(_)).Times(2);
    }

    std::unique_ptr<TimeMock> timeMock_;
    std::unique_ptr<CargoTypes> cargoTypes_;
    std::unique_ptr<PlayerMock> playerMock_;
    std::unique_ptr<Store> store_;
};

TEST_F(TestSuit, StoreShouldRecalculatePrice) {
    const auto* cargo = store_->GetCargo(kFruitName);

    // Min cargo
    EXPECT_EQ(75, store_->RecalculateCargoBuyPrice({cargo, 0}));
    EXPECT_EQ(67, store_->RecalculateCargoSellPrice({cargo, 0}));

    // Medium cargo
    EXPECT_EQ(45, store_->RecalculateCargoBuyPrice({cargo, 50}));
    EXPECT_EQ(37, store_->RecalculateCargoSellPrice({cargo, 50}));

    // Max cargo
    EXPECT_EQ(15, store_->RecalculateCargoBuyPrice({cargo, 100}));
    EXPECT_EQ(7, store_->RecalculateCargoSellPrice({cargo, 100}));
}

TEST_F(TestSuit, StoreShouldRecalculatePriceDuringSelling) {
    const auto* cargo = store_->GetCargo(kAlcoholName);
    store_->SetAmountForTesting(cargo, kAlcoholAmount);
    EXPECT_EQ(60, store_->RecalculateCargoBuyPrice({cargo, kAlcoholAmount}));
    EXPECT_EQ(30, store_->RecalculateCargoSellPrice({cargo, kAlcoholAmount}));

    EXPECT_CALL(*playerMock_, GetMoney()).WillOnce(testing::Return(1000));
    EXPECT_CALL(*playerMock_, GetAvailableSpace()).WillOnce(testing::Return(100));
    EXPECT_CALL(*playerMock_, PurchaseCargo(cargo, 704, 10));
    // Buy 10 cargo
    ASSERT_EQ(store_->Buy(cargo, 10, playerMock_.get()), Store::Response::done);

    EXPECT_EQ(84, store_->RecalculateCargoBuyPrice({cargo, kAlcoholAmount - 10}));
    EXPECT_EQ(54, store_->RecalculateCargoSellPrice({cargo, kAlcoholAmount - 10}));
}

TEST_F(TestSuit, StoreShouldSellCargoCheaperThenBuying) {
    const auto* cargo = store_->GetCargo(kAlcoholName);
    store_->SetAmountForTesting(cargo, kAlcoholAmount);
    EXPECT_EQ(60, store_->RecalculateCargoBuyPrice({cargo, kAlcoholAmount}));
    EXPECT_EQ(30, store_->RecalculateCargoSellPrice({cargo, kAlcoholAmount}));

    EXPECT_CALL(*playerMock_, GetMoney()).WillOnce(testing::Return(20000));
    EXPECT_CALL(*playerMock_, GetAvailableSpace()).WillOnce(testing::Return(100));
    EXPECT_CALL(*playerMock_, PurchaseCargo(cargo, 17830, 100));
    // Buy 100 cargo
    ASSERT_EQ(store_->Buy(cargo, 100, playerMock_.get()), Store::Response::done);
    
    EXPECT_CALL(*playerMock_, SellCargo(cargo, 15070, 100));
    // Sell 100 cargo
    ASSERT_EQ(store_->Sell(cargo, 100, playerMock_.get()), Store::Response::done);
}

TEST_F(TestSuit, StoreShouldSellCargoForTheSamePriceWhenHirepurchase) {
    const auto* cargo = store_->GetCargo(kJewelleryName);
    store_->SetAmountForTesting(cargo, kJewelleryAmount);
    EXPECT_EQ(750, store_->RecalculateCargoBuyPrice({cargo, kJewelleryAmount}));
    EXPECT_EQ(625, store_->RecalculateCargoSellPrice({cargo, kJewelleryAmount}));

    size_t price1 = 0;
    EXPECT_CALL(*playerMock_, SellCargo(_, _, _))
        .WillOnce(testing::SaveArg<1>(&price1));
    ASSERT_EQ(store_->Sell(cargo, 20, playerMock_.get()), Store::Response::done);
    size_t price2 = 0;
    EXPECT_CALL(*playerMock_, SellCargo(_, _, _))
        .WillOnce(testing::SaveArg<1>(&price2));
    ASSERT_EQ(store_->Sell(cargo, 15, playerMock_.get()), Store::Response::done);
    size_t price3 = 0;
    EXPECT_CALL(*playerMock_, SellCargo(_, _, _))
        .WillOnce(testing::SaveArg<1>(&price3));
    ASSERT_EQ(store_->Sell(cargo, 8, playerMock_.get()), Store::Response::done);
    
    const size_t sold_cargo = 43;
    // Restore amount of cargo to previus value, before selling
    store_->SetAmountForTesting(cargo, kJewelleryAmount);
    EXPECT_CALL(*playerMock_, SellCargo(_,  (price1 + price2 + price3), _));
    ASSERT_EQ(store_->Sell(cargo, sold_cargo, playerMock_.get()), Store::Response::done);
}

TEST_F(TestSuit, StoreShouldNotBuyWhenNotEnoughSpaceOnShip) {
    const auto* cargo = store_->GetCargo(kJewelleryName);
    store_->SetAmountForTesting(cargo, kJewelleryAmount);
    EXPECT_CALL(*playerMock_, GetAvailableSpace()).WillOnce(testing::Return(25));
    ASSERT_EQ(store_->Buy(cargo, 30, playerMock_.get()), Store::Response::lack_of_space);
}

TEST_F(TestSuit, StoreShouldNotBuyWhenNotEnoughMoney) {
    const auto* cargo = store_->GetCargo(kJewelleryName);
    store_->SetAmountForTesting(cargo, kJewelleryAmount);
    EXPECT_CALL(*playerMock_, GetMoney()).WillOnce(testing::Return(50));
    EXPECT_CALL(*playerMock_, GetAvailableSpace()).WillOnce(testing::Return(25));
    ASSERT_EQ(store_->Buy(cargo, 10, playerMock_.get()), Store::Response::lack_of_money);
}

TEST_F(TestSuit, StoreShouldNotBuyWhenNotEnoughCargoInStore) {
    const auto* cargo = store_->GetCargo(kJewelleryName);
    store_->SetAmountForTesting(cargo, kJewelleryAmount);
    ASSERT_EQ(store_->Buy(cargo, 51, playerMock_.get()), Store::Response::lack_of_cargo);
}

TEST_F(TestSuit, StoreShouldNotSellWhenNotEnoughSpaceForCargo) {
    const auto* cargo = store_->GetCargo(kJewelleryName);
    store_->SetAmountForTesting(cargo, kJewelleryAmount);
    ASSERT_EQ(store_->Sell(cargo, 51, playerMock_.get()), Store::Response::lack_of_space);
}
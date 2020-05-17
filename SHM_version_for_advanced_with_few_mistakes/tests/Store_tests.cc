#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "Alcohol.h"
#include "Fruit.h"
#include "GTime.h"
#include "Item.h"
#include "MockClasses.h"
#include "Player.h"
#include "Store.h"
#include "Test_values.h"
#include "TimeServiceLocator.h"

using testing::_;
using testing::AtLeast;
using testing::AtMost;
using testing::MockFunction;
using testing::Return;

class TestSuit : public testing::Test {
public:
    TestSuit():
        timeMock_(std::make_unique<TimeMock>()) {

        TimeServiceLocator::Provide(timeMock_.get());
        playerMock_ = std::make_unique<PlayerMock>(kPlayerMoney);
        CreateStore();
        store_->SetCargo(prepareCargoForTest());
    }

    void CreateStore() {
     // Check if Store register observer, rest call will be from Fruit class
     // randomize generating during creating stock.
     EXPECT_CALL(*timeMock_, AddObserver(_)).Times(AtLeast(1));
     store_ = std::make_unique<Store>();
    }

    void TearDown() override {
        // Check if Player and Store unregister thier observer
        EXPECT_CALL(*timeMock_, RemoveObserver(_)).Times(AtLeast(2));
    }

    std::vector<std::unique_ptr<Cargo>> prepareCargoForTest() {
        std::vector<std::unique_ptr<Cargo>> cargo;
        cargo.push_back(std::make_unique<Alcohol>(kAlcoholAmount, 
            kAlcoholName, kAlcoholBasePrice, kAlcoholPercentage));
        cargo.push_back(std::make_unique<Fruit>(kFruitAmount, 
            kFruitName, kFruitBasePrice, kFruitExpiryTime,
            kFruitTimeElapsed));
        cargo.push_back(std::make_unique<Item>(kItemAmount, 
            kItemlName, kItemBasePrice, Item::Rarity::legendary));
        return cargo;
    }

    std::unique_ptr<TimeMock> timeMock_;
    std::unique_ptr<PlayerMock> playerMock_;
    std::unique_ptr<Store> store_;
};

TEST_F(TestSuit, StoreShouldRecalculatePrice) {
    auto* cargo = store_->GetCargo(1);
    EXPECT_EQ(112, store_->RecalculateCargoBuyPrice(cargo));
    EXPECT_EQ(125, store_->RecalculateCargoSellPrice(cargo));

    *cargo += 50;
    EXPECT_EQ(62, store_->RecalculateCargoBuyPrice(cargo));
    EXPECT_EQ(75, store_->RecalculateCargoSellPrice(cargo));

    *cargo += 50;
    EXPECT_EQ(12, store_->RecalculateCargoBuyPrice(cargo));
    EXPECT_EQ(25, store_->RecalculateCargoSellPrice(cargo));

    *cargo -= 25;
    EXPECT_EQ(37, store_->RecalculateCargoBuyPrice(cargo));
    EXPECT_EQ(50, store_->RecalculateCargoSellPrice(cargo));
}

TEST_F(TestSuit, StoreShouldRecalculatePriceDuringSelling) {
    auto* cargo = store_->GetCargo(0);
    EXPECT_EQ(2, store_->RecalculateCargoBuyPrice(cargo));
    EXPECT_EQ(5, store_->RecalculateCargoSellPrice(cargo));

    EXPECT_CALL(*playerMock_, GetMoney()).WillOnce(testing::Return(1000));
    EXPECT_CALL(*playerMock_, GetAvailableSpace()).WillOnce(testing::Return(100));
    EXPECT_CALL(*playerMock_, PurchaseCargo(_, 55));
    ASSERT_EQ(store_->Buy(cargo, 10, playerMock_.get()), Store::Response::done);

    EXPECT_EQ(4, store_->RecalculateCargoBuyPrice(cargo));
    EXPECT_EQ(7, store_->RecalculateCargoSellPrice(cargo));
}

TEST_F(TestSuit, StoreShouldRecalculatePriceDuringBuyingCargoWhichNotExistInStore) {
    auto cargo = std::make_unique<Alcohol>(kAlcoholAmount, 
        kAlcoholName, kAlcoholBasePrice, kAlcoholPercentage - 1);

    // 9 (alco_price) * (2.25 - (2 * 100 / 250)) = 13.05 -> 13
    EXPECT_EQ(13, store_->RecalculateCargoBuyPrice(cargo.get()));
    EXPECT_CALL(*playerMock_, SellCargo(_, 240));
    EXPECT_EQ(store_->Sell(cargo.get(), 20, playerMock_.get()), Store::Response::done);
    auto soldCargo = store_->GetCargo(3);
    // Cargo available in stock now = 20
    EXPECT_EQ(16, store_->RecalculateCargoBuyPrice(soldCargo));
    EXPECT_EQ(18, store_->RecalculateCargoSellPrice(soldCargo));
}

TEST_F(TestSuit, StoreShouldRecalculatePriceDuringBuyingCargoWhichExistInStore) {
    auto cargo = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice, Item::Rarity::legendary);

    // 1000 * (2.25 - (2 * 50 / 100) -> 1250
    EXPECT_EQ(1250, store_->RecalculateCargoBuyPrice(cargo.get()));
    EXPECT_CALL(*playerMock_, SellCargo(_, 21'990));
    ASSERT_EQ(store_->Sell(cargo.get(), 20, playerMock_.get()), Store::Response::done);
    auto soldCargo = store_->GetCargo(2);
    // Cargo available in stock now = 70;
    EXPECT_EQ(850, store_->RecalculateCargoBuyPrice(soldCargo));
    EXPECT_EQ(1100, store_->RecalculateCargoSellPrice(soldCargo));
}

TEST_F(TestSuit, StoreShouldSellCargoForTheSamePriceWhenHirepurchase) {
    auto cargo = std::make_unique<Item>(kItemAmount + 50, 
        kItemlName, kItemBasePrice, Item::Rarity::legendary);

    size_t price1 = 0;
    EXPECT_CALL(*playerMock_, SellCargo(_, _))
        .WillOnce(testing::SaveArg<1>(&price1));
    ASSERT_EQ(store_->Sell(cargo.get(), 20, playerMock_.get()), Store::Response::done);
    size_t price2 = 0;
    EXPECT_CALL(*playerMock_, SellCargo(_, _))
        .WillOnce(testing::SaveArg<1>(&price2));
    ASSERT_EQ(store_->Sell(cargo.get(), 15, playerMock_.get()), Store::Response::done);
    size_t price3 = 0;
    EXPECT_CALL(*playerMock_, SellCargo(_, _))
        .WillOnce(testing::SaveArg<1>(&price3));
    ASSERT_EQ(store_->Sell(cargo.get(), 8, playerMock_.get()), Store::Response::done);
    
    const size_t sold_cargo = 43;
    auto soldCargo = store_->GetCargo(2);
    // Restore amount of cargo to previus value, before selling
    *soldCargo -= sold_cargo;
    EXPECT_CALL(*playerMock_, SellCargo(_,  (price1 + price2 + price3)));
    ASSERT_EQ(store_->Sell(cargo.get(), sold_cargo, playerMock_.get()), Store::Response::done);
}

TEST_F(TestSuit, StoreShouldAddNewCargoWhenNotExist) {
    auto cargo = std::make_unique<Alcohol>(kAlcoholAmount, 
        kAlcoholName, kAlcoholBasePrice, kAlcoholPercentage - 1);

    EXPECT_CALL(*playerMock_, SellCargo(_, _));
    ASSERT_EQ(store_->Sell(cargo.get(), 20, playerMock_.get()), Store::Response::done);
    ASSERT_TRUE(store_->GetCargo(3) != nullptr);
}

TEST_F(TestSuit, StoreShouldAccumulateCargoWhenExist) {
    auto cargo = std::make_unique<Item>(kItemAmount, 
        kItemlName, kItemBasePrice, Item::Rarity::legendary);

    EXPECT_CALL(*playerMock_, SellCargo(_, _));
    ASSERT_EQ(store_->Sell(cargo.get(), 20, playerMock_.get()), Store::Response::done);
    auto soldCargo = store_->GetCargo(2);
    EXPECT_EQ(soldCargo->GetAmount(), 70);
    ASSERT_EQ(store_->GetCargo(3), nullptr);
}

TEST_F(TestSuit, StoreShouldNotSellWhenNotEnoughSpaceOnShip) {
    auto* cargo = store_->GetCargo(0);
    EXPECT_CALL(*playerMock_, GetAvailableSpace()).WillOnce(testing::Return(25));
    ASSERT_EQ(store_->Buy(cargo, 30, playerMock_.get()), Store::Response::lack_of_space);
}

TEST_F(TestSuit, StoreShouldNotSellWhenNotEnoughMoney) {
    auto* cargo = store_->GetCargo(0);
    EXPECT_CALL(*playerMock_, GetMoney()).WillOnce(testing::Return(50));
    EXPECT_CALL(*playerMock_, GetAvailableSpace()).WillOnce(testing::Return(25));
    ASSERT_EQ(store_->Buy(cargo, 10, playerMock_.get()), Store::Response::lack_of_money);
}

TEST_F(TestSuit, StoreShouldNotSellWhenNotEnoughCargoInStore) {
    auto* cargo = store_->GetCargo(0);
    ASSERT_EQ(store_->Buy(cargo, 110, playerMock_.get()), Store::Response::lack_of_cargo);
}
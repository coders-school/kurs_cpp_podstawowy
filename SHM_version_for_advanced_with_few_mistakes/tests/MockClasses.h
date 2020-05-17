#ifndef MOCKCLASSES_H
#define MOCKCLASSES_H

#include "gmock/gmock.h"

#include "Fruit.h"
#include "GTime.h"
#include "Island.h"
#include "Map.h"
#include "Player.h"

class TimeMock : public Time {
public:
    MOCK_METHOD1(AddObserver, void(Observer*));
    MOCK_METHOD1(RemoveObserver, void(Observer*));
    MOCK_CONST_METHOD0(GetElpasedTime, size_t());
    MOCK_METHOD0(Increment, Time&());
    Time& operator++() override { return Increment(); }
};

class PlayerMock : public Player {
public:
    PlayerMock(size_t money): Player(money) {}
    MOCK_METHOD1(PayCrew, void(size_t));
    MOCK_CONST_METHOD0(GetAvailableSpace, size_t());
    MOCK_CONST_METHOD0(GetMoney, size_t());
    MOCK_CONST_METHOD0(GetSpeed, size_t());
    MOCK_CONST_METHOD1(GetCargo, Cargo*(size_t));
    MOCK_METHOD2(PurchaseCargo, void(std::unique_ptr<Cargo>, size_t));
    MOCK_METHOD2(SellCargo, void(Cargo*, size_t));
    MOCK_CONST_METHOD0(PrintCargo, void());
};

class FruitMock : public Fruit {
public:
    FruitMock(size_t amount, const std::string& name, size_t base_price,
		size_t expiry_date, size_t time_elapsed):
        Fruit(amount, name, base_price, expiry_date, time_elapsed) {}
    ~FruitMock() override = default;
    MOCK_CONST_METHOD1(Print, std::ostream&(std::ostream&));
    MOCK_CONST_METHOD0(GetPrice, size_t());
    MOCK_CONST_METHOD0(GetName, std::string());
    MOCK_CONST_METHOD0(GetAmount, size_t());
    MOCK_CONST_METHOD0(GetBasePrice, size_t());
    MOCK_METHOD1(Add, Cargo&(size_t));
    Cargo& operator+=(size_t amount) override { return Add(amount); }
    MOCK_METHOD1(Subtract, Cargo&(size_t));
    Cargo& operator-=(size_t amount) override { return Subtract(amount); }
    MOCK_CONST_METHOD1(Equal, bool(const Cargo&));
	bool operator==(const Cargo& cargo) const override { return Equal(cargo); }
    MOCK_METHOD0(NextDay, void());
};

class MapMock : public Map {
public:
	MapMock(): Map() {}
    MOCK_METHOD1(Travel, void(Island*));
    MOCK_CONST_METHOD1(GetDistanceToIsland, void(Island*));
    MOCK_METHOD1(GetIsland, Island*(const Island::Coordinates&));
    MOCK_CONST_METHOD0(GetCurrentPosition, Island*(void));
};

#endif // MOCKCLASSES_H
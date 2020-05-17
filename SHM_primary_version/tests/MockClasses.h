#ifndef MOCKCLASSES_H
#define MOCKCLASSES_H

#include "gmock/gmock.h"

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
    MOCK_METHOD3(PurchaseCargo, void(const Cargo* cargo, size_t price, size_t amount));
    MOCK_METHOD3(SellCargo, void(const Cargo* cargo, size_t price, size_t amount));
    MOCK_CONST_METHOD0(PrintCargo, void());
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
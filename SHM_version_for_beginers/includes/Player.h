#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "Cargo.h"
#include "Ship.h"

class Time;

// Class is responsible for every action made by player
class Player : public Ship::Delegate {
public:
	Player(size_t money, Time* time);
	virtual ~Player() = default;
	
	// override from Ship::Delegate
	virtual void PayCrew(size_t money) override;

	virtual size_t GetAvailableSpace() const { return available_space_; }
    virtual size_t GetMoney() const { return money_; }
	virtual size_t GetSpeed() const;
	virtual Cargo* GetCargo(size_t index) const;
	virtual void PurchaseCargo(std::unique_ptr<Cargo> cargo, size_t price);
	virtual void SellCargo(Cargo* cargo, size_t price);
	virtual void PrintCargo() const;
	
private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
	size_t available_space_;
};

#endif // PLAYER_H
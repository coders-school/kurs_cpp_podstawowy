#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <vector>

#include "Cargo.h"
#include "Ship.h"

// Class is responsible for every action made by player
class Player : public Ship::Delegate {
public:
	Player(size_t money);
	virtual ~Player() = default;
	
	// override from Ship::Delegate
	virtual void PayCrew(size_t money) override;

	virtual size_t GetAvailableSpace() const { return available_space_; }
	virtual size_t GetAvailableShips() const { return ships_.size(); }
    virtual size_t GetMoney() const { return money_; }
	virtual size_t GetSpeed() const;
	virtual void PurchaseCargo(const Cargo* cargo, size_t price, size_t amount);
	virtual void SellCargo(const Cargo* cargo, size_t price, size_t amount);
	virtual void PrintCargo() const;
	virtual void PrintShips() const;
	virtual Ship* GetShip(size_t id) const;
	virtual void BuyShip(std::unique_ptr<Ship>&& ship, size_t price);
	virtual void SellShip(Ship* ship, size_t price);
	
private:
    std::vector<std::unique_ptr<Ship>> ships_;
    size_t money_;
	size_t available_space_;
};

#endif // PLAYER_H
#include "Player.h"

#include <algorithm>

#include "Cargo.h"
#include "Ship.h"
#include "ShipFactory.h"

constexpr char kName[] = "BLACK WIDOW";

Player::Player(size_t money): money_(money) {
	ships_.push_back(ShipFactory::CreateShip(
				ShipFactory::ShipType::Pinnace, kName, this));
	available_space_ = (ships_.at(0)->GetAvailableCapacity());
}

void Player::PayCrew(size_t money) {
	if (money > money_)
		money_ = SIZE_MAX;
	else
		money_ -= money;
}

size_t Player::GetSpeed() const {
	return std::min_element(begin(ships_), end(ships_),
		[](const auto& lhs, const auto& rhs){
			return lhs->GetSpeed() < rhs->GetSpeed();
	})->get()->GetSpeed();
}

void Player::PurchaseCargo(const Cargo* cargo, size_t price, size_t amount) {
	available_space_ -= amount;
	money_ -= price;
	for (const auto& ship : ships_) {
		size_t capacity = ship->GetAvailableCapacity();
		if (capacity == 0)
			continue;
		else if (capacity >= amount)	{
			ship->Load(cargo, amount);
			break;
		}
		ship->Load(cargo, capacity);
		amount -= capacity;
	}
}

void Player::SellCargo(const Cargo* cargo, size_t price, size_t amount) {
	money_ += price;
	available_space_ += amount;
	for (const auto& ship : ships_) {
		size_t unloaded = ship->TryUnload(cargo, amount);
		amount -= unloaded;
		if (amount == 0)
			break;
	}
}

void Player::PrintCargo() const {
	for (const auto& ship : ships_) {
		ship->PrintCargo();
		std::cout << '\n' << std::string(80, '*') << '\n';
	}
}

void Player::PrintShips() const {
	std::for_each(begin(ships_), end(ships_),
		[](const auto& ship){
			std::cout << *ship << '\n';
	});
}

Ship* Player::GetShip(size_t id) const {
	auto found = std::find_if(begin(ships_), end(ships_),
		[id](const auto& ship){
			return ship->GetId() == id;
	});

	return found != std::end(ships_) ? found->get() : nullptr;
}

void Player::BuyShip(std::unique_ptr<Ship>&& ship, size_t price) {
	money_ -= price;
	available_space_ += ship->GetCapacity();
	ships_.push_back(std::move(ship));
}

void Player::SellShip(Ship* ship, size_t price) {
	money_ += price;
	available_space_ -= ship->GetCapacity();
	ships_.erase(std::find_if(begin(ships_), end(ships_),
		[id = ship->GetId()](const auto& ship){
			return ship->GetId() == id;
	}));
}
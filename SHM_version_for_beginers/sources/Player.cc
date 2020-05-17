#include "Player.h"

#include "Cargo.h"
#include "Ship.h"
#include "GTime.h"

constexpr size_t kCapacity = 100;
constexpr size_t kCrew = 50;
constexpr size_t kSpeed = 10;
constexpr char kName[] = "BLACK WIDOW";
constexpr size_t kId= 10;

Player::Player(size_t money, Time* time): ship_(std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kName, kId, time, this)),
	money_(money),
	available_space_(kCapacity) {
}

void Player::PayCrew(size_t money) {
	if (money > money_)
		money_ = SIZE_MAX;
	else
		money_ -= money;
}

size_t Player::GetSpeed() const {
	return ship_->GetSpeed();
}

Cargo* Player::GetCargo(size_t index) const {
	return ship_->GetCargo(index);
}

void Player::PurchaseCargo(std::unique_ptr<Cargo> cargo, size_t price) {
	available_space_ += cargo->GetAmount();
	ship_->Load(std::move(cargo));
	money_ -= price;
}

void Player::SellCargo(Cargo* cargo, size_t price) {
	available_space_ -= cargo->GetAmount();
	ship_->Unload(cargo);
	money_ += price;
}

void Player::PrintCargo() const {
	ship_->PrintCargo();
}
#include "Ship.h"

#include <algorithm>
#include <functional>
#include <iostream>

Ship::Ship(int capacity, int crew, int speed, 
	std::string name, size_t id, Time* time, Delegate* delegate):
		capacity_(capacity),
		crew_(crew),
		speed_(speed),
		name_(name),
		id_(id),
		time_(time),
		delegate_(delegate) {
	time_->AddObserver(this);
}

Ship::~Ship() {
	time_->RemoveObserver(this);
}

void Ship::PrintCargo() const {
	std::cout << "\nAvailable cargo:\n";
	std::for_each(begin(cargo_), end(cargo_),
		[i{0}](const auto& cargo) mutable {
			std::cout << ++i << "| "; 
			cargo->Print(std::cout) << "\n"; 
	});
}

void Ship::Load(std::unique_ptr<Cargo> cargo) {
	// If cargo exist cumulate it, if not add to vector
	if (auto match_cargo = FindMatchCargo(cargo.get())) {
		*match_cargo += cargo->GetAmount();
		return;
	}
	cargo_.push_back(std::move(cargo));
}
void Ship::Unload(Cargo* cargo) {
	// If cargo was sell remove it from vector
	if (cargo->GetAmount() == 0)
		RemoveFromStorage(cargo);
}

Cargo* Ship::GetCargo(size_t index) const {
	if (cargo_.size() > index)
		return cargo_[index].get();
	return nullptr;
}

void Ship::NextDay() {
	delegate_->PayCrew(crew_);
}

Cargo* Ship::FindMatchCargo(Cargo* cargo) {
	auto match_cargo = std::find_if(std::begin(cargo_), std::end(cargo_),
		[cargo](const auto& el) {
		return *el == *cargo;
	});
	return match_cargo != std::end(cargo_) ? match_cargo->get() : nullptr;
}

void Ship::RemoveFromStorage(Cargo* cargo) {
	cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
		[cargo](const auto& el) {
		return *el == *cargo;
	}));
}
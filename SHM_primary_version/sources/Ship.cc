#include "Ship.h"

#include <algorithm>
#include <functional>
#include <iostream>

#include "TimeServiceLocator.h"

Ship::Ship(int capacity, int crew, int speed, size_t id, size_t price,
		std::string name, Delegate* delegate):
		capacity_(capacity),
		crew_(crew),
		speed_(speed),
		id_(id),
		price_(price),
		name_(name),
		delegate_(delegate) {
	TimeServiceLocator::GetTime()->AddObserver(this);
	available_capacity_ = capacity_;
}

Ship::~Ship() {
	TimeServiceLocator::GetTime()->RemoveObserver(this);
}

void Ship::PrintCargo() const {
	std::cout << "\nAvailable cargo:\n";
	std::for_each(begin(cargo_), end(cargo_),
		[i{0}](const auto& cargo) mutable {
			std::cout << ++i << "| "
			<< *cargo.first << " Amount: " << cargo.second << '\n'; 
	});
}

void Ship::Load(const Cargo* cargo, size_t amount) {
	cargo_[cargo] += amount;
	available_capacity_ -= amount;
}

size_t Ship::TryUnload(const Cargo* cargo, size_t amount) {
	auto it = cargo_.find(cargo);
	if (it == std::end(cargo_))
		return 0u;

	auto cargo_amount = it->second;
	if (cargo_amount > amount) {
		cargo_[cargo] -= amount;
		available_capacity_ += amount;
		return amount;
	}
		
	available_capacity_ += cargo_amount;
	RemoveFromStorage(cargo);
	return cargo_amount;
}

const Cargo* Ship::GetCargo(const std::string& name) const {
	auto found = std::find_if(begin(cargo_), end(cargo_),
		[&name](const auto& pair){
			return pair.first->GetName() == name;
	});

	return found != std::end(cargo_) ? found->first : nullptr;
}

void Ship::NextDay() {
	delegate_->PayCrew(crew_);
}

void Ship::RemoveFromStorage(const Cargo* cargo) {
	cargo_.erase(cargo_.find(cargo));
}

std::ostream& operator<<(std::ostream& os, const Ship& ship) {
	return os << "Id: " << ship.id_ << " | name: " << ship.name_ 
			<< " crew: " << ship.crew_ << " speed: " << ship.speed_
			<< " cargo holded: " << ship.capacity_ - ship.available_capacity_
			<< " price: " << ship.price_;
}
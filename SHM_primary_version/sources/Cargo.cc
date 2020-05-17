#include "Cargo.h"

#include <iostream>

Cargo::Cargo(std::string name, size_t base_price) :
	name_(name),
	base_price_(base_price) {
}

bool Cargo::operator==(const Cargo& cargo) const {
	return cargo.GetName() == name_;
}

std::ostream& operator<<(std::ostream& os, const Cargo& cargo) {
	return os << "Name: " << cargo.GetName();
}
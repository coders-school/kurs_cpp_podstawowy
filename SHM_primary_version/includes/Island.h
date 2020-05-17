#ifndef ISLAND_H
#define ISLAND_H

#include <cmath>
#include <memory>
#include <iostream>

#include "Store.h"

class CargoTypes;

// Class describes position of island and available store.
class Island {
public:
	class Coordinates {
	public:
		Coordinates() = default;
		Coordinates(size_t pos_x, size_t pos_y) :
			pos_x_(pos_x), pos_y_(pos_y) {}
		static size_t Distance(const Coordinates& lhs, const Coordinates& rhs) {
			return std::sqrt(std::pow((int)lhs.pos_x_ - (int)rhs.pos_x_, 2)
				+ std::pow((int)lhs.pos_y_ - (int)rhs.pos_y_, 2));
		}
		bool operator==(const Coordinates& lhs) const { 
			return this->pos_x_ == lhs.pos_x_ && this->pos_y_ == lhs.pos_y_; 
		}
		friend std::ostream& operator<<(std::ostream& out, const Coordinates& cord) {
			return out << "{ x: " << cord.pos_x_ << " | y: " << cord.pos_y_ << " }";
		}

	private:
		const size_t pos_x_{ 0 };
		const size_t pos_y_{ 0 };
	};

	Island() {}
    Island(size_t pos_x, size_t pos_y);
	Coordinates GetCoordinates() const { return position_; }
	Store* GetStore() const { return store_.get(); }

private:
    std::unique_ptr<Store> store_;
    Coordinates position_;
};

#endif // ISLAND_H
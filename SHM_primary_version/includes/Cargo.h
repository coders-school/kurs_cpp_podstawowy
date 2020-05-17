#ifndef CARGO_H
#define CARGO_H

#include <iostream>
#include <string>

// Class represent parameteres of each cargo
class Cargo {
public:
	Cargo(std::string name, size_t base_price);
    virtual ~Cargo() = default;

	std::string GetName() const { return name_; }
	size_t GetBasePrice() const { return base_price_; }
	bool operator==(const Cargo& cargo) const;

    friend std::ostream& operator<<(std::ostream& os, const Cargo& cargo);

protected:
    const std::string name_;
    const size_t base_price_;
};

#endif // CARGO_H
#ifndef CARGO_H
#define CARGO_H

#include <iostream>
#include <string>

#include "GTime.h"

// Class represent all cargo available in game
// every good frome game has his own price, which could be different 
// than base price if some conditions was satisfied
class Cargo : public Time::Observer {
public:
    Cargo() = default;
	Cargo(size_t amount, std::string name, size_t base_price);
    virtual ~Cargo() = default;

    virtual std::ostream& Print(std::ostream& os) const = 0;
    virtual size_t GetPrice() const = 0;
    virtual std::string GetName() const = 0;
	virtual size_t GetAmount() const = 0;
	virtual size_t GetBasePrice() const = 0;
    virtual Cargo& operator+=(size_t amount) = 0;
	virtual Cargo& operator-=(size_t amount) = 0;
	virtual bool operator==(const Cargo& cargo) const = 0;

protected:
    std::string name_;
	size_t amount_;
    size_t base_price_;
};

#endif // CARGO_H
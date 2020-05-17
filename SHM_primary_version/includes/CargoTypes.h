#ifndef CARGO_TYPES_H
#define CARGO_TYPES_H

#include <vector>

#include "Cargo.h"

// Class represent all cargo available in game
class CargoTypes {
public:
    CargoTypes();
    std::vector<const Cargo*> GetAvailableCargo() const;

private:
    Cargo fruit_;
    Cargo alcohol_;
    Cargo wheat_;
    Cargo wood_;
    Cargo vegetables_;
    Cargo spices_;
    Cargo canvas_;
    Cargo cotton_;
    Cargo wool_;
    Cargo jewellery_;
};

#endif // CARGO_TYPES_H
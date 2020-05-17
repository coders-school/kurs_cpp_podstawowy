#include "CargoTypes.h"

constexpr size_t kCargoTypeNum = 10;

CargoTypes::CargoTypes():
	fruit_("Fruit", 30),
    alcohol_("Alcohol", 120),
    wheat_("Wheat", 50),
    wood_("Wood", 60),
    vegetables_("Vegetables", 35),
    spices_("Spices", 300),
    canvas_("Canvas", 150),
    cotton_("Cotton", 90),
    wool_("Wool", 120),
    jewellery_("Jewellery", 500)
{}

std::vector<const Cargo*> CargoTypes::GetAvailableCargo() const {
    std::vector<const Cargo*> cargo(kCargoTypeNum);
    cargo[0] = &fruit_;
    cargo[1] = &alcohol_;
    cargo[2] = &wheat_;
    cargo[3] = &wood_;
    cargo[4] = &vegetables_;
    cargo[5] = &spices_;
    cargo[6] = &canvas_;
    cargo[7] = &cotton_;
    cargo[8] = &wool_;
    cargo[9] = &jewellery_;

    return cargo;
 }
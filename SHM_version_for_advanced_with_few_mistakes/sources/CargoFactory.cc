#include "CargoFactory.h"

CargoFactory::CargoType operator++(CargoFactory::CargoType& type) {
    return type = static_cast<CargoFactory::CargoType>(
        std::underlying_type_t<CargoFactory::CargoType>(type) + 1);
}

CargoFactory::CargoType operator*(CargoFactory::CargoType type) {
    return type;
}

CargoFactory::CargoType begin(CargoFactory::CargoType) {
    return CargoFactory::CargoType::Alcohol;
}

CargoFactory::CargoType end(CargoFactory::CargoType) {
    return CargoFactory::CargoType::LAST;
}

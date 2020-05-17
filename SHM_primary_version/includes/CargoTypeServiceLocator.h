#ifndef CARGO_TYPE_SERVICE_LOCATOR_H
#define CARGO_TYPE_SERVICE_LOCATOR_H

#include "CargoTypes.h"

class CargoTypeServiceLocator {
public:
    static CargoTypes* GetCargoType() { return service_; }
    static void Provide(CargoTypes* service) {
        service_ = service;
    }

private:
    static CargoTypes* service_;
};

#endif  // CARGO_TYPE_SERVICE_LOCATOR_H
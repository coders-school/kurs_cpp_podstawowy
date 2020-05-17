#ifndef TIME_SERVICE_LOCATOR_H
#define TIME_SERVICE_LOCATOR_H

#include "GTime.h"

class TimeServiceLocator {
public:
    static Time* GetTime() { return service_; }
    static void Provide(Time* service) {
        service_ = service;
    }

private:
    static Time* service_;
};

#endif  // TIME_SERVICE_LOCATOR_H
#ifndef SHIP_INFO_H
#define SHIP_INFO_H

#include <array>

struct ShipInfo {
    size_t kCapacity;
    size_t kCrew;
    size_t kSpeed;
    size_t kPrice;
};

constexpr std::array<ShipInfo, 8> kShipsInfo {{
    {100, 40, 10, 2000},
    {110, 45, 11, 2200},
    {140, 55, 11, 3000},
    {170, 60, 12, 3600},
    {220, 80, 12, 5000},
    {250, 90, 13, 6000},
    {300, 100, 14, 8000},
    {350, 120, 15, 10000}
}};

#endif // SHIP_INFO_H
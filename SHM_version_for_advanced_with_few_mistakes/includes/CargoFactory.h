#ifndef CARGO_FACTORY_H
#define CARGO_FACTORY_H

#include <iostream>
#include <memory>
#include <random>
#include <type_traits>

#include "Alcohol.h"
#include "Cargo.h"
#include "Fruit.h"
#include "Item.h"

constexpr size_t kMinPercentage = 10;
constexpr size_t kMaxPercentage = 96;
constexpr size_t kMinTimeToSpoil = 10;
constexpr size_t kMaxTimeToSpoil = 20;
constexpr size_t kRarityMax = 10;
constexpr char kAlcoholName[] = "Acohol";
constexpr char kFruitlName[] = "Fruit";
constexpr char kItemlName[] = "Item";

class CargoFactory {
public: 
    enum class CargoType {
        Alcohol, Fruit, Item, LAST
    };

    static std::unique_ptr<Cargo> CreateCargo(CargoType type, 
                                size_t amount, 
                                size_t base_price) {
        std::random_device rd;
        std::mt19937 gen(rd());
        switch(type) {
        case CargoType::Alcohol: {
            std::uniform_int_distribution<> percentage_dist(
                kMinPercentage, kMaxPercentage);	
            return CreateCargoT(type, amount, kAlcoholName,
                base_price, percentage_dist(gen));
            break;
            }
        case CargoType::Fruit: {
            std::uniform_int_distribution<> expiry_date_dist(
                kMinTimeToSpoil, kMaxTimeToSpoil);
            return CreateCargoT(type, amount, kFruitlName,
                base_price, expiry_date_dist(gen));
            break;
            }
        case CargoType::Item: {
            std::uniform_int_distribution<> rarity_dist(0, kRarityMax);
            return CreateCargoT(type, amount, kItemlName,
                base_price, GetRarity(rarity_dist(gen)));	
            break;
            }
        }

        std::cerr << __func__ << " Can't Create cargo!";
        return nullptr;
    }

    static std::unique_ptr<Cargo> CreateCargo(Cargo* cargo, size_t amount) {
        if (auto* alcohol = dynamic_cast<Alcohol*>(cargo))
            return CreateCargoT(CargoType::Alcohol, amount, alcohol);
        else if (auto* fruit = dynamic_cast<Fruit*>(cargo))
            return CreateCargoT(CargoType::Fruit, amount, fruit);
        else if (auto* item = dynamic_cast<Item*>(cargo))
            return CreateCargoT(CargoType::Item, amount, item);

        std::cerr << __func__ << " Can't Create cargo!";
        return nullptr;
    }

private:
    template <typename... Ts>
    static std::unique_ptr<Cargo> CreateCargoT(CargoType type, Ts&&... params) {
        switch (type)
        {
        case CargoType::Alcohol:
            return constructArgs<Alcohol, Ts...>(std::forward<Ts>(params)...);
            break;
        case CargoType::Fruit:
            return constructArgs<Fruit, Ts...>(std::forward<Ts>(params)...);
            break;
        case CargoType::Item:
            return constructArgs<Item, Ts...>(std::forward<Ts>(params)...);
            break;
        default:
            std::cerr << "Wrong type of cargo!";
            return nullptr;
            break;
        }
    }

    static Item::Rarity GetRarity(size_t num) {
        if (num < 4) {
            return Item::Rarity::common;
        } else if (num < 7) {
            return Item::Rarity::rare;
        } else if (num < 10) {
            return Item::Rarity::epic;
        }
        return Item::Rarity::legendary;
    }
};

// Simple SFINAE. If we can construct object like Fruit(arg1, arg2)
// We enable this function If we can't we call constructArgs(...).
template <typename Type, typename... Ts>
std::enable_if_t<std::is_constructible<Type, Ts...>::value,
            std::unique_ptr<Type>>
constructArgs(Ts&&... params) {
    return std::make_unique<Type>(std::forward<Ts>(params)...);
}

template <typename Type, typename... Ts>
std::unique_ptr<Type> constructArgs(...) {
    std::cerr << __func__ << "(...) -> Can't match parameters!";
    return nullptr;
} 

// Make possible itarate through enum class
CargoFactory::CargoType operator++(CargoFactory::CargoType& type);
CargoFactory::CargoType operator*(CargoFactory::CargoType type);
CargoFactory::CargoType begin(CargoFactory::CargoType);
CargoFactory::CargoType end(CargoFactory::CargoType);

#endif  // CARGO_FACTORY_H
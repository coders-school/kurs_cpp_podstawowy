#ifndef MAP_H
#define MAP_H

#include <vector>

#include "Island.h"

// Class responsible for generation map which will be used to travel.
class Map {
public:
	Map();
    void Travel(Island* destination);
	size_t GetDistanceToIsland (Island* destination) const;
	Island* GetIsland(const Island::Coordinates& coordinate);
	Island* GetCurrentPosition() const { return current_position_; }
	friend std::ostream& operator<<(std::ostream& out, const Map& map);

	// for testing
	void SetIslandForTesting(std::vector<Island>&& island) { islands_ = std::move(island); }

private:
    Island* current_position_;
    std::vector<Island> islands_;
};

#endif // MAP_H
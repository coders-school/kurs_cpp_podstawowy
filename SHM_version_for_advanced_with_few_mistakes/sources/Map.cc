#include "Map.h"

#include <algorithm>
#include <random>

constexpr size_t kIslandNum = 10;
constexpr size_t kWidth = 50;
constexpr size_t kHeight = 50;

Map::Map() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> width_gen(0, kWidth);
	std::uniform_int_distribution<> height_gen(0, kHeight);
	std::vector<Island> islands(kIslandNum);
	std::vector<std::pair<size_t, size_t>> used_position;

	// Generate map
	islands_.reserve(kIslandNum);
	for (size_t i = 0; i < kIslandNum; ++i) {
		while (true) {
			size_t x = width_gen(gen);
			size_t y = height_gen(gen);
			if (std::find_if(begin(used_position), end(used_position),
				[x, y](const auto& pos){
					return pos.first == x && pos.second == y;
				}) == std::end(used_position)) {
				used_position.push_back({ x, y });
				islands_.emplace_back(x, y);
				break;
			}
		}
	}

	current_position_ = &islands_.front();
}

Island* Map::GetIsland(const Island::Coordinates& coordinate) {
	auto island = std::find_if(std::begin(islands_), std::end(islands_), 
		[&coordinate](const Island& island) {
			return coordinate == island.GetCoordinates();
		});
	return island != std::end(islands_) ? &*island : nullptr;
}

size_t Map::GetDistanceToIsland(Island* destination) const {
	return Island::Coordinates::Distance(
		current_position_->GetCoordinates(), destination->GetCoordinates());
}

void Map::Travel(Island* destination) {
	current_position_ = destination;
}

std::ostream& operator<<(std::ostream& out, const Map& map) {
	out << "ISLANDS:\n";
	std::for_each(begin(map.islands_), end(map.islands_), 
		[&out](const Island& island) {
			out << island.GetCoordinates() << "\n";
	});
	return out;
}
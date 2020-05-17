#include "Island.h"

Island::Island(size_t pos_x, size_t pos_y): 
	position_(Coordinates(pos_x, pos_y)),
	store_(std::make_unique<Store>()) {
}
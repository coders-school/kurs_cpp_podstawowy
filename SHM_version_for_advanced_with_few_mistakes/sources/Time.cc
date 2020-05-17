#include "GTime.h"
#include <iostream>
#include <algorithm>

void Time::AddObserver(Observer* obs) {
	if (GetObserverIt(obs) == std::end(observers_))
		observers_.push_back(obs);
}

void Time::RemoveObserver(Observer* obs) {
	if (auto to_remove = GetObserverIt(obs) ; to_remove != std::end(observers_))
		observers_.erase(to_remove);
}

Time::ObserverIT Time::GetObserverIt(Observer* obs) {
	return std::find_if(begin(observers_), end(observers_),
		[obs](const auto* current) {
		return current == obs;
	});
}

Time& Time::operator++() {
	++time_elapsed_;
	std::cout << "observers_: " << observers_.size() << "\n";
	for (const auto& obs : observers_)
		obs->NextDay();
	return *this;
}
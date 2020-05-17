class Ship  {
public:
  void Load(std::unique_ptr<Cargo> cargo) {
    if (auto match_cargo = FindMatchCargo(cargo.get())) {
      *match_cargo += cargo->GetAmount();
      return;
	  }
	  cargo_.push_back(std::move(cargo));
  }
  
  void Unload(Cargo* cargo) {
		  RemoveFromStorage(cargo);
  }

  Cargo* FindMatchCargo(Cargo* cargo) {
    for (auto el : cargo_) {
      if (el->GetName() == "Fruit") {
        if (el->GetName() == cargo->GetName() &&
            el->GetBasePrice() == cargo->GetBasePrice() &&
            el->GetExpiryDate() == cargo->GetExpiryDate())
            return el.get();
      } else if (el->GetName() == "Alcohol") {
        if (el->GetName() == cargo->GetName() &&
            el->GetBasePrice() == cargo->GetBasePrice() &&
            el->GetPercentage() == cargo->GetPercentage())
            return el.get();
      } else {
        if (el->GetName() == cargo->GetName() &&
            el->GetBasePrice() == cargo->GetBasePrice() &&
            el->GetRarity() == cargo->GetRarity())
            return el.get();
      }
    }
  }

  void RemoveFromStorage(Cargo* cargo) {
    cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
      [cargo](const auto& el) {
      return *el == *cargo;
    }));
  }
};

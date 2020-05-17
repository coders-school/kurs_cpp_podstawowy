class Ship  {
public:
  Ship(): id_(-1) {}
  Ship(int crew, int speed, size_t id): crew_(crew),
    speed_(speed), id_(id) {}
  Ship(int capacity, int crew, int speed, const std::string& name, size_t id):
    Ship(crew, speed, id) {
      name_ = name;
      capacity_ = capacity;
  }

  void SetName(const std::string& name) { name_ = name; }

  Ship& operator-=(size_t num) { crew_ -= num; return *this; }
  Ship& operator+=(size_t num) { crew_ += num; return *this;}

	size_t GetCapacity() const { return capacity_; }
  size_t GetCrew() const { return crew_; }
  size_t GetSpeed() const { return speed_; }
  std::string GetName() const { return name_; }
  size_t GetId() const { return id_; }

private:
  size_t capacity_;
  size_t crew_;
  size_t speed_;
  std::string name_;
  const size_t id_;
};

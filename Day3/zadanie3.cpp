class Ship  {
public:
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
    size_t id_;
};

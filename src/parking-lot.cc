// http://www.lintcode.com/zh-cn/problem/parking-lot
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// enum type for Vehicle
enum class VehicleSize { Motorcycle, Compact, Large };

// Foward declaration to make circular reference work.
class ParkingSpot;
class Level;

// Use pImpl idiom to make copy assignment work.
class VehicleImpl {
public:
  vector<weak_ptr<ParkingSpot>> parking_spots() const noexcept {
    return parking_spots_;
  }

  int spots_needed() const noexcept { return spots_needed_; }

  VehicleSize size() const noexcept { return size_; }

  void park_in_spot(const shared_ptr<ParkingSpot> &spot) {
    parking_spots_.emplace_back(spot);
  }

  void clear_spots();

  virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot> &spot) const
      noexcept {
    return true;
  }

protected:
  vector<weak_ptr<ParkingSpot>> parking_spots_;
  int spots_needed_;
  VehicleSize size_;
};

class Vehicle {
public:
  Vehicle() : pImpl_(make_shared<VehicleImpl>()) {}

  vector<weak_ptr<ParkingSpot>> parking_spots() const noexcept {
    return pImpl_->parking_spots();
  }

  int spots_needed() const noexcept { return pImpl_->spots_needed(); }

  VehicleSize size() const noexcept { return pImpl_->size(); }

  void park_in_spot(const shared_ptr<ParkingSpot> &spot) {
    pImpl_->park_in_spot(spot);
  }

  void clear_spots() { pImpl_->clear_spots(); }

  virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot> &spot) const
      noexcept {
    return pImpl_->can_fit_in_spot(spot);
  }

protected:
  shared_ptr<VehicleImpl> pImpl_;
};

class ParkingSpot : public std::enable_shared_from_this<ParkingSpot> {
public:
  ParkingSpot(const shared_ptr<Level> &level, int row, int spot_number,
              VehicleSize spot_size)
      : level_(level), row_(row), spot_number_(spot_number),
        spot_size_(spot_size), vehicle_(nullptr) {}

  bool is_available() const noexcept { return vehicle_ == nullptr; }

  bool can_fit_vehicle(Vehicle *vehicle) {
    return is_available() && vehicle->can_fit_in_spot(shared_from_this());
  }

  void park(Vehicle *vehicle) {
    vehicle_ = vehicle;
    vehicle_->park_in_spot(shared_from_this());
  }

  void remove_vehicle();

  int row() const noexcept { return row_; }

  int spot_number() const noexcept { return spot_number_; }

  VehicleSize size() const noexcept { return spot_size_; }

private:
  weak_ptr<Level> level_;
  int row_, spot_number_;
  VehicleSize spot_size_;
  Vehicle *vehicle_;
};

// Use pImpl idiom to make copy assignment work.
class BusImpl : public VehicleImpl {
public:
  BusImpl() {
    spots_needed_ = 5;
    size_ = VehicleSize::Large;
  }

  virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot> &spot) const
      noexcept {
    return spot->size() == VehicleSize::Large;
  }
};

class Bus : public Vehicle {
public:
  Bus() { pImpl_ = make_shared<BusImpl>(); }
};

// Use pImpl idiom to make copy assignment work.
class CarImpl : public VehicleImpl {
public:
  CarImpl() {
    spots_needed_ = 1;
    size_ = VehicleSize::Compact;
  }

  virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot> &spot) const
      noexcept {
    return spot->size() != VehicleSize::Motorcycle;
  }
};

class Car : public Vehicle {
public:
  Car() { pImpl_ = make_shared<CarImpl>(); }
};

// Use pImpl idiom to make copy assignment work.
class MotorcycleImpl : public VehicleImpl {
public:
  MotorcycleImpl() {
    spots_needed_ = 1;
    size_ = VehicleSize::Motorcycle;
  }

  virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot> &spot) const
      noexcept {
    return true;
  }
};

class Motorcycle : public Vehicle {
public:
  Motorcycle() { pImpl_ = make_shared<MotorcycleImpl>(); }
};

class Level : public std::enable_shared_from_this<Level> {
public:
  Level(int flr, int num_rows, int spots_per_row)
      : num_rows_(num_rows), floor_(flr), spots_per_row_(spots_per_row),
        number_spots_(0), available_spots_(0) {}

  // Use two-phase construction to avoid the problem that
  // shared_from_this() cannot be used in ctor!
  void init() {
    for (int row = 0; row < num_rows_; ++row) {
      int i = 0;
      for (; i < spots_per_row_ / 4; ++i) {
        spots_.emplace_back(make_shared<ParkingSpot>(
            shared_from_this(), row, number_spots_, VehicleSize::Motorcycle));
        ++number_spots_;
      }

      for (; i < spots_per_row_ / 4 * 3; ++i) {
        spots_.emplace_back(make_shared<ParkingSpot>(
            shared_from_this(), row, number_spots_, VehicleSize::Compact));
        ++number_spots_;
      }

      for (; i < spots_per_row_; ++i) {
        spots_.emplace_back(make_shared<ParkingSpot>(
            shared_from_this(), row, number_spots_, VehicleSize::Large));
        ++number_spots_;
      }
    }
    available_spots_ = number_spots_;
  }

  bool park_vehicle(Vehicle *vehicle) {
    if (available_spots() < vehicle->spots_needed()) {
      return false;
    }

    const auto &spot_num = find_available_spots(vehicle);
    if (spot_num < 0) {
      return false;
    } else {
      park_starting_at_spot(spot_num, vehicle);
      return true;
    }
  }

  int find_available_spots(Vehicle *vehicle) {
    const auto &spots_needed = vehicle->spots_needed();
    int last_row = -1;
    int spots_found = 0;

    for (int i = 0; i < spots_.size(); ++i) {
      auto &spot = spots_[i];
      if (last_row != spot->row()) {
        spots_found = 0;
        last_row = spot->row();
      }
      if (spot->can_fit_vehicle(vehicle)) {
        ++spots_found;
      } else {
        spots_found = 0;
      }

      if (spots_found == spots_needed) {
        return i - (spots_needed - 1);
      }
    }

    return -1;
  }

  void park_starting_at_spot(int spot_num, Vehicle *vehicle) {
    for (int i = spot_num; i < spot_num + vehicle->spots_needed(); ++i) {
      spots_[i]->park(vehicle);
    }
    available_spots_ -= vehicle->spots_needed();
  }

  void spot_freed() noexcept { ++available_spots_; }

  int available_spots() const noexcept { return available_spots_; }

private:
  int num_rows_;
  int floor_;
  int spots_per_row_;
  int number_spots_;
  int available_spots_;
  vector<shared_ptr<ParkingSpot>> spots_;
};

void VehicleImpl::clear_spots() {
  for (const auto &spot : parking_spots_) {
    if (auto spt = spot.lock()) {
      spt->remove_vehicle();
    }
  }
  parking_spots_.clear();
}

void ParkingSpot::remove_vehicle() {
  if (auto spt = level_.lock()) {
    spt->spot_freed();
  }
  vehicle_ = nullptr;
}

class ParkingLot {
public:
  // @param n number of leves
  // @param num_rows  each level has num_rows rows of spots
  // @param spots_per_row each row has spots_per_row spots
  ParkingLot(int n, int num_rows, int spots_per_row) {
    for (int i = 0; i < n; ++i) {
      auto &&ptr = make_shared<Level>(i, num_rows, spots_per_row);
      ptr->init();
      levels_.emplace_back(ptr);
    }
  }

  // Park the vehicle in a spot (or multiple spots)
  // Return false if failed
  bool parkVehicle(Vehicle &vehicle) {
    unParkVehicle(
        vehicle); // This may make the parked vehicle move to another place.

    for (auto &level : levels_) {
      if (level->park_vehicle(&vehicle)) {
        return true;
      }
    }
    return false;
  }

  // unPark the vehicle
  void unParkVehicle(Vehicle &vehicle) { vehicle.clear_spots(); }

private:
  vector<shared_ptr<Level>> levels_;
};

// below is the runaable simple solution

// enum type for Vehicle
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::map;

enum class VehicleSize { Motorcycle, Compact, Large };

class Vehicle {
public:
  virtual VehicleSize size() = 0;
  virtual int spot_num() = 0;
};

class Bus : public Vehicle {
public:
  VehicleSize size() override { return VehicleSize::Large; }
  int spot_num() override { return 5; }
};

class Car : public Vehicle {
public:
  VehicleSize size() override { return VehicleSize::Compact; }
  int spot_num() override { return 1; }
};

class Motorcycle : public Vehicle {
public:
  VehicleSize size() override { return VehicleSize::Motorcycle; }
  int spot_num() override { return 1; }
};

class Level {
public:
  Level(int num_rows, int spots_per_row) {
    int moto = spots_per_row / 4;
    moto_spots.resize(moto);
    int car = spots_per_row / 4 * 3;
    compact_spots.resize(car - moto);
    large_spots.resize(spots_per_row - car);
  }

  bool park_vehicle(Vehicle *vehicle, VehicleSize size, int num) {
    if (size == VehicleSize::Motorcycle) {
      for (int i = 0; i < moto_spots.size(); ++i) {
        if (moto_spots[i] == NULL) {
          moto_spots[i] = vehicle;
          vehicle_to_spot[vehicle][VehicleSize::Motorcycle] = i;
          return true;
        }
      }
      return false;
    } else if (size == VehicleSize::Compact) {
      for (int i = 0; i < compact_spots.size(); ++i) {
        if (compact_spots[i] == NULL) {
          compact_spots[i] = vehicle;
          vehicle_to_spot[vehicle][VehicleSize::Compact] = i;
          return true;
        }
      }
      for (int i = 0; i < large_spots.size(); ++i) {
        if (large_spots[i] == NULL) {
          large_spots[i] = vehicle;
          vehicle_to_spot[vehicle][VehicleSize::Large] = i;
          return true;
        }
      }
      return false;
    } else if (size == VehicleSize::Large) {
      for (int i = 0; i < large_spots.size(); ++i) {
        if (large_spots[i] == NULL) {
          bool can_park = true;
          for (int j = i; j < i + num; ++j) {
            if (large_spots[j] != NULL) {
              can_park = false;
              break;
            }
          }
          if (can_park) {
            for (int j = i; j < i + num; ++j) {
              large_spots[j] = vehicle;
            }
            vehicle_to_spot[vehicle][VehicleSize::Large] = i;
            return true;
          }
        }
      }
      return false;
    }
  }

  void unpark_vehicle(Vehicle *vehicle) {
    map<VehicleSize, int> spot = vehicle_to_spot[vehicle];
    VehicleSize size = vehicle->size();
    if (spot.count(size)) {
      int idx = spot[size];
      if (size == VehicleSize::Motorcycle) {
        moto_spots[idx] = NULL;
      } else if (size == VehicleSize::Compact) {
        compact_spots[idx] = NULL;
      } else {
        for (int i = idx; i < large_spots.size(); ++i) {
          if (large_spots[i] == vehicle) {
            large_spots[i] = NULL;
          } else {
            break;
          }
        }
      }
    } else if (size == VehicleSize::Compact && spot.count(VehicleSize::Large)) {
      int idx = spot[VehicleSize::Large];
      large_spots[idx] = NULL;
    }
  }

private:
  vector<Vehicle *> moto_spots;
  vector<Vehicle *> compact_spots;
  vector<Vehicle *> large_spots;
  map<Vehicle *, map<VehicleSize, int>> vehicle_to_spot;
};

class ParkingLot {
public:
  // @param n number of leves
  // @param num_rows  each level has num_rows rows of spots
  // @param spots_per_row each row has spots_per_row spots
  ParkingLot(int n, int num_rows, int spots_per_row) {
    for (int i = 0; i < n; ++i) {
      Level *level = new Level(num_rows, spots_per_row);
      levels.push_back(level);
    }
  }

  // Park the vehicle in a spot (or multiple spots)
  // Return false if failed
  bool parkVehicle(Vehicle &vehicle) {
    for (int i = 0; i < levels.size(); ++i) {
      if (levels[i]->park_vehicle(&vehicle, vehicle.size(),
                                  vehicle.spot_num())) {
        vehicle_to_level[&vehicle] = levels[i];
        return true;
      }
    }
    return false;
  }

  // unPark the vehicle
  void unParkVehicle(Vehicle &vehicle) {
    Level *level = vehicle_to_level[&vehicle];
    if (level) {
      level->unpark_vehicle(&vehicle);
    }
  }

private:
  vector<Level *> levels;
  map<Vehicle *, Level *> vehicle_to_level;
};

int main() {
  ParkingLot pl(1, 1, 11);
  Motorcycle m;
  Vehicle &moto = m;
  auto ret = pl.parkVehicle(moto);
  cout << "parking moto: " << ret << endl;
  for (int i = 0; i < 5; i++) {
    Car c;
    Vehicle &cur_car = c;
    ret = pl.parkVehicle(cur_car);
    cout << "parking car" << i + 1 << ":" << ret << endl;
  }

  Bus b;
  Vehicle &bus = b;
  ret = pl.parkVehicle(bus);
  cout << "parking bus: " << ret << endl;

  return 0;
}

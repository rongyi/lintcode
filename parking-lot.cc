// http://www.lintcode.com/zh-cn/problem/parking-lot
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

// enum type for Vehicle
enum class VehicleSize {
  Motorcycle,
  Compact,
  Large
};

class Vehicle {

};

class Bus: public Vehicle {

};

class Car: public Vehicle {

};

class Motorcycle: public Vehicle {

};

class Level {

};

class ParkingLot {
public:
  // @param n number of leves
  // @param num_rows  each level has num_rows rows of spots
  // @param spots_per_row each row has spots_per_row spots
  ParkingLot(int n, int num_rows, int spots_per_row) {

  }

  // Park the vehicle in a spot (or multiple spots)
  // Return false if failed
  bool parkVehicle(Vehicle &vehicle) {

  }

  // unPark the vehicle
  void unParkVehicle(Vehicle &vehicle) {

  }
};

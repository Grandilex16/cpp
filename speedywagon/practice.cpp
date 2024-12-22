#include "speedywagon.cpp"
#include "speedywagon.h"
#include <ios>
#include <iostream>

using namespace speedywagon;

int main() {

  // pointer syntax
  std::string opponent = "Michael Sanders";
  std::string *ethan{&opponent};
  std::string passport_name{*ethan};

  std::cout << *ethan << "\n";
  std::cout << passport_name << "\n";
  std::cout << "\n";

  // pointer arithmetic
  int gatecode[] = {462, 753, 218, 611, 977};
  int *ptr{&gatecode[0]};
  int dialed_address{*(ptr + 2)};
  std::cout << dialed_address << "\n";
  std::cout << "\n";

  // accessing member variables
  struct Superhero {
    std::string superpower;
  };
  Superhero wonder_woman{};
  Superhero *dianaPrince = &wonder_woman;
  dianaPrince->superpower = "Lasso of Truth";

  std::cout << "Wonder woman, pocesses the mighty " << dianaPrince->superpower
            << "!" << "\n";

  // Task 1
  std::cout << "\n";
  pillar_men_sensor *sensor{nullptr};
  bool isConnected = connection_check(sensor);
  std::cout << std::boolalpha << isConnected;

  // Task 2
  std::cout << "\n";
  pillar_men_sensor sensor_array[3] = {{0}, {101}, {22}};
  int total_activity = activity_counter(sensor_array, 3);
  std::cout << total_activity << "\n";

  // Task 3
  std::cout << "\n";
  pillar_men_sensor db{9008, "songokunoie", {7, 7, 7}};
  bool alarm = alarm_control(&db);
  std::cout << std::boolalpha << alarm << "\n";

  // Task 4
  pillar_men_sensor wham{0, "Rome", {1, 605, 313, 4000}};
}

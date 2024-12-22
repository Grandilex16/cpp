#pragma once
#include <string>

namespace star_map {

enum System {
  Sol,
  BetaHydri,
  EpsilonEridani,
  AlphaCentauri,
  DeltaEridani,
  Omicron2Eridani,
};
} // namespace star_map

namespace heaven {

class Vessel {
public:
  Vessel(std::string name, int age);
  Vessel(std::string name, int num, star_map::System some_system);

  Vessel replicate(std::string name);
  void make_buster();
  bool shoot_buster();

  int generation = 2;
  int busters = 0;
  star_map::System current_system;
  std::string str;
  int num;

private:
}; // class Vessel

std::string get_older_bob(Vessel one, Vessel two);
bool in_the_same_system(Vessel, Vessel);

} // namespace heaven

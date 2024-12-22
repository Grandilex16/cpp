#include "doctor_data.cpp"
#include "doctor_data.h"
#include <ios>
#include <iostream>

using namespace std;

int main() {
  heaven::Vessel bob{"Robert Johansson", 1};
  heaven::Vessel will{"Riker", 2, star_map::System::BetaHydri};

  heaven::Vessel bob5 = will.replicate(bob.str + "2");

  cout << bob5.busters << "\n";
  bob5.make_buster();
  cout << bob5.busters << "\n";
  bool success = bob5.shoot_buster();
  cout << boolalpha << success << "\n";
  cout << bob5.busters << "\n";
  success = bob5.shoot_buster();
  cout << boolalpha << success << "\n";

  heaven::Vessel bob1{"Bob", 1, star_map::System::AlphaCentauri};
  heaven::Vessel marv{"Marvin", 2, star_map::System::DeltaEridani};
  heaven::Vessel milo{"Milo", 3, star_map::System::DeltaEridani};
  heaven::Vessel howie{"Howard", 4, star_map::System::Omicron2Eridani};

  cout << heaven::get_older_bob(bob1, marv) << "\n";
  cout << boolalpha << heaven::in_the_same_system(marv, milo) << "\n";
  cout << boolalpha << heaven::in_the_same_system(marv, howie) << "\n";
}

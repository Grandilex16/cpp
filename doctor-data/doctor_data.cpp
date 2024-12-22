#include "doctor_data.h"

using namespace std;

namespace heaven {

Vessel::Vessel(string str, int num) : str(str), num(num) {}

Vessel::Vessel(string str, int num, star_map::System some_system)
    : current_system(some_system), str(str), num(num) {}

Vessel Vessel::replicate(string name) {
  return Vessel(name, this->num, this->current_system);
}

void Vessel::make_buster() { busters++; }
bool Vessel::shoot_buster() {

  if (busters > 0) {
    busters = 0;
    return true;
  } else {
    return false;
  }
}

string get_older_bob(Vessel one, Vessel two) {

  string str1 = one.str;
  string str2 = two.str;
  return str1;
}

bool in_the_same_system(Vessel one, Vessel two) {

  if (one.current_system == two.current_system) {
    return true;
  } else {
    return false;
  }
}
} // namespace heaven

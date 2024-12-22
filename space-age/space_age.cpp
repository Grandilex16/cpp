#include "space_age.h"

#include <cmath>

namespace space_age {

space_age::space_age(long int num) : num(num) {}

long int space_age::seconds() const { return num; }

// 1 year = 31,557,600 seconds
// 1 second = 0.00000003169 years
double space_age::on_earth() const { return num / 31557600.0; }

double space_age::on_mercury() const {
  return round((on_earth() / 0.2408467) * 100.0) / 100.0;
}

double space_age::on_venus() const {
  return round((on_earth() / 0.61519726) * 100.0) / 100.0;
}

double space_age::on_mars() const {
  return round((on_earth() / 1.8808158) * 100.0) / 100.0;
}

double space_age::on_jupiter() const {
  return round((on_earth() / 11.862615) * 100.0) / 100.0;
}

double space_age::on_saturn() const {
  return round((on_earth() / 29.447498) * 100.0) / 100.0;
}

double space_age::on_uranus() const {
  return round((on_earth() / 84.016846) * 100.0) / 100.0;
}

double space_age::on_neptune() const {
  return round((on_earth() / 164.79132) * 100.0) / 100.0;
}
} // namespace space_age

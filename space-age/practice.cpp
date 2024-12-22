#include <iostream>

#include "space_age.cpp"

int main() {
  long int num = 189839836;
  const space_age::space_age age(num);
  std::cout << "Seconds: " << age.seconds() << "\n";
  std::cout << "Earth Time: " << age.on_earth() << "\n";
  std::cout << "Venus Time: " << age.on_venus() << "\n";
  std::cout << "Mars Time: " << age.on_mars() << "\n";
  std::cout << "Jupiter Time: " << age.on_jupiter() << "\n";
  std::cout << "Saturn Time: " << age.on_saturn() << "\n";
  std::cout << "Uranus Time: " << age.on_uranus() << "\n";
  std::cout << "Neptune Time: " << age.on_neptune() << "\n";
}

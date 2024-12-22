#include "ellens_alien_game.cpp"
#include <ios>
#include <iostream>

using namespace std;

using namespace targets;
int main() {

  Alien alien{2, 0};

  cout << alien.get_health() << "\n";
  alien.hit();
  cout << alien.get_health() << "\n";
  alien.hit();
  cout << alien.get_health() << "\n";
  alien.hit();
  cout << alien.get_health() << "\n";
  alien.hit();
  cout << alien.get_health() << "\n";
  cout << boolalpha << alien.is_alive() << "\n";

  return 0;
}

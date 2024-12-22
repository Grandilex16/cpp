#include "/home/jayce/cpp/allergies/allergies.cpp"
#include "/home/jayce/cpp/allergies/allergies.h"
#include <iostream>
#include <map>

using namespace std;

// Ellen's Alien Game Practice
class Alien {
public:
  int x_coordinate;
  int y_coordinate;
  Alien(int x, int y) {
    x_coordinate = x;
    y_coordinate = y;
  }

  int get_health() { return health; }

  bool hit() { return health -= 1; }

  bool is_alive() { return health > 0; }

  bool teleport(int x_new, int y_new) {
    x_coordinate = x_new;
    y_coordinate = y_new;
    return true;
  }

  bool collision_detection(const Alien &other) {
    return (x_coordinate == other.x_coordinate &&
            y_coordinate == other.y_coordinate);
  }

private:
  int health = 3;
};

class Wizard {
public:
  Wizard(string new_name) { name = new_name; }
  Wizard(string new_name, int new_damage) {
    name = new_name;
    damage = new_damage;
  }
  int cast_spell() { return damage; }
  string name{};

private:
  int damage{5};
};

int main() {

  // Ellen's Alien Game Practice
  Alien Alien(2, 0);
  cout << "Alien's location is: " << Alien.x_coordinate << " "
       << Alien.y_coordinate << "\n";
  Alien.teleport(5, 6);
  cout << "Alien's new location is: " << Alien.x_coordinate << " "
       << Alien.y_coordinate;

  cout << "\n";

  cout << "Health: " << Alien.get_health() << "\n\n";
  cout << "Alien Alive?" << std::boolalpha << Alien.is_alive() << "\n";
  Alien.hit();
  cout << "Alien Alive?" << std::boolalpha << Alien.is_alive() << "\n";
  cout << Alien.get_health() << "\n";
  Alien.hit();
  cout << "Alien Alive?" << std::boolalpha << Alien.is_alive() << "\n";
  cout << Alien.get_health() << "\n";
  Alien.hit();
  cout << "Alien Alive?" << std::boolalpha << !Alien.is_alive() << "\n";
  cout << Alien.get_health() << "\n";
  Alien.hit();
  cout << "Alien Alive?" << std::boolalpha << !Alien.is_alive() << "\n";
  cout << Alien.get_health() << "\n";
  Alien.hit();

  cout << "\n\n";

  class Alien Malcom(3, 6);
  class Alien altham(-2, 12);
  cout << Malcom.collision_detection(altham) << "\n";
  altham.teleport(3, 6);
  cout << altham.collision_detection(altham);

  cout << "\n\n";

  Wizard el{"Eleven"};
  Wizard vecna{"Vecna", 50};

  cout << el.name << "\n";
  cout << vecna.name << " " << vecna.cast_spell() << "\n\n";

  // Allergies practice
  cout << "ALLERGIES PRACTICE: \n";

  allergies::allergy_test test(1);
  cout << test.is_allergic_to("eggs");

  cout << "\n";

  cout << "getting Alleriges: \n";

  for (string i : test.get_allergies()) {
    cout << i << "\n";
  }

  cout << "\n\n";
  map<string, int> allergies_map{
      {"eggs", 1},         {"peanuts", 2},   {"shellfish", 4},
      {"strawberries", 8}, {"tomatoes", 16}, {"chocolate", 32},
      {"pollen", 64},      {"cats", 128},    {"milk", 256},
      {"soy", 512},        {"fish", 1024}};

  multimap<string, string> map_protiens{
      {"Methionine", "AUG"}, {"Phenylalanine", "UUU"}, {"Phenylalanine", "UUC"},
      {"Leucine", "UUA"},    {"Leucine", "UUG"},       {"Serine", "UCU"},
      {"Serine", "UCC"},     {"Serine", "UCA"},        {"Serine", "UCG"},
      {"Tyrosine", "UAU"},   {"Tyrosine", "UAC"},      {"Cysteine", "UGU"},
      {"Cysteine", "UGC"},   {"Tryptophan", "UGG"},
  };

  string sequence = "AUGUUUUCUUAAAUG";
  int seq_len = sequence.length();
  for (int i = 0; i < seq_len; i++) {

    string codon = sequence.substr(i, 3);
    cout << codon << " ";
    i += 3;
  }

  // for(pair i : map_protiens) {
  // 	cout << i.second << " ";
  // }

  return 0;
}

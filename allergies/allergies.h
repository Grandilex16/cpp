#include <map>
#include <string>
#include <unordered_set>
#if !defined(ALLERGIES_H)
#define ALLERGIES_H

using namespace std;

namespace allergies {

class allergy_test {
public:
  allergy_test(int num);
  bool is_allergic_to(string str);
  unordered_set<string> get_allergies();

private:
  map<string, int> allergies_map{
      {"eggs", 1},         {"peanuts", 2},   {"shellfish", 4},
      {"strawberries", 8}, {"tomatoes", 16}, {"chocolate", 32},
      {"pollen", 64},      {"cats", 128},    {"milk", 256},
      {"soy", 512},        {"fish", 1024}};

  int score;
};

}; // namespace allergies

#endif // ALLERGIES_H
